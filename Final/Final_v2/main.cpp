#include <iostream>
#include "string"
#include "cmath"
using namespace std;

#pragma warning(disable: 6001) // warning lien quan toi appear_best

int main() {
    int i, type, swap;
    int m = 0, n = 0, e = 0, f = 0, flag = 0, soldier = 1, check = 0, point = 0, same = 0;
    int neg = 0, pos = 0, compare = 0, square_num = 0, prime_number = 0, frequency = 1, appear_num = 0;
    int arrays_num[100], arrays_copied1[100], arrays_copied2[100];
    string arrays[100];

    check_others:
    cout << "Nhap vao cac phan tu trong mang (ket thuc boi dau '.')\n";
    for (i = 0; i <= n; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ":";
        cin >> arrays[i];
        if (arrays[i] == ".") {
            cout << "Done !";
            break;
        }
        n++;
    }

    // Cau 1
    cout << "\nc1/ Mang ban vua nhap gom: ";
    for (i = 0; i < n; i++) {
        arrays_num[i] = stoi(arrays[i]);
        arrays_copied1[i] = arrays_num[i]; // dung cho c4a
        arrays_copied2[i] = arrays_num[i]; // dung cho c4b
        if (arrays_num[i] < 0) neg++;
        else pos++;
        cout << arrays_num[i] << " ";
    }

    for (i = 0; i < n; i++) if (arrays_num[0] == arrays_num[i + 1]) check++; // vd: 9 9 9 9 ...

    // Cau 2
    cout << "\nc2/ Mang ban vua nhap co: " << n << " phan tu";

    // Cau 3
    cout << "\nc3/ Mang sap xep tang dan: ";
    if (n == 1 || check != n - 1) {
        for (i = 0; i < n; i++) {
            for (int l = i + 1; l < n; l++) {
                if (arrays_num[i] > arrays_num[l]) {
                    swap = arrays_num[i];
                    arrays_num[i] = arrays_num[l];
                    arrays_num[l] = swap;
                }
            }
            cout << arrays_num[i] << " ";
        }
    }

    // Cau 4
    negative:
    for (i = 0; i < n - e; i++) { // mang toan so am
        if (arrays_copied1[i] >= 0) {
            for (int l = i; l < n; l++) arrays_copied1[l] = arrays_copied1[l + 1];
            e++;
            goto negative;
        }
    }

    e = 0; // reset gia tri e ve 0
    positive:
    for (i = 0; i < n - e; i++) { // mang toan so duong
        if (arrays_copied2[i] < 0) {
            for (int l = i; l < n; l++) arrays_copied2[l] = arrays_copied2[l + 1];
            e++;
            goto positive;
        }
    }

    cout << "\nc4/ Mang nguyen am / nguyen duong bao gom: ";
    for (i = 0; i < neg; i++) cout << arrays_copied1[i] << " ";
    cout << "/ ";
    for (i = 0; i < pos; i++) cout << arrays_copied2[i] << " ";

    // Cau 5
    cout << "\nc5/ Phan tu lon nhat / nho nhat trong mang: ";
    if (n != 1 && check != n - 1) {
        for (i = 0; i < n; i++) if (compare < arrays_num[i]) compare = arrays_num[i];
        cout << compare << " / ";
        for (i = 0; i < n; i++) if (compare > arrays_num[i]) compare = arrays_num[i];
        cout << compare;
    }

    // Cau 6
    c6:
    for (i = 0; i < n; i++) {
        if (arrays_num[i] / sqrt(arrays_num[i]) == int(sqrt(arrays_num[i])) && arrays_num[i] != 1) {
            if (flag == 0) {
                square_num++;
            } else {
                if (arrays_num[i] == arrays_num[i + 1]) continue;
                cout << arrays_num[i] << " ";
            }
        }
    }

    if (flag == 0) {
        cout << "\nc6/ Co " << square_num << " so chinh phuong trong mang vua nhap";
        if (square_num != 0) {
            cout << ". Bao gom: ";
            flag++;
            goto c6;
        }
    }

    flag = 0; // reset gia tri flag ve 0
    // Cau 7
    c7:
    for (i = 0; i < n; i++) {
        for (int l = 1; l <= arrays_num[i]; l++) {
            if (arrays_num[i] % l == 0) {
                if (arrays_num[i] == same) break; // tranh so bi trung lap
                m++;
            }
        }
        if (m == 2) {
            if (flag != 0) cout << arrays_num[i] << " ";
            prime_number++;
            same = arrays_num[i];
        }
        m = 0;
    }

    if (flag == 0) {
        cout << "\nc7/ Co " << prime_number << " so nguyen to trong mang vua nhap";
        if (prime_number != 0) {
            cout << ". Bao gom: ";
            flag++;
            same = 0;
            goto c7;
        }
    }

    flag = 0; // reset gia tri flag ve 0
    // Cau 8
    c8:
    for (i = 0; i < n; i++) {
        if (arrays_num[i] == arrays_num[i + 1]) {
            f++;
            if (flag != 0 && f == 1) {
                cout << arrays_num[i] << " ";
                arrays_copied1[point] = arrays_num[i];
                point++;
            }
            frequency++;
        } else {
            f = 0;
            if (frequency > 1) appear_num++;
            frequency = 1;
        }
        if (soldier < frequency) soldier = frequency;
    }

    if (flag == 0) {
        cout << "\nc8/ Co " << appear_num << " phan tu trong mang xuat hien nhieu hon 1 lan";
        if (appear_num != 0) {
            cout << ". Bao gom: ";
            flag++;
            goto c8;
        }
    }

    frequency = 1; // reset gia tri frequency ve 0
    // Cau 9
    cout << "\nc9/ Cac phan tu xuat hien nhieu nhat trong mang: ";
    for (i = 0; i < n; i++) {
        if (arrays_num[i] == arrays_num[i + 1]) {
            frequency++;
        } else {
            frequency = 1;
        }
        if (frequency == soldier) cout << arrays_num[i] << " ";
    }
    if (soldier > 1) cout << "(Tan suat xuat hien: " << soldier << ")";

    e = 0; // reset gia tri e ve 0
    // Cau 10
    for (int l = 0; l < point; l++) {
        fre_1time:
        for (i = 0; i < n - e; i++) {
            if (arrays_num[i] == arrays_copied1[l]) {
                for (int k = i; k < n - e; k++) arrays_num[k] = arrays_num[k + 1];
                e++;
                goto fre_1time;
            }
        }
    }

    cout << "\nc10/ Mang gom cac phan tu chi xuat hien 1 lan: ";
    for (i = 0; i < n - e; i++) cout << arrays_num[i] << " ";
    //    cout << "(Tong so phan tu: " << n - e << ")";

    retype:
    cout << "\nBan co muon thuc hien lai chuong trinh khong ? (0 - Khong / 1 - Co) =>";
    cin >> type;

    switch (type) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;

        case 1:
            m = 0; // reset cac gia tri ve 0
            n = 0;
            e = 0;
            f = 0;
            flag = 0;
            soldier = 1;
            check = 0;
            point = 0;
            neg = 0;
            pos = 0;
            compare = 0;
            square_num = 0;
            prime_number = 0;
            frequency = 1;
            appear_num = 0;
            goto check_others;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
