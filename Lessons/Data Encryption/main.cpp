#include <iostream>
#include "myCaro.h"

using namespace std;

int main() {
    auto gamers = new myCaro("Encrypt_Caro");
    int option;
    char step;

    try_other:
    do {
        cout << "Luot di dau tien (X / O):";
        cin >> step;
        if (step != 'X' && step != 'O') cout << "Nuoc di nay khong hop le !\n";
    } while (step != 'X' && step != 'O');
    gamers->in_turn(step);
    gamers->out_turn();
    gamers->up_encryptedData();
    gamers->down_decryptedData();
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Ban co muon choi van co khac ? (0 - Khong / !0 - Co) =>";
        cin >> option;
        if (cin.fail()) cout << "Ban nhap sai kieu du lieu !\n";
    } while (cin.fail());
    if (option != 0) {
        gamers->renew_turn();
        goto try_other;
    } else {
        free(gamers);
        cout << "Cam on ban da su dung chuong trinh ! \n";
        system("pause");
    }
    return 0;
}
