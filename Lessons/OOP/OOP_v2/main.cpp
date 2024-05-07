#include <iostream>

using namespace std;

class divNum {
private:
    int n;
    int* arr;

public:
    divNum(int);
    divNum(const divNum&);
    void update(int, int);
    int get(int);
};

divNum::divNum(int n) {
    this->n = n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = 0;
}

divNum::divNum(const divNum& new_obj) {
    n = new_obj.n;
    arr = new int(n);
    for (int i = 0; i < n; ++i) arr[i] = new_obj.arr[i];
}

void divNum::update(int pos, int val) {
    arr[pos] = val;
}

int divNum::get(int pos) {
    return arr[pos];
}

int main() {
    divNum ps2(5), ps3(ps2);

    ps2.update(2, 100);
    cout << ps3.get(2);
    return 0;
}