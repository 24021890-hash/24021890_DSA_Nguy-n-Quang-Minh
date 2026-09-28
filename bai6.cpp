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
