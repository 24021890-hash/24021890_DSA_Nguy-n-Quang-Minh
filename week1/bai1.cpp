#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Nhap so luong phan tu N: ";
    cin >> n;

  
    if (n <= 0) {
        cout << "So luong phan tu phai lon hon 0!\n";
        return 0;
    }

    vector<long long> a(n);
    long long tong = 0;

    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i]; 
    }

    cout << "Tong cac phan tu trong day la: " << tong << "\n";

    return 0;
}
