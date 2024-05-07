#include <iostream>
#include "vector"

using namespace std;

// Overload Operator

istream& operator >> (istream& vtin, vector <int>& data) {
    int temp;

    if (vtin >> temp) data.push_back(temp);
    return vtin;
}

ostream& operator << (ostream& vtout, const vector <int>& data) {
    for (auto& i : data) cout << i << ' ';
    cout << endl;
    return vtout;
}

typedef struct {
    int nume;
    int deno;
} realNum;

istream& operator >> (istream& str_in, realNum& data) {
    cout << "Nhap vao tu so:";
    str_in >> data.deno;
    cout << "Nhap vao mau so:";
    str_in >> data.nume;
    return str_in;
}

ostream& operator << (ostream& str_out, realNum& data) {
    str_out << data.deno << '/' << data.nume;
    return str_out;
}

realNum operator + (realNum& data1, realNum& data2) {
    realNum transfer_out;

    transfer_out.deno = data1.deno * data2.nume + data1.nume * data2.deno;
    transfer_out.nume = data1.nume * data2.nume;
    return transfer_out;
}

template <class data_type> void my_swap(data_type &a, data_type &b) {
    data_type tmp = a;
    a = b;
    b = tmp;
}

int main() {
    string x = "Trong Phuc", y = "StrongFood";
    int a = 5, b = 2;

    my_swap(a, b);
    cout << a << " / " << b << endl;
    my_swap(x, y);
    cout << x << " / " << y;
    /*realNum myNum_A, myNum_B, result;

    cout << "Nhap vao phan so A (cach nhau boi ' '):\n";
    cin >> myNum_A;
    cout << "Nhap vao phan so B (cach nhau boi ' '):\n";
    cin >> myNum_B;
    result = myNum_A + myNum_B;
    cout << "Ket qua phep cong 2 phan so A va B: " << result;*/
    return 0;
}