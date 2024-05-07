//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef EMPLOYEE_MANAGER_DAYSOFFMONTH_H
#define EMPLOYEE_MANAGER_DAYSOFFMONTH_H

#include <iostream>
#include <string>

using namespace std;

const string retype_please = ". Moi ban nhap lai !\n";

class Daysoff_Month { // so ngay ghi <= 28
private:
    int stored_day = 28;
    int available{}; // co phep
    int unavailable{}; // khong phep

public:
    void set_available(int data);
    void set_unavailable(int data);

    int get_available() const;
    int get_unavailable() const;
    int get_storedDay() const;
};

#endif //EMPLOYEE_MANAGER_DAYSOFFMONTH_H
