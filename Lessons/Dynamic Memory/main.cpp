#include <iostream>
#include <string>
#include <memory.h>
//#include <cstdlib> // or malloc.h, tuy thuoc vao project yeu cau toc do truy xuat nhanh hay cham

using namespace std;

int main() {
    string name = "Nguyen Trong Phuc";
    size_t n = name.length();
    char* ptr = nullptr;
    char* cpy = nullptr;
    char* fnd = nullptr;
    char fnd_c = 'P';
    int cmp_val;

//    ptr = (int*)calloc(n, sizeof(int)); // Continuous Memory, 10 mieng banh mi (tu 10 o banh mi)
    ptr = (char*)malloc(n * sizeof(char)); // Memory Allocate, 1 o banh mi (co 10 phan)
    cpy = (char*)malloc(n * sizeof(char));
    if (ptr == nullptr || cpy == nullptr) return 1;

    /*MEMSET*/
    // 10 byte nhan value = 2 (0 - 255), size: so byte de sao chep |00000010|-|00000010|-|00000010|-|00000010|-... => ptr[0] != 2
    // de xuat: int (4 byte) => char (1 byte)
//    memset(ptr, '9', n); // 2: ascii = :)), de xuat: '2' va chi cho phep cac ki tu thuoc ascii do ta dang thao tac tren tung byte

    /*MEMCPY + MEMMOVE*/
    for (int i = 0; i <= n; i++) *(ptr + i) = name[i];
//    memcpy(cpy, ptr, n + 1); // when overlap happens then it just ignore it
    memmove(cpy, ptr, n + 1); // when overlap it start from first position
    for (int i = 0; i < n + 1; i++) cout << cpy[i];
    cout << endl;

    /*MEMCMP*/
    cmp_val = memcmp(ptr, cpy, n); // so sanh theo gia tri bang ma ascii
    if (cmp_val > 0) cout << ptr << " > " << cpy;
    else if (cmp_val == 0) cout << ptr << " = " << cpy;
    else cout << ptr << " < " << cpy;
    cout << endl;

    /*MEMCHR*/
    fnd = (char*)memchr(cpy, fnd_c, n);
    if (fnd != nullptr) cout << fnd << " was found in cpy";
    else cout << fnd_c << " was not found in cpy";

    free(ptr); // tuong tu delete[] ptr;
    free(cpy);
    free(fnd);
    return 0;
}
