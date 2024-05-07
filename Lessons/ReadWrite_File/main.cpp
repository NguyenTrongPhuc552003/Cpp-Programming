#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * ios::in : mo file de doc
 * ios::out : mo file de ghi
 * ios::ate : mo file va dua con tro ve cuoi file
 * ios::app : mo file va dua con tro ve cuoi file, nhung du lieu moi ghi vao se duoc ghi tiep vao cuoi file
 * ios::trunc : mo file va xoa noi dung cu
 * ios::binary : mo file nhi phan
 * */

/*
 * get() : doc tung ky tu trong file
 * getline() : doc het 1 dong trong file (neu gioi han lai so luong phan tu can lay => failbit() = 1, tellg = -1, tellp = -1)
 * write(reinterpret_cast<char*>(file), sizeof(data)) : reinterpret_cast: copy vung nho 2 con tro
 * read(___________________________________________)
 * */

typedef struct information {
    string name;
    string sex;
    int age{};
    int height{};
    int weight{};
} infor;

/*
 * static_cast: ep kieu du lieu co moi lien he voi nhau
 * reinterpret_cast: nguoc lai voi static_cast, hoat dong tot voi con tro, thay doi so buoc nhay cua con tro (exp: struct => char)
 * EXP: struct* a = (struct)b => error; struct* a = reinterpret_cast<struct*>(&b) => OK
 * => chuyen dung cho huong doi tuong
 * */

/*
 * &(char abc) trong struct co van de giua chuoi va ky tu khi ta truy cap dia chi cua no
 * => de fix loi nay, ta ep kieu: static_cast<void*>(&struct.abc)
 * cac dia chi trong struct khong co dinh, de truy cap vao tung thuoc tinh trong struct ta truy cap nhu sau: *(&struct + 1) => con tro struct
 * => tuong tu nhu cach truy cap trong array[0], array[1], ...
 * nhung khi ta chuyen tu kdlieu nay -> kdlieu khac thi phai ep kieu de truct tro den dung gia tri thuoc tinh do
 * */

int main() {
    infor people[20]; // or infor people[20] = {{"NTPhuc", "Nam", 20, 176, 54}, {"VHNam", "Nam", 20, 180, 65}, ...};
    string element_output_file[] = {"Ho va ten", "Gioi tinh", "Do tuoi", "Chieu cao", "Can nang"};
    string name_p[] = {"NTPhuc", "VHNam", "PTPhong", "NHPhuc", "NTKiet"};
    string sex_p = "Nam";
    char receive_file;
    int age_p = 20;
    int height_p[] = {176, 180, 170, 170, 170};
    int weight_p[] = {54, 65, 55, 60, 57};
    int people_num = 5;

    for (int i = 0; i < people_num; i++) {
        people[i].name = name_p[i];
        people[i].sex = sex_p;
        people[i].age = age_p;
        people[i].height = height_p[i];
        people[i].weight = weight_p[i];
    }
    /*//DOC VA GHI
    fstream fp("book.txt", ios::in | ios::out | ios::ate); // or fstream fp; fp.open("book.txt", ios::out | ios::app);
    if (!fp) {
        cout << "File error !";
        return 1;
    }

    fp.close();*/

    // GHI FILE !
    ofstream writef; // khoi tao luong nhan du lieu va ghi vao file / or ofstream writef("boot.txt");
    writef.open("book.csv"); // or writef.open("C:\\writefs\\Trong_Phuc\\OneDrive - VNU-HCMUS\\Desktop\\book.txt");
    if (!writef) {
        cout << "Write file error !";
        return 1;
    }
    for (const auto& i : element_output_file) {
        writef << i << "\t\t";
    }
    writef << '\n';
    for (int i = 0; i < people_num; i++) {
        writef << people[i].name << "\t\t" << people[i].sex << "\t\t" << people[i].age << "\t\t" << people[i].height << "\t\t" << people[i].weight << '\n';
    }
    writef.close();

    // DOC FILE !
    ifstream readf("book.csv");
    if (!readf) {
        cout << "Read file error !";
        return 1;
    }
    while (readf.get(receive_file)) { // or !readf.eof()
        cout << receive_file;
    }
    readf.close();
    system("pause");
    return 0;
}
