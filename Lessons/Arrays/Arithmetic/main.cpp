#include <iostream>
#include "string"
using namespace std;

int main() {
    int n = 0;
    int arrays_num[100];
    string arrays[100];

    cout << "Nhap vao cac phan tu (Ket thuc boi dau '.')\n";
    for (int i = 0; i <= n; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ":";
        cin >> arrays[i];
        if (arrays[i] == ".") break;
        n++;
    }

    cout << "Mang ban vua nhap gom: ";
    for (int i = 0; i < n; i++) {
        arrays_num[i] = stoi(arrays[i]);
        cout << arrays_num[i] << " ";
    }
    cout << "\nMang ban vua nhap co: " << n << " phan tu";

    return 0;
}
