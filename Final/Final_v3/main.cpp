#include <iostream>
#include "string"
using namespace std;

int main() {
    string names, compared_name, new_name, get_name;
    bool flag = true;
    char space = ' ';
    int i, e, option, pos, same, check;
    int counter = 0;

    check_other:
    cout << "Nhap vao ten nhieu nguoi cach nhau boi dau ' ' (Vd: phuc manh kiet ...):"; // vd: phuc nam kiet phuc phung
    getline(cin, names);

    if (names.empty()) { // 1: chua nhap du lieu, 0: co du lieu
        cout << "Ban chua nhap du lieu. Moi ban nhap lai !\n";
        goto check_other;
    }

    for (i = 0; i < names.length(); i++) { // kiem tra kt tu Alphabet trong chuoi ten
        names[i] = tolower(names[i]); // chuyen ve cac chu cai thuong
        if (names[i] != ' ' && (names[i] < 'a' || names[i] > 'z') && (names[i] < 'A' || names[i] > 'Z')) {
            cout << "Xuat hien ky tu khong thuoc Alphabet. Moi ban nhap lai !\n";
            goto check_other;
        }
    }

    for (i = 0; i < names.length(); i++) { // kiem tra ten bi trung lap trong chuoi
        if (names[i] != ' ') {
            counter++; // dem so ky tu trong ten cu the
            if (flag) {
                e = i; // lay gia tri index tai ky tu dau tien
                flag = false;
            }
        } else {
            get_name = names.substr(e, counter); // lay ra cai ten truoc dau cach
            same = names.find(get_name,i); // tim cai ten trong chuoi
            flag = true;
            counter = 0;

            if (same >= 0 && same < names.length()) { // tra ve vi tri cu the
                cout << "Cai ten \"" << get_name << "\" xuat hien nhieu hon 1 lan trong chuoi. Moi ban nhap lai !\n";
                goto check_other;
            }
        }
    }

    again:
    cout << "Nhap vao ten bat ky de kiem tra (co the trung / khong trung voi cac ten trong chuoi tren):";
    cin >> compared_name;

    if (compared_name.empty()) { // 1: chua nhap du lieu, 0: co du lieu
        cout << "Ban chua nhap du lieu. Moi ban nhap lai !\n";
        goto again;
    }

    for (i = 0; i < compared_name.length(); i++) { // kiem tra ky tu Alphabet trong ten can kiem tra
        if ((compared_name[i] < 'a' || compared_name[i] > 'z') && (compared_name[i] < 'A' || compared_name[i] > 'Z')) {
            cout << "Xuat hien ky tu khong thuoc Alphabet. Moi ban nhap lai !\n";
            goto again;
        }
    }

    pos = names.find(compared_name, 0); // tim cai ten bi trung lap trong chuoi

    if (pos >= 0 && pos < names.length()) {
        cout << "Cai ten \"" << compared_name << "\" da xuat hien trong chuoi. Nam o vi tri: " << pos + 1;
        retype:
        cout << "\nMoi ban nhap vao 1 trong 4 lua chon ben duoi:";
        cout << "\n(0) Them ten moi sau ten bi trung trong chuoi\n(1) Xoa ten bi trung trong chuoi\n(2) Thay the ten bi trung trong chuoi voi ten moi\n(3) Thoat chuong trinh";
        cout << "\nLua chon cua ban:";
        cin >> option;

        if (option == 0 || option == 1 || option == 2) {
            if (option == 0 || option == 2) {
                cout << "Nhap vao ten moi:";
                cin.ignore(100, '\n');
                getline(cin, new_name);
            }
            cout << "Chuoi ban dau: " << names;
            cout << "\nChuoi da xu li: ";

            if (option == 0) names.insert(pos + compared_name.length(), space + new_name);
            else if (option == 1) names.erase(pos, compared_name.length() + 1);
            else names.replace(pos, compared_name.length(), new_name);
            cout << names;

        } else if (option == 3) {
            goto exit;
        } else {
            cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
        }
    } else cout << "Ten ban vua nhap khong bi trung lap trong chuoi";

    do {
        cout << "\nBan co muon kiem tra lai voi chuoi ten khac ? (0 - Khong / 1 - Co) =>";
        cin >> check;
        if (check < 0 || check > 1) cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !";
    } while (check < 0 || check > 1);

    exit:
    if (check == 0 || option == 3) {
        cout << "Cam on ban da su dung chuong trinh !\n";
        system("pause");
    } else {
        cin.ignore(100, '\n');
        names = '\0';
        compared_name = '\0';
        new_name = '\0';
        flag = true;
        counter = 0;
        system("cls");
        goto check_other;
    }

    return 0;
}
