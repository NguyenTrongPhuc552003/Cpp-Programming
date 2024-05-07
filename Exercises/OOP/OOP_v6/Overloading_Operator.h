//
// Created by Trong_Phuc on 20/03/2023.
//

#ifndef OOP_V6_OVERLOADING_OPERATOR_H
#define OOP_V6_OVERLOADING_OPERATOR_H

#include <iostream>
#include "string"
#include "iomanip"

using namespace std;

typedef struct {
    string name;
    unsigned int id;
} student;

bool check_name(const string& namein) {
    for (auto& i : namein) {
        if (!isalpha(i) && i != ' ') return false;
    }
    return true;
}

bool check_id(unsigned int idin) { // true_format: 21207197 => 8 numbers
    unsigned int format_counter = 0;

    while (idin != 0) {
        idin /= 10;
        format_counter++;
    }
    if (format_counter != 8) return false;
    return true;
}

istream& operator >> (istream& new_in, student& data) {
    static unsigned int n_in = 0;

    n_in++;
    do {
        cout << "Nhap vao ho va ten sinh vien thu " << n_in << ':';
        getline(new_in, data.name);
        if (!check_name(data.name)) cout << "Ban nhap ky tu khac Alpha. Moi ban nhap lai !\n";
    } while (!check_name(data.name));
    do {
        cout << "Nhap vao MSSV thu " << n_in << " (toi thieu: 8 so):";
        new_in >> data.id;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            new_in.clear();
            new_in.ignore();
        } else {
            if (!check_id(data.id)) cout << "Ban nhap sai dinh dang. Moi ban nhap lai !\n";
        }
    } while (new_in.fail() || !check_id(data.id));
    new_in.ignore(100, '\n');
    return new_in;
}

ostream& operator << (ostream& new_out, student& data) {
    static unsigned int n_out = 0;

    n_out++;
    new_out << "Ho va ten sinh vien thu " << n_out << ": " << data.name << endl;
    new_out << "MSSV thu " << n_out << ": " << setw(23) << setfill(' ') << data.id << endl;
    return new_out;
}

#endif //OOP_V6_OVERLOADING_OPERATOR_H
