#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sắp xếp dãy tăng dần
void sapXepTangDan(vector<int>& a) {
    sort(a.begin(), a.end());
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

    sapXepTangDan(a);

    cout << "Day sau khi sap xep: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
/*
 * PHAN TICH DO PHUC TAP:
 * - Thoi gian (Time Complexity): O(N log N) -> Do thuat toan std::sort.
 * - Bo nho (Space Complexity):   O(N)       -> Luu màng gom N phan tu.
 */
