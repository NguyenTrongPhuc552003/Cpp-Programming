#include <iostream>
#include <string>

using namespace std;

/*
 * isdigit('5')
 * isalpha('b')
 * isblank(' ')
 * ispunct('@')
 * islower('A')
 * isupper('a')
 * */

int main () {
    string names, names_compared;
    bool flag = true, lock = true;
    int i, e, pos, counter = 0;

    cout << "Nhap vao mot chuoi ten cach nhau boi dau cach: ";
    getline(cin, names); // phuc kiet nam phuc

    for (i = 0; i < names.length(); i++) names[i] = (char)tolower(names[i]); // chuyen ve chu thuong

    cout << "Ten bi trung lap trong chuoi: ";
    for (i = 0; i < names.length(); i++) {
        if (names[i] != ' ') {
            counter++; // dem so ky tu trong ten cu the
            if (flag) {
                e = i; // lay gia tri index tai ky tu dau tien
                flag = false;
            }
        } else {
            names_compared = names.substr(e, counter); // lay ra cai ten truoc dau cach
            // abc.rfind("abc", last_pos) // reverse_find: tim chuoi bat dau tu vi tri cuoi cung
            /* abc.find_first_of(const string& str, size_t pos = 0 || const char* s, size_t pos = 0 || const char* s, size_t pos, size_t n || char c, size_t pos = 0)
                  > pos: vi tri ky tu dau tien trong chuoi
                  > s: con tro duoc tro den mang cac ky tu
                  > c: ky tu tim kiem
                  return (first_char_pos != string::npos) ? first_char_pos : string::npos
            */
            /* abc.find_last_of(const string& str, size_t pos = npos || const char* s, size_t pos = npos || const char* s, size_t pos, size_t n || char c, size_t pos = npos)
                  > pos: vi tri ky tu chuoi cung trong chuoi
                  > s: con tro duoc tro den mang cac ky tu
                  > c: ky tu tim kiem
                  return (last_char_pos != string::npos) ? last_char_pos || string::npos
            */
            // abc.find_first_not_of(...)
            // abc.find_last_not_of(...)
            pos = (int)names.rfind(names_compared, i); // tim cai ten trong chuoi

            if (pos > i && pos < names.length()) {
                cout << names_compared;
                lock = false;
                break;
            } else { // tra ve vi tri ngoai khoang tren thi tiep tuc tim kiem
                flag = true;
                counter = 0;
            }
        }
    }
    if (lock) cout << "khong ton tai !";

    /*string hoten;
    char hoten_new[100];
    int i, m;
    bool flag = true;

    cout << "Nhap vao ho cua ban:";
    getline(cin, hoten); // nguyen Trong Phuc
    cout << "Ho va ten ban dau: " << hoten;

    for (i = 0; i < hoten.length(); i++) {
        if (hoten[i] != ' ') {
            if (flag) {
                hoten_new[i] = toupper(hoten[i]);
                flag = false;
                continue;
            }
            hoten_new[i] = tolower(hoten[i]);

        } else {
            hoten_new[i] = ' ';
            flag = true;
        }
    }

    // Ho ten da xu li
    cout << "\nHo va ten da xu li: ";
    for (m = 0; m < i; m++) cout << hoten_new[l];

    // Ho ten viet thuong
    cout << "\nHo va ten viet thuong: ";
    for (m = 0; m < i; m++) {
        hoten_new[m] = tolower(hoten[m]);
        cout << hoten_new[m];
    }

    // Ho ten viet hoa
    cout << "\nHo va ten viet hoa: ";
    for (m = 0; m < i; m++) {
        hoten_new[m] = toupper(hoten[m]);
        cout << hoten_new[m];
    }*/

    return 0;
}