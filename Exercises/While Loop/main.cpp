#include <iostream>
using namespace std;

int main() {
    int age;

    do {
        do {
            cout << "Hay nhap vao tuoi cua ban (0 - 100): ";
            cin >> age;
        } while (age > 100); // Kiem tra dieu kien > 100
    } while (age < 0 || age > 100); // Kiem tra dieu kien < 0

    if (age > 0 && age <= 18) cout << "Thieu nien"; // 0 - 18: thieu nien
    if (age > 18 && age <= 60) cout << "Trung nien"; // 19 - 60: trung nien
    if (age > 60 && age <= 100) cout << "Cao tuoi"; // 61 - 100: cao tuoi

    return 0;
}
