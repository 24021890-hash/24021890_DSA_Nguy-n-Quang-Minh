#include <iostream>
#include <numeric> 
#include <cmath>  

using namespace std;


void rutGonPhanSo(int &a, int &b) {
    if (b == 0) return; // Tránh chia cho 0

  
    int ucln = std::gcd(abs(a), abs(b));

   
    a /= ucln;
    b /= ucln;

    
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    int a, b;
    cout << "Nhap tu so a va mau so b: ";
    cin >> a >> b;

    if (b == 0) {
        cout << "Mau so phai khac 0!\n";
        return 0;
    }

    rutGonPhanSo(a, b);

    
    if (b == 1) {
        cout << "Phan so sau khi rut gon: " << a << "\n";
    } else {
        cout << "Phan so sau khi rut gon: " << a << "/" << b << "\n";
    }

    return 0;
}
/*
 * PHAN TICH DO PHUC TAP:
 * - Thoi gian (Time Complexity): O(log(min(|a|, |b|))) -> Do thuat toan Euclide tim UCLN.
 * - Bo nho (Space Complexity):   O(1)                 -> Chi dung bien nguyen, khong ton them bo nho.
 */
