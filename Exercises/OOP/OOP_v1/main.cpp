#include <iostream>
#include "Examination.h"

using namespace std;

int main() {
    auto* contestant = new Student;
    int option;

    check_again:
    contestant->input_name();
    contestant->input_date();
    contestant->input_id();
    contestant->input_marks();
    contestant->output_infors();

    do {
        cout << "Ban co muon kiem tra lai voi thong tin khac ? (0 - Khong / !0 - Co) =>";
        cin >> option;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            cin.clear();
            cin.ignore();
        } else {
            if (option == 0) {
                cout << "Cam on ban da su dung chuong trinh !\n";
                system("pause");
            } else {
                system("cls");
                cin.ignore(100, '\n');
                goto check_again;
            }
        }
    } while (cin.fail());
    return 0;
}
