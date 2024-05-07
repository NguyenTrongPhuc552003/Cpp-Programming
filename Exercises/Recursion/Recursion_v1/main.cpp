#include <iostream>
using namespace std;

void reverseNum(unsigned long long data) { // 123456789
    if (data != 0) {
        cout << data % 10;
        reverseNum(data / 10);
    }
}

int main() {
    unsigned long long n;
    cout << "Nhap vao mot so nguyen duong n: ";
    cin >> n;
    cout << "Ket qua dao nguoc cua n la: ";
    reverseNum(n);
    return 0;
}
