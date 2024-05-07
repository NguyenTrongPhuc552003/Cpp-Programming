#include <iostream>
using namespace std;

void SoNguyento (int x) {
    int m = 0;

    for (int i = 0; i <= x; i++) {
        for (int l = 1; l <= x; l++) {
            if (i % l == 0) m++;
        }
        if (m == 2) cout << i << " ";
        m = 0; // reset gia tri m ve 0 neu ko phat hien so nguyen to
    }
}

int main() {
    int n;

    cout << "Chuong trinh kiem tra cac so nguyen to nho hon n";
    retype:
    cout << "\nNhap vao n =>";
    cin >> n;

    if (n <= 1) {
        cout << "Khong ton tai so nguyen to trong khoang nay. MOi ban nhap lai !";
        goto retype;
    } else {
        cout << "Danh sach cac so nguyen to be hon hoac bang n: ";
        SoNguyento(n);
    }

    return 0;
}
