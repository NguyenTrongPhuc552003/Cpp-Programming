#include <iostream>
using namespace std;

// Cre: https://vnseeder.blogspot.com/2014/05/bai-toan-oi-tien-bang-thuat-toan-tham.html
// Bai co ve kho nen tui phai tham khao them

int main() {
    int vnd, usd; // 500, 1000, ..., 500.000 VND / 1, 2, 5, ..., 100 USD
    int lan = 0, unit = 0; // language / VND or USD
    int viet1000, viet2000, viet5000, viet10000, viet20000, viet50000, viet100000, viet200000, viet500000; // Vietnam_1000VND
    int eng1, eng2, eng5, eng10, eng20, eng50, eng100; // UnitedStates_1USD

    cout << "ATM - RUT TIEN / WITHDRAWAL.\n";

    retype: {
        cout << "Ngon ngu / Language (VIET - 0 / ENG - 1): ";
        cin >> lan;

        currency:
        if (lan == 0) {
            cout << "Ban muon rut tien (VND - 0) hay (USD - 1) ? => ";
            cin >> unit;
        } else if (lan == 1){
            cout << "Do you want to withdraw (VND - 0) or (USD - 1) ? => ";
            cin >> unit;
        } else {
            cout << "Hay chon dung ngon ngu ! / Choose the right language !\n";
            goto retype;
        }
    }

    switch (unit) {
        case 0: // Rut tien VND
            if (lan == 0) cout << "Moi ban nhap so tien can rut (VND): ";
            else cout << "Please enter the withdrawal amount (VND): ";
            cin >> vnd;

            viet500000 = vnd / 500000; // Tinh toan so tien VND can chuyen doi
            vnd %= 500000;
            viet200000 = vnd / 200000;
            vnd %= 200000;
            viet100000 = vnd / 100000;
            vnd %= 100000;
            viet50000 = vnd / 50000;
            vnd %= 50000;
            viet20000 = vnd / 20000;
            vnd %= 20000;
            viet10000 = vnd / 10000;
            vnd %= 10000;
            viet5000 = vnd / 5000;
            vnd %= 5000;
            viet2000 = vnd / 2000;
            vnd %= 2000;
            viet1000 = vnd / 1000;
            vnd %= 1000;

            cout << "So to 500000: " << viet500000 << endl;
            cout << "So to 200000: " << viet200000 << endl;
            cout << "So to 100000: " << viet100000 << endl;
            cout << "So to 50000: " << viet50000 << endl;
            cout << "So to 20000: " << viet20000 << endl;
            cout << "So to 10000: " << viet10000 << endl;
            cout << "So to 5000: " << viet5000 << endl;
            cout << "So to 2000: " << viet2000 << endl;
            cout << "So to 1000: " << viet1000 << endl;
            break;

        case 1: // Rut tien USD
            if (lan == 1) cout << "Please enter the withdrawal amount (USD): ";
            else cout << "Moi ban nhap so tien can rut (USD): ";
            cin >> usd;

            eng100 = usd / 100; // Tinh toan so tien USD can chuyen doi;
            usd %= 100;
            eng50 = usd / 50;
            usd %= 50;
            eng20 = usd / 20;
            usd %= 20;
            eng10 = usd / 10;
            usd %= 10;
            eng5 = usd / 5;
            usd %= 5;
            eng2 = usd / 2;
            usd %= 2;
            eng1 = usd / 1;
            usd %= 1;

            cout << "100$ bills: " << eng100 << endl;
            cout << "50$ bills: " << eng50 << endl;
            cout << "20$ bills: " << eng20 << endl;
            cout << "10$ bills: " << eng10 << endl;
            cout << "5$ bills: " << eng5 << endl;
            cout << "2$ bills: " << eng2 << endl;
            cout << "1$ bills: " << eng1 << endl;
            break;

        default:
            cout << "Hay chon dung don vi tien ban muon quy doi ! / Select the correct currency you want to convert !\n";
            goto currency;
    }

    return 0;
}
