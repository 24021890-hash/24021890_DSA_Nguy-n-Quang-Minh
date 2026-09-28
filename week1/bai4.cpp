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
