#include <iostream>
#include "Overloading_Operator.h"

using namespace std;

int main() {
    student sv1, sv2;

    cout << "Quan li thong tin sinh vien !\n";
    cin >> sv1 >> sv2; // input
    cout << setw(10) << setfill(' ') << "Thong tin sinh vien\n";
    cout << sv1 << sv2; // output
    return 0;
}
