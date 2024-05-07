#include <iostream>
#include "MemAlloc.h"

using namespace std;

bool check_id(int data) {
    unsigned int counter = 0;

    while (data != 0) {
        counter++;
        data /= 10;
    }
    if (counter != 8) return false;
    return true;
}

int main() {
    my_array arr; // con tro arr
    int amount = 5, input;
    bool flag;

    arr.n = amount; // khoi tao so luong o nho duoc cap phat
    if (arr.intType == nullptr) return 1;

    for (int i = 0; i < arr.size(); i++) {
        do {
            flag = true;
            cout << "Nhap vao MSSV thu " << i + 1 << " (Vd: 21207197):";
            cin >> input;
            if (cin.fail()) {
                cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
                cin.clear();
                cin.ignore();
                flag = false;
            } else {
                if (!check_id(input)) cout << "Ban nhap sai MSSV. Moi ban nhap lai !\n";
            }
        } while (!flag || !check_id(input));
        arr.push_back(input);
    }

    cout << "Cac MSSV ban vua nhap lan luot la: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.intType[i] << ' ';
        if (i == arr.size() - 1) cout << endl;
    }

    do { // pop_back
        flag = true;
        cout << "Ban muon xoa bot bao nhieu MSSV da nhap ? =>";
        cin >> input;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            cin.clear();
            cin.ignore();
            flag = false;
        } else {
            if (input > arr.size()) cout << "Ban nhap lon hon so luong ban dau. Moi ban nhap lai !\n";
        }
    } while (!flag || input > amount);
    for (int i = 0; i < input; i++) arr.pop_back();
    cout << "Sau khi xoa bot, con lai: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr.intType[i] << ' ';
        if (i == arr.size() - 1) cout << endl;
    }

    do { // erase
        flag = true;
        cout << "Ban co muon xoa het du lieu con lai ? (0 - Khong / !0 - Co) =>";
        cin >> input;
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            cin.clear();
            cin.ignore();
            flag = false;
        }
    } while (!flag);
    arr.erase();
    cout << "Sau khi xoa sach, con lai: ";
    for (int i = 0; i < arr.size(); i++) cout << arr.intType[i] << ' ';
    free(arr.intType);
    return 0;
}
