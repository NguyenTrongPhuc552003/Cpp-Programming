#include <iostream>
using namespace std;

int main() {
    short num;

    cout << "Moi ban nhap tu ban phim (0 - 3): ";
    cin >> num;

    switch (num) {
        case 0: cout << "Ban vua nhap so 0";
            break;
        case 1: cout << "Ban vua nhap so 1";
            break;
        case 2: cout << "Ban vua nhap so 2";
            break;
        case 3: cout << "Ban vua nhap so 3";
            break;
        default: cout << "Ban nhap sai cmnr";
    }

    return 0;
}
