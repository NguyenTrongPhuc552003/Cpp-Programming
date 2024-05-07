#include <iostream>
using namespace std;

void Add_Arrays (int arrays[], int elements) {
    int arrays_copied[100];
    int add_pos, add_insert;

    for (int i = 0; i < elements; i++) arrays_copied[i] = arrays[i];

    do {
        cout << "\nBan muon them vao vi tri nao ? =>";
        cin >> add_pos;
        if (add_pos < 1 || add_pos > elements) cout << "Khong ton tai vi tri do. Moi ban nhap lai !";
    } while (add_pos < 1 || add_pos > elements);

    do {
        cout << "Ban muon them bao nhieu phan tu sau vi tri nay ? =>";
        cin >> add_insert;
        if (add_insert < 1) cout << "So phan tu duoc them phai lon hon 0. Moi ban nhap lai !\n";
    } while (add_insert < 1);

    for (int i = add_pos - 1; i < elements; i++) arrays[i + add_insert] = arrays_copied[i];

    for (int i = add_pos; i < add_pos + add_insert; i++) {
        cout << "Nhap vao phan tu THEM thu " << i << ":";
        cin >> arrays[i];
    }

    cout << "Mang ban nhap luc dau: ";
    for (int i = 0; i < elements; i++) cout << arrays_copied[i] << " ";
    cout << "\nMang sau khi duoc THEM: ";
    for (int i = 0; i < elements + add_insert; i++) cout << arrays[i] << " ";
}

void Sub_Arrays (int arrays[], int elements) {
    int arrays_copied[100];
    int sub_pos, sub_insert;

    for (int i = 0; i < elements; i++) arrays_copied[i] = arrays[i];

    do {
        cout << "\nBan muon xoa o vi tri nao ? =>";
        cin >> sub_pos;
        if (sub_pos < 1 || sub_pos > elements) cout << "Khong ton tai vi tri do. Moi ban nhap lai !";
    } while (sub_pos < 1 || sub_pos > elements);

    do {
        cout << "Ban muon xoa bao nhieu phan tu o vi tri nay ? =>";
        cin >> sub_insert;
        if (sub_insert < 1 || sub_insert > (elements - sub_pos + 1)) cout << "So phan tu duoc them phai lon hon 0 hoac be hon bang " << (elements - sub_pos + 1) << ". Moi ban nhap lai !\n";
    } while (sub_insert < 1 || sub_insert > (elements - sub_pos + 1));

    for (int i = sub_pos - 1; i <= (elements + sub_insert); i++) arrays[i] = arrays[i + sub_insert]; // 1 1 4, 1 2 3, 2 1 3, 2 3 1

    cout << "Mang ban nhap luc dau: ";
    for (int i = 0; i < elements; i++) cout << arrays_copied[i] << " ";
    cout << "\nMang sau khi duoc XOA: ";
    for (int i = 0; i < elements - sub_insert; i++) cout << arrays[i] << " ";
}

int main() {
    int arrays[100];
    int n, m, k;

    check_others:
    cout << "Chuong trinh them / xoa phan tu trong mang";
    do {
        cout << "\nBan muon mang co bao nhieu phan tu ? =>";
        cin >> n;
        if (n < 1) cout << "So phan tu trong mang phai lon hon 0. Moi ban nhap lai !";
    } while (n < 1);

    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ":";
        cin >> arrays[i];
    }

    retype:
    cout << "Ban muon them / xoa cac phan tu ? (0 - Them / 1 - Xoa) =>";
    cin >> m;
    if (m == 0 || m == 1) cout << "Hien tai co " << n << " vi tri (1 - " << n << ") de ban lua chon";

    switch (m) {
        case 0:
            Add_Arrays(arrays, n);
            break;
        case 1:
            Sub_Arrays(arrays, n);
            break;
        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !\n";
            goto retype;
    }

    do {
        cout << "\nBan co muon thuc hien lai chuong trinh voi mang khac ? (0 - Khong / 1 - Co) =>";
        cin >> k;
        if (k < 0 || k > 1) cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
    } while (k < 0 || k > 1);

    if (k == 0) {
        cout << "Cam on ban da su dung chuong trinh !\n";
        system("pause");
    } else goto check_others;

    return 0;
}
