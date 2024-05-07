//
// Created by Trong_Phuc on 09/01/2024.
//

#ifndef OOP_V9_LIBRARY_H
#define OOP_V9_LIBRARY_H

#include "Manager.h"

class Library : protected Manager {
private:
    Manager* ext_mng = new Manager;
    string please = ". Moi ban nhap lai !\n";
    string name, adr;
    int amount;

//    bool check_address(string &data); // skip
    static bool check_amount(int &data);

    void input_amount();
    void input_extMng();

public:
    void input_com();
//    void output_com();
};

bool Library::check_amount(int &data) {
    if (data < 0 || data > 1000) return false;
    return true;
}

void Library::input_amount() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao so luong sach (0 < input < 1000):";
        cin >> amount;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << please;
        } else {
            if (!check_amount(amount)) cout << "Ban nhap sai so luong" << please;
        }
    } while (cin.fail() || !check_amount(amount));
}

void Library::input_extMng() {
    Manager::input_name();
    ext_mng->input_id();
    Manager::input_address();
    ext_mng->input_phoneNumber();
}

void Library::input_com() {
    input_name();
    input_id();
    input_address();
    input_amount();
    input_extMng();
}

#endif //OOP_V9_LIBRARY_H
