#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

typedef struct {
    int nume; // tu so
    int deno; // mau so
} divNum;

istream &operator>>(istream &new_in, forward_list<divNum> &data_in) {
    divNum numIn;
    static unsigned int order = 0;
    bool flag;

    order++;
    do {
        flag = true;
        cout << "Nhap vao tu so thu " << order << ':';
        new_in >> numIn.nume;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            new_in.clear();
            new_in.ignore();
            flag = false;
        }
    } while (!flag);
    do {
        flag = true;
        cout << "Nhap vao mau so thu " << order << ':';
        new_in >> numIn.deno;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            new_in.clear();
            new_in.ignore();
            flag = false;
        } else {
            if (numIn.deno == 0) cout << "Mau so phai khac 0 !\n";
        }
    } while (!flag || numIn.deno == 0);
    data_in.emplace_front(numIn);
    return new_in;
}

void negative_counter(forward_list<divNum> &data) {
    unsigned int cnt = 0;
    bool flag = true;

    outputForwardList:
    for (auto& i: data) {
        if ((i.nume < 0 && i.deno > 0) || (i.nume > 0 && i.deno < 0)) {
            if (flag) cnt++;
            else cout << ((i.deno < 0) ? i.nume * (-1) : i.nume) << '/' << abs(i.deno) << ' ';
        }
    }
    if (flag) {
        cout << "- Co " << cnt << " so am trong DSLK_D nay ";
        if (cnt != 0) {
            cout << "(bao gom: ";
            flag = false;
            goto outputForwardList;
        } else {
            cout << endl;
        }
    } else {
        cout << "\b)\n";
    }
}

void compare_divnums(forward_list<divNum> data) { // 9/1 8/2 7/3 6/2 5/1 4/1 3/4
    divNum copiedDiv;
    int comMul = 1, foundDiv = 0, timesCnt = 0, comDeno;

    while (timesCnt != 4) {
        for (auto& i : data) {
            switch (timesCnt) {
                case 0: // tim mau so chung
                    comMul *= i.deno;
                    break;
                case 1: // quy dong mau so
                    i.nume *= comMul / i.deno;
                    break;
                case 2: // phan so lon nhat
                    if (foundDiv < i.nume) {
                        copiedDiv = i;
                        comDeno = comMul / i.deno;
                        foundDiv = i.nume;
                    }
                    break;
                default: // phan so nho nhat
                    if (foundDiv > i.nume) {
                        copiedDiv = i;
                        comDeno = comMul / i.deno;
                        foundDiv = i.nume;
                    }
            }
        }
        if (timesCnt == 2 || timesCnt == 3) {
            cout << "- Phan so ";
            if (timesCnt == 2) cout << "lon nhat";
            else cout << "nho nhat";
            cout << " trong DSLK_D la: " << ((copiedDiv.deno < 0) ? copiedDiv.nume * (-1) : copiedDiv.nume) / comDeno << '/' << abs(copiedDiv.deno) << ' ' << endl;
        }
        timesCnt++;
    }
}

int main() {
    forward_list <divNum> myNumber;
    unsigned int n = 0;

    do {
        cout << "Ban muon them vao DSLK_D bao nhieu phan so ? =>";
        cin >> n;
        if (n == 0) cout << "So luong phai khac 0. Moi ban nhap lai !\n";
    } while (n == 0);
    for (int i = 0; i < n; i++) cin >> myNumber;
    negative_counter(myNumber);
    compare_divnums(myNumber);
    return 0;
}
