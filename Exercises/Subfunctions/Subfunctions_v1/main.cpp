#include <iostream>
#include "cmath"
#include "iomanip"
using namespace std;

int circumference_rectangle (int x, int y) { return 2 * (x + y); } // chu vi hinh chu nhat

int circumference_triangle (int x, int y, int z) { return x + y + z; } // chu vi hinh tam giac

int area_rectangle (int x, int y) { return x * y; } // dien tich hinh chu nhat

double area_triangle (int x, int y, int z) { // dien tich hinh tam giac
    int p = (x + y + z) / 2;
    return sqrt(abs(p * (p - x) * (p - y) * (p - z)));
}

int main() {
    int n, a, b, c;

    cout << "Tinh chu vi va dien tich hinh hoc";
    retype:
    cout << "\nBan muon tinh toan voi hinh nao ? (hinh chu nhat - 0 / hinh tam giac - 1)=>";
    cin >> n;

    switch (n) {
        case 0:
            cout << "Canh thu 1:";
            cin >> a;
            cout << "Canh thu 2:";
            cin >> b;

            cout << "Chu vi hinh chu nhat = " << circumference_rectangle(a, b);
            cout << "\nDien tich hinh chu nhat = " << area_rectangle(a, b);
            break;

        case 1:
            cout << "Canh thu 1:";
            cin >> a;
            cout << "Canh thu 2:";
            cin >> b;
            cout << "Canh thu 3:";
            cin >> c;

            cout << "Chu vi hinh tam giac = " << circumference_triangle(a, b, c);
            cout << "\nDien tich hinh tam giac = " << setprecision(4) << area_triangle(a, b, c);
            break;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
