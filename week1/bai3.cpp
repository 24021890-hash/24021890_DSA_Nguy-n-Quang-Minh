#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n < 0) {
        cout << "Khong tinh duoc giai thua cho so am!\n";
        return 0;
    }

    unsigned long long giaiThua = 1;
    for (int i = 1; i <= n; i++) {
        giaiThua *= i;
    }

    cout << n << "! = " << giaiThua << "\n";

    return 0;
}
/*
 * PHAN TICH DO PHUC TAP:
 * - Thoi gian (Time Complexity): O(N) -> Vong lap chay tu 1 den N (N phep nhan).
 * - Bo nho (Space Complexity):   O(1) -> Chi dung 1 bien 'result' de luu ket qua.
 */
