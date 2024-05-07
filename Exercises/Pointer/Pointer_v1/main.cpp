#include <iostream>
#include <string>
using namespace std;

bool checkForm(string data) {
    bool flag = true;

    again:
    for (int i = 0; i < data.length(); i++) {
        if (flag) { // kiem tra spam dau cach
            if (data[i] == ' ') {
                if (i == 0) {
                    return false; // dau cach o vi tri dau tien
                } else {
                    if (data[i + 1] == ' ') return false; // 2 dau cach lien tiep
                }
            }
        } else { // ky tu bat thuong
            if (data[i] < '0' || data[i] > '9') return false;
        }
    }
    if (flag) {
        flag = false;
        goto again;
    }
    return true;
}

void output_processor(string data[], int begin, int enough) {
    int transfer_num, *pointer;

    if (begin != enough) {
        transfer_num = stoi(data[begin]);
        pointer = &transfer_num;
        cout << *pointer << ' ';
        output_processor(data, begin + 1, enough);
    } else {
        cout << '\n';
    }
}

void arrayPointer_io(string data[], int element) {
    string *pointer = data;
    int count, start = 0;
    
    for (count = 0; count < element; count++) {
        retype:
        cout << "Nhap vao phan tu thu " << count + 1 << " ('/' => endLoop):";
        getline(cin, *(pointer + count));
        if (*(pointer + count) != "/") {
            if ((*(pointer + count)).empty()) {
                cout << "Ban chua nhap du lieu. Moi ban nhap lai !\n";
                goto retype;
            } else {
                if (!checkForm(*(pointer + count))) {
                    cout << "Ban nhap sai dinh dang cmnr. Moi ban nhap lai !\n";
                    goto retype;
                }
            }
        } else {
            *(pointer + count) = '\0';
            cout << "Mang gom cac phan tu sau: ";
            output_processor(data, start, count);
            break;
        }
    }
}

int main() {
    string array[100];
    int option, amount = sizeof(array) / sizeof(array[0]);

    other:
    cout << "Nhap xuat mang bang con tro !\n";
    arrayPointer_io(array, amount); // nhap xuat mang bang con tro

    error:
    cout << "Ban co muon kiem tra lai voi mang khac ? (0 - Khong / 1 - Co) =>";
    cin >> option;

    switch (option) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            goto other;
        default:
            cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !\n";
            goto error;
    }
    return 0;
}
