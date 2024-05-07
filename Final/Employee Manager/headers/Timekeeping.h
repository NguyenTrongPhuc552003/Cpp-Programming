//
// Created by Trong_Phuc on 29/06/2023.
//

#ifndef EMPLOYEE_MANAGER_TIMEKEEPING_H
#define EMPLOYEE_MANAGER_TIMEKEEPING_H

#include "DaysoffMonth.h"

class Timekeeping {
private:
    Daysoff_Month *dsm = new Daysoff_Month(); // so ngay nghi trong thang <= 28
    string result; // TO = tot, TB = Dat, KE = kem
    int overtime; // so ngay lam them <= 28

    static bool valid_daysoff(int data);
    static bool valid_result(const string &data);
    int get_storedDay();
    static string get_reverseString(string data);

public:
    static string standardize_money(double data);
    void set_daysoff();
    void set_result();
    void set_overtime();

    int get_overTime() const;
    string get_result();
    int get_daysoffAvailable();
    int get_daysoffUnavailable();
    double get_totalSalary(int baseSal, int childNum, const string& eduLvl) const;
};

#endif //EMPLOYEE_MANAGER_TIMEKEEPING_H
