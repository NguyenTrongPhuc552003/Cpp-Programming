#include <iostream>
#include <malloc.h>
#include <fstream>
#include <iomanip>
#include <unistd.h>

#define leftw(n, v) left << setw(n) << v
//#define rightw(n, v) right << setw(n) << v

using namespace std;

typedef struct inforManager {
    char* name = nullptr;
    char* date = nullptr;
    char* sex = nullptr;
    char* faculty = nullptr;
    char* college = nullptr;
} dymStudent;

string lineConsole, filePath = "dymData.txt";

bool check_elements(unsigned int val, string &data) {
    unsigned int AD = 0, d = 0, m = 0, y = 0; // quy uoc chung moi khi kiem tra datein
    unsigned int posD = 0, posM = 3, sizeDM = 2, sizeY = 4, sizeFormat = 10;

    switch (val) {
        case 0: // ho va ten
        case 3: // khoa
        case 4: // truong
            for (auto &i : data) {
                if (i != ' ' && !isalpha(i)) return false;
            }
            break;
        case 1: // ngay thang nam sinh
            if (data.length() == sizeFormat) { // sizeof(date) phai bang 10
                for(int i = 0; i < data.length(); i++) { // kiem tra ngay thang nam
                    if (data[i] == '/') {
                        if (i == posD + sizeDM) {
                            d = stoi(data.substr(posD, sizeDM));
                            if (d > 31 || d <= 0) return false;
                        } else if (i == posM + sizeDM) {
                            m = stoi(data.substr(posM, sizeDM));
                            if (m > 12 || m <= 0) return false;
                        }
                    } else {
                        if (data[i] < '0' || data[i] > '9') return false;
                        if (i == data.length() - 1) y = stoi(data.substr(sizeDM + sizeY, sizeY));
                    }
                }
                if (y < 1800) { // nam sinh va nam hien tai phai tu 1800 tro len
                    return false;
                } else {
                    if (m == 4 || m == 6 || m == 9 || m == 11) { // nhung thang co ngay <= 30
                        if (d > 30) return false;
                    } else if (m == 2) { // thang co ngay bang 28 hoac 29
                        while (AD < y) AD += 4;
                        if (y == AD) {
                            if (d > 29) return false;
                        } else {
                            if (d > 28) return false;
                        }
                    }
                }
            } else {
                return false;
            }
            break;
        default: // gioi tinh
            if (data != "Nam" && data != "Nu") return false;
    }
    return true;
}

void dymIn_option(dymStudent &dymInput) {
    string input, please = "Moi ban nhap lai !\n";
    string elements[] = {"ho va ten (Alphabet)",
                         "ngay thang nam sinh (31/12/1800)",
                         "gioi tinh (Nam / Nu)",
                         "khoa (Alphabet)",
                         "truong (Alphabet)"};
    unsigned int amount = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < amount; i++) {
        do {
            cout << "Nhap vao " << elements[i] << " cua ban:";
            getline(cin, input);
            if (input == "\n") {
                cout << "Ban chua nhap du lieu. " << please;
            } else {
                if (!check_elements(i, input)) cout << "Ban nhap chua dung dinh dang. " << please;
            }
        } while (input == "\n" || !check_elements(i, input));

        switch (i) {
            case 0:
                dymInput.name = (char*)malloc((input.length() + 1) * sizeof(char));
                if (dymInput.name == nullptr) cout << "Du lieu dau vao vuot gioi han cho phep !\n";
                else snprintf(dymInput.name, input.length() + 1, "%s", input.c_str());
                break;
            case 1:
                dymInput.date = (char*)malloc((input.length() + 1) * sizeof(char));
                if (dymInput.date == nullptr) cout << "Du lieu dau vao vuot gioi han cho phep !\n";
                else snprintf(dymInput.date, input.length() + 1, "%s", input.c_str());
                break;
            case 2:
                dymInput.sex = (char*)malloc((input.length() + 1) * sizeof(char));
                if (dymInput.sex == nullptr) cout << "Du lieu dau vao vuot gioi han cho phep !\n";
                else snprintf(dymInput.sex, input.length() + 1, "%s", input.c_str());
                break;
            case 3:
                dymInput.faculty = (char*)malloc((input.length() + 1) * sizeof(char));
                if (dymInput.faculty == nullptr) cout << "Du lieu dau vao vuot gioi han cho phep !\n";
                else snprintf(dymInput.faculty, input.length() + 1, "%s", input.c_str());
                break;
            default:
                dymInput.college = (char*)malloc((input.length() + 1) * sizeof(char));
                if (dymInput.college == nullptr) cout << "Du lieu dau vao vuot gioi han cho phep !\n";
                else snprintf(dymInput.college, input.length() + 1, "%s", input.c_str());
        }
    }
}

void dymUp_option(dymStudent &dymUpload) {
    ofstream dataUpload(filePath);
    if (!dataUpload) {
        cout << "Failed to upload !\n";
    } else {
        dataUpload << leftw(21, "HO VA TEN:") << dymUpload.name << endl;
        dataUpload << leftw(21, "NGAY THANG NAM SINH: ") << dymUpload.date << endl;
        dataUpload << leftw(21, "GIOI TINH: ") << dymUpload.sex << endl;
        dataUpload << leftw(21, "KHOA: ") << dymUpload.faculty << endl;
        dataUpload << leftw(21, "TRUONG: ") << dymUpload.college << endl;
        cout << "Ban da sao luu du lieu thanh cong !\n";
    }
    dataUpload.close();
}

void dymDown_option() {
    ifstream dataDownload(filePath);
    if (!dataDownload) {
        cout << "Failed to download !\n";
    } else {
        dataDownload >> lineConsole[0];
        if (lineConsole[0] == '\0') {
            cout << "Hien chua co du lieu trong file !\n";
        } else {
            while (getline(dataDownload, lineConsole)) cout << lineConsole << endl;
        }
    }
    dataDownload.close();
}

int main() {
    dymStudent student;
    char myOption, please[] = ". Moi ban nhap lai !\n";
    bool dataFlag = false;

    student_manager:
    cout << "QUAN LI THONG TIN SINH VIEN\n";
    cout << "(0) - Nhap thong tin sinh vien\n";
    cout << "(1) - Luu thong tin sinh vien\n";
    cout << "(2) - Xuat thong tin sinh vien\n";
    cout << "(3) - Thoat chuong trinh\n";
    cout << "Lua chon cua ban =>";
    cin >> myOption;
    cin.ignore();

    if (myOption != '3') {
        system("cls");
        switch (myOption) {
            case '0':
                dymIn_option(student);
                dataFlag = true;
                break;
            case '1':
                if (!dataFlag) {
                    cout << "Ban chua nhap thong tin" << please;
                    sleep(2);
                } else {
                    dymUp_option(student);
                }
                break;
            case '2':
                dymDown_option();
                break;
            default:
                cout << "Gia tri ban nhap chua phu hop" << please;
                sleep(2);
        }
        goto student_manager;
    }
    free(student.name);
    free(student.date);
    free(student.sex);
    free(student.faculty);
    free(student.college);
    cout << "Cam on ban da su dung chuong trinh !\n";
    system("pause");
    return 0;
}
