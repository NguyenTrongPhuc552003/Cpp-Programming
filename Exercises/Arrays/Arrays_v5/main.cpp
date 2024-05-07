#include <iostream>
using namespace std;

int main() {
    int array[100], array_copied[100];
    int n, m, i, l;
    int neg = 0, pos = 0, f = 0;

    cout << "Chuong trinh chiet xuat phan tu am va duong";
    again:
    do {
        cout << "\nBan muon kiem tra bao nhieu phan tu ? =>";
        cin >> n;
        if (n <= 0) cout << "So phan tu nhap vao phai lon hon 0. Moi ban nhap lai !";
    } while (n <= 0);

    for (i = 0; i < n; i++) {
        cout << "Phan tu thu " << i + 1 << " :";
        cin >> array[i];
        array_copied[i] = array[i];
        if (array[i] < 0) neg++;
        else pos++;
    }

    a:
    for (i = 0; i < n - f; i++) { // tach so nguyen am o mang goc
        if (array[i] >= 0) {
            for (l = i; l < n; l++) array[l] = array[l + 1];
            f++;
            goto a;
        }
    }

    f = 0; // reset gia tri f ve 0

    b:
    for (i = 0; i < n - f; i++) { // tach so nguyen duong o mang sao chep
        if (array_copied[i] < 0) {
            for (l = i; l < n; l++) array_copied[l] = array_copied[l + 1];
            f++;
            goto b;
        }
    }

    cout << "Cac phan tu nguyen am bao gom: ";
    for (i = 0; i < neg; i++) cout << array[i] << " "; // mang so nguyen am

    cout << "\nCac phan tu nguyen duong bao gom: ";
    for (i = 0; i < pos; i++) cout << array_copied[i] << " "; // mang so nguyen duong

    retype:
    cout << "\nBan co muon nhap lai voi mang khac khong ? (0 - Khong / 1 - Co) =>";
    cin >> m;

    switch (m) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh\n";
            system("pause");
            break;

        case 1:
            pos = 0;
            neg = 0;
            goto again;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
