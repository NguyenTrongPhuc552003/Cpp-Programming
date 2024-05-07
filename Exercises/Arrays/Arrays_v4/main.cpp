#include <iostream>
using namespace std;

int main() {
    int array[100];
    int n, i, l, del_pos, del_num;

    cout << "Chuong trinh xoa vi tri cua phan tu bat ki trong mang\n";
    again:
    do {
        cout << "Ban muon mang co bao nhieu phan tu ? =>";
        cin >> n;
        if (n <= 0) cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai\n";
    } while (n <= 0);

    for (i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << ":";
        cin >> array[i];
    }

    cout << "Hien tai co " << n << " vi tri" << " tu 1 - " << n << " tuong ung ";
    for (i = 0; i < n; i++) cout << array[i] << " ";

    do {
        cout << "\nBan muon xoa phan tu o vi tri thu may ? =>";
        cin >> del_pos;
        if (del_pos < 1 || del_pos > n) cout << "Vi tri ban chon khong ton tai. Moi ban nhap lai";
    } while (del_pos < 1 || del_pos > n);

    cout << "Hien tai co " << n - del_pos + 1 << " phan tu ban co the xoa";

    do {
        cout << "\nBan muon xoa bao nhieu phan tu tai vi tri thu " << del_pos << " ? =>";
        cin >> del_num; // nhap vao bao nhieu => infinite value hien thi bay nhieu (vd: 4 => ... # # # #)
        if (del_num <= 0 || del_num > (n - del_pos + 1)) cout << "Vuot qua so phan tu duoc phep xoa. Moi ban nhap lai";
    } while (del_num <= 0 || del_num > (n - del_pos + 1));

    cout << "Mang nhap ban dau gom: ";
    for (i = 0; i < n; i++) cout << array[i] << " ";

    cout << "\nMang sau khi xoa gom: ";
    for (i = 0; i < n; i++) {
        if (del_pos == i + 1) { // vi tri bat dau xoa
            for (i = del_pos - 1; i < n; i++) { // xu li xoa "bao nhieu phan tu"
                if (del_pos - 1 + del_num == n) goto skip; // array[n] = infinite value
                array[i] = array[del_pos - 1 + del_num];
                cout << array[i] << " ";
                del_num++;
            }
        } else cout << array[i] << " ";
    }

    skip:
    do {
        cout << "\nBan co muon chay lai chuong trinh khong ? (0 - Khong / 1 - Co) =>";
        cin >> l;

        if (l == 0) {
            cout << "Cam on ban da su dung chuong trinh\n";
            system("pause");
        } else if (l == 1) {
            goto again;
        } else cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai";

    } while (l != 0 && l != 1);

    return 0;
}
