#include <iostream>
#include <string>

using namespace std;

void abc(int array[], int amount) {
    int* ptr = array;
    cout << "Mang ban vua nhap:";
    for (int i = 0; i < amount; i++) cout << ' ' << *array[ptr + i];
}

int* absMax(int* array[], int amount) {
    int* maxNum = new int;
    *maxNum = 0;
    int i;

    for (i = 0; i < amount; i++) {
        if (*maxNum < abs(*array[i])) *maxNum = abs(*array[i]);
    }
    return maxNum;
}

int main() {
    int* num_transfer = new int[100];
    int i, n;

    cout << "Ban muon nhap vao bao nhieu phan tu ? =>";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Nhap vao phan tu thu " << i + 1 << ':';
        cin >> *(num_transfer + i);
    }
    abc(&num_transfer, n);
//    cout << "Gia tri tuyet doi lon nhat cua phan tu trong mang vua nhap la: " << absMax(&num_transfer, n);
    delete[] num_transfer;
    return 0;
}
