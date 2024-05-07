#include <iostream>
using namespace std;

void swapPointer(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    cout << "Sau khi doi cho:";
}

void checkAbs(int* x, int* y) {
    if (abs(*x) > abs(*y)) swapPointer(&(*x), &(*y)); // hoac swapPointer(x, y) vi x <=> &(*x)
    else cout << "Chua the doi cho:";
}

int main() {
    int a, b, option;

    other:
    cout << "Thuc hien doi 2 bien a va bien b\n";
    cout << "Nhap vao a:";
    cin >> a;
    cout << "Nhap vao b:";
    cin >> b;
    checkAbs(&a, &b);
    cout << " a = " << a;
    cout << " va b = " << b;

    error:
    cout << "Ban co muon kiem tra lai voi mang khac ? (0 - Khong / 1 - Co) =>";
    cin >> option;

    switch (option) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            goto other;
        default:
            cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !\n";
            goto error;
    }
    return 0;
}
