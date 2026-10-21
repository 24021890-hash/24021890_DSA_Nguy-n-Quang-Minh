#include <iostream>
#include <vector>

using namespace std;

void xoaPhanTu(vector<int>& a, int k) {
    if (k >= 0 && k < a.size()) {
        a.erase(a.begin() + k);
    }
}

void chenPhanTu(vector<int>& a, int y, int m) {
    if (m >= 0 && m <= a.size()) {
        a.insert(a.begin() + m, y);
    }
}

void inDay(const vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Nhap N: ";
    cin >> n;

    vector<int> a(n);
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cout << "Nhap vi tri k can xoa (chi số tu 0): ";
    cin >> k;
    xoaPhanTu(a, k);
    cout << "Day sau khi xoa vi tri " << k << ": ";
    inDay(a);

    int y, m;
    cout << "Nhap gia tri y va vi tri m can chen: ";
    cin >> y >> m;
    chenPhanTu(a, y, m);
    cout << "Day sau khi chen " << y << " vao vi tri " << m << ": ";
    inDay(a);

    return 0;
}
/*
================================================================================
                    PHAN TICH DO PHUC TAP (COMPLEXITY)
================================================================================

1. HAM tinhTong():
   - Thoi gian (Time): O(N * M)
     Duyet qua tat ca N dong va M cot (tong cong N * M phan tu).
   - Bo nho (Space): O(1)
     Chi dung 1 bien 'tong' de tinh, khong ton thêm bo nho.

2. HAM xoaDong():
   - Thoi gian (Time): O(N)
     Doi cac con tro dong phia sau i sang trai 1 vi tri. Thao tac nay khong
     phu thuoc vao so cot M.
     + Tot nhat: O(1) khi xoa dong cuoi cung.
     + Xau nhat: O(N) khi xoa dong dau tien.
   - Bo nho (Space): O(1)
     Doi con tro dong truc tiep tren manga hien tai.

3. HAM inMang():
   - Thoi gian (Time): O(N * M)
   - Bo nho (Space): O(1)

4. TOAN BO CHUONG TRINH (MAIN):
   - Nhap mang: O(N * M) time, O(N * M) space
   - Tinh tong: O(N * M) time, O(1) space
   - Xoa dong:  O(N) time,     O(1) space
   - In mang:   O(N * M) time, O(1) space
   --------------------------------------------------
   => Tong do phuc tap thoi gian (Time Complexity):  O(N * M)
   => Tong do phuc tap bo nho   (Space Complexity): O(N * M)
================================================================================
*/
