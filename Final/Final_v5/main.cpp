#include <iostream>
#include "BookMng.h"
#include "LibMng.h"

using namespace std;

int main() {
    auto myLib = new LibMng;
    auto myBook = new BookMng;
    string please = ". Moi ban nhap lai !\n";
    int option, m;

    welcome:
    myLib->main_userInterface(); // giao dien dang nhap / dang ki, xuat thong tin ng dung, ...
    menu_lib:
    cout << "==> MENU StrongFood's Book Library <==";
    cout << "\n0 - Quyen gop them sach vao thu vien.";
    cout << "\n1 - Liet ke toan bo so sach hien co trong thu vien.";
    cout << "\n2 - Tra cuu sach theo ID, Ten sach, Ngay nhap sach, Ten tac gia.";
    cout << "\n3 - Sap xep thu tu sach theo ID (tang dan), Ngay nhap sach (cu - moi), Trang thai sach (uu tien co san).";
    cout << "\n4 - Xuat ra toan bo sach co trong thu vien o dang <file>.txt ben trong project.";
    cout << "\n5 - Roi khoi giao dien MENU.";
    cout << "\nLua chon cua ban la:";
    cin >> option;

    if (option >= 0 && option <= 4) system("cls");
    switch (option) {
        case 0:
            myBook->add();
            break;
        case 1:
            myBook->list();
            break;
        case 2:
            myBook->search();
            break;
        case 3:
            myBook->sort();
            break;
        case 4:
            myBook->print_all();
            break;
        case 5:
            goto retype;
        default:
            cout << "Gia tri ban nhap khong phu hop" << please;
            goto menu_lib;
    }
    retype:
    cout << "Ban co muon su dung tiep thu vien hoac dang xuat tai khoan ? (0 - Khong / 1 - Co) =>";
    cin >> m;
    switch (m) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1: // reset du lieu cac bien
            goto welcome;
        default:
            cout << "Gia tri ban nhap khong phu hop" << please;
            goto retype;
    }
    return 0;
}