#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Hay nhap vao so bang cuu chuong: ";
    cin >> num;

    for (int i = 0; i < 10; i++) {
        cout << num << " * " << i + 1;
        cout << " = ";
        cout << num * (i + 1) << endl;
    }

    return 0;
}
