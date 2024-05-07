//#include <iostream>
#include "FormatText.h"

//using namespace std;

int main() {
    string input;
    auto* edit = new Format;

    cout << "Nhap vao mot van ban bat ki:";
    getline(cin, input);
    cout << "Viet thuong: " << edit->tolower_all(input) << endl;
    cout << "Viet hoa: " << edit->toupper_all(input) << endl;
    cout << "In hoa chu cai dau tien: " << edit->upper_FirstChar(input);
    return 0;
}
