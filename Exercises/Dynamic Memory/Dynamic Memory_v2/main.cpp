#include <iostream>
#include "malloc.h"

using namespace std;

bool check_id(unsigned int data) {
    unsigned int counter = 0;
    while (data != 0) {
        counter++;
        data /= 10;
    }
    if (counter != 8) return false;
    return true;
}

int main() {
    unsigned int* dym_id = nullptr;
    unsigned int* id_copied = nullptr;
    unsigned int n = 2, option; // cap phat san 2 o nho (n)

    dym_id = (unsigned int*)malloc(n * sizeof(unsigned int));
    realloc_label:
    if (dym_id == nullptr) return 1;
    for (static int i = 0; i < n; i++) {
        do {
            cout << "Nhap vao MSSV thu " << i + 1 << " (vd: 21207197):";
            cin >> dym_id[i];
            if (!check_id(dym_id[i])) cout << "MSSV khong hop le. Moi ban nhap lai !\n";
        } while (!check_id(dym_id[i]));
    }
    cout << "Ban co muon nhap tiep khong ? (0 - Khong / !0 - Co) =>";
    cin >> option;
    if (option != 0) { // sau moi lan nhap lai se tang them 2 o nho
        n += 2;
        id_copied = dym_id;
        dym_id = (unsigned int*)realloc(id_copied, n * sizeof(unsigned int));
        goto realloc_label;
    } else {
        cout << "Cam on ban da su dung chuong trinh !\n";
        system("pause");
        free(dym_id);
    }
    return 0;
}
