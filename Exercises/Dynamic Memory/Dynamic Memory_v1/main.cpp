#include <iostream>
#include "malloc.h"

using namespace std;

int main() {
    int* number = nullptr;
    int* number_copied = nullptr;
    int n = 1; // khoi tao truoc 1 vung nho

    number = (int*)malloc(n * sizeof(int));
    if (number == nullptr) return 1;
    do {
        cout << "Nhap vao so nguyen thu " << n << " (cin.fail() => end_loop):";
        cin >> number[n - 1];
        if (cin.fail()) {
            n--;
            break;
        } else {
            n++;
            number_copied = number;
            number = (int*)realloc(number_copied,n * sizeof(int));
        }
    } while (!cin.fail());
    cout << "Cac phan tu ban vua nhap: ";
    for (int i = 0; i < n; i++) cout << number[i] << ' ';
    free(number);
    return 0;
}
