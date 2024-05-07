#include <iostream>
#include <string>
using namespace std;

int main() {
    string hoten;
    int i, l, m, n, space_check = 0, space_counter = 0, ho = 0, ten_dem = 0, ten = 0;

    check_others:
    cout << "Nhap vao ho va ten cua ban:";
//    cin.ignore(100, '\n');
    fflush(stdin);
    getline(cin, hoten);

    for (i = 0; i < hoten.length(); i++) if (hoten[i] == ' ') space_check++; // dem xem co bao nhieu dau cach

    cout << "Ho cua ban: ";
    for (i = 0; i < hoten.length(); i++) {
        if (hoten[i] == ' ') { // dau cach dau tien
            space_counter++;

            cout << " (" << ho << " ky tu)" << "\nTen dem cua ban: ";
            for (l = i + 1; l < hoten.length(); l++) {
                if (hoten[l] == ' ') { // cac dau cach tiep theo
                    space_counter++;

                    if (space_counter == space_check) { // dau cach cuoi cung
                        cout << " (" << ten_dem << " ky tu)" << "\nTen cua ban: ";
                        for (m = l + 1; m < hoten.length(); m++) {
                            cout << hoten[m];
                            ten++;
                        }
                        cout << " (" << ten << " ky tu)";
                        goto retype;
                    }

                } else ten_dem++;
                cout << hoten[l];
            }
            if (space_counter == 1) {
                cout << " (" << ten_dem << " ky tu)";
                goto retype;
            }
        }
        cout << hoten[i];
        ho++;
    }

    retype:
    cout << "\nBan co muon kiem tra lai voi cai ten khac ? (0 - Khong / 1 - Co) =>";
    cin >> n;

    switch (n) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;

        case 1:
            space_check = 0;
            space_counter = 0;
            ho = 0;
            ten_dem = 0;
            ten = 0;
            goto check_others;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
