//
// Created by Trong_Phuc on 07/03/2023.
//

#ifndef OOP_V5_GPA_H
#define OOP_V5_GPA_H

#include <iostream>
#include "vector"

using namespace std;

// public => public -> public, protected -> protected
// protected => public -> protected, protected -> protected
// private => public -> private, protected -> private

class Subjects {
private:
//    unsigned int l;
public:
    static void subjects_amount(unsigned int& data);
};

class GPA : public Subjects {
private:
    vector <unsigned int> credits, marks;
    unsigned int i, credits_sum = 0;
    float mark_brand = 0, datain, temp;
public:
    void credits_input(unsigned int& amount);
    void marks_input(unsigned int& amount);
    void subjects_result(unsigned int& amount);
};

void Subjects::subjects_amount(unsigned int& data) {
    do {
        cout << "Nhap vao so mon hoc cua ban [1; 100]:";
        cin >> data;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu !\n";
            cin.clear();
            cin.ignore();
        } else {
            if (data < 1 || data > 100) cout << "Ban nhap sai so mon hoc !\n";
        }
    } while (data < 1 || data > 100);
}

void GPA::credits_input(unsigned int& amount) {
    for (i = 0; i < amount; i++) {
        do {
            cout << "So tin chi mon thu " << i + 1 << " [1; 3]:";
            cin >> datain;
            if (cin.fail()) {
                cout << "Ban nhap sai kieu du lieu !\n";
                cin.clear();
                cin.ignore();
            } else {
                if (datain < 1 || datain > 3) {
                    cout << "Ban nhap sai so tin chi !\n";
                } else {
                    credits.emplace_back(datain);
                    credits_sum += int(datain);
                }
            }
        } while (datain < 1 || datain > 3);
    }
}

void GPA::marks_input(unsigned int& amount) {
    for (i = 0; i < amount; i++) {
        do {
            cout << "Nhap vao diem mon thu " << i + 1 << " [0; 10]:";
            cin >> datain;
            if (cin.fail()) {
                cout << "Ban nhap sai kieu du lieu !\n";
                cin.clear();
                cin.ignore();
            } else {
                if (datain < 0 || datain > 10) cout << "Ban nhap sai so diem !\n";
                else marks.emplace_back(datain);
            }
        } while (datain < 0 || datain > 10);
    }
}

void GPA::subjects_result(unsigned int& amount) {
    for (i = 0; i < amount; i++) mark_brand += float(credits[i] * marks[i]);
    temp = mark_brand / float(credits_sum);
    cout << "Ket qua hoc tap GPA cua ban:\n";
    cout << " - Thang diem 10.0: " << temp << endl;
    cout << " - Thang diem 4.0: " << temp * 4.0 / 10.0 << endl;
    cout << " - Thang diem chu: ";
    if (temp < 4.0) cout << "F";
    else if (temp <= 4.9) cout << "D";
    else if (temp <= 5.4) cout << "D+";
    else if (temp <= 6.4) cout << "C";
    else if (temp <= 6.9) cout << "C+";
    else if (temp <= 7.9) cout << "B";
    else if (temp <= 8.4) cout << "B+";
    else if (temp <= 9.4) cout << "A";
    else cout << "A+";
    cout << endl;
}

#endif //OOP_V5_GPA_H
