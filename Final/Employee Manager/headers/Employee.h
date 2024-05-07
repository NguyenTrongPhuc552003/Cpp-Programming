//
// Created by Trong_Phuc on 29/06/2023.
//

#ifndef EMPLOYEE_MANAGER_EMPLOYEE_H
#define EMPLOYEE_MANAGER_EMPLOYEE_H

#include <algorithm>
#include <list>
#include <iomanip>
#include "Storage.h"

class Employee {
private:
    Resume *rsm = new Resume();
    Storage *str = new Storage();
    list<Resume *> my_list;
    string features[5] = {"Them", "Xoa", "Tim kiem", "Bang luong", "Thoat chuong trinh"};
    string header = "---> BANG LUONG HANG THANG <---\n";
    string taskbar = "| MA SO NHAN VIEN |   HO VA TEN   | LUONG CAN BAN (VND) | LUONG THUC LINH (VND) |\n"; // co tat ca 4 dau gach xo (bo dau cuoi)
    int comInt, amount_menu = sizeof(features) / sizeof(features[0]);

    static int partition(string *arr, int l, int h);
    static void nonRecursion_quickSort(string *data, int h);
    static int align_title(string &data, int slashPos); // tra ve gia tri can le
    static unsigned long long dashPos(string &data, int order);
    static string dashPair(string &data, int orderA, int orderB);

public:
    int get_selectionMenu() const;
    void menu();
    void add();
    void del();
    void find();
    void all();
};

#endif //EMPLOYEE_MANAGER_EMPLOYEE_H
