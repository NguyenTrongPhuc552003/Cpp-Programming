#include <iostream>
#include "string"
using namespace std;

int length_integer(int number) { // tim do dai chu so
    int length = 0;
    while (number > 0) {
        length++;
        number /= 10;
    }
    return length;
}

int main() {
    string input = "10h9g5a4f16a12b3p", alphabet;
    int num, amount;
    int x_counter = 0, o_counter = 0;

    next:
    num = stoi(input); // lay gia tri dau tien trong chuoi
    amount = length_integer(num) + 1; // "+ 1" => xoa luon ky tu alphabet
    alphabet = input.substr(amount - 1, 1);

    if (num > 0 && num < 16) {
        if (x_counter <= o_counter) { // luot di dau tien la cua X
            if (alphabet >= "a" && alphabet <= "o") x_counter++;
        } else { // tiep theo la O
            if (alphabet >= "a" && alphabet <= "o") o_counter++;
        }
    }

    input.erase(0, amount); // xoa luot di dau tien de tiep tuc luot di moi
    if (input.length() != 0) goto next;

    cout << "So luot di cua X = " << x_counter;
    cout << "\nSo luot di cua O = " << o_counter;

    return 0;
}
