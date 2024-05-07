#include <iostream>
#include <iterator>
#include "forward_list"

using namespace std;

typedef struct {
    int deno;
    int nume;
} divNum;

istream &operator>>(istream &f_listin, forward_list<divNum> &data) {
    divNum process;

    do {
        cout << "Nhap vao tu so thu:";
        f_listin >> process.deno;
        if (f_listin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            f_listin.clear();
            f_listin.ignore();
        }
    } while (f_listin.fail());
    do {
        cout << "Nhap vao mau so thu:";
        f_listin >> process.nume;
        if (f_listin.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            f_listin.clear();
            f_listin.ignore();
        } else {
            if (process.nume == 0) cout << "Mau so phai khac 0 !\n";
        }
    } while (f_listin.fail() || process.nume == 0);
    data.push_front(process);
    return f_listin;
}

ostream &operator<<(ostream &f_listout, divNum &data) {
    f_listout << data.deno << '/' << data.nume;
    return f_listout;
}

bool negative_check(divNum &data) { // check phan so am
    if ((data.deno > 0 && data.nume > 0) || (data.deno < 0 && data.nume < 0)) return false;
    return true;
}

void div_Max(forward_list<divNum> data) { // a b c d e
    for (auto& i : data) {

    }
}

int main() {
    forward_list <divNum> myNum;
    unsigned int negative_counter = 0, amount = 3; // so luong phan so can nhap

    for (int i = 0; i < amount; i++) {
        cout << "Nhap vao phan so o node thu " << i + 1 << ":\n";
        cin >> myNum;
    }
    for (auto& i : myNum) {
        if (negative_check(i)) negative_counter++;
    }
    cout << "- Co tong cong " << negative_counter << " so am trong danh sach\n";
    cout << "- Phan so lon nhat va be nhat lan luot la: ";
    div_Max(myNum);
    return 0;
}
