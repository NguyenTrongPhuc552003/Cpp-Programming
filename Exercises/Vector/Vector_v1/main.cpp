#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int is_number(const string& data) {
    for (char i : data) {
        if (i < '0' || i > '9') return false;
    }
    return stoi(data);
}

void sortVector_increase(vector <int>& data) {
    for (int i = 0; i != data.size() - 1; i++) {
        for (int n = i + 1; n < data.size(); n++) {
            if (data[i] > data[n]) {
                int temp = data[i];
                data[i] = data[n];
                data[n] = temp;
            }
        }
    }
    cout << "Cac phan tu vector duoc sap xep tang dan:";
    for (auto& i : data) cout << ' ' << i;
    cout << endl;
}

void squareVector_numbers(vector <int>& vecMain, vector <int>& vecBranch) { // 0 1 2 3 4 ... 9 10
    for (auto& i : vecMain) { // 9 = 3 * 3
        for (int n = 0; n <= i; n++) {
            if (pow(n, 2) == i) vecBranch.push_back(i);
        }
    }
    cout << "Cac so chinh phuong trong vector nhanh moi:";
    for (auto& i : vecBranch) cout << ' ' << i;
    cout << endl;
}

void primeVector_numbers(vector <int>& vecMain, vector <int>& vecBranch) {
    int primeCounter = 0;

    for (auto& i : vecMain) {
        for (int l = 1; l <= i; l++) {
            if (i % l == 0) primeCounter++;
        }
        if (primeCounter == 2) vecBranch.push_back(i);
        primeCounter = 0;
    }
    cout << "Cac so nguyen to trong vector nhanh moi:";
    for (auto& i : vecBranch) cout << ' ' << i;
    cout << endl;
}

void removeBranch_fromMain(vector <int>& vecMain, vector <int>& vecBranch1, vector <int>& vecBranch2) {
    bool again = true;

    next:
    for (int i  = 0; i < vecMain.size(); i++) {
        if (again) {
            for (auto& g : vecBranch1) {
                if (vecMain[i] == g) vecMain.erase(vecMain.begin() + i);
            }
        } else {
            for (auto& h : vecBranch2) {
                if (vecMain[i] == h) vecMain.erase(vecMain.begin() + i);
            }
        }
    }
    if (again) {
        again = false;
        goto next;
    } else {
        cout << "Vector goc sau khi xu li:";
        for (auto& i : vecMain) cout << ' ' << i;
        cout << endl;
    }
}

int main() {
    vector <int> array, branchSquare, branchPrime;
    string input;

    re_input:
    cout << "Nhap vao cac so nguyen (nhap '/' => end type)\n>";
    while (getline(cin, input) && input != "/") {
        if (!is_number(input)) {
            cout << "Yeu cau chi nhap so hoac '/'. Moi ban nhap lai !\n";
            goto re_input;
        } else {
            array.push_back(is_number(input));
        }
        for (auto& i : array) cout << '\"' << i << "\" ";
        cout << '>';
    }
    sortVector_increase(array); // sap xep cac phan tu trong vector array tang dan
    squareVector_numbers(array, branchSquare); // tim va gan so chinh phuong len vector branchSquare
    primeVector_numbers(array, branchPrime); // tim va gan so nguyen to len vector branchPrime
    removeBranch_fromMain(array, branchSquare, branchPrime); // loai bo cac nhanh ra khoi vector goc
    return 0;
}
