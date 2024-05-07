#include <iostream>

using namespace std;

typedef struct divNum {
    int deno{};
    int nume{};
} divNum;

istream& operator >> (istream& new_in, divNum& transfer_in) { // toan tu nhap
    static unsigned int n = 0;
    do {
        cout << "Nhap vao tu so thu " << ++n << ':';
        new_in >> transfer_in.deno;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            new_in.clear();
            new_in.ignore();
        }
    } while (new_in.fail());
    do {
        cout << "Nhap vao mau so thu " << n << ':';
        new_in >> transfer_in.nume;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            new_in.clear();
            new_in.ignore();
        } else {
            if (transfer_in.nume == 0) cout << "Mau so phai khac 0 !\n";
        }
    } while (new_in.fail() || transfer_in.nume == 0);
    return new_in;
}

ostream& operator << (ostream& new_out, divNum& transfer_out) { // toan tu xuat
    new_out << ((transfer_out.nume < 0) ? transfer_out.deno * (-1) : transfer_out.deno) << '/' << abs(transfer_out.nume);
    return new_out;
}

divNum operator + (divNum& data1, divNum& data2) { // + - * /
    divNum transfer_add;

    transfer_add.deno = data1.deno * data2.nume + data1.nume * data2.deno;
    transfer_add.nume = data1.nume * data2.nume;
    return transfer_add;
}

divNum operator - (divNum& data1, divNum& data2) {
    divNum transfer_sub;

    transfer_sub.deno = data1.deno * data2.nume - data1.nume * data2.deno;
    transfer_sub.nume = data1.nume * data2.nume;
    return transfer_sub;
}

divNum operator * (divNum& data1, divNum& data2) {
    divNum transfer_mul;

    transfer_mul.deno = data1.deno * data2.deno;
    transfer_mul.nume = data1.nume * data2.nume;
    return transfer_mul;
}

divNum operator / (divNum& data1, divNum& data2) {
    divNum transfer_div;

    transfer_div.deno = data2.nume * data1.deno;
    transfer_div.nume = data2.deno * data1.nume;
    return transfer_div;
}

divNum minimalist_fractions(divNum data) { // rut gon phan so
    int abs_deno = abs(data.deno), abs_nume = abs(data.nume);
    int abs_max = (abs_deno < abs_nume) ? abs_deno : abs_nume; // tim abs_max giua tu so va mau so

    for (int i = abs_max; i > 0; i--) {
        if (data.deno % i == 0 && data.nume % i == 0) {
            data.deno /= i;
            data.nume /= i;
        }
    }
    return data;
}

int main() {
    divNum num1, num2, result, mf_num;
    char calculations[] = {'+', '-', '*', '/'};
    int i, amount = sizeof(calculations) / sizeof(calculations[0]);

    while (true) {
        cout << "Chuong trinh tinh toan phan so !\nTiep tuc (!0 - Yes / 0 - No):";
        cin >> i;
        if (i) {
            do {
                cout << "Moi ban chon phep tinh:\n";
                for (i = 0; i < amount; i++) {
                    cout << i + 1 << "/ Phep tinh " << calculations[i] << ":\n";
                }
                cout << "Ban chon:";
                cin >> i;
                if (i < 0 || i >= amount) cout << "Khong ton tai phep tinh nay !\n";
            } while (i < 0 || i >= amount);
            cin >> num1 >> num2; // input
            switch (i) { // calculating
                case 0:
                    result = num1 + num2;
                    break;
                case 1:
                    result = num1 - num2;
                    break;
                case 2:
                    result = num1 * num2;
                    break;
                default:
                    result = num1 / num2;
            }
            cout << "Ket qua: " << result << endl;
            mf_num = minimalist_fractions(result);
            cout << "Toi gian: " << mf_num << endl;
        } else {
            cout << "Cam on ban da su dung chuong trinh !\n";
            break;
        }
    }
    return 0;
}
