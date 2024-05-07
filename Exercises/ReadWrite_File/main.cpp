#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    char name[20];
    int age;
} student;

int main() {
    auto* mine = new student;
    char c, Data_path[] = "Data.bin";

    fstream com_f(Data_path, ios::in | ios::out);
    if (!com_f) {
        cout << "File error !\n";
        return 1;
    }
    cout << "Nhap vao ho va ten:";
    gets_s(mine->name);
    cout << "Nhap vao tuoi:";
    cin >> mine->age;
    com_f << reinterpret_cast<char*>(mine);
    com_f.seekp(0); // dat con tro file ve vi tri ban dau
    while (com_f.get(c)) {
        cout << c;
    }
    com_f.close();
    return 0;
}
