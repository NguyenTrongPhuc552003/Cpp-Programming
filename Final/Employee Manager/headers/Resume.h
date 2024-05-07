//
// Created by Trong_Phuc on 29/06/2023.
//

#ifndef EMPLOYEE_MANAGER_RESUME_H
#define EMPLOYEE_MANAGER_RESUME_H

#include "Timekeeping.h"

class Resume {
private:
    Timekeeping *tkp;
    string id, name, edu_level, comStr, foundId, contentFile;
    char status, comChar;
    int children, base_salary, comInt;

    static bool valid_id(const string &data);
    static bool valid_name(const string &data);
    static bool valid_status(char data);
    static bool valid_children(int data);
    static bool valid_eduLevel(const string &data);
    static bool valid_baseSalary(int data);

    void put_id(string &data, bool findMode);
    void put_name(string &data);
    void put_status(char &data);
    void put_children(int &data);
    void put_eduLevel(string &data);
    void put_baseSalary(int &data);

public:
    Resume();
    ~Resume();

    void set_id(bool searchMode);
    void set_name();
    void set_status();
    void set_children();
    void set_eduLevel();
    void set_baseSalary();
    void set_timeKeeping();
    void set_contentFile(const string &data);

    string get_id(bool searchMode);
    string get_name();
    char get_status() const;
    int get_children() const;
    string get_eduLevel();
    int get_baseSalary() const;
    Timekeeping *get_timeKeeping();
    double get_totalSalary();
    string get_contentFile();

    static string get_standardizeMoney(double data);
    static string get_standardizeStatus(char data);
    static string get_standardizeEduLevel(const string& data);
    static string get_standardizeResult(const string &data);
    static string get_shortenName(string data);
};

#endif //EMPLOYEE_MANAGER_RESUME_H
