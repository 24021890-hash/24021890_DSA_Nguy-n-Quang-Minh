#include <iostream>
#include <string>
#include <stdexcept>

template <typename Key, typename Value>
class ArraySymbolTable {
private:
    Key* keys;
    Value* vals;
    int n;        // Số phần tử hiện có
    int capacity; // Sức chứa tối đa của mảng

    // Thay đổi kích thước mảng động: O(N)
    void resize(int newCapacity) {
        Key* tempKeys = new Key[newCapacity];
        Value* tempVals = new Value[newCapacity];
        for (int i = 0; i < n; i++) {
            tempKeys[i] = keys[i];
            tempVals[i] = vals[i];
        }
        delete[] keys;
        delete[] vals;
        keys = tempKeys;
        vals = tempVals;
        capacity = newCapacity;
    }

public:
    ArraySymbolTable(int initCapacity = 4) : n(0), capacity(initCapacity) {
        keys = new Key[capacity];
        vals = new Value[capacity];
    }

    ~ArraySymbolTable() {
        delete[] keys;
        delete[] vals;
    }

    // Trả về số lượng khóa nhỏ hơn key (Tìm kiếm nhị phân): O(log N)
    int rank(Key key) const {
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < keys[mid])      hi = mid - 1;
            else if (key > keys[mid]) lo = mid + 1;
            else                      return mid;
        }
        return lo;
    }

    // Lấy giá trị theo khóa: O(log N)
    Value get(Key key) const {
        if (isEmpty()) throw std::out_of_range("Symbol Table is empty");
        int i = rank(key);
        if (i < n && keys[i] == key) {
            return vals[i];
        }
        throw std::out_of_range("Key not found");
    }

    // Thêm mới hoặc cập nhật: O(N) do phải dịch chuyển phần tử
    void put(Key key, Value val) {
        int i = rank(key);

        // Nếu khóa đã tồn tại -> Cập nhật giá trị
        if (i < n && keys[i] == key) {
            vals[i] = val;
            return;
        }

        // Nếu đầy mảng -> Nhân đôi kích thước
        if (n == capacity) resize(2 * capacity);

        // Dịch các phần tử từ vị trí i sang phải 1 bước để giữ thứ tự
        for (int j = n; j > i; j--) {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
        }
        keys[i] = key;
        vals[i] = val;
        n++;
    }

    // Xóa khóa: O(N)
    void remove(Key key) {
        if (isEmpty()) return;
        int i = rank(key);

        // Không tìm thấy khóa
        if (i == n || keys[i] != key) return;

        // Dịch các phần tử phía sau sang trái 1 bước
        for (int j = i; j < n - 1; j++) {
            keys[j] = keys[j + 1];
            vals[j] = vals[j + 1];
        }
        n--;

        // Thu nhỏ mảng nếu số phần tử chỉ còn 1/4 sức chứa
        if (n > 0 && n == capacity / 4) resize(capacity / 2);
    }

    bool contains(Key key) const {
        int i = rank(key);
        return (i < n && keys[i] == key);
    }

    Key min() const {
        if (isEmpty()) throw std::out_of_range("Symbol Table is empty");
        return keys[0];
    }

    Key max() const {
        if (isEmpty()) throw std::out_of_range("Symbol Table is empty");
        return keys[n - 1];
    }

    int size() const { return n; }
    bool isEmpty() const { return n == 0; }
};

int main() {
    ArraySymbolTable<std::string, int> st;
    st.put("S", 0);
    st.put("E", 1);
    st.put("A", 2);
    st.put("R", 3);
    st.put("E", 6); // Cập nhật E thành 6

    std::cout << "Min key: " << st.min() << "\n";         // A
    std::cout << "Max key: " << st.max() << "\n";         // S
    std::cout << "Value of E: " << st.get("E") << "\n";   // 6

    st.remove("E");
    std::cout << "Contains E: " << (st.contains("E") ? "Yes" : "No") << "\n"; // No
    return 0;
}
