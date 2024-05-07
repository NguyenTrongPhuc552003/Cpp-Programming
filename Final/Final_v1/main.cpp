#include <iostream>
#include "chrono"
#include "thread"
using namespace std;

int main() {
    string basic_num[] = {"mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"}; // chu so
    long long n, m, i, options, money, money_copied, money_billion, money_million, money_thousand, to50, to100, to200, to500; // cac bien so / tien nhap, tien don vi / menh gia tien
    long long remainder = 1000000, billion = 1000000000, million = 1000000, thousand = 1000; // so du (co san 1.000.000 VND) / xu li in ra so bang chu

    cout << "ATM StrongFood55 (ngon ngu: tieng Viet)";
    retype_select:
    do {
        cout << "\nBan muon rut tien, nap tien hay truy van so du ? (0 - Rut tien / 1 - Nap tien / 2 - Truy van) =>";
        cin >> options;
        if (options < 0 || options > 2) cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
    } while (options < 0 || options > 2);

    cout << "He thong dang xu li yeu cau cua ban";
    this_thread::sleep_for(chrono::milliseconds(1000)); // delay 1s

    switch (options) {
        case 0: // rut tien trong tai khoan
            if (remainder < 50000) {
                cout << "\nSo du trong tai khoan khong du de thuc hien giao dich. Moi ban nap them tien vao tai khoan";
                goto retype_select;
            }
            cout << "\nLuu y: so tien phai la boi so cua 50.000 VND (Vd: 50, 100, 150, 200, ...)";
            retype_0:
            do {
                cout << "\nBan muon rut bao nhieu tien trong tai khoan? (toi thieu 50.000 VND & toi da 5.000.000 VND cho 1 lan rut) =>";
                cin >> money;
                if (money < 50000 || money > 5000000 || money % 50000 != 0) cout << "So tien ban nhap khong phu hop. Moi ban nhap lai !";
            } while (money < 50000 || money > 5000000 || money % 50000 != 0);

            if (money > remainder) {
                cout << "So tien ban rut lon hon so du !";
                do {
                    cout << "\nBan co muon nap them tien vao so du HAY nhap lai so tien khac ? (0 - Nap tien / 1 - Nhap lai) =>";
                    cin >> n;
                    if (n == 0) goto retype_1;
                    else if (n == 1) goto retype_0;
                    else cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
                } while (n < 0 || n > 1);
                
            } else { // money >= 50.000 && money <= remainder
                money_copied = money;
                to500 = money / 500000;
                money %= 500000;
                to200 = money / 200000;
                money %= 200000;
                to100 = money / 100000;
                money %= 100000;
                to50 = money / 50000;
                money %= 50000;
            }
            remainder -= money_copied; // tru tien vao so du
            break;

        case 1: // nap them tien vao tai khoan
            cout << "\nLuu y: so tien phai la boi so cua 50.000 VND (Vd: 50, 100, 150, 200, ...)";
            retype_1:
            do {
                cout << "\nBan muon nap them bao nhieu tien vao tai khoan ? (toi thieu 50.000 VND) =>";
                cin >> money;
                if (money < 50000 || money % 50000 != 0) cout << "So tien ban nhap khong phu hop. Moi ban nhap lai !";
            } while (money < 50000 || money % 50000 != 0);
            money_copied = money;
            remainder += money_copied; // cong tien vao so du
            break;

        case 2: // truy van so du trong tai khoan
            cout << "\nSo tien hien tai trong tai khoan cua ban la " << remainder << " VND.";
            money_copied = remainder;
            this_thread::sleep_for(chrono::milliseconds(1000)); // delay 1s
            break;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype_select;
    }

    if (options == 0 || options == 1) {
        cout << "He thong dang xu li ";
        for (i = 0; i < 5; i++) {
            this_thread::sleep_for(chrono::milliseconds(1000)); // delay 1s
            cout << "==";
        }

        cout << "\nBan da ";
        if (options == 0) {
            cout << "rut tien thanh cong !";
            cout << "\nSo to 500: " << to500 << "\tSo to 200: " << to200;
            cout << "\nSo to 100: " << to100 << "\tSo to 50: " << to50;
        } else cout << "nap tien thanh cong !";
        cout << "\nSo tien: " << money_copied << " VND"; // Vd: 1.256.350.000 VND
    }

    cout << "\nBang chu: "; // ti (options = 2), trieu, nghin

    if (money_copied >= billion) { // HANG TI (truy van so du)
        money_billion = money_copied / billion;

        if (money_billion <= 10) { // 1 - 10
            cout << basic_num[money_billion - 1];

        } else if (money_billion < 20) { // 11 - 19
            if (money_billion == 15) cout << "muoi lam";
            else cout << "muoi " << basic_num[(money_billion % 10) - 1];

        } else if (money_billion < 100) { // 20 - 99
            cout << basic_num[(money_billion / 10) - 1] << " muoi";
            if (money_billion % 10 == 5) cout << " lam"; // 25, 35, 45, ...
            else if (money_billion % 10 != 0) cout << " " << basic_num[(money_billion % 10) - 1];

        } else { // 100 - 999
            cout << basic_num[(money_billion / 100) - 1] << " tram";
            if (money_billion % 100 > 0 && money_billion % 100 < 10) { // n01 - n09
                cout << " le " << basic_num[(money_billion % 100) - 1];

            } else if (money_billion % 100 >= 10 && money_billion % 100 < 20) { // n10 - n19
                cout << " muoi";
                if (money_billion % 100 == 15) cout << " lam"; // nn5
                else if (money_billion % 100 != 10) cout << " " << basic_num[(money_billion % 10) - 1];

            } else if (money_billion % 100 >= 20) { // n20 - 999
                cout << basic_num[(money_billion % 100 / 10) - 1] << " muoi";
                if (money_billion % 10 == 5) cout << " lam"; // nn5
                else if (money_billion % 10 != 0) cout << " " << basic_num[(money_billion % 10) - 1];
            }
        }
        cout << " ti ";
    }

    if (money_copied % billion >= million) { // HANG TRIEU
        money_million = money_copied % billion / million;

        if (money_million <= 10) { // 1 - 10
            cout << basic_num[money_million - 1];

        } else if (money_million < 20) { // 11 - 19
            if (money_copied > billion) cout << "khong tram ";
            if (money_million == 15) cout << "muoi lam";
            else cout << "muoi " << basic_num[(money_million % 10) - 1];

        } else if (money_million < 100) { // 20 - 99
            if (money_copied > billion) cout << "khong tram ";
            cout << basic_num[(money_million / 10) - 1] << " muoi";
            if (money_million % 10 == 5) cout << " lam"; // 25, 35, 45, ...
            else if (money_million % 10 != 0) cout << " " << basic_num[(money_million % 10) - 1];

        } else { // 100 - 999
            cout << basic_num[(money_million / 100) - 1] << " tram";
            if (money_million % 100 > 0 && money_million % 100 < 10) { // n01 - n09
                cout << " le " << basic_num[(money_million % 100) - 1];

            } else if (money_million % 100 >= 10 && money_million % 100 < 20) { // n10 - n19
                cout << " muoi";
                if (money_million % 100 == 15) cout << " lam"; // nn5
                else if (money_million % 100 != 10) cout << " " << basic_num[(money_million % 10) - 1];

            } else if (money_million % 100 >= 20) { // n20 - 999
                cout << basic_num[(money_million % 100 / 10) - 1] << " muoi";
                if (money_million % 10 == 5) cout << " lam"; // nn5
                else if (money_million % 10 != 0) cout << " " << basic_num[(money_million % 10) - 1];
            }
        }
        cout << " trieu ";
    }

    if (money_copied % million >= 50 * thousand) { // HANG NGHIN - 100.000 VND
        money_thousand = money_copied % million / thousand; // 50 - 950 (50, 55, 60, ...)

        if (money_thousand < 100) { // 50 - 90
            if (money_copied > million && money_copied % million == 50 * thousand) cout << "khong tram ";
            cout << basic_num[(money_thousand / 10) - 1] << " muoi";
            if (money_thousand % 10 == 5) cout << " lam";

        } else { // 100 - 950
            cout << basic_num[(money_thousand / 100) - 1] << " tram";
            switch (money_thousand % 100) {
                case 0:
                    break;
                case 5:
                    cout << " le nam";
                    break;
                case 10:
                    cout << " muoi";
                    break;
                case 15:
                    cout << " muoi lam";
                    break;
                default: // n20 - n50
                    cout << " " << basic_num[(money_thousand % 100 / 10) - 1] << " muoi";
                    if (money_thousand % 10 == 5) cout << " lam";
            }
        }
        cout << " nghin ";
    }

    cout << "VND";

    do {
        cout << "\nBan co muon thuc hien lai giao dich khac khong ? (0 - Khong / 1 - Co) =>";
        cin >> m;

        if (m == 0) {
            cout << "Cam on ban da su dung ATM StrongFood55 !\n";
            break;
        } else if (m == 1) goto retype_select;
        else cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";

    } while (m < 0 || m > 1);

    system("pause");

    return 0;
}
