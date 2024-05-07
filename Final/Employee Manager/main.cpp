#include "headers/Employee.h"

int main() {
    auto* ele = new Employee();
    bool loop_menu = true;

    while (loop_menu) {
        ele->menu();
        switch (ele->get_selectionMenu()) {
            case 0: // them nhan vien
                ele->add();
                break;
            case 1: // xoa nhan vien (dua tren id)
                ele->del();
                break;
            case 2: // tim kiem thong tin nhan vien (dua tren id)
                ele->find();
                break;
            case 3: // (sap xep) bang luong nhan vien hang thang
                ele->all();
                break;
            default:
                loop_menu = false;
                cout << "Cam on ban da su dung chuong trinh !\n";
        }
        system("pause");
        system("cls");
    }
    return 0;
}
