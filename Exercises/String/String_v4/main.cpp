#include <iostream>
#include <string>
using namespace std;

int position_str(int change_position, string full_name) { // 1 < change_position <= space_counter
    int space_counter = 0;

    for (int i = 0; i <= full_name.length(); i++) {
        if (full_name[i] == ' ') space_counter++;
        if (change_position == 1) return i;
        else if (change_position == space_counter + 1) return i + 1;
    }
    return 0;
}

int amount_str(int change_position, string full_name) { // tra ve so luong ky tu tai vi tri change_position cho den khi gap ky tu dau ' '
    int amount_counter = 0;

    for (int i = 0; i <= full_name.length(); i++) {
        if (change_position == i) {
            for (int k = i; k <= full_name.length(); k++) {
                if (full_name[k] == ' ') return amount_counter + 1;
                amount_counter++;
            }
        }
    }
    return 0;
}

int main() {
    string hoten, change, condition;
    bool flag = true;
    int n, m, e, f, g, last, position, amount, flag2 = 0, space_counter = 0, space_num = 0, tendem = 0, sotendem = 0;

    check_other:
    do {
        cout << "Nhap vao ho va ten cua ban:";
        getline(cin, hoten);
        if ((hoten < "A" || hoten > "Z") && (hoten < "a" || hoten > "z")) cout << "Ten cua ban chua ky tu la. Moi ban nhap lai !\n";
        if (hoten[hoten.length() - 1] == ' ') cout << "Khong nhap ky tu ket thuc bang dau ' '. Moi ban nhap lai !\n";
    } while ((hoten < "A" || hoten > "Z") && (hoten < "a" || hoten > "z") || hoten[hoten.length() - 1] == ' ');

    do {
        cout << "Ban muon Them hay Xoa cac thanh phan trong ten ban vua nhap ? (0 - Them / 1 - Xoa) =>";
        cin >> n;
        if (n < 0 || n > 1) cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !\n";
    } while (n < 0 || n > 1);

    hoten.push_back(' '); // chen dau cach vao vi tri cuoi cung cua chuoi
    for (int i = 0; i <= hoten.length(); i++) {
        if (hoten[i] == ' ') space_num++;
    }

    for (int i = 0; i <= hoten.length(); i++) {
        if (hoten[i] != ' ') {
            if (flag) {
                e = i;
                flag = false;
            }
        } else {
            space_counter++;

            if (space_counter == space_num - 1) {
                f = i; // tim gia tri i tai dau cach space_num - 1
                for (int d = g + 1; d <= f; d++) tendem++; // dem so ky tu trong ten dem
            } else if (space_counter >= 1 && space_counter < space_num - 1) {
                if (space_counter == 1) g = i; // tim gia tri i tai dau cach dau tien
                sotendem++; // dem so phan tu ngan cach boi dau cach trong ten dem
            }

            if (n == 1 && space_num > 3) { // in ra vi tri / thanh phan de lua chon
                if (space_counter == 1) {
                    cout << "(0) Ho {";
                } else if (space_counter == space_num) {
                    cout << "(2) Ten {";
                } else {
                    if (!flag2) cout << "(1) Ten dem {";
                    flag2++;
                }
            }

            cout << "(" << space_counter << ") ";
            for (int l = e; l < i; l++) cout << hoten[l];
            cout << " ";

            if (n == 1 && space_num > 3) {
                if (space_counter == 1 || space_counter == space_num || space_counter == space_num - 1) cout << "\b}\n";
            }
            flag = true;
        }
    }
    last = space_counter + 1;

    if (n == 0) { // lua chon them
        cout << "(" << last << ")";
        do {
            cout << "\nCo " << last << " vi tri de ban them vao. Ban chon vi tri nao ? =>";
            cin >> position;
            if (position < 0 || position > last) cout << "Khong ton tai vi tri do. Moi ban nhap lai !";
        } while (position < 0 || position > last);

        cout << "Nhap vao phan tu can them:";
        cin.ignore(100, '\n');
        getline(cin, change);

        if (position == 1) position = 0; // vi tri dau tien
        else if (position == last) position = hoten.length(); // vi tri cuoi cung
        else position = position_str(position, hoten);

        change.push_back(' '); // chen ky tu dau ' ' vao cuoi vi tri cua change

        cout << "Ten ban nhap luc dau: " << hoten;
        cout << "\nTen ban sau khi them: " << hoten.insert(position, change);

    } else { // lua chon xoa
        do {
            cout << "Co 3 thanh phan (Ho, Ten dem, Ten) de ban xoa. Ban chon thanh phan thu may ? =>";
            cin >> position;
            if (position < 0 || position > 2) cout << "Khong ton tai thanh phan do. Moi ban nhap lai !";
        } while (position < 0 || position > 2);

        if (space_num > 3) {
            if (position == 0) {
                position = 1;

            } else if (position == 2) {
                position = space_num;

            } else {
                cout << "Co " << sotendem << " phan tu trong Ten dem, gom: ";
                for (int i = 2; i < 2 + sotendem; i++) cout << i << " ";

                cout << "\b. Ban muon xoa phan tu thu may (hoac chon 1 de xoa tat ca) ? =>";
                cin >> position;

                if (position == 1) {
                    position = position_str(2, hoten);
                    amount = tendem;
                    goto skip;
                }
            }
        }

        position = position_str(position, hoten);
        amount = amount_str(position, hoten);

        skip:
        cout << "Ten ban nhap luc dau: " << hoten;
        cout << "\nTen ban sau khi xoa: " << hoten.erase(position, amount);
    }

    retype_check:
    cout << "\nBan co muon kiem tra lai voi cai ten khac ? (0 - Khong / 1 - Co) =>";
    cin >> m;

    switch (m) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;

        case 1:
            cin.ignore(100, '\n');
            space_counter = 0;
            space_num = 0;
            tendem = 0;
            sotendem = 0;
            flag = true;
            flag2 = 0;
            goto check_other;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype_check;
    }

    return 0;
}
