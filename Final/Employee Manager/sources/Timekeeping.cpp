//
// Created by Trong_Phuc on 21/04/2024.
//
#include "../headers/Timekeeping.h"

/*CHECKING METHODS*/

bool Timekeeping::valid_daysoff(int data) { // kiem tra so ngay nghi, ngay lam them
    if (data < 0 || data > 28) return false;
    return true;
}

bool Timekeeping::valid_result(const string& data) { // kiem tra ket qua cong viec
    if (data != "TO" && data != "TB" && data != "KE") return false;
    return true;
}

int Timekeeping::get_storedDay() { return dsm->get_storedDay(); }

string Timekeeping::get_reverseString(string data) {
    unsigned int len = data.length(), n = len - 1;
    int i = 0;

    while (i <= n) {
        //Using the swap method to switch values at each index
        swap(data[i], data[n]);
        n = n - 1;
        i = i + 1;
    }
    return data;
}

/*SET VALUE METHODS*/

string Timekeeping::standardize_money(double data) { // theo don vi VND
    if (data < 1000.0) return to_string(data);
    string result, processing_money = get_reverseString(to_string((long)data));
    for (int i = 0; i < processing_money.length(); i++) {
        result.push_back(processing_money[i]);
        if ((i + 1) % 3 == 0 && i != processing_money.length() - 1) result.push_back('.');
    }
    result = get_reverseString(result);
    return result;
}

void Timekeeping::set_daysoff() {
    int daysoff;
    bool next_daysoff = true;

    while (true) {
        do {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            cout << "Nhap vao so ngay nghi " << (next_daysoff ? "co phep" : "khong phep") << " (<= " << get_storedDay() << " ngay):";
            cin >> daysoff;
            if (cin.fail()) {
                cout << "Ban nhap sai kieu du lieu" + retype_please;
            } else {
                if (!valid_daysoff(daysoff) || daysoff > get_storedDay()) cout << "Ban nhap chua dung so ngay" << retype_please;
            }
        } while (cin.fail() || !valid_daysoff(daysoff) || daysoff > get_storedDay());
        if (next_daysoff) {
            dsm->set_available(daysoff);
            next_daysoff = false;
        } else {
            dsm->set_unavailable(daysoff);
            if (dsm->get_available() + dsm->get_unavailable() >= 28) { // so ngay nghi phep + khong phep >= 28
                next_daysoff = true;
                cout << "Ban nghi qua nhieu" << retype_please;
            } else {
                break;
            }
        }
    }
}

void Timekeeping::set_result() {
    do {
        cout << "Nhap vao ket qua lam viec (TO - Tot / TB - Dat / KE - Kem):";
        cin >> result;
        if (!valid_result(result)) cout << "Ban nhap chua dung ket qua" << retype_please;
    } while (!valid_result(result));
}

void Timekeeping::set_overtime() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao so ngay lam them (<= " << get_storedDay() << "):";
        cin >> overtime;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << retype_please;
        } else {
            if (overtime > get_storedDay()) cout << "Ban nhap chua dung so ngay" << retype_please;
        }
    } while (cin.fail() || overtime > get_storedDay());
}

/*GET VALUE METHODS*/

int Timekeeping::get_overTime() const { return overtime; }

string Timekeeping::get_result() { return result; }

int Timekeeping::get_daysoffAvailable() { return dsm->get_available(); }

int Timekeeping::get_daysoffUnavailable() { return dsm->get_unavailable(); }

double Timekeeping::get_totalSalary(int baseSal, int childNum, const string& eduLvl) const { // luong thuc linh = luong can ban + phu troi (<= 2.000.000)
    double surcharge = 0.0; // phu troi

    if (childNum > 2) surcharge += 5.0 / 100.0 * baseSal;
    if (eduLvl == "CH") surcharge += 10.0 / 100.0 * baseSal;
    if (get_overTime() > 0) surcharge += 4.0 / 100.0 * (baseSal / 28.0) * get_overTime();
    return (baseSal + surcharge);
}