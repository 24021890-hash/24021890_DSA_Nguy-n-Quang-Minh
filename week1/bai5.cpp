#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu N: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<double> a(n);
    double tong = 0;

    cout << "Nhap " << n << " so thuc: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i];
    }

    double trungBinh = tong / n;

    cout << "Gia tri trung binh: " << trungBinh << "\n";
    cout << "Cac phan tu >= trung binh: ";
    for (double x : a) {
        if (x >= trungBinh) {
            cout << x << " ";
        }
    }
    cout << "\n";

    return 0;
}
