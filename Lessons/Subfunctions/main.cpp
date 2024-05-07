#include <iostream>
#include "iomanip"
#include "cmath"
using namespace std;

void Basic_Equation (int number, float a, float b) {
    switch (number) {
        case 0:
            cout << "Phep cong: " << a << " + " << b << " = " << a + b;
            break;
        case 1:
            cout << "Phep tru: " << a << " - " << b << " = " << a - b;
            break;
        case 2:
            cout << "Phep nhan: " << a << " * " << b << " = " << a * b;
            break;
        default:
            cout << "Phep chia: " << a << " / " << b << " = " << setprecision(4) << a / b;
    }
}

void Check_soChinhPhuong_range5 (int n) {
    int flag = 0; // dat co hieu

    for (int m = n - 1; m > n - 6; m--) {
        if (m / sqrt(m) == int(sqrt(m)) && m != 1) {
            flag++;
            cout << "So " << m << " la so chinh phuong nho va gan nhat voi so " << n;
        }
    }
    if (flag == 0) cout << "Khong ton tai so chinh phuong trong pham vi 5 so be hon so " << n;
}

int main() {
    int n, swap = 0, arrays[100];
    float x, y;

    cout << "Chuong trinh tinh toan co ban / So thu 1 (+ - * /) So thu 2\n";
    cout << "Moi ban nhap tu ban phim phep tinh tuong ung\nPhep cong (0) / Phep tru (1)\nPhep nhan (2) / Phep chia(3)\n=>";
    cin >> n;
    cout << "Nhap vao so thu 1:";
    cin >> x;
    do {
        if (n == 3) cout << "Nhap vao so thu 2 (Phep chia yeu cau so chia phai khac 0):";
        else cout << "Nhap vao so thu 2:";
        cin >> y;
    } while (y == 0 && n == 3);

    Basic_Equation(n, x, y); // 4 phep toan co ban

    cout << "\nChuong trinh kiem tra so chinh phuong";
    cout << "\nBan muon kiem tra bao nhieu phan tu ? =>";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao so thu " << i + 1 << ":";
        cin >> arrays[i];
    }

    for (int i = 0; i < n; i++) if (swap < arrays[i]) swap = arrays[i]; // dat linh canh
    Check_soChinhPhuong_range5(swap);

    return 0;
}
