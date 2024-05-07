#include <iostream>
using namespace std;

void check_name(string our_names, string name) {
    int e, m = 0, n = 0, length = 0, flag = 0, space_num = 0, same = 0;
    bool lock_name = true;

    our_names[our_names.length()] = ' '; // chen them ky tu ' ' vao sau vi tri cuoi cung trong chuoi vua nhap

    for (int i = 0; i < our_names.length() + 1; i++) { // phuc kiet nam phuc manh
        if (our_names[i] != ' ') {
            if (flag == 0) { // lay gia tri cua i
                e = i;
                flag++;
            }
            if (name[m] == our_names[i]) n++; // kiem tra ten bi trung
            m++;

        } else {
            space_num++; // so ky tu ' ' => xac dinh vi tri cai ten bi trung lap trong chuoi
            for (int l = e; l < e + m; l++) length++; // kiem tra do dai tung cai ten trong chuoi

            if (n == length) { // vd: phuc == phuc
                same++;
                if (same == 1) {
                    cout << "Cai ten \"" << name << "\" co trong chuoi vua nhap\n";
                    cout << "Vi tri cua \"" << name << "\" trong chuoi vua nhap la: " << space_num;
                } else {
                    cout << " " << space_num;
                }
                lock_name = false;
            }
            length = 0;
            flag = 0;
            m = 0;
            n = 0;
        }
    }
    if (lock_name) cout << "Cai ten \"" << name << "\" khong ton tai trong chuoi vua nhap";
}

int main() {
    string names, compared_name;
    int a;
    
    check_others:
//    fflush(stdin); // xoa ky tu \n trong bo nho dem
    cout << "Nhap vao ten nhieu nguoi cach nhau boi dau ' ' (Vd: phuc manh kiet ...):";
    getline(cin, names);

    for (char name : names) { // kiem tra chu in hoa va ky tu thuoc dang Alphabet trong chuoi vua nhap
        if (name >= 'A' && name <= 'Z') {
            cout << " Yeu cau nhap chu thuong & cac ky tu thuoc dang Alphabet (a - z). Moi ban nhap lai !\n";
            goto check_others;
        }
    }

    cout << "Nhap vao tiep 1 cai ten bat ki (co the trung / khong trung voi nhung ten vua nhap):";
    getline(cin, compared_name);

    check_name(names, compared_name); // kiem tra ten bi trung va vi tri cua no trong chuoi vua nhap

    retype:
    cout << "\nBan co muon kiem tra voi chuoi va ten khac ? (0 - Khong / 1 - Co) =>";
    cin >> a;

    switch (a) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;

        case 1:
            cin.ignore(100, '\n'); // xoa ky tu \n trong bo nho dem
            goto check_others;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
