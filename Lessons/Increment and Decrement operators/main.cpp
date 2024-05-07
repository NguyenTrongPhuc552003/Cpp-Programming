#include <iostream>
using namespace std;

int main() {
    int n, i, type;
    int m = 0;

    check_again:
    cout << "Kiem tra so nguyen to tu 1 - n\nNhap vao n: ";
    cin >> n; // 4

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            m++; // Check bao nhieu so uoc
        }
    }

    if (m == 2) {
        cout << "Day la so nguyen to";
    } else {
        cout << "Day khong la so nguyen to";
    }

    cout << "\nBan co muon kiem tra them so khac ? (0 - Khong / 1 - Co): ";
    cin >> type;

    if (type == 1) {
        m = 0;
        goto check_again;
    } else {
        cout << "Cam on ban da su dung chuong trinh";
    }

    return 0;
}
