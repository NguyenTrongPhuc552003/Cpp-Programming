#include <iostream>
#include "myMath.h"

using namespace std;

int main() {
    auto* findNum = new Calculation;
    string x = "Phuc", y = "Bi";
//    int x = 3, y = 4;
    int a, b, c, d;

    retype:
    cout << "Nhap vao lan luot 4 so bat ki (cach nhau boi dau cach ' '):";
    cin >> a >> b >> c >> d;
    if (b == 0 || d == 0) {
        cout << "Mau so phai khac 0. Moi ban nhap lai !\n";
        goto retype;
    }
    findNum->setValues(a, b, c, d);
    cout << "Ket qua cua (a / b) + (c / d) = " << findNum->getResult();

    cout << "Doi 2 du lieu bat ki cho nhau (Vd:int - int, string - string, ...): ";
    swapData(x, y);
    cout << "x = " << x << "; y = " << y;
    return 0;
}
