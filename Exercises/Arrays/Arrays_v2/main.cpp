#include <iostream>
using namespace std;

int main() {
    int array[100];
    int num_check, i, l, n, swap, same;
    int counter = 0, flag = 0;

    cout << "Chuong trinh sap xep cac phan tu theo thu tu tang dan\n";
    again:
    cout << "Ban muon kiem tra bao nhieu so ? =>";
    cin >> num_check;

    for (i = 0; i < num_check; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ":";
        cin >> array[i];
    }

    missions:
    for (i = 0; i < num_check; i++) {
        for (l = i; l < num_check; l++) {
            if (flag == 0) { // Sap xep tang dan
                if (array[i] > array[l]) {
                    swap = array[i];
                    array[i] = array[l];
                    array[l] = swap;
                }
            } else { // Kiem tra phan tu xuat hien bao nhieu lan (sau khi sap xep tang dan)
                if (array[i] == array[l]) { // Cho nay tui se giai thich sau neu khong hieu
                    if (l == num_check - 1) {
                        counter++;
                        goto skip;
                    } else { // l = [0; num_check - 2]
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

    cout << "Thu tu tang dan cac phan tu: ";
    for (i = 0; i < num_check; i++) cout << array[i] << " ";

    if (counter < 1) { // Sau khi sap xep xong, counter = 0 va ta cho flag++
        flag++;
        goto missions;
    } else { // counter >= 1 khi va chi khi flag != 0
        skip:
        if (counter == 1) cout << "\nKhong ton tai so trung lap";
        else cout << "\nSo " << same << " xuat hien nhieu nhat: " << counter << " lan";
    }

    error:
    cout << "\nBan co muon thuc hien lai chuong trinh khong ? (0 - Khong / 1 - Co) =>";
    cin >> n;

    switch(n) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh\n";
            system("pause");
            break;

        case 1:
            counter = 0;
            flag = 0;
            goto again;

        default:
            cout << "So ban vua nhap khong phu hop";
            goto error;
    }

    return 0;
}
