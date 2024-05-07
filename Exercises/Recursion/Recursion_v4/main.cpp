#include <iostream>
#include "string"
using namespace std;

unsigned int maxArray;
int best_number; // data[] => su dung du lieu da duoc sap xep, vd: 1 2 2 3 3 4 5 5 5 5 6 6
bool flag_io = false;

void inStr_outNum(string data[], int transfered_data[], unsigned int start_value, bool signal) {
    if (signal) {
        cout << "Nhap vao phan tu thu " << start_value + 1 << " (nhap '/' de ket thuc):";
        cin >> data[start_value];
        if (data[start_value] != "/") {
            inStr_outNum(data, transfered_data, start_value + 1, signal);
        } else {
            data[start_value] = data[start_value + 1]; // xoa ky tu '/'
            maxArray = start_value; // dung cho cac ham ben duoi
        }
    }
    if (start_value != 0) {
        transfered_data[start_value - 1] = stoi(data[start_value - 1]);
        inStr_outNum(data, transfered_data, start_value - 1, flag_io);
    }
}

void increment_soft(int data[], unsigned int element, unsigned int compare, unsigned int max, unsigned int point, bool flag) { // 5 4 3 2 1
    int temp;

    if (max != 0) {
        if (data[element] > data[compare]) {
            temp = data[element];
            data[element] = data[compare];
            data[compare] = temp;
        }
        if (compare == max - 1) {
            element++;
            compare = element;
            if (element == max - 1) {
                element = 0;
                max = 0;
            }
        }
        increment_soft(data, element, compare + 1, max, point, flag);
    } else {
        if (!flag) {
            cout << "Mang gom cac phan tu duoc sap xep: ";
            flag = true;
            increment_soft(data, element, compare, max, point, flag);
        } else {
            cout << data[element] << " ";
            if (point - 1 != 0) increment_soft(data, element + 1, compare, max, point - 1, flag);
        }
    }
}

void founded_most_appearNum(int data[], int best_appear, unsigned int amount, int start_value, int compare, int appear_counter) {
    if (amount != 0) {
        if (data[start_value] == data[compare]) {
            appear_counter++;
        } else {
            if (appear_counter >= best_appear) {
                best_appear = appear_counter;
                best_number = data[start_value];
            }
            if (compare == amount - 1 || compare > amount - 1) amount = 0;
            appear_counter = 1;
            start_value = compare;
            compare = start_value;
        }
        founded_most_appearNum(data, best_appear, amount, start_value, compare + 1, appear_counter);
    } else {
        cout << "\nMang chua phan tu '" << best_number << "' xuat hien nhieu nhat voi " << best_appear << " lan";
    }
}

int main() {
    string array[100];
    int numbers[100];
    int f, l, i = 0, m = 0, n = 0, e = 1;
    bool flag = true;

    check_other:
    // goi ham nay truoc de quy doi du lieu array => numbers
    inStr_outNum(array, numbers, i, flag);

    // ham tiep theo dung de sap xep tang dan cac phan tu trong numbers
    increment_soft(numbers, m, n, maxArray, maxArray, flag_io);

    // tim ra so xuat hien nhieu nhat va lon nhat
    founded_most_appearNum(numbers, e, maxArray, i, e, e);

    retype:
    cout << "\nBan co muon kiem tra lai voi mang khac ? (0 - Khong / 1 - Co) =>";
    cin >> f;
    switch (f) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            for (l = 0; l < 100; l++) {
                array[l] = '\0';
                numbers[l] = '\0';
            }
            goto check_other;
        default:
            cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
