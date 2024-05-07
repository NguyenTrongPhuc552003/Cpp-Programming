//
// Created by Trong_Phuc on 26/02/2023.
//

#ifndef OOP_V4_COUNTDATE_H
#define OOP_V4_COUNTDATE_H

#include <iostream>
#include "string"

using namespace std;

class Calendar {
private:
    unsigned int AD = 0, countDays = 0, d = 0, m = 0, y = 0; // quy uoc chung moi khi kiem tra datein
    unsigned int db = 0, mb = 0, yb = 0; // luu tru ngay sinh nhat, date_birthday
    unsigned int dp = 0, mp = 0, yp = 0; // ____________ hien tai, date_present
    unsigned int posD = 0, posM = 3, sizeDM = 2, sizeY = 4, sizeFormat = 10;
public:
    bool checkDatein(const string& data, const string& element);
    unsigned int count_yourBirthdayToNow();
    void resetDate();
};

bool Calendar::checkDatein(const string &data, const string& element) {
    if (data.length() == sizeFormat) { // sizeof(date) phai bang 10
        for(int i = 0; i < data.length(); i++) { // kiem tra ngay thang nam
            if (data[i] == '/') {
                if (i == posD + sizeDM) {
                    d = stoi(data.substr(posD, sizeDM));
                    if (d > 31 || d <= 0) return false;
                } else if (i == posM + sizeDM) {
                    m = stoi(data.substr(posM, sizeDM));
                    if (m > 12 || m <= 0) return false;
                }
            } else {
                if (data[i] < '0' || data[i] > '9') return false;
                if (i == data.length() - 1) y = stoi(data.substr(sizeDM + sizeY, sizeY));
            }
        }
        if (y < 1800) { // nam sinh va nam hien tai phai tu 1800 tro len
            return false;
        } else {
            if (m == 4 || m == 6 || m == 9 || m == 11) { // nhung thang co ngay <= 30
                if (d > 30) return false;
            } else if (m == 2) { // thang co ngay bang 28 hoac 29
                while (AD < y) AD += 4;
                if (y == AD) {
                    if (d > 29) return false;
                } else {
                    if (d > 28) return false;
                }
            }
        }
        if (element == "BIRTHDAY") {
            db = d;
            mb = m;
            yb = y;
        } else {
            if (y < yb) {
                return false;
            } else if (y == yb) {
                if (m < mb) {
                    return false;
                } else if (m == mb) {
                    if (d <= db) return false;
                }
            }
            dp = d;
            mp = m;
            yp = y;
        }
    } else {
        return false;
    }
    return true;
}

unsigned int Calendar::count_yourBirthdayToNow() { // du lieu luu tru o dang chuan
    while (db != dp || mb != mp || yb != yp) {
        AD = 0;
        if (mb == 4 || mb == 6 || mb == 9 || mb == 11) {
            if (db > 30) {
                db = 1;
                mb++;
            } else {
                db++;
                countDays++;
            }
        } else if (mb == 2) {
            while (AD < yb) AD += 4;
            if (yb == AD) {
                if (db > 29) {
                    db = 1;
                    mb++;
                } else {
                    db++;
                    countDays++;
                }
            } else {
                if (db > 28) {
                    db = 1;
                    mb++;
                } else {
                    db++;
                    countDays++;
                }
            }
        } else {
            if (db > 31) {
                db = 1;
                if (mb != 12) {
                    mb++;
                } else {
                    mb = 1;
                    yb++;
                }
            } else {
                db++;
                countDays++;
            }
        }
    }
    return countDays;
}

void Calendar::resetDate() {
    AD = 0;
    countDays = 0;
}

#endif //OOP_V4_COUNTDATE_H
