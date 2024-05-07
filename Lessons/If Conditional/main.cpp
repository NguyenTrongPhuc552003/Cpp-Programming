#include <iostream>
#include "cmath"

using namespace std;

int main () {
    double a, b, c, delta, x, x1, x2;

    cout << "Phuong trinh bac 2: ax^2 + bx + c = 0\n";
    cout << "Nhap a =";
    cin >> a;
    cout << "Nhap b =";
    cin >> b;
    cout << "Nhap c =";
    cin >> c;

    if (a == 0) { // a = 0 => Phuong trinh bac 1
        if (b == 0) { // b = 0
            if (c == 0) // c = 0
                cout << "Phuong trinh co vo so nghiem";
            else
                cout << "Phuong trinh vo nghiem cmnr";

        } else {
            if (c == 0)
                cout << "Phuong trinh co nghiem duy nhat x = 0";
            else
                cout << "Phuong trinh co nghiem x = " << - c / b;
        }

    } else { // a != 0
        delta = pow(b, 2) - 4 * a * c; // calculating delta

        if (delta > 0) {
            x1 = (-b + sqrt(delta)) / 2 * a;
            x2 = (-b - sqrt(delta)) / 2 * a;
            cout << "Phuong trinh co 2 nghiem phan biet: x1 = " << x1 << " va x2 = " << x2;
        } else if (delta == 0) {
            x = - b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x;
        } else {
            cout << "Phuong trinh vo nghiem cmnr";
        }
    }

    return 0;
}