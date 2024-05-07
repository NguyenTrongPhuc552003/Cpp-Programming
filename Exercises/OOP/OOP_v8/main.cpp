#include <iostream>
#include "Overloading_Operator_OOP.h"

using namespace std;

int main() {
    divNum ps1(1, 2), ps2(3, 4), result; // khoi tao 2 ps
    unsigned int math_amount = 4;

    for (int i = 0; i < math_amount; i++) {
        switch (i) {
            case 0:
                result = ps1 + ps2;
                cout << "Ket qua phep cong: ";
                break;
            case 1:
                cout << "Ket qua phep tru: ";
                result = ps1 - ps2;
                break;
            case 2:
                result = ps1 * ps2;
                cout << "Ket qua phep nhan: ";
                break;
            default:
                result = ps1 / ps2;
                cout << "Ket qua phep chia: ";
        }
        cout << result << endl;
    }
    ps1++;
    cout << "ps++: " << ps1 << endl;
    ++ps1;
    cout << "++ps: " << ps1 << endl;
    ps2 = ps1++;
    cout << "ps = ps++: " << ps2 << endl;
    return 0;
}
