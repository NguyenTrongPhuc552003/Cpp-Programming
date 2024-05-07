#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    int number = 100;
    float basic, ta,da,gs;

    basic = 10000;
    ta = 800;
    da = 5000;
    gs = basic + ta + da;

    cout << setw(20) << setfill('*') << "This line is filled with '*'\n" << setw(20) << setfill('*') << "Test" << endl;
    cout << setw(10) << "Basic" << setw(10) << basic << endl
         << setw(10) << "TA" << setw(10) << ta << endl
         << setw(10) << "DA" << setw(10) << da << endl
         << setw(10) << "GS" << setw(10) << gs << endl;
    cout << "Hex Value = " << hex << number << endl;
    cout << "Octal Value = " << oct << number << endl;
    cout << "Setbase Value = " << setbase(8) << number << endl;
    cout << "Setbase Value = " << setbase(16) << number << endl;
    return 0;
}
