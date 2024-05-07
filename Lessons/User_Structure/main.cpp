#include <iostream>
#include "string"
using namespace std;

/*struct abc {
    string a;
    int b;
    char c;
    ...
};

 * Trong C, ta can goi trong ham main: struct abc a;

 * Trong C++, typedef <old_data_type> <new_data_type>; => typedef dung de tranh bi loi ben C compiler
   vd: typedef struct {...} sinhvien sv; or typedef struct {...} sv;
   => Trong ham main c++, ta goi sv sv1, sv2; (tuong duong int b, string c, ...)
   or sv sv1 = {"abc", "cde", 19, 2003}; // {ho va ten, dia chi, tuoi, nam sinh}
   sv1.ten = "abc";
   sv1.tuoi = 19;
   sv2.ten;
   sv2.tuoi;
*/

typedef struct {
    string name;
    string sex;
    unsigned int age;
    string address;
} student;

int main() {
    student sv[10]; // sv1, sv2, sv3, sv4, sv5 => nen khai bao nhu nay de tranh tran bo nho stack
    string elements[] = {"Ho va ten", "Gioi tinh", "Tuoi", "Dia chi"};
    int i, m = 0;

    for (i = 0; i < 5; i++) {
        cout << "Nhap vao thong tin cua sinh vien thu " << i + 1 << ":\n";
        cout << "Ho va ten:";
        getline(cin, sv[i].name);
        cout << "Gioi tinh:";
        getline(cin, sv[i].sex);
        cout << "Tuoi:";
        cin >> sv[i].age;
        cout << "Dia chi:";
        cin.ignore(100, '\n');
        getline(cin, sv[i].address);
    }

    cout << "Sinh vien =>";
    for (i = 0; i < 5; i++) cout << "\tThu " << i + 1;
    for (i = 0; i < 4; i++) {
        cout << "\n" << elements[i] << ":";
        m++;
        for (int l = 0; l < 5; l++) {
            cout << "\t";
            if (m == 1) cout << sv[i].name;
            else if (m == 2) cout << sv[i].sex;
            else if (m == 3) cout << sv[i].age;
            else cout << sv[i].address;
        }
    }

    return 0;
}
