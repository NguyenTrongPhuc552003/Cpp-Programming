#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> array;
    int n, data = 0, option = 0, amount = 0;

    cout << "Nhap vao cac so nguyen cho mang (nhap 9999 => end type)\n>";
    while (cin >> data && data != 9999) {
        array.push_back(data);
        for (auto& i : array) cout << '\"' << i << "\" "; // liet ke cac phan tu vua nhap trong mang
//        for (auto h = array.begin(); h != array.end(); ++h) cout << '\"' << *h << "\" "; // hoac nhu nay
        cout << '>';
    }

    option_retype:
    cout << "Ban muon them hay xoa du lieu vua nhap ? (0 - Them / 1 - Xoa) =>";
    cin >> option;
    amount_retype:
    cout << "Ban muon ";
    if (option == 0) {
        cout << "them ";
    } else if (option == 1) {
        cout << "xoa ";
    } else {
        cout << "Gia tri ban vua nhap khong phu hop. Moi ban nhap lai !\n";
        goto option_retype;
    }
    cout << "bao nhieu phan tu ? =>";
    cin >> amount;
    if (amount <= 0 || amount > array.size()) {
        cout << "So luong ban vua nhap lon hon hoac nho hon kich thuoc cua mang hien tai.\n";
        cout << "Moi ban nhap lai !\n";
        goto amount_retype;
    }

    for (n = 0; n < amount; n++) {
        if (option == 0) {
            cout << "Nhap vao so thu " << n + 1 << ':';
            cin >> data;
            array.push_back(data);
        } else {
            array.pop_back();
        }
    }
    cout << "Mang sau khi xu li: ";
    for (auto& i : array) cout << '\"' << i << "\" ";
    return 0;
}
