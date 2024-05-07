#include <iostream>
using namespace std;

int main() {
    int num;
    float a, b;
    string c = "Nhap a va b:\n";

    do {
        cout << "\nNhap vao tu ban phim tu 1 - 4: ";
        cin >> num;

        switch (num) {
            case 1:
                cout << "Phep cong: a + b\n" << c;
                cin >> a;
                cin >> b;
                cout << "Ket qua: " << a + b;
                break;

            case 2:
                cout << "Phep tru: a - b\n" << c;
                cin >> a;
                cin >> b;
                cout << "Ket qua: " << a - b;
                break;

            case 3:
                cout << "Phep nhan: a * b\n" << c;
                cin >> a;
                cin >> b;
                cout << "Ket qua: " << a * b;
                break;

            case 4:
                cout << "Phep chia: a / b (NOTE: So bi chia != 0)\n" << c;
                cin >> a;
                cin >> b;
                while (b == 0) { // Kiem tra b khac 0, vi b = 0 ra infinite value
                    cout << "Nhap lai b != 0: ";
                    cin >> b;
                }
                cout << "Ket qua: " << a / b;
                break;

            default:
                cout << "Moi ban nhap lai tu ban phim 1 - 4 !";
        }
    } while (num < 1 || num > 4); // Kiem tra dieu kien nhap tu ban phim 1 - 4

    return 0;
}
