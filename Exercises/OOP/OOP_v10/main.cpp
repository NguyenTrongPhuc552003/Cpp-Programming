#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    auto my_information = new StudentManager;
    string menu_selections[] = {"Dang ki tai khoan",
                                "Dang nhap tai khoan (khac)",
                                "Xuat thong tin tai khoan",
                                "Quen mat khau",
                                "Thoat chuong trinh"};
    unsigned int amount_selections = sizeof(menu_selections) / sizeof(menu_selections[0]);

    welcome:
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << "CHAO MUNG " << ((my_information->hi_usr().length() >= 1 && my_information->option_menu > 0 && my_information->option_menu < 3) ? my_information->hi_usr() : "DEN VOI BINH NGUYEN VO TAN") << endl;
        for (int i = 0; i < amount_selections; i++) cout << i << " - " << menu_selections[i] << endl; // in ra cac lua chon thuoc menu
        cout << "Lua chon cua ban:";
        cin >> my_information->option_menu;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
        } else {
            if (my_information->option_menu < 0 || my_information->option_menu >= amount_selections) cout << "Lua chon khong phu hop. Moi ban nhap lai !\n";
        }
    } while (cin.fail() || my_information->option_menu < 0 || my_information->option_menu > amount_selections - 1);

    if (my_information->option_menu < amount_selections - 1) {
        system("cls");
        cin.ignore();
    }
    switch (my_information->option_menu) {
        case 0:
        case 1:
            cin >> my_information;
            break;
        case 2:
            cout << my_information;
            break;
        case 3:
            my_information->forget_password();
            break;
        default:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
    }
    if (my_information->option_menu < amount_selections - 1) {
        system("pause");
        goto welcome;
    }
    return 0;
}
