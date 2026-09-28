#include <iostream>
#include <vector>

using namespace std;

long long tinhTong(const vector<vector<int>>& a) {
    long long tong = 0;
    for (const auto& dong : a) {
        for (int x : dong) {
            tong += x;
        }
    }
    return tong;
}

void xoaDong(vector<vector<int>>& a, int i) {
    if (i >= 0 && i < a.size()) {
        a.erase(a.begin() + i);
    }
}

void inMang(const vector<vector<int>>& a) {
    for (const auto& dong : a) {
        for (int x : dong) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Nhap N va M: ";
    cin >> n >> m;

    if (n <= 0 || m <= 0) return 0;

    vector<vector<int>> a(n, vector<int>(m));
    cout << "Nhap mang " << n << "x" << m << ":\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> a[r][c];
        }
    }

    cout << "Tong cac phan tu: " << tinhTong(a) << "\n";

    int i;
    cout << "Nhap dong i can xoa (chi so tu 0): ";
    cin >> i;

    xoaDong(a, i);

    cout << "Mang sau khi xoa dong " << i << ":\n";
    inMang(a);

    return 0;
}
