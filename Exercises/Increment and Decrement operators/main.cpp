#include <iostream>
using namespace std;

int main() {
    float n, l;
    float m = 1;
    int i = 0;

    cout << "Kiem tra so chinh phuong\n";
    retype: {
        cout << "Nhap vao so n:";
        cin >> n;
    }
    
    while (m <= n) { // Kiem tra so tu 1 - n
        if (n / m == m) { // Neu n / m = m (Vd: 81 / 9 = 9) thi chan lai
            cout << "Day la so chinh phuong: " << n << " = " << m << "^2\n";
            cout << "Ban co muon kiem tra them so khac ? (0 - Khong / 1 - Co): ";
            cin >> l;
            i++; // i = 1 dung cho dieu kien ben duoi "Day khong phai la ..."
            if (l != 0) {
                goto retype;
            } else {
                i = 1; // i = 1
                break;
            }
        }
        m++;
    }

    if (i != 1) {
        cout << "Day khong phai la so chinh phuong\nMoi ban nhap lai so khac !\n";
        m = 1; // Reset gia tri m
        goto retype;
    }

    return 0;
}
