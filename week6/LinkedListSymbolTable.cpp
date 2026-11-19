#include <iostream>
#include <string>
#include <stdexcept>

template <typename Key, typename Value>
class LinkedListSymbolTable {
private:
    struct Node {
        Key key;
        Value val;
        Node* next;
        Node(Key k, Value v, Node* n) : key(k), val(v), next(n) {}
    };

    Node* head;
    int count;

public:
    LinkedListSymbolTable() : head(nullptr), count(0) {}

    ~LinkedListSymbolTable() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Thêm mới hoặc cập nhật giá trị cho khóa: O(N)
    void put(Key key, Value val) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->val = val; // Đã tồn tại -> Cập nhật giá trị
                return;
            }
        }
        // Chưa tồn tại -> Thêm vào đầu danh sách
        head = new Node(key, val, head);
        count++;
    }

    // Lấy giá trị theo khóa: O(N)
    Value get(Key key) const {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) {
                return x->val;
            }
        }
        throw std::out_of_range("Key not found in Symbol Table");
    }

    // Kiểm tra khóa có tồn tại không: O(N)
    bool contains(Key key) const {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) return true;
        }
        return false;
    }

    // Xóa một cặp khóa-giá trị: O(N)
    void remove(Key key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    head = curr->next; // Xóa phần tử đầu
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                count--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    int size() const { return count; }
    bool isEmpty() const { return count == 0; }
};

int main() {
    LinkedListSymbolTable<std::string, int> st;
    st.put("apple", 10);
    st.put("banana", 20);
    st.put("apple", 15); // Cập nhật giá trị của apple

    std::cout << "Size: " << st.size() << "\n";           // 2
    std::cout << "Apple: " << st.get("apple") << "\n";   // 15

    st.remove("banana");
    std::cout << "Contains banana: " << (st.contains("banana") ? "Yes" : "No") << "\n"; // No

    return 0;
}
