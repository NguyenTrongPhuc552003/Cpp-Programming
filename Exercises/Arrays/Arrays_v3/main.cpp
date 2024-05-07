#include <iostream>
using namespace std;

int main() {
    int array[100], array_copied[100];
    int n, i, l, request, location, insert, swap, same;
    int counter = 0, flag = 0;

    cout << "Chuong trinh kiem tra so phan tu trong mang\n";
    again:
    cout << "Ban muon nhap vao mang bao nhieu phan tu:";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ":";
        cin >> array[i];
        array_copied[i] = array[i]; // sao chep het sang array_copied de thuc hien mot so cong viec
    }

    cout << "Ban co muon chen them mot so phan tu vao mang ? (0 - Khong / 1 - Co) =>";
    request_retype:
    cin >> request;

    if (request == 1) { // thuc hien nhiem vu chen vao vi tri ...
        cout << "Hien tai co " << n << " vi tri tu 1 den " << n << " de ban lua chon !\nBan chon vi tri thu:"; // chon vi tri tu 1 - n
        do {
            cin >> location; // 3
            if (location > n || location < 1) cout << "Khong ton tai vi tri nay. Moi ban nhap lai =>";
        } while (location > n || location < 1);

        cout << "Ban muon chen them bao nhieu phan tu sau vi tri nay ? (so phan tu phai > 0) =>"; // so phan tu duoc chen them
        do {
            cin >> insert;
        } while (insert < 0);

        if (location == 1) { // vi tri thu 1
            for (i = 0; i < n; i++) array[i + insert] = array_copied[i]; // NOTE !!!

            for (i = 0; i < insert; i++) {
                cout << "Phan tu duoc chen thu " << i + 1 << ":";
                cin >> array[i];
            }

        } else if (location == n) { // vi tri cuoi cung
            for (i = n; i < n + insert; i++) {
                cout << "Phan tu duoc chen thu " << i + 1 << ":";
                cin >> array[i];
            }

        } else { // cac vi tri con lai, vd: chon vi tri 3 => 2 phan tu dung truoc no khong bi anh huong
            for (i = location - 1; i < n; i++) array[i + insert] = array_copied[i];

            for (i = location; i < location + insert; i++) {
                cout << "Phan tu duoc chen thu " << i + 1 << ":";
                cin >> array[i];
            }
        }

        cout << "Mang duoc nhap ban dau: ";
        for (i = 0; i < n; i++) cout << array_copied[i] << " ";
        cout << "\nMang sau khi duoc chen: ";
        for (i = 0; i < n + insert; i++) cout << array[i] << " ";

        if (location > 1 && location < n + insert) { // dat for vao if duoi day DE TRANH "Mang sau khi duoc chen: " in ra so
            missions:
            for (i = 0; i < n + insert; i++) {
                for (l = i; l < n + insert; l++) {
                    if (flag == 0) { // Sap xep tang dan
                        if (array[i] > array[l]) {
                            swap = array[i];
                            array[i] = array[l];
                            array[l] = swap;
                        }
                    } else { // Kiem tra phan tu xuat hien bao nhieu lan (sau khi sap xep tang dan)
                        if (array[i] == array[l]) {
                            if (l == n + insert - 1) {
                                counter++;
                                goto skip;
                            } else { // l = [0; n + insert - 2]
                                counter++;
                                same = array[i];
                            }
                        } else { // 2 != 3
                            if (counter <= 1) {
                                counter = 0;
                                continue;
                            } else goto skip; // counter = 2
                        }
                    }
                }
            }

            cout << "\nThu tu tang dan cac phan tu: ";
            for (i = 0; i < n + insert; i++) cout << array[i] << " ";

            if (counter < 1) { // Sau khi sap xep xong, counter = 0 va ta cho flag++
                flag++;
                goto missions;
            } else { // counter >= 1 khi va chi khi flag != 0
                skip:
                if (counter == 1) cout << "\nKhong ton tai so trung lap";
                else cout << "\nSo " << same << " xuat hien nhieu nhat: " << counter << " lan";
            }
        }

    } else if (request == 0) { // nguoi dung khong muon chen them cac phan tu moi
        cout << "Mang ban vua nhap bao gom nhung phan tu sau: ";
        for (i = 0; i < n; i++) cout << array[i] << " ";
        cout << "\nMang duoc dao nguoc thanh: ";
        for (i = n - 1; i >= 0; i--) cout << array[i] << " ";

    } else {
        cout << "So ban nhap khong phu hop. Moi ban nhap lai =>";
        goto request_retype;
    }

    cout << "\nBan co muon kiem tra lai chuong trinh voi mang khac ? (0 - Khong / 1 - Co) =>";
    do {
        cin >> l;

        if (l == 0) {
            cout << "Cam on ban da su dung chuong trinh\n";
            system("pause");
        } else if (l == 1) {
            goto again;
        } else cout << "So ban nhap khong phu hop. Moi ban nhap lai =>";

    } while (l < 0 || l > 1);

    return 0;
}
