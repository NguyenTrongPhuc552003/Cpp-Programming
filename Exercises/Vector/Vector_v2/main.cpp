#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    vector <int> array, same_data, best_appear, appear_pos;
    vector <int>::iterator same_pos;
    int data, option, soldier = 0, same = 0;

    other:
    cout << "Nhap vao cac so nguyen (co the nhap nhieu lan 1 so, nhap '/' de ket thuc)\n>";
    while (cin >> data) {
        array.emplace_back(data); // day du lieu tu ben trai (dang truoc) vao vector, tuong tu push_back nhung save memory better (using &)
        for (auto& i : array) cout << '\"' << i << "\" ";
        cout << '>';
    }

    for (int i = 0; i < array.size(); i++) {
        for (int l = i; l < array.size(); l++) {
            if (array[i] == array[l]) same++;
        }
        if (same > 1) {
            same_pos = find(same_data.begin(), same_data.end(), array[i]); // tim so xuat hien bi trung lap
            if (same_pos == same_data.end()) same_data.emplace_back(array[i]); // cac so nguyen xuat hien nhieu hon 1 lan, tranh lap so da xuat hien (Vd: 1 1 2 1 1 1)
            if (soldier <= same) { // cac so nguyen xuat hien nhieu nhat
                best_appear.emplace_back(array[i]);
                soldier = same;
            }
        }
        same = 0;
    }
    cout << "- Cac so nguyen xuat hien nhieu hon 1 lan: ";
    for (auto& i : same_data) cout << i << ' ';
    cout << "\n- Cac so nguyen xuat hien nhieu nhat: ";
    for (auto& i : best_appear) cout << i << ' ';
    cout << "\n- Cac so nguyen chi xuat hien 1 lan: ";
    for (auto& l : same_data) {
        do {
            same_pos = array.begin(); // khoi tao vi tri bat dau trong array
            for (auto& i : array) {
                if (i == l) { // xac dinh vi tri cua so nguyen bi trung lap
                    array.erase(same_pos);
                    break;
                }
                ++same_pos;
            }
        } while (same_pos != array.end());
    }
    for (auto& i : array) cout << i << ' ';

    retype:
    cout << "\nBan co muon kiem tra lai chuong trinh voi day so khac ? (0 - Khong / !0 - Co):";
    cin >> option;
    if (cin.fail()) {
        cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
        cin.clear();
        cin.ignore();
        goto retype;
    } else {
        if (option == 0) {
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
        } else {
            goto other;
        }
    }
    return 0;
}
