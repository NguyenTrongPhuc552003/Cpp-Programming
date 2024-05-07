//
// Created by Trong_Phuc on 21/04/2024.
//
#include "../headers/Employee.h"

/*CHECKING METHODS*/

bool Resume::valid_id(const string &data) { // kiem tra id
    if (data.length() != 8) {
        return false;
    } else {
        for (char i: data) {
            if (!isdigit(i)) return false;
        }
    }
    return true;
}

bool Resume::valid_name(const string &data) { // kiem tra ten
    if (data.length() >= 20) {
        return false;
    } else {
        for (int i = 0; i < data.length(); i++) {
            if (!isblank(data[i])) {
                if (!isalpha(data[i])) return false;
            } else { // vi tri dau tien, cuoi cung hoac 2 dau cach lien tiep
                if (i == 0 || i == data.length() - 1 || isblank(data[i + 1])) return false;
            }
        }
    }
    return true;
}

bool Resume::valid_status(char data) { // kiem tra tinh trang hon nhan
    if (data != 'M' && data != 'S') return false;
    return true;
}

bool Resume::valid_children(int data) { // kiem tra so con
    if (data < 0 || data > 20) return false;
    return true;
}

bool Resume::valid_eduLevel(const string &data) { // kiem tra trinh do van hoa
    if (data != "C1"
        && data != "C2"
        && data != "C3"
        && data != "DH"
        && data != "CH")
        return false;
    return true;
}

bool Resume::valid_baseSalary(int data) { // kiem tra luong can ban
    if (data > 1000000) return false;
    return true;
}

/*PUT VALUE METHODS*/

void Resume::put_id(string &data, bool findMode) { // tim kiem hoac gan du lieu
    if (findMode) foundId = data;
    else id = data;
}

void Resume::put_name(string &data) { name = data; }

void Resume::put_status(char &data) { status = data; }

void Resume::put_children(int &data) { children = data; }

void Resume::put_eduLevel(string &data) { edu_level = data; }

void Resume::put_baseSalary(int &data) { base_salary = data; }

/*CONSTRUCTOR*/
Resume::Resume() {
    tkp = nullptr;
    id = name = edu_level = comStr = foundId = contentFile = "";
    status = comChar = '\0';
    children = base_salary = comInt = 0;
}

/*DESTRUCTOR*/
Resume::~Resume() {
    delete tkp;
}

/*SET VALUE METHODS*/

void Resume::set_id(bool searchMode) {
    bool com_ProcessingId;

    do {
        com_ProcessingId = false;
        cout << "Nhap vao ma so nhan vien " << (searchMode ? "tim kiem" : "moi") << " (8 chu so ngau nhien):";
        getline(cin, comStr);
        if (comStr.empty()) {
            cout << "Ban chua nhap du lieu" << retype_please;
        } else {
            if (!valid_id(comStr)) {
                cout << "Ban nhap chua dung ma so" << retype_please;
            } else {
                if (get_contentFile().find(comStr) != string::npos) {
                    if (!searchMode) {
                        cout << "Ma so nhan vien nay bi trung lap" << retype_please;
                        com_ProcessingId = true;
                    }
                } else {
                    if (searchMode) {
                        cout << "Khong tim thay ma so nhan vien nay" << retype_please;
                        com_ProcessingId = true;
                    }
                }
            }
        }
    } while (!valid_id(comStr) || com_ProcessingId);
    put_id(comStr, searchMode);
}

void Resume::set_name() {
    do {
        cout << "Nhap vao ho va ten nhan vien (khong qua 20 ky tu Alphabet):";
        getline(cin, comStr);
        if (comStr.empty()) {
            cout << "Ban chua nhap du lieu" << retype_please;
        } else {
            if (!valid_name(comStr)) cout << "Ban nhap chua dung ho va ten" << retype_please;
        }
    } while (comStr.empty() || !valid_name(comStr));
    put_name(comStr);
}

void Resume::set_status() {
    do {
        cout << "Nhap vao tinh trang hon nhan (M - Married / S - Single):";
        cin >> comChar;
        if (!valid_status(comChar)) cout << "Ban nhap chua dung tinh trang hon nhan" << retype_please;
    } while (!valid_status(comChar));
    put_status(comChar);
}

void Resume::set_children() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao so con (khong qua 20):";
        cin >> comInt;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << retype_please;
        } else {
            if (!valid_children(comInt)) cout << "Ban nhap chua dung so con" << retype_please;
        }
    } while (cin.fail() || !valid_children(comInt));
    cin.ignore(100, '\n');
    put_children(comInt);
}

void Resume::set_eduLevel() {
    do {
        cout << "Nhap vao trinh do van hoa (C1 / C2 / C3 / DH / CH):";
        getline(cin, comStr);
        if (comStr.empty()) {
            cout << "Ban chua nhap du lieu" << retype_please;
        } else {
            if (!valid_eduLevel(comStr)) cout << "Ban nhap chua dung trinh do van hoa" << retype_please;
        }
    } while (comStr.empty() || !valid_eduLevel(comStr));
    put_eduLevel(comStr);
}

void Resume::set_baseSalary() {
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Nhap vao luong can ban (<= 1.000.000):";
        cin >> comInt;
        if (cin.fail()) {
            cout << "Ban chua nhap du lieu" <<retype_please;
        } else {
            if (!valid_baseSalary(comInt)) cout << "Ban nhap chua dung luong can ban" << retype_please;
        }
    } while (cin.fail() || !valid_baseSalary(comInt));
    cin.ignore(100, '\n');
    put_baseSalary(comInt);
}

void Resume::set_timeKeeping() {
    tkp = new Timekeeping();
    tkp->set_daysoff();
    tkp->set_result();
    tkp->set_overtime();
}

void Resume::set_contentFile(const string &data) { contentFile = data; }

/*GET VALUE METHODS*/

string Resume::get_id(bool searchMode) {
    if (searchMode) return foundId;
    return id;
}

string Resume::get_name() { return name; }

char Resume::get_status() const { return status; }

int Resume::get_children() const { return children; }

string Resume::get_eduLevel() { return edu_level; }

int Resume::get_baseSalary() const { return base_salary; }

Timekeeping* Resume::get_timeKeeping() { return tkp; }

double Resume::get_totalSalary() { return tkp->get_totalSalary(get_baseSalary(), get_children(), get_eduLevel()); }

string Resume::get_contentFile() { return contentFile; }

/*STANDARDIZE ATTRIBUTIONS*/

string Resume::get_standardizeMoney(double data) { return Timekeeping::standardize_money(data); }

string Resume::get_standardizeStatus(char data) {
    if (data == 'S') return "Single";
    return "Married";
}

string Resume::get_standardizeEduLevel(const string& data) {
    if (data == "C1") return "Tieu hoc";
    if (data == "C2") return "Trung hoc Co so";
    if (data == "C3") return "Trung hoc Pho thong";
    if (data == "DH") return "Dai hoc";
    return "Cao hoc";
}

string Resume::get_standardizeResult(const string &data) {
    if (data == "TO") return "Tot";
    else if (data == "TB") return "Dat";
    return "Kem";
}

string Resume::get_shortenName(string data) { // Nguyen Trong Phuc => N.T.Phuc
    string shortenName;
    unsigned int m = 0, blankCounter = 0;
    bool blankMode = true;

    while (true) {
        for (int i = 0; i < data.length(); i++) {
            if (blankMode) { // dem so luong dau cach
                if (isblank(data[i])) blankCounter++;
            } else {
                if (isblank(data[i])) {
                    m++;
                    if (m == blankCounter) {
                        shortenName.append(data.substr(i + 1)); // Phuc
                        break;
                    }
                } else {
                    if (i == 0 || isblank(data[i - 1])) {
                        shortenName.append(1, (char)toupper(data[i])); // N.H.
                        shortenName.append(".");
                    }
                }
            }
        }
        if (blankMode) {
            if (blankCounter == 0) return data; // abc, def
            blankMode = false;
        } else {
            break;
        }
    }
    return shortenName;
}