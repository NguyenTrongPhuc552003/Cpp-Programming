//
// Created by Trong_Phuc on 03/05/2023.
//

#ifndef REVIEW_STUDENT_H
#define REVIEW_STUDENT_H

#include <iostream>
#include <string>
#include <malloc.h>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

#define leftw(n, v) left << setw(n) << v
//#define rightw(n, v) right << setw(n) << v

class Student {
private:
    string com_str, please = ". Moi ban nhap lai !\n";
    string filePath = "OOP_Review.csv";
    const unsigned int fileAlign = 21, subjectAmount = 5;
    float avrMark = 0.0;
    char* name = nullptr;
    char* date = nullptr;
    char* sex = nullptr;
    char* fac = nullptr;
    char* gpa = nullptr;

    void dym_elements(char* &transfer, string &data, unsigned int element);
    auto studentAmount() -> int;
    static auto forProcess_marks(string &data, unsigned int n) -> bool;
    static auto check_str(string &data) -> bool;
    static auto check_date(string &data) -> bool;
    static auto check_sex(string &data) -> bool;
    static auto check_mark(string &data) -> bool;

public:
    ~Student() {
        delete(name);
        delete(date);
        delete(sex);
        delete(fac);
        delete(gpa);
    }
    friend auto operator >> (istream& new_in, Student* &data) -> istream&;
    friend auto operator << (ostream& new_out, Student* &data) -> ostream&;
    void name_input();
    void date_input();
    void sex_input();
    void fac_input();
    void marks_input();
    void all_output();
    void clean_file();
};

// DYNAMICALLY ALLOCATING & UPLOAD TO "FILE.TXT"

void Student::dym_elements(char* &transfer, string &data, unsigned int element) {
    static unsigned int orderStudents = 0;
    static unsigned int orderMark = 0;
    static bool flag = true;

    transfer = (char*)malloc(data.length() + 1);
    if (transfer == nullptr) {
        cout << "Loi kich thuoc du lieu dau vao !\n";
    } else {
        if (element == 4) { // calculating average gpa
            orderMark++;
            avrMark += stof(data);
            if (orderMark == 5) {
                avrMark /= (float)orderMark;
                snprintf(transfer, 5, "%s", to_string(avrMark * 4.0 / 10.0).c_str()); // GPA_Mark's size: #.## + '\0'
            }
        } else {
            snprintf(transfer, data.length() + 1, "%s", data.c_str());
        }
        ofstream dataUpload(filePath, ios_base::app); // MODE: Append
        if (dataUpload.fail()) {
            cout << "File bi loi !\n";
        } else {
            switch (element) {
                case 0:
                    if (flag) {
                        orderStudents = studentAmount();
                        flag = false;
                    }
                    orderStudents++;
                    dataUpload << leftw(29, ' ') << ">> SINH VIEN THU " << orderStudents << " <<\n";
                    dataUpload << leftw(fileAlign, "HO VA TEN: ");
                    break;
                case 1:
                    dataUpload << leftw(fileAlign, "NGAY THANG NAM SINH: ");
                    break;
                case 2:
                    dataUpload << leftw(fileAlign, "GIOI TINH: ");
                    break;
                case 3:
                    dataUpload << leftw(fileAlign, "KHOA:");
                    break;
                default:
                    if (orderMark == 5) {
                        dataUpload << leftw(fileAlign, "DIEM GPA: ") << transfer << endl;
                        avrMark = 0.0;
                        orderMark = 0;
                    }
            }
            if (element != 4) {
                dataUpload << transfer << endl;
            }
        }
        dataUpload.close();
    }
    free(transfer);
}

// COUNTING STUDENTS

auto Student::studentAmount() -> int {
    ifstream dataDownload(filePath);
    int count = 0;
    bool flag = true;

    if (dataDownload.fail()) {
        cout << "File bi loi hoac khong ton tai !\n";
        flag = false;
    } else {
        while (getline(dataDownload, com_str)) {
            if (com_str.find(">> SINH VIEN THU") != string::npos) {
                count++;
            }
        }
    }
    dataDownload.close();
    return (flag) ? count : -1;
}

auto Student::forProcess_marks(string &data, unsigned int n) -> bool {
    for (int i = 0; i < data.length(); i++) {
        if (i == n) {
            if (data[i] != '.') {
                return false;
            }
        } else {
            if (data[i] < '0' || data[i] > '9') {
                return false;
            }
        }
    }
    return true;
}

// CHECK INPUT

auto Student::check_str(string &data) -> bool {
    return all_of(data.cbegin(), data.cend(), [](char i) {
        return i == ' ' || (isalpha(i) != 0);
    });
}

auto Student::check_date(string &data) -> bool {
    unsigned int AD = 0;
    unsigned int d = 0;
    unsigned int m = 0;
    unsigned int y = 0; // quy uoc chung moi khi kiem tra datein
    unsigned int posD = 0;
    unsigned int posM = 3;
    unsigned int sizeDM = 2;
    unsigned int sizeY = 4;
    unsigned int sizeFormat = 10;

    if (data.length() == sizeFormat) { // sizeof(date) phai bang 10
        for(int i = 0; i < data.length(); i++) { // kiem tra ngay thang nam
            if (data[i] == '/') {
                if (i == posD + sizeDM) {
                    d = stoi(data.substr(posD, sizeDM));
                    if (d > 31 || d <= 0) {
                        return false;
                    }
                } else if (i == posM + sizeDM) {
                    m = stoi(data.substr(posM, sizeDM));
                    if (m > 12 || m <= 0) {
                        return false;
                    }
                }
            } else {
                if (data[i] < '0' || data[i] > '9') {
                    return false;
                }
                if (i == data.length() - 1) {
                    y = stoi(data.substr(sizeDM + sizeY, sizeY));
                }
            }
        }
        if (y < 1800) { // nam sinh va nam hien tai phai tu 1800 tro len
            return false;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) { // nhung thang co ngay <= 30
            if (d > 30) {
                return false;
            }
        } else if (m == 2) { // thang co ngay bang 28 hoac 29
            while (AD < y) {
                AD += 4;
            }
            if (y == AD) {
                if (d > 29) {
                    return false;
                }
            } else {
                if (d > 28) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

auto Student::check_sex(string &data) -> bool {
    return !(data != "Nam" && data != "Nu");
}

auto Student::check_mark(string &data) -> bool {
    if (data.length() == 4) {
        if (!forProcess_marks(data, 1)) {
            return false; // #.##
        }
    } else if (data.length() == 5) {
        if (!forProcess_marks(data, 2)) {
            return false; // ##.##
        }
    } else {
        return false;
    }
    return true;
}

// STRING INPUT

auto operator >> (istream& new_in, Student* &data) -> istream& {
    data->name_input();
    data->date_input();
    data->sex_input();
    data->fac_input();
    data->marks_input();
    return new_in;
}

void Student::name_input() {
    do {
        cout << "Nhap vao ho va ten cua ban (Alphabet):";
        getline(cin, com_str);
        if (!check_str(com_str)) {
            cout << "Chi cho phep ky tu Alphabet" << please;
        }
    } while (!check_str(com_str));
    dym_elements(name, com_str, 0);
}

void Student::date_input() {
    do {
        cout << "Nhap vao ngay thang nam sinh cua ban (dd/mm/yyyy):";
        getline(cin, com_str);
        if (!check_date(com_str)) {
            cout << "Ban nhap chua dung dinh dang" << please;
        }
    } while (!check_date(com_str));
    dym_elements(date, com_str, 1);
}

void Student::sex_input() {
    do {
        cout << "Nhap vao gioi tinh cua ban (Nam / Nu):";
        getline(cin, com_str);
        if (!check_sex(com_str)) {
            cout << "Khong ton tai gioi tinh nay" << please;
        }
    } while (!check_sex(com_str));
    dym_elements(sex, com_str, 2);
}

void Student::fac_input() {
    do {
        cout << "Nhap vao khoa cua ban (Alphabet):";
        getline(cin, com_str);
        if (!check_str(com_str)) {
            cout << "Chi cho phep ky tu Alphabet" << please;
        }
    } while (!check_str(com_str));
    dym_elements(fac, com_str, 3);
}

void Student::marks_input() {
    for (int i = 0; i < subjectAmount; i++) {
        do {
            cout << "Nhap vao diem mon thu " << i + 1 << " (#.## hoac 10.##):";
            getline(cin, com_str);
            if (!check_mark(com_str)) {
                cout << "Ban nhap chua dung dinh dang" << please;
            }
        } while (!check_mark(com_str));
        dym_elements(gpa, com_str, 4);
    }
}

// FILE OUTPUT

auto operator << (ostream& new_out, Student* &data) -> ostream& {
    data->all_output();
    system("pause");
    system("cls");
    return new_out;
}

void Student::all_output() {
    ifstream dataDownload(filePath);
    if (dataDownload.fail()) {
        cout << "File bi loi hoac khong ton tai !\n";
    } else {
        dataDownload >> com_str;
        if (com_str.empty()) {
            cout << "Hien tai chua co du lieu trong file !" << please;
        } else {
            cout << leftw(29, ' ') << com_str;
            while (getline(dataDownload, com_str)) {
                cout << com_str << endl;
            }
        }
    }
    dataDownload.close();
}

void Student::clean_file() {
    ofstream cleanFile(filePath); // without Append mode
    if (cleanFile.fail()) {
        cout << "File bi loi !\n";
    } else {
        cout << "Da xoa du lieu file thanh cong !\n";
        cleanFile << "";
    }
    cleanFile.close();
}

#endif //REVIEW_STUDENT_H
