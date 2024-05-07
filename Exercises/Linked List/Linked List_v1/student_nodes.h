//
// Created by Trong_Phuc on 11/03/2023.
//

#ifndef LINKED_LIST_V1_STUDENT_NODES_H
#define LINKED_LIST_V1_STUDENT_NODES_H

#include <iostream>
#include "fstream"
#include "iomanip"
#include "chrono"
#include "thread"
#include "string"
#include "vector"
#include "list"

#define FLAG_RST 0
#define leftw(n, v) left << setw(n) << v
#define rightw(n, v) right << setw(n) << v

using namespace std;
using namespace this_thread;
using namespace chrono_literals;

class studentNodes {
private:
    list <unsigned int> id_store; // luu tru id
    list <string> name_store; // luu tru name
    list <unsigned int> sex_store; // luu tru gioi tinh
    list <string> date_store; // luu tru ngay thang nam sinh
    list <string> class_store; // luu tru lop hoc
    string retypePlease = "Vui long nhap lai !\n";
    string code_field[17] = {"MAT", "ITE", "PHY", "CHE", // code nganh HCMUS bao gom 17 khoa theo thu tu tren xuong o web: congthongtin
                             "BIO", "GEO", "ENV", "BIT",
                             "MAS", "ELC", "OCE", "ENT",
                             "NUT", "COM", "GET", "MED", "DAS"};
    string input_string; // input_data o dang string
    unsigned int input_int = 0; // input_data o dang int
    unsigned int menu_option = 0, nodes_exist = 0, codeField_amount = sizeof(code_field) / sizeof(code_field[0]);
    bool flag_saved = false;

protected:
    static unsigned int maxNodes(list <string> &data);
    template <typename list_type> bool same_check(list_type &data_in, list <list_type> &data_check);
    template <typename list_out> list_out output_nodes(list <list_out> &data, int &val);
    void notify_errorData();
    void modify_streamData(basic_ostream<char, char_traits<char>> &dataStream);
    static string standardizeName(string &data);

    bool check_id(unsigned int data);
    static bool check_name(const string& data);
    static bool check_date(const string& data);
    bool check_class(const string &data);

public:
    unsigned int flag_menu_option = 0;
    static void delay_list(unsigned int nodes_delaySecond) ;
    void init_menu();
    void input_id();
    void input_name();
    void input_sex();
    void input_date();
    void input_class();
    void output_infors();
    void output_sort();
    void backup_infors();
    void reset_io();
};

unsigned int studentNodes::maxNodes(list <string> &data) {
    unsigned int max_sizeNode = 0;

    for (auto& i : data) {
        if (i.size() > max_sizeNode) max_sizeNode = i.size();
    }
    return max_sizeNode;
}

template <typename list_type> bool studentNodes::same_check(list_type &data_in, list <list_type> &data_check) {
    if (!data_check.empty()) {
        for (auto& i : data_check) {
            if (data_in == i) return false;
        }
    }
    return true;
}

template <> unsigned int studentNodes::output_nodes(list <unsigned int> &data, int &val) { // FIX: In instantiation of function template specialization 'studentNodes::output_nodes<unsigned int>
    unsigned int counter = 0;

    for (auto& i : data) {
        if (val == counter) return i;
        counter++;
    }
    return 1;
}

template <> string studentNodes::output_nodes(list <string> &data, int &val) { // Link: https://stackoverflow.com/questions/4933056/how-do-i-explicitly-instantiate-a-template-function
    unsigned int counter = 0;

    for (auto& i : data) {
        if (val == counter) return i;
        counter++;
    }
    return "ERROR";
}

void studentNodes::notify_errorData() {
    cout << "Ban nhap sai kieu du lieu. " << retypePlease;
    cin.clear();
    cin.ignore();
}

void studentNodes::modify_streamData(basic_ostream <char, char_traits <char>> &dataStream) {
    dataStream << rightw((60 + maxNodes(name_store)) / 2 + 9, "THONG TIN SINH VIEN\n"); // can le giua
    dataStream << leftw(9, "MSSV") << leftw(maxNodes(name_store) + 2, "| HO VA TEN") << leftw(30, " | GIOI TINH (0 - NAM / !0 - NU)") << leftw(13, " | NGAY SINH") << leftw(6, " | LOP") << endl;
    for (int i = 0; i < (nodes_exist / 5); i++) {
        dataStream << leftw(9, output_nodes(id_store, i) << "| ");
        dataStream << leftw(maxNodes(name_store), output_nodes(name_store, i) << " | ");
        dataStream << leftw(29, output_nodes(sex_store, i) << " | ");
        dataStream << leftw(10, output_nodes(date_store, i) << " | ");
        dataStream << leftw(11, output_nodes(class_store, i)) << endl;
    }
}

string studentNodes::standardizeName(string &data) { // nGUYeN tRoNg PhUC
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != ' ') { // skip ' '
            if (i == 0 || data[i - 1] == ' ') data[i] = (char)toupper(data[i]);
            else data[i] = (char)tolower(data[i]);
        }
    }
    return data;
}

void studentNodes::delay_list(unsigned int nodes_delaySecond) {
    cout << "He thong dang xu li: ";
    while (nodes_delaySecond != 0) {
        sleep_for(1s); // delay 1s
        cout << "==";
        nodes_delaySecond--;
        if (nodes_delaySecond == 0) cout << endl;
    }
}

void studentNodes::init_menu() {
    retype_option:
    system("cls");
    cout << "Trinh quan li sinh vien HCMUS\n";
    cout << "- 0: Khoi tao thong tin\n";
    cout << "- 1: Truy xuat thong tin\n";
    cout << "- 2: Sap xep truong du lieu\n";
    cout << "- 3: Luu lai toan bo thong tin vua nhap\n";
    cout << "- 4: Thoat MENU\n";
    cout << "=>";
    cin >> menu_option;
    if (cin.fail()) {
        notify_errorData();
    } else {
        nodes_exist = id_store.size() + name_store.size() + sex_store.size() + date_store.size() + class_store.size(); // minimum = 5
        switch (menu_option) {
            case 0:
            case 1:
            case 2:
                if (menu_option != 0) {
                    if (!(nodes_exist % 5 == 0 && nodes_exist >= 5)) {
                        cout << "Hien tai chua co du lieu. Vui long bo sung them !\n";
                    } else {
                        if (flag_menu_option == 0 && !flag_saved) cout << "Ban chua sao luu du lieu vua nhap. Hay sao luu truoc khi tiep tuc !\n";
                    }
                    if (!(nodes_exist % 5 == 0 && nodes_exist >= 5) || (nodes_exist % 5 == 0 && nodes_exist >= 5 && flag_menu_option == 0 && !flag_saved)) {
                        sleep_for(1s);
                        goto retype_option;
                    }
                } else {
                    flag_saved = true;
                }
                system("cls");
                break;
            case 3:
                if (flag_menu_option == 0 && !flag_saved) {
                    cout << "Hien tai chua co du lieu. Vui long bo sung them !\n";
                    sleep_for(1s);
                    goto retype_option;
                }
                break;
            case 4:
                break;
            default:
                cout << "Khong ton tai gia tri nay. " << retypePlease;
                sleep_for(1s);
                goto retype_option;
        }
        flag_menu_option = menu_option;
    }
}

bool studentNodes::check_id(unsigned int data) { // 21 20 7 197 = 8
    unsigned int format_id = 0, academic_present = 22, data_copied = data, trainingSys;
    bool flag_codeField = false;

    while (data != 0) {
        format_id++;
        data /= 10;
    }
    if (format_id != 8) {
        return false;
    } else {
        if (data_copied / 1000000 > academic_present) {
            return false; // khoa hien tai dang la 2022
        } else {
            for (int i = 11; i < codeField_amount + 13; i++) { // 11 - 28
                if (i == data_copied / 10000 % 100 && i != 24) {
                    flag_codeField = true;
                    break;
                }
            }
            if (!flag_codeField) {
                return false;
            } else { // co ton tai codeClass
                trainingSys = data_copied % 10000 / 1000;
                if (trainingSys != 0 && trainingSys != 5 && trainingSys != 6 && trainingSys != 7) return false; // check he dao tao
            }
        }
    }
    return true;
}

bool studentNodes::check_name(const string &data) {
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == ' ') {
            if (i == 0) {
                return false; // vi tri dau tien phai khac dau cach
            } else {
                if (data[i + 1] == ' ') return false; // 2 dau cach lien ke nhau
            }
        } else {
            if (!isalpha(data[i])) return false;
        }
    }
    return true;
}

bool studentNodes::check_date(const string &data) {
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

bool studentNodes::check_class(const string &data) { // 21ELC_CLC3
    unsigned int academy_num, academy_present = 22;
    string academy_size = data.substr(0, 2); // 21
    string codeField_in = data.substr(2, 3); // ELC
    string mid_char = data.substr(5, 1); // '_'
    string element = data.substr(6, 3); // CLC or DTR
    string last_char = data.substr(9, 1); // 1 - 9
    unsigned int format_class = data.size(), standardizeField;
    bool flag_class = false;

    if (format_class != 10) {
        return false; // format chuan: 10 ky tu
    } else {
        for (auto& i : academy_size) {
            if (i < '0' || i > '9') return false;
        }
        academy_num = stoi(academy_size);
        if (academy_num < 10 || academy_num > academy_present) return false; // kiem tra khoa hien tai
        for (int i = 0; i < codeField_amount; i++) {
            if (code_field[i] == codeField_in) { // kiem tra code nganh dao tao
                if (i < 13) standardizeField = 11; // khong ton tai codeField 24
                else standardizeField = 12;
                if (i + standardizeField == id_store.back() / 10000 % 100) flag_class = true;
                break;
            }
        }
        if (!flag_class) return false;
        if (mid_char != "_") return false; // kiem tra dau '_'
        if (element != "CLC" && element != "DTR" && element != "TTI" && element != "VPH") return false; // kiem tra he dao tao
        if (last_char < "0" || last_char > "9") return false;
    }
    return true;
}

void studentNodes::input_id() {
    do {
        retype_id:
        cout << "Nhap vao MSSV cua ban (Vd: 21207197):";
        cin >> input_int;
        if (cin.fail()) {
            notify_errorData();
        } else {
            if (!check_id(input_int)) {
                cout << "Ban nhap chua dung dinh dang. " << retypePlease;
            } else {
                if (!same_check(input_int, id_store)) {
                    cout << "Ban vua nhap MSSV nay roi. " << retypePlease;
                    goto retype_id;
                } else {
                    id_store.push_back(input_int);
                    cin.ignore(100, '\n');
                }
            }
        }
    } while (cin.fail() || !check_id(input_int));
}

void studentNodes::input_name() {
    do {
        cout << "Nhap vao ho va ten cua ban:";
        getline(cin, input_string);
        if (input_string.empty()) {
            cout << "Ban chua nhap du lieu. " << retypePlease;
        } else {
            if (cin.fail()) {
                notify_errorData();
            } else {
                if (!check_name(input_string)) cout << "Ten nay chua ky tu dac biet. " << retypePlease;
                else name_store.push_back(standardizeName(input_string)); // chuan hoa ho va ten
            }
        }
    } while (input_string.empty() || cin.fail() || !check_name(input_string));
}

void studentNodes::input_sex() {
    do {
        cout << "Nhap vao gioi tinh cua ban (Nam - 0 / Nu - !0):";
        cin >> input_int;
        if (cin.fail()) {
            notify_errorData();
        } else {
            sex_store.push_back(input_int);
            cin.ignore(100, '\n');
        }
    } while (cin.fail());
}

void studentNodes::input_date() {
    do {
        retype_date:
        cout << "Nhap vao ngay thang nam sinh cua ban (dd/mm/yyyy):";
        getline(cin, input_string);
        if (input_string.empty()) {
            cout << "Ban chua nhap du lieu. " << retypePlease;
        } else {
            if (cin.fail()) {
                notify_errorData();
            } else {
                if (!check_date(input_string)) {
                    cout << "Ban nhap chua dung dinh dang hoac ngay sinh khong dung. " << retypePlease;
                } else {
                    if (!same_check(input_string, date_store)) {
                        cout << "Ban vua nhap ngay sinh nay roi. " << retypePlease;
                        goto retype_date;
                    } else {
                        date_store.push_back(input_string);
                    }
                }
            }
        }
    } while (input_string.empty() || cin.fail() || !check_date(input_string));
}

void studentNodes::input_class() {
    do {
        cout << "Nhap vao lop ban dang hoc (Vd: 21ELC_CLC3):";
        getline(cin, input_string);
        if (input_string.empty()) {
            cout << "Ban chua nhap du lieu. " << retypePlease;
        } else {
            if (cin.fail()) {
                notify_errorData();
            } else {
                if (!check_class(input_string)) cout << "Ban nhap chua dung dinh dang (hoac khac voi ID). " << retypePlease;
                else class_store.push_back(input_string);
            }
        }
    } while (input_string.empty() || cin.fail() || !check_class(input_string));
}

void studentNodes::output_infors() {
    modify_streamData(cout);
}

void studentNodes::output_sort() {
    int sort_option, sort_type;

    do {
        cout << "Ban muon sap xep theo thong tin nao ?\n";
        cout << "- 0: MSSV\n";
        cout << "- 1: Ho va ten\n";
        cout << "- 2: Gioi tinh\n";
        cout << "- 3: Ngay sinh\n";
        cout << "- 4: Lop\n=>";
        cin >> sort_option;
        if (cin.fail()) {
            notify_errorData();
        } else {
            if (sort_option < 0 || sort_option > 4) cout << "Lua chon khong hop le. " << retypePlease;
        }
    } while (cin.fail() || sort_option < 0 || sort_option > 4);
    do {
        cout << "Ban muon sap xep tang dan hay giam dan tu tren xuong (0 - Giam / !0 - Tang) =>";
        cin >> sort_type;
        if (cin.fail()) notify_errorData();
    } while (cin.fail());

    switch (sort_option) {
        case 0:
            if (sort_type == 0) id_store.sort(greater<unsigned int>());
            else id_store.sort();
            break;
        case 1:
            if (sort_type == 0) name_store.sort(greater<string>());
            else name_store.sort();
            break;
        case 2:
            if (sort_type == 0) sex_store.sort(greater<unsigned int>());
            else sex_store.sort();
            break;
        case 3:
            if (sort_type == 0) date_store.sort(greater<string>());
            else date_store.sort();
            break;
        default:
            if (sort_type == 0) class_store.sort(greater<string>());
            else class_store.sort();
    }
    output_infors();
}

void studentNodes::backup_infors() {
    string saved_streamfile = "Information_Student.txt";

    ofstream storedData(saved_streamfile);
    if (!storedData) {
        cout << "Loi dinh dang file. Khong the tai len !\n";
    } else {
        modify_streamData(storedData);
        cout << "Ban da sao luu thong tin thanh cong !\n";
        flag_saved = true;
    }
}

void studentNodes::reset_io() {
    menu_option = 0;
    nodes_exist = 0;
}

#endif //LINKED_LIST_V1_STUDENT_NODES_H
