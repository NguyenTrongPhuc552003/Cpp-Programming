#include <iostream>
using namespace std;

void Lunisolar_Tomorrow (int d, int m, int y) { // Vd: 04/03/2022
    int AD = 0;

    if (m == 4 || m == 6 || m == 9 || m == 11) { // nhung thang co 30 ngay
        if (d == 30 || d > 30) {
            if (d > 30) cout << "Chu y: thang ban vua nhap chi co 30 ngay\n";
            d = 1;
            m++;
        } else d++;
    } else if (m == 2) {
        while (AD < y) AD += 4; // nam Cong Nguyen tien dan ve nam hien tai, chu ky 4 nam
        if (y == AD) { // nam nhuan => thang 2 co 29 ngay
            if (d == 29 || d > 29) {
                if (d > 29) cout << "Chu y: thang ban vua nhap chi co 29 ngay (ly do: nam nhuan)\n";
                d = 1;
                m++;
            } else d++;
        } else { // nam ko nhuan => thang 2 co 28 ngay
            if (d == 28 || d > 28) {
                if (d > 28) cout << "Chu y: thang ban vua nhap chi co 28 ngay (ly do: nam khong nhuan)\n";
                d = 1;
                m++;
            } else d++;
        }
    } else { // nhung thang co 31 ngay
        if (m == 12) {
            if (d == 31) {
                d = 1;
                m = 1;
                y++;
            } else d++;
        } else {
            if (d == 31) {
                d = 1;
                m++;
            } else d++;
        }
    }
    cout << "Ngay mai: ";
    if (d < 10) cout << "0" << d;
    else cout << d;
    cout << "/";
    if (m < 10) cout << "0" << m;
    else cout << m;
    cout << "/" << y << "\n";
}

int main() {
    string condition[] = {"ngay hom nay [1 - 31]:", "thang hom nay [1 - 12]:", "nam hom nay (nam > 0):"};
    unsigned int dayDt = 0, monthDt = 0, yearDt = 0;
    unsigned int date[3], n;

    check_again:
    cout << "Ban muon boc lich ?\n";
    for (int i = 0; i < 3; i++) {
        do {
            cout << "Nhap vao " << condition[i];
            cin >> date[i];
            if (date[i] < 1 || (date[i] > 12 && i == 1) || date[0] > 31) cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !\n";
        } while (date[i] < 1 || (date[i] > 12 && i == 1) || date[0] > 31);
    }
//    cout << "Hoi tiep, ban sinh ngay bao nhieu ? (dd mm yyyy) =>";
//    cin >> dayDt >> monthDt >> yearDt;

    // VN - am duong lich (T_moon: 28, 29 (thang 2 cua nam thu 4), T_sun: 365, 366 (nam thu 4))
    // Trai Dat quay quanh Mat Troi het 365 ngay 5 gio 48' 46" => 365 ngay (sau 4 nam, 4 * 5 gio 48' 46" => 1 ngay cong vao thang 2 cua nam thu 4)
    Lunisolar_Tomorrow(date[0], date[1], date[2]); // ngay mai la ngay may ?
//    Lunisolar_Calendar(date[0], date[1], date[2]); // xem lich tong quat

    retype:
    cout << "Ban co muon kiem tra lai voi thoi gian khac ? (0 - Khong / 1 - Co) =>";
    cin >> n;
    switch (n) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            goto check_again;
        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !\n";
            goto retype;
    }

    return 0;
}
