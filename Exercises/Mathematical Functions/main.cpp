#include <iostream>
#include "cmath"
#include "iomanip"
using namespace std;

int main() {
    double a, b, c, abs_a, abs_b, abs_c, doi, ke, huyen, sin_doih, cos_keh, tan_doik, cot_ked, dientich, chuvi;

    do {
        cout << "Chuong trinh kiem tra tam giac vuong (a^2 + b^2 = c^2)\n"; // TH: tam giac vuong can => canh huyen * sqrt(2)
        cout << "Canh ngan nhat se la canh doi\n";
        cout << "Nhap vao canh a =";
        cin >> a;
        cout << "Nhap vao canh b =";
        cin >> b;
        cout << "Nhap vao canh c =";
        cin >> c;

        if (pow(a, 2) + pow(b, 2) != pow(c, 2)) cout << "Chua phai tam giac vuong, moi ban nhap lai\n";

    } while (pow(a, 2) + pow(b, 2) != pow(c, 2)); // Kiem tra dieu kien a^2 + b^2 = c^2

    abs_a = abs(a);
    abs_b = abs(b);
    abs_c = abs(c);

    if (abs_a > abs_b && abs_a > abs_c) { // Kiem tra canh huyen => Dien tich
        huyen = abs_a;
        if (abs_b > abs_c) {
            doi = abs_c;
            ke = abs_b;
        } else {
            doi = abs_b;
            ke = abs_c;
        }
        dientich = (abs_b * abs_c) / 2;
    }
    if (abs_b > abs_a && abs_b > abs_c) {
        huyen = abs_b;
        if (abs_a > abs_c) {
            doi = abs_c;
            ke = abs_a;
        } else {
            doi = abs_a;
            ke = abs_c;
        }
        dientich = (abs_a * abs_c) / 2;
    }
    if (abs_c > abs_a && abs_c > abs_b) {
        huyen = abs_c;
        if (abs_a > abs_b) {
            doi = abs_b;
            ke = abs_a;
        } else {
            doi = abs_a;
            ke = abs_b;
        }
        dientich = (abs_a * abs_b) / 2;
    }

    sin_doih = doi / huyen;
    cos_keh = ke / huyen;
    tan_doik = doi / ke;
    cot_ked = ke / doi;

    chuvi = abs_a + abs_b + abs_c;

    cout << "Dien tich tam giac vuong = " << dientich << endl;
    cout << "Chu vi tam giac vuong = " << chuvi << endl;
    cout << "SIN: doi / huyen = " << setprecision(3) << fixed << sin_doih << endl; // Lay 3 so thap phan sau dau phay
    cout << "COS: ke / huyen = " << setprecision(3) << fixed << cos_keh << endl;
    cout << "TAN: doi / ke = " << setprecision(3) << fixed << tan_doik << endl;
    cout << "COT: ke / doi = " << setprecision(3) << fixed << cot_ked << endl;

    return 0;
}
