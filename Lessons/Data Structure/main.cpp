#include <iostream>

using namespace std;

int exponentiation(int num, int radix) { // 5^3
    if (radix < 2) {
        return num;
    } else {
        return num * exponentiation(num, radix - 1);
    }
}

int revNum = 0;

unsigned int reverse(int num) { // 12345
    if (num != 0) {
        int remainder = num % 10;
        revNum = revNum * 10 + remainder;
        reverse(num / 10);
    }
    return revNum;
}

int main() {
    int a, b, c;

    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Ban da nhap sai dinh dang. Vui long nhap lai !\n";
        }
        cout << "Nhap vao mot co so nguyen:";
        cin >> a;
    } while (cin.fail()); // nhap sai kieu du lieu dau vao
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Ban da nhap sai dinh dang. Vui long nhap lai !\n";
        }
        cout << "Nhap vao mot so mu nguyen:";
        cin >> b;
    } while (cin.fail()); // nhap sai kieu du lieu dau vao
    do {
        if (cin.fail() || !(c >= 1 && c <= 1000000)) {
            cin.clear();
            cin.ignore();
            cout << "Ban da nhap sai dinh dang. Vui long nhap lai !\n";
        }
        cout << "Nhap vao mot so nguyen duong (1 - 1.000.000):";
        cin >> c;
    } while (cin.fail() || !(c >= 1 && c <= 1000000)); // nhap sai kieu du lieu dau vao

    cout << "Luy thua co so " << a << " mu " << b << " la: " << exponentiation(a, b) << endl;
    cout << "Dao nguoc cua so " << c << " la: " << reverse(c);
    return 0;
}
