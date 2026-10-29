#include <iostream>
#include <string>

using namespace std;

// Node lưu trữ cặp Key - Value trong danh sách liên kết
struct HashNode {
    string key;
    int value;
    HashNode* next;

    HashNode(string k, int v) {
        key = k;
        value = v;
        next = nullptr;


    
   

    // Thêm hoặc cập nhật một cặp (Key, Value)
    void insert(string key, int value) {
        int index = hashFunction(key);
        HashNode* current = table[i = index];

        // Kiểm tra xem key đã tồn tại chưa, nếu có thì cập nhật giá trị mới
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Nếu chưa tồn tại, tạo node mới và thêm vào đầu danh sách liên kết tại bucket tương ứng
        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Tìm kiếm giá trị dựa vào key (Trả về -1 nếu không tìm thấy)
    int search(string key) {
        int index = hashFunction(key);
        HashNode* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Không tìm thấy
    }

    // Xóa một phần tử dựa vào key
    void remove(string key) {
        int index = hashFunction(key);
        HashNode* current = table[index];
        HashNode* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    // Node cần xóa nằm ở đầu danh sách
                    table[index] = current->next;
                } else {
                    // Node nằm ở giữa hoặc cuối danh sách
                    prev->next = current->next;
                }
                delete current;
                cout << "Da xoa key: " << key << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Khong tìm thay key: " << key << " de xoa." << endl;
    }

    // Hiển thị toàn bộ bảng băm
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            HashNode* current = table[i];
            while (current != nullptr) {
                cout << "[" << current->key << ": " << current->value << "] -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    // Tạo bảng băm với dung lượng 5 bucket để dễ minh họa va chạm
    HashTable ht(5);

    // Thêm dữ liệu
    ht.insert("Apple", 100);
    ht.insert("Banana", 150);
    ht.insert("Orange", 200);
    ht.insert("Grape", 250);

    cout << "--- Hien thi Bang Bam ---" << endl;
    ht.display();

    // Tìm kiếm
    cout << "\nTim kiem 'Banana': " << ht.search("Banana") << endl;
    cout << "Tim kiem 'Mango': " << ht.search("Mango") << endl;

    // Xóa phần tử
    cout << "\n--- Sau khi xoa 'Apple' ---" << endl;
    ht.remove("Apple");
    ht.display();

    return 0;
}
