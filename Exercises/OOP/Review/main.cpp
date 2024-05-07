#include <iostream>
#include "Student.h"

using namespace std;

auto main() -> int {
    auto *mine = new Student;
    int option = 0;
    int flag_error;
    
    do {
        do {
            flag_error = 0;
            cout << "QUAN LI THONG TIN SINH VIEN\n";
            cout << "(0) - Nhap thong tin sinh vien\n";
            cout << "(1) - Xuat thong tin sinh vien\n";
            cout << "(2) - Xoa du lieu trong file\n";
            cout << "(3) - Thoat chuong trinh\n";
            cout << "Lua chon cua ban:";
            cin >> option;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                flag_error = 1;
            } else {
                if (option < 0 || option > 3) {
                    cout << "Khong ton tai lua chon nay. Moi ban nhap lai !\n";
                }
            }
        } while (flag_error == 1 || (option < 0 || option > 3));

        cin.ignore();
        switch (option) {
            case 0:
                system("cls");
                cin >> mine; // input operator overloading
                break;
            case 1:
                system("cls");
                cout << mine; // output operator overloading
                break;
            case 2:
                system("cls");
                mine->clean_file();
                break;
            default:
                delete mine;
                cout << "Cam on ban da su dung chuong trinh !\n";
                system("pause");
        }
    } while (option != 3);
    return 0;
}
