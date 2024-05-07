#include <iostream>
using namespace std;

int main() {
    int num, rep;

    cout << "Chuong trinh nhap vao so lon hon 55\n";
    cout << "Ban muon dung While_Loop (0) hay Do_While (1) ? => Phan hoi (0/1): ";
    cin >> rep;

    if (rep == 0) { // Vong lap while
        do {
            cout << "Hay nhap vao so lon hon 55: ";
            cin >> num;
        } while (num <= 55);
    } else { // Vong lap do while
        cout << "Nhap vao so lon hon 55: ";
        cin >> num;

        while (num <= 55) {
            cout << "Nhap lai so lon hon 55: ";
            cin >> num;
        }
    }
    cout << "Ban vua nhap so lon hon 55";

    return 0;
}
