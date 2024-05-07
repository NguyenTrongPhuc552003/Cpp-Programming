//
// Created by Trong_Phuc on 20/02/2023.
//

#ifndef OOP_V1_EXAMINATION_H
#define OOP_V1_EXAMINATION_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Student {
protected:
    vector <char> stateout;
    string namein, datein, idin, combicode, scores[9];
    string sciences[9] = {"Toan", "Van", "Anh", "Ly", "Hoa", "Sinh", "Su", "Dia", "GDCD"};
    string exam_combination[4] = {"+ A00", "+ B00", "+ C00", "+ D01"};
    unsigned int amountSub = sizeof(sciences) / sizeof(sciences[0]), amountCom = sizeof(exam_combination) / sizeof(exam_combination[0]);

private:
    static bool check_namein(const string& data);
    static bool check_datein(const string& data);
    static bool check_idin(const string& data);
    static bool check_subjects(const string& data, const int& subjects);

public:
    Student() {
        cout << "Cham diem va tra cuu diem thi cua ban\n";
    }
    void input_name();
    void input_date();
    void input_id();
    void input_marks();
    void output_infors();
};

bool Student::check_namein(const string& data) {
    for (unsigned char i : data) {
        if (!isalpha(i) && i != ' ') return false;
    }
    return true;
}

bool Student::check_datein(const string& data) { // 05/05/2003
    unsigned int posD = 0, posM = 3, sizeDM = 2, sizeY = 4, sizeFormat = 10;
    unsigned int AD = 0, d = 0, m = 0, y = 0;

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
    return true;
}

bool Student::check_idin(const string& data) { // 53008416 => (53: ma Hoi dong thi, 008416: SBD)
    string examCode[] = {"TN", "XH"}, states_path = "States.txt";
    string received_state;
    size_t posFile;
    unsigned int sizeFormat = 8, posState = 0, sizeState = 2;
    bool found = true;

    if (data.length() == sizeFormat) {
        ifstream searchState;
        searchState.open(states_path);
        if (searchState.is_open()) { // tim ma tinh/thanh pho
            while(getline(searchState, received_state)) {
                posFile = received_state.find(data.substr(posState, sizeState));
                if (posFile == string::npos) {
                    found = false;
                } else {
                    found = true;
                    break; // da tim thay
                }
            }
            if (!found) return false;
            else searchState.close();
        }
        for (auto& i : examCode) { // TN, XH
            if (data.substr(sizeState, sizeState) == i) {
                found = true;
                break;
            } else {
                found = false;
            }
        }
        if (!found) return false;
        for (auto& i : data.substr(sizeState * 2, sizeState * 2)) { // 0 - 9
            if (i < '0' || i > '9') return false;
        }
    } else {
        return false;
    }
    return true;
}

bool Student::check_subjects(const string& data, const int& subject) {
    switch (subject) {
        case 0: // Toan: 50c
            for (auto& i : data) {
                if (i < '0' || i > '9') return false;
            }
            if (stoi(data) > 50) return false;
            break;
        case 1: // Van: 10.0d
            if (data.length() == 4) {
                if (data != "10.0") return false;
            } else { // 7.8
                for (int i = 0; i < data.length(); i++) {
                    if (i != 1) {
                        if (data[i] < '0' || data[i] > '9') return false;
                    } else {
                        if (data[i] != '.') return false;
                    }
                }
            }
            break;
        default: // con lai: 40c
            for (auto& i : data) {
                if (i < '0' || i > '9') return false;
            }
            if (stoi(data) > 40) return false;
    }
    return true;
}

void Student::input_name() {
    do {
        cout << "Nhap vao ho va ten cua ban (thuoc Alphabet):";
        getline(cin, namein);
        if (!check_namein(namein)) cout << "Chi duoc nhap cac ky tu Alphabet !\n";
    } while (!check_namein(namein));
}

void Student::input_date() {
    do {
        cout << "Nhap vao ngay thang nam sinh cua ban (dd/mm/yyyy):";
        getline(cin, datein);
        if (!check_datein(datein)) cout << "Vui long nhap dung format va date (du 18 tuoi tro len) !\n";
    } while (!check_datein(datein));
}

void Student::input_id() {
    do {
        cout << "Nhap vao ma so sinh vien (Vd: 63TN1234)\n";
        cout << "- 63: Ma so tinh/thanh pho\n";
        cout << "- TN: Ma to hop thi (KHTN, KHXH)\n";
        cout << "- 1234: Ma so bao danh sinh vien tai cum thi\n";
        cout << "=>";
        getline(cin, idin);
        if (!check_idin(idin)) cout << "Nhap chua dung format hoac khong tim thay Tinh/Thanh pho !\n";
    } while (!check_idin(idin));
}

void Student::input_marks() {
    string foundState;
    string codeState = idin.substr(0, 2), states_path = "States.txt";
    ifstream outputState(states_path);

    cout << "Cum thi: So Giao duc va Dao tao ";
    while (getline(outputState, foundState)) { // do tim tung dong trong States.txt
        if (foundState.substr(0, 2) == codeState) {
            for (auto& g : foundState) {
                if ((g >= '0' && g <= '9') || g == ':' || g == '/') continue; // bo qua cac ky tu nay
                cout << g; // in ra console Tinh / Thanh pho
                stateout.push_back(g); // gan du lieu Tinh / Thanh pho vao bien stateout
            }
            break;
        }
    }
    combicode = idin.substr(2, 2); // gan To hop thi
    cout << "\nTo hop thi: KH" << idin.substr(2, 2) << ", bao gom: Toan - Van - Anh - ";
    if (combicode == "TN") cout << "Ly - Hoa - Sinh\n";
    else cout << "Su - Dia - GDCD\n";
    for (int i = 0; i < amountSub; i++) {
        if (combicode == "XH") {
            if (i > 2 && i < 6) continue;
        } else {
            if (i == 6) break;
        }
        do {
            cout << "Nhap vao so ";
            if (sciences[i] == "Van") {
                cout << "diem cua mon " << sciences[i] << " (10.0 hoac #.#):";
            } else {
                cout << "cau dung mon " << sciences[i];
                if (sciences[i] == "Toan") cout << " [0; 50]:";
                else cout << " [0; 40]:";
            }
            cin >> scores[i];
            if (scores[i].empty()) {
                break;
            } else {
                if (!check_subjects(scores[i], i)) cout << "Ban nhap sai dinh dang hoac khac gioi han so cau !\n";
            }
        } while (!check_subjects(scores[i], i));
    }
}

void Student::output_infors() {
    float scores_combination[9], averageSub = 0;
    int averageLoop = 3;

    system("cls");
    cout << "Thong tin thi sinh:";
    cout << "\n- Ho va ten: " << namein;
    cout << "\n- Ngay thang nam sinh: " << datein;
    cout << "\n- SBD: " << idin;
    cout << "\n- Cum thi: ";
    for (auto& i : stateout) cout << i;
    cout << "\n- Khoi thi: KH" << combicode;

    for (int i = 0; i < amountSub; i++) {
        if (i == 0) { // diem mon Toan
            scores_combination[i] = float(stoi(scores[i]) * 0.2);
            cout << "\n  + Mon " << sciences[i] << ": " << scores_combination[i] << "   ";
        } else if (i == 1) {
            scores_combination[i] = stof(scores[i]);
            cout << "+ Mon " << sciences[i] << ": " << scores_combination[i] << "   ";
        } else {
            if (combicode == "XH") {
                if (i > 2 && i < 6) continue;
            } else {
                if (i == 6) break;
            }
            scores_combination[i] = float(stoi(scores[i]) * 0.25);
            cout << "+ Mon " << sciences[i] << ": " << scores_combination[i] << "   ";
            if (i == 2) cout << "\n  ";
        }
    }
    cout << "\n- Diem TB cac mon thuoc to hop KH" << combicode << ": ";
    if (combicode == "XH") averageLoop = 6;
    for (int i = averageLoop; i < averageLoop + 3; i++) { // 3 4 5, 6 7 8
        averageSub += float(stoi(scores[i]) * 0.25);
    }
    cout << averageSub / 3.0 << endl;

    cout << "- Diem thi khoi:\n";
    for (int i = 0; i < amountCom; i++) {
        if (combicode == "TN") {
            if (i == 2) continue;
        } else {
            if (i == 0 || i == 1) continue;
        }
        averageSub = 0;
        cout << "  " << exam_combination[i] << ": ";
        for (int l = 0; l < amountSub; l++) {
            switch (i) {
                case 0: // Toan, Ly, Hoa
                    if (l == 0 || l == 3 || l == 4) averageSub += scores_combination[l];
                    break;
                case 1: // Toan, Hoa, Sinh
                    if (l == 0 || l == 4 || l == 5) averageSub += scores_combination[l];
                    break;
                case 2: // Van, Su, Dia
                    if (l == 1 || l == 6 || l == 7) averageSub += scores_combination[l];
                    break;
                default: // Toan, Van, Anh
                    if (l >= 0 && l <= 2) averageSub += scores_combination[l];
            }
        }
        cout << averageSub << endl;
    }
}
#endif //OOP_V1_EXAMINATION_H
