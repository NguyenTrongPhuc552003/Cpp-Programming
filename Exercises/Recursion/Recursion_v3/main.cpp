#include <iostream>
using namespace std;

void input_array(int array[], int max_array, int start_point) {
    int sum = 0;
    if (start_point < max_array) {
        cout << "Nhap vao phan tu thu " << start_point + 1 << ":";
        cin >> array[start_point];
        input_array(array, max_array, start_point + 1);
    } else {
        cout << "Mang goc bao gom cac phan tu sau: ";
        for (int i = 0; i < max_array; i++) {
            cout << array[i] << " ";
            sum += array[i];
        }
        cout << "\nTong cac gia tri trong mang la: " << sum;
    }
}

int main() {
    int array[1000], n, i = 0;

    cout << "Ban muon nhap vao mang bao nhieu phan tu ? =>";
    cin >> n;
    input_array(array, n, i);

    return 0;
}
