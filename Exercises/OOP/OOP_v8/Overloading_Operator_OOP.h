//
// Created by Trong_Phuc on 16/03/2023.
//

#ifndef OOP_V8_OVERLOADING_OPERATOR_OOP_H
#define OOP_V8_OVERLOADING_OPERATOR_OOP_H

#include <iostream>

using namespace std;

class divNum {
public:
    divNum() = default;
    divNum(int deno, int nume) {
        this->deno = deno;
        this->nume = nume;
    }
    divNum operator + (divNum& data2) const { // loai bot tham so thu 1 (tranh tinh trang divNum + other)
        divNum transfer_add;

        transfer_add.deno = this->deno * data2.nume + data2.deno * this->nume;
        transfer_add.nume = this->nume * data2.nume;
        return transfer_add;
    }
    divNum operator - (divNum& data2) const {
        divNum transfer_sub;

        transfer_sub.deno = this->deno * data2.nume - data2.deno * this->nume;
        transfer_sub.nume = this->nume * data2.nume;
        return transfer_sub;
    }
    divNum operator * (divNum& data2) const {
        divNum transfer_mul;

        transfer_mul.deno = this->deno * data2.deno;
        transfer_mul.nume = this->nume * data2.nume;
        return transfer_mul;
    }
    divNum operator / (divNum& data2) const {
        divNum transfer_div;

        transfer_div.deno = data2.nume * this->deno;
        transfer_div.nume = data2.deno * this->nume;
        return transfer_div;
    }
    divNum& operator += (divNum& data2) {
        *this = *this + data2;
        return *this;
    }
    divNum& operator -= (divNum& data2) {
        *this = *this - data2;
        return *this;
    }
    divNum &operator ++ () { // ++ps
        this->deno += this->nume;
        return *this;
    }
    divNum operator ++ (int) { // ps++ (int => phan biet voi ++ps)
        divNum res(*this);

        ++(*this);
        return res;
    }
    divNum operator -- () { // --ps
        this->deno -= this->nume;
        return *this;
    }
    divNum operator -- (int) { // ps--
        divNum res(*this);

        --(*this);
        return res;
    }
    friend istream& operator >> (istream& new_in, divNum& data);
    friend ostream& operator << (ostream& new_out, divNum& data);

private:
    int deno{};
    int nume{};
};

istream& operator >> (istream& new_in, divNum& data) {
    do {
        cout << "Nhap vao tu so:";
        new_in >> data.deno;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu !\n";
            new_in.clear();
            new_in.ignore();
        }
    } while (new_in.fail());
    do {
        cout << "Nhap vao phan so:";
        new_in >> data.nume;
        if (new_in.fail()) {
            cout << "Ban nhap sai kieu du lieu !\n";
            new_in.clear();
            new_in.ignore();
        } else {
            if (data.nume == 0) cout << "Mau so phai khac 0 !\n";
        }
    } while (new_in.fail() || data.nume == 0);
    return new_in;
}

ostream &operator << (ostream &new_out, divNum &data) {
    new_out << data.deno << '/' << data.nume;
    return new_out;
}

#endif //OOP_V8_OVERLOADING_OPERATOR_OOP_H
