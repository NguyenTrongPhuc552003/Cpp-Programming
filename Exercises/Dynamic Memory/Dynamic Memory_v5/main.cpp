#include <iostream>
#include "my_memory.h"

using namespace std;

int main() {
    char name[] = "Nguyen Trong Phuc", fac[30] = " HCMUS";

    cout << "Do dai cua " << name << " la: " << stlen(name);
    stcat(name, fac);
    cout << "\nSau khi ghep chuoi: " << name;
    stcpy(name, fac);
    cout << "\nSau khi sao chep (chong chap): " << name;
    return 0;
}
