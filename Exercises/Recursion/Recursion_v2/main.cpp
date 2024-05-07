#include <iostream>
using namespace std;

int UCLN(int x, int y) { // thuat toan euclid
    if (y == 0) return x;
    return UCLN(y, x % y);;
}

int BCNN(int x, int y) { // tim max giua x va y, chia max cho x va y neu du 0 thi return max, nguoc lai tiep tuc BCNN(x, y) voi max++
    static int z = max(x, y);
    if (z % x == 0 && z % y == 0) {
        return z;
    } else {
        z++;
    }
    return BCNN(x, y);
}

int main() {
    int a, b;

    cout << "Tim UCLN va BCNN cua 2 so a, b\n";
    cout << "Nhap vao so a:";
    cin >> a;
    cout << "Nhap vao so b:";
    cin >> b;
    
    cout << "Uoc chung lon nhat cua 2 so a, b la: " << UCLN(a, b);
    cout << "\nBoi chung nho nhat cua 2 so a, b la: " << BCNN(a, b);

    return 0;
}
