#include <iostream>
using namespace std;

int main() {
    int array_int[10];
    int i = 0, flag = 0;
    int m, n, l, g, ger_div;

    cout << "Chuong trinh kiem tra so nguyen to\n";
    retype:
    cout << "Ban muon kiem tra bao nhieu so ? (MIN: 1 / MAX: 10) =>";
    cin >> l;

    if (l == 1) { // Neu chi nhap 1 so
        cout << "Nhap vao so can kiem tra:";
        cin >> array_int[0];

    } else if (l > 1 && l <= 10) { // Nhap nhieu so
        while (i < l){
            cout << "Nhap vao so thu " << i + 1 << ":";
            cin >> array_int[i];
            i++;
        }

    } else { // Nhap ngoai khoang gia tri cho phep
        cout << "So khong phu hop. Moi ban nhap lai\n";
        goto retype;
    }

    for (m = 0; m < l; m++) { // Bat dau lay gia tri tu 10 so vua nhap
        ger_div = 0;

        for (n = 1; n <= array_int[m]; n++) { // Kiem tra so nguyen to co 2 uoc chung: 0 va chinh no
            if (array_int[m] % n == 0) ger_div++;
        }

        if (ger_div == 2) { // 2 uoc chung => liet ke cac so nguyen to
            if (flag == 0) {
                if (l == 1) {
                    cout << array_int[m] << " la so nguyen to";
                    goto skip;
                } else cout << "Cac so nguyen to: ";
                flag = 1;
            }
            cout << array_int[m] << " ";
        }
    }

    skip:
    do {
        cout << "\nBan co muon kiem tra lai so khac ? (0 - Khong / 1 - Co) =>";
        cin >> g;
    } while (g < 0 || g > 1);

    flag = 0; // tat co de nhap lai khau kiem tra so nguyen to

    if (g == 1) {
        i = 0;
        goto retype;
    } else cout << "Cam on ban da su dung chuong trinh";

    return 0;
}
