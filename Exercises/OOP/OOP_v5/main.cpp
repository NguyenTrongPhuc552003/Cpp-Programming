#include "GPA.h"

int main() {
    auto myGPA = new GPA;
    unsigned int n = 0, option;

    other:
    myGPA->subjects_amount(n);
    myGPA->credits_input(n);
    myGPA->marks_input(n);
    myGPA->subjects_result(n);

    do {
        cout << "Ban co muon kiem tra lai voi bang diem khac (0 - Khong / !0 - Co) =>";
        cin >> option;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu !\n";
            cin.clear();
            cin.ignore();
        } else {
            if (option == 0) {
                cout << "Cam on ban da su dung chuong trinh !\n";
                system("pause");
            } else {
                n = 0;
                goto other;
            }
        }
    } while (cin.fail());
    return 0;
}
