#include <iostream>
#include "student_nodes.h"

using namespace std;

int main() {
    auto myList = new studentNodes;
    unsigned int end_menu, time_process = 3;

    program_begin:
    myList->init_menu();
    if (myList->flag_menu_option >= 1 && myList->flag_menu_option <= 3) myList->delay_list(time_process); // he thong dang xu li

    switch (myList->flag_menu_option) {
        case 0: // khoi tao thong tin sinh vien
            myList->input_id();
            myList->input_name();
            myList->input_sex();
            myList->input_date();
            myList->input_class();
            break;
        case 1: // truy xuat thong tin sinh vien
            myList->output_infors();
            break;
        case 2: // sap xep thong tin dua tren truong du lieu
            myList->output_sort();
            break;
        case 3: // sao luu thong tin thanh cong !
            myList->backup_infors();
            break;
        default: // exit
            break;
    }

    do {
        cout << "Ban co muon su dung lai chuong trinh khong ? (0 - Khong / !0 - Co) =>";
        cin >> end_menu;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
        } else {
            if (end_menu == 0) {
//                delete[] myList;
                cout << "Cam on ban da su dung chuong trinh !\n";
                system("pause");
            } else {
                myList->flag_menu_option = FLAG_RST;
                myList->reset_io();
                goto program_begin;
            }
        }
    } while (cin.fail());
    return 0;
}
