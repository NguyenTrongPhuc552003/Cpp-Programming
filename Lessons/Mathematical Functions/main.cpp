#include <iostream>
#include "cmath"
#include "iomanip" // or bits/stdc++.h => setprecision(int n), 'fixed': co dinh so thap phan sau dau phay
using namespace std;

int main() {
//    const float pi = 3.14; // const + dataType + variable
    float a, b, c, d;

    cout << "Cac ham so hoc\n";
    cout << "Nhap vao a:";
    cin >> a;
    cout << "Nhap vao b:";
    cin >> b;
    cout << "Nhap vao c:";
    cin >> c;
    cout << "Nhap vao d:";
    cin >> d;

    cout << "Ket qua a^b = " << pow(a, b) << endl; // luy thua
    cout << "Ket qua can bac 2 cua c = " << sqrt(c) << endl; // can bac 2
    cout << "Ket qua can bac d cua c = " << pow(c, 1 / (float)d) << endl; // can bac n
    cout << "Gia tri lon nhat giua a va b la " << max(a, b) << endl; // GTLN
    cout << "Gia tri nho nhat giua c va d la " << min(c, d) << endl; // GTNN
    if (a < 0) cout << "Gia tri tuyet doi cua a la " << abs(a) << endl; // Gia tri tuyet doi
    if (b < 0) cout << "Gia tri tuyet doi cua b la " << abs(b) << endl;
    cout << "Gia tri thap phan 2 so sau dau phay can bac 2 cua a la " << setprecision(2) << fixed << sqrt(a) << endl;
    cout << "So thap phan can bac d cua c lam tron thanh so nguyen la " << round(pow(c, 1 / (float)d)); // lam tro so thap phan => so nguyen

    return 0;
}
