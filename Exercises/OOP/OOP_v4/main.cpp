#include "CountDate.h"

int main() {
    auto* myCalendar = new Calendar;
    string birthdayin, todayin;
    int option;

    other:
    do {
        cout << "Nhap vao ngay sinh cua ban (dd/mm/yyyy & yyyy >= 1800):";
        cin >> birthdayin;
        if (!myCalendar->checkDatein(birthdayin, "BIRTHDAY")) cout << "Ban nhap chua dung format hoac date khong ton tai !\n";
    } while (!myCalendar->checkDatein(birthdayin, "BIRTHDAY"));
    do {
        cout << "Nhap vao ngay hom nay (dd/mm/yyyy > your_birthday & yyyy >= 1800):";
        cin >> todayin;
        if (!myCalendar->checkDatein(todayin, "PRESENT")) cout << "Ban nhap chua dung format hoac date truoc sinh nhat cua ban !\n";
    } while (!myCalendar->checkDatein(todayin, "PRESENT"));

    cout << "Ban da sinh ra duoc " << myCalendar->count_yourBirthdayToNow() << " ngay ke tu ngay " << birthdayin << " cho den hien tai\n";
    cout << "Ban co muon kiem tra lai voi ngay khac ? (0 - Khong / !0 - Co) =>";
    cin >> option;
    if (option == 0) {
        cout << "Cam on ban da su dung chuong trinh !\n";
        system("pause");
    } else {
        myCalendar->resetDate();
        goto other;
    }
    return 0;
}
