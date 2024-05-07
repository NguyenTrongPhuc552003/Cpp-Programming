//
// Created by Trong_Phuc on 16/05/2023.
//

#ifndef OOP_V9_MANAGER_H
#define OOP_V9_MANAGER_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string name, please = ". Moi ban nhap lai !\n";

class Manager {
private:
    int id {}, phone {};

//    bool check_address(string &data); // skip
    static bool check_id(int data);
    static bool check_phoneNumber(int data);

protected:
    static bool check_name(string &data);

public:
    static void input_name();
    static void input_address();
    void input_id();
    void input_phoneNumber();
};

bool Manager::check_name(string &data) {
    return all_of(data.cbegin(), data.cend(), [](char i) {
        return i == ' ' || isalpha(i);
    });
}

bool Manager::check_id(int data) {
    unsigned int cnt_id = 0, std_id = 4;

    if (data < 0) {
        return false;
    } else {
        while (data > 0) {
            cnt_id++;
            data /= 10;
        }
        if (cnt_id != std_id) return false;
    }
    return true;
}

bool Manager::check_phoneNumber(int data) {
    unsigned int cnt_phone = 0, std_phone = 9;

    if (data < 0) {
        return false;
    } else {
        while (data > 0) {
            cnt_phone++;
            data /= 10;
        }
        if (cnt_phone != std_phone) return false;
    }
    return true;
}

void Manager::input_name() {
    do {
        cout << "Nhap vao ho va ten cua ban (Alphabet):";
        getline(cin, name);
        if (name.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            if (!check_name(name)) cout << "Ban nhap sai dinh dang" << please;
        }
    } while (!check_name(name));
}

void Manager::input_address() {
    do {
        cout << "Nhap vao dia chi cua ban:";
        getline(cin, name);
        if (name.empty()) cout << "Ban chua nhap du lieu" << please;
    } while (name.empty());
}

void Manager::input_id() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao ID cua ban (4 chu so ngau nhien):";
        cin >> id;
        if(cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << please;
        } else {
            if (!check_id(id)) cout << "Ban nhap chua dung dinh dang" << please;
        }
    } while (cin.fail() || !check_id(id));
}

void Manager::input_phoneNumber() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao so dien thoai cua ban (9 chu so ngau nhien):";
        cin >> phone;
        if(cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << please;
        } else {
            if (!check_phoneNumber(phone)) cout << "Ban nhap chua dung dinh dang" << please;
        }
    } while (cin.fail() || !check_phoneNumber(phone));
}

#endif //OOP_V9_MANAGER_H
