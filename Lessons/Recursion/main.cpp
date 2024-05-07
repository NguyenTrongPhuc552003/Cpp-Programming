#include <iostream>
using namespace std;

/* Fibonacci
 1 1 2 3 5 8 13 ... | khi pos = 1 hoac pos = 2 thi ket qua = 1, voi pos = 3 thi
 a + b = c f(n)     | chung ta khong biet ket qua. Tuy nhien, ket qua (pos = 3)
 1 + 0 = 1  1       | tuan theo quy luat ...
 0 + 1 = 1  2       |
 1 + 1 = 2  3       |
 1 + 2 = 3  4       |
 2 + 3 = 5  5       |
 3 + 5 = 8  6       |
 5 + 8 = 13 7*/

long long fibonacci(int position) {
    if (position == 1 || position == 2) {
        return 1;
    } else {
        return fibonacci(position - 1) + fibonacci(position - 2);
    }
}

int main() {
    int n;

    cout << "Nhap vao vi tri n trong day so Fibonacci:";
    cin >> n;
    cout << "So Fibonacci cua vi tri vua nhap la: " << fibonacci(n);

    return 0;
}
