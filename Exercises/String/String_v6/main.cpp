#include <iostream>
#include "string"
using namespace std;

string check_math(string data, const string& feature, int position) {
    string get_number, single_number;
    string numbers[] = {"mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};
    int i, m, number_pos, number_total;
    int amount = position, number_counter = 0, restart = 0;
    bool flag = true, check = true, after = true;

    number_total = sizeof(numbers) / sizeof(numbers[0]); // co tat ca 10 so, tu 1 - 10
    again:
    get_number = data.substr(restart, amount); // hai muoi mot, nam muoi tram, muoi chin nhan hai
    if (!after) get_number.push_back(' ');
    for (i = 0; i < get_number.length(); i++) {
        if (get_number[i] != ' ') {
            number_counter++;
            if (flag) {
                number_pos = i;
                flag = false;
            }
        } else {
            single_number = get_number.substr(number_pos, number_counter);
            for (m = 0; m < number_total; m++) {
                if (single_number == numbers[m] || single_number == "lam") { // #5: ... muoi lam
                    check = false;
                    break;
                }
            }
            if (check) return "ERROR"; // ket thuc for, khong co bat ki so nao thoa man => return true
            number_counter = 0;
            flag = true;
            check = true;
        }
    }
    if (after) {
        restart = position + feature.length() + 1;
        amount = data.length() - restart;
        after = false;
        goto again;
    }
    return data;
}

string text_processor(int data) {
    string number_found, numbers[] = {" Mot", " Hai", " Ba", " Bon", " Nam", " Sau", " Bay", " Tam", " Chin", " Muoi"};
    int number_saved, number_length = 0;

    number_saved = data;
    while (number_saved > 0) { // tim do dai cua data
        number_saved /= 10;
        number_length++;
    }

    switch (number_length) {
        case 1: // 0 - 9
            if (data == 0) number_found = " Khong";
            else number_found = numbers[data - 1];
            break;

        case 2: // 10 - 99
            if (data / 10 == 1) number_found = numbers[9];
            else number_found = numbers[(data / 10) - 1] + numbers[9];
            if (data % 10 != 0) {
                if (data % 10 == 5) number_found += numbers[4];
                else number_found += numbers[(data % 10) - 1];
            }
            break;

        case 3: // 100 - 999, vd: 105, 115, 120
            number_found = numbers[(data / 100) - 1] + " Tram";
            if (data / 10 % 10 != 0) {
                if (data / 10 % 10 == 1) number_found += numbers[9];
                else number_found += numbers[(data / 10 % 10) - 1] + numbers[9];
                if (data % 10 != 0) {
                    if (data % 10 == 5) number_found += numbers[4];
                    else number_found += numbers[(data % 10) - 1];
                }
            } else {
                if (data % 10 != 0) {
                    if (data % 10 == 5) number_found += " Le" + numbers[4];
                    else number_found += " Le" + numbers[(data % 10) - 1];
                }
            }
            break;

        default: // 1000 - 9801, vd: 1005, 1015, 1105, 1114
            number_found = numbers[(data / 1000) - 1] + " Nghin";
            if (data / 100 % 10 == 0) number_found += " Khong Tram";
            else number_found += numbers[(data / 100 % 10) - 1] + " Tram";
            if (data / 10 % 10 == 0) {
                if (data % 10 != 0) number_found += " Le" + numbers[(data % 10) - 1];
            } else {
                if (data / 10 % 10 == 1) number_found += numbers[9];
                else number_found += numbers[(data / 10 % 10) - 1] + numbers[9];
                if (data % 10 != 0) {
                    if (data % 10 == 5) number_found += numbers[4];
                    else number_found += numbers[(data % 10) - 1];
                }
            }
    }
    return number_found;
}

void text_numberic_results(string data, const string& feature, int position) {
    string get_number, numbers[] = {"mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};
    int i, m, number_pos, number_total;
    int number_counter = 0, restart = 0, amount = position, a = 0, b = 0, check_numberTen = 0;
    bool after = true, flag = true, other = true;

    number_total = sizeof(numbers) / sizeof(numbers[0]); // co tat ca 10 so, tu 1 - 10
    processNumber:
    get_number = data.substr(restart, amount); // mot, muoi hai, ba muoi, bon muoi lam
    if (!after) get_number.push_back(' ');

    for (i = 0; i < get_number.length(); i++) {
        if (get_number[i] != ' ') {
            number_counter++;
            if (flag) {
                number_pos = i;
                flag = false;
            }
        } else {
            for (m = 0; m < number_total; m++) { // do tim so
                if (numbers[m] == get_number.substr(number_pos, number_counter)) { // 2, 10
                    check_numberTen++;
                    if (other) {
                        if (check_numberTen == 2 && numbers[m] == "muoi") {
                            a *= 10;
                        } else {
                            a += m + 1;
                        }
                        if (i == get_number.length() - 1) {
                            check_numberTen = 0;
                            other = false;
                        }
                    } else {
                        if (check_numberTen == 2 && numbers[m] == "muoi") {
                            b *= 10;
                        } else {
                            b += m + 1;
                        }
                    }
                    break;
                }
            }
            number_counter = 0;
            flag = true;
        }
    }
    if (after) {
        restart = position + feature.length() + 1;
        amount = data.length() - restart;
        number_counter = 0;
        flag = true;
        after = false;
        goto processNumber;
    }

    for (i = 0; i < data.length(); i++) {
        if (data[i] != ' ') {
            if (flag) {
                data[i] = toupper(data[i]);
                flag = false;
            }
        } else {
            flag = true;
        }
    }
    cout << "Bang chu: " << data << " Bang";
    if (feature == "cong") {
        cout << text_processor(a + b);
    } else if (feature == "tru") {
        cout << text_processor(a - b);
    } else if (feature == "nhan") {
        cout << text_processor(a * b);
    } else {
        cout << text_processor(int(a / b));
    }
    cout << "\nBang so: ";
    if (feature == "cong") {
        cout << a << " + " << b << " = " << a + b;
    } else if (feature == "tru") {
        cout << a << " - " << b << " = " << a - b;
    } else if (feature == "nhan") {
        cout << a << " * " << b << " = " << a * b;
    } else {
        cout << a << " / " << b << " = " << int(a / b);
    }
}

int main() {
    string calculate, please = ". Moi ban nhap lai !\n";
    string accept, calculattion_pass, functions[] = {"cong", "tru", "nhan", "chia"};
    int i, l, function_pos;
    int function_total = sizeof(functions) / sizeof(functions[0]), function_exist = 4;

    check_other:
    cout << "Nhap vao mot phep tinh toan (gia tri khong lon hon 100), vd: mot cong mot\nNhap o day:";
    getline(cin, calculate);

    if (calculate.empty()) { // kiem tra du lieu dau vao
        cout << "Ban chua nhap du lieu" << please;
        goto check_other;
    } else {
        for (i = 0; i < calculate.length(); i++) {
            if (calculate[i] == ' ') { // kiem tra spam dau cach
                if (calculate[i + 1] == ' ') {
                    cout << "Khong duoc nhap 2 dau cach lien tiep" << please;
                    goto check_other;
                }
                if (i == 0 || i == calculate.length() - 1) {
                    cout << "Khong duoc nhap dau cach vao vi tri dau tien / cuoi cung" << please;
                    goto check_other;
                }
            }
            calculate[i] = tolower(calculate[i]); // doi ve chu cai thuong
        }
        for (i = 0; i < function_total; i++) { // kiem tra phep tinh co ton tai hay khong
            function_pos = calculate.find(functions[i], 0);
            if (function_pos < 0 || function_pos >= calculate.length()) {
                function_exist--;
            } else {
                accept = functions[i];
                break; // ton tai 1/4 phep tinh
            }
        }
    }

    if (function_exist == 0) {
        cout << "Ban nhap thieu 1 trong 4 phep tinh hoac chua nhap phep tinh nao" << please;
        function_exist = 4;
        goto check_other;
    } else {
        calculattion_pass = check_math(calculate, accept, function_pos);
        if (calculattion_pass == "ERROR") {
            cout << "Gia tri / Phep tinh ban nhap bi loi" << please;
            goto check_other;
        } else {
            text_numberic_results(calculattion_pass, accept, function_pos);
        }
    }
    retype:
    cout << "\nBan co muon kiem tra lai chuong trinh voi phep tinh khac ? (0 - Khong / 1 - Co) =>";
    cin >> l;
    switch (l) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            cin.ignore(100, '\n');
            function_exist = 4;
            goto check_other;
        default:
            cout << "Gia tri ban nhap khong phu hop" << please;
            goto retype;
    }

    return 0;
}
