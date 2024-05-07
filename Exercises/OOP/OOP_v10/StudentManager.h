//
// Created by Trong_Phuc on 18/05/2023.
//

#ifndef OOP_V10_STUDENTMANAGER_H
#define OOP_V10_STUDENTMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <malloc.h>
#include <iomanip>

//#define leftw(n, v) left << setw(n) << v
//#define rightw(n, v) right << setw(n) << v

using namespace std;

class StudentManager {
private:
    const char *acc_path = "Accounts.txt", *infor_path = "Information.txt"; // tranh dat ten "CMakeCache.txt"
    string usr_email, pass, com_io, please = ". Moi ban nhap lai !\n"; // sign in - sign up
    string elements[5] = {"ho va ten", "mssv", "lop", "khoa", "truong"};
    unsigned int fsignin_cnt; // do tim vi tri thong tin, tai khoan nguoi dung

    bool exist_account(string &user_name);
    char check_account(bool style, string &data);
    static char check_information(int &style, string &data);
    static string standardize_name(string &data);
    void input_account(bool sign_type);
    void input_information();
    void output_information();

public:
    int option_menu = 0;
    string hi_usr();
    void forget_password();
    friend istream &operator >> (istream &new_in, StudentManager *data);
    friend ostream &operator << (ostream &new_out, StudentManager *data);
};

bool StudentManager::exist_account(string &user_name) {
    ifstream dataDownload(acc_path);
    if (!dataDownload) {
        cout << "This file \"" << acc_path << "\" is corrupted !\n";
    } else {
        if (dataDownload.bad() || dataDownload.fail()) {
            cout << "An error occured during reading !\n";
        } else {
            while (getline(dataDownload, com_io)) { // check su trung lap email
                if (com_io.substr(0, com_io.find(' ')) == user_name) return true;
            }
        }
        dataDownload.close();
    }
    return false;
}

char StudentManager::check_account(bool style, string &data) { // style: 0 - user_email / 1 - pass
    size_t a_email = 0, b_email;
    bool upper_c = false, punct_c = false, digit_c = false;

    if (style) {
        if (data.length() < 5) {
            return '1'; // user_email chua dat do dai toi thieu
        } else {
            for (auto &i: data) { // check so luong '@'
                if (i == '@') a_email++;
            }
            if (a_email > 1) { // email chi chua 1 '@'
                return '2';
            } else if (a_email == 1) {
                a_email = data.find('@'); // '@': forward lookup
                b_email = data.rfind('.');
                if (a_email + b_email == SIZE_MAX) {
                    return '3'; // data khong chua 2 ky tu nay
                } else {
                    if (a_email > b_email) return '4'; // sau '@' khong co '.'
                }
                for (int i = 0; i < data.length(); i++) {
                    if (i == 0 || i == data.length() - 1) {
                        if (data[i] == '@' || data[i] == '.') return '5'; // '@' & '.' nam o vi tri dau hoac cuoi
                    } else {
                        if ((data[i] == '@' && data[i + 1] == '.') ||
                            (data[i] == '.' && data[i + 1] == '@'))
                            return '6'; // '@ & '.' nam lien ke nhau
                    }
                }
            } else { // DAY LA USER_NAME
                for (auto &i: data) {
                    if (ispunct(i)) return '8'; // user_name khong duoc chua ky tu dac biet
                }
            }
            if (exist_account(data)) return '7'; // user_email bi trung lap
            else return 'b'; // khong tim thay user_email
        }
    } else { // mat khau
        for (auto &i: data) {
            if (i == ' ') return 'a'; // khong duoc phep chua dau cach
            if (isupper(i) && !upper_c) upper_c = true; // toggling state only 1
            if (ispunct(i) && !punct_c) punct_c = true;
            if (isdigit(i) && !digit_c) digit_c = true;
        }
        if (!(upper_c && punct_c && digit_c)) return '9'; // toi thieu 3 dieu kien
    }
    return '0';
}

char StudentManager::check_information(int &style, string &data) {
    for (auto &i: data) {
        switch (style) {
            case 0: // ho va ten
            case 3: // khoa
                if (!isalpha(i) && !isblank(i)) return '1';
                break;
            case 1: // mssv
                if (!isdigit(i) || data.length() != 8) return '2';
                break;
            default: // lop, truong
                if (ispunct(i)) return '3';
        }
    }
    return '0';
}

string StudentManager::standardize_name(string &data) {
    string processed_name, pre_pcs;
    unsigned int dcut_size = 0, dcut_pos;
    bool lock_posCut = true;

    if (data.find(' ') != SIZE_MAX) { // co dau cach trong data
        for (int i = 0; i < data.length(); i++) { // a  b c     d
            if (!isblank(i)) {
                if (lock_posCut) {
                    dcut_pos = i;
                    lock_posCut = false;
                }
                dcut_size++;
            } else {
                if (!lock_posCut) {
                    pre_pcs = data.substr(dcut_pos, dcut_size);
                    pre_pcs[0] = static_cast<char>(toupper(pre_pcs[0])); // viet hoa chu cai dau tien
                    processed_name += pre_pcs + ' ';
                    dcut_size = 0;
                    lock_posCut = true;
                }
            }
        }
        processed_name.pop_back(); // xoa ky tu ' ' o vi tri cuoi cung
    } else {
        return data;
    }
    return processed_name;
}

void StudentManager::input_account(bool sign_type) {
    size_t blank_pos;
    unsigned int signin_pos = 0, overfail_signin = 0, overfail_option;
    bool valid_acc = false, overfail_flag = true, just_signup;

    resign:
    cout << (sign_type ? "DANG KY" : "DANG NHAP") << " TAI KHOAN\n";
    if (overfail_signin >= 3 && !sign_type) { // dang nhap sai qua 3 lan
        do {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            cout << "Ban da nhap sai toi " << overfail_signin << " lan, tiep tuc hay thoat ? (0 - Tiep tuc / !0 - Thoat):";
            cin >> overfail_option;
            if (cin.fail()) cout << "Ban nhap sai kieu du lieu" << please;
        } while (cin.fail());
        if (overfail_option != 0) {
            usr_email.clear();
            overfail_flag = false;
            goto quit_overfail;
        }
    }
    do {
        cout << "Nhap vao ten nguoi dung / email (standard_email: a@b.c):";
        getline(cin, usr_email);
        if (usr_email.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            just_signup = true;
            if (check_account(true, usr_email) != '0' && sign_type) {
                switch (check_account(true, usr_email)) {
                    case '1':
                        cout << "email chua dat do dai toi thieu\n";
                        break;
                    case '2':
                        cout << "email chi cho phep 1 '@'\n";
                        break;
                    case '3':
                        cout << "email phai chua toi thieu 2 ky tu '@' va '.'\n";
                        break;
                    case '4':
                        cout << "sau '@' bat buoc phai co '.'\n";
                        break;
                    case '5':
                        cout << "'@' & '.' khong duoc nam o vi tri dau hoac cuoi email\n";
                        break;
                    case '6':
                        cout << "'@' & '.' khong duoc nam lien ke nhau\n";
                        break;
                    case '7':
                        cout << "user_email nay da duoc su dung\n";
                        break;
                    default: // user_name
                        cout << "user_name khong duoc chua ky tu dac biet\n";
                }
                just_signup = false;
            }
        }
    } while (usr_email.empty() || !just_signup); // chi xet phan dang ki
    do {
        cout << "Nhap vao mat khau (toi thieu 1 ky tu: in hoa, dac biet, con so):";
        getline(cin, pass);
        if (pass.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            just_signup = true;
            if (check_account(false, pass) != '0' && sign_type) {
                if (check_account(false, pass) == '9') cout << "Mat khau chua du cac dieu kien tren" << please;
                else cout << "Mat khau khong cho phep dau cach" << please;
                just_signup = false;
            }
        }
    } while (pass.empty() || !just_signup);

    quit_overfail:
    if (sign_type) { // sign up
        ofstream data_upload(acc_path, ios::app);
        if (!data_upload) {
            cout << "This file \"" << acc_path << "\" is corrupted !\n";
        } else {
            if (data_upload.bad() || data_upload.fail()) {
                cout << "An error occured during writing !\n";
            } else {
                data_upload << usr_email << ' ' << pass << endl;
                cout << "Dang ky tai khoan thanh cong !\n";
            }
            data_upload.close();
        }
    } else { // sign in
        if (overfail_flag) { // check so lan dang nhap that bai
            ifstream data_download(acc_path);
            if (!data_download) {
                cout << "This file \"" << acc_path << "\" is corrupted !\n";
            } else {
                if (data_download.bad() || data_download.fail()) {
                    cout << "An error occured during reading !\n";
                } else {
                    while (getline(data_download, com_io)) {
                        signin_pos++;
                        blank_pos = com_io.find(' ');
                        if (blank_pos != SIZE_MAX && usr_email == com_io.substr(0, blank_pos) &&
                            pass == com_io.substr(blank_pos + 1, com_io.length() - blank_pos)) {
                            fsignin_cnt = signin_pos;
                            valid_acc = true;
                            break;
                        }
                    }
                    system("cls");
                    if (valid_acc) {
                        cout << "Dang nhap tai khoan thanh cong !\n";
                    } else {
                        cout << "Ten tai khoan hoac Mat khau khong dung" << please;
                        overfail_signin++;
                        goto resign;
                    }
                }
                data_download.close();
            }
        }
    }
}

void StudentManager::input_information() {
    char* elements_input[sizeof(elements) / sizeof(elements[0])] = {nullptr};
    bool infor_process = false, error_dym = false;
    ofstream data_upload(infor_path);

    input_account(true); // sign up
    cout << "NHAP VAO THONG TIN CA NHAN\n";
    infor_io:
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        if (!infor_process) {
            do {
                cout << "Nhap vao " << elements[i] << " cua ban:";
                getline(cin, com_io);
                if (com_io.empty()) {
                    cout << "Ban chua nhap du lieu" << please;
                } else {
                    if (check_information(i, com_io) != '0') {
                        if (check_information(i, com_io) == '1') cout << "Ho va ten, chi cho phep ky tu Alphabet (ngoai tru ' ')";
                        else if (check_information(i, com_io) == '2') cout << "MSSV chi cho phep 8 chu so";
                        else cout << "Lop, truong khong cho phep ky tu dac biet";
                        cout << please;
                    }
                }
            } while (com_io.empty() || check_information(i, com_io) != '0');
            elements_input[i] = (char*)malloc((com_io.length() + 1) * sizeof(char));
            if (elements_input[i] == nullptr) {
                cout << "Du lieu dau vao \"" << com_io << "\" vuot gioi han memory cho phep.\n";
                error_dym = true;
                break;
            } else {
                if (i == 0) com_io = standardize_name(com_io); // chuan hoa cai ten
                snprintf(elements_input[i], com_io.length() + 1, "%s", com_io.c_str()); // cap phat thanh cong
            }
        } else { // bat dau qua trinh ghi du lieu vao Information.txt
            if (!data_upload) {
                cout << "This file \"" << infor_path << "\" is corrupted !\n";
                break;
            } else {
                if (data_upload.bad() || data_upload.fail()) {
                    cout << "An error occured during reading !\n";
                    break;
                } else {
                    data_upload << elements_input[i] << ',';
                    if (i == sizeof(elements) / sizeof(elements[0]) - 1) data_upload << endl;
                }
                data_upload.close();
            }
        }
    }
    if (!infor_process && !error_dym) {
        infor_process = true;
        goto infor_io;
    }
    for (auto& i : elements_input) free(i);
}

void StudentManager::output_information() {
    unsigned int foutput_cnt = 0, forder = 0, felement_scroll = 0, fcut_length = 0, fcut_pos, option;
    bool fonce_pos = true;

    ifstream data_download(infor_path);
    if (!data_download) {
        cout << "This file \"" << infor_path << "\" is corrupted !\n";
    } else {
        if (usr_email.empty() && option_menu != 1) {
            cout << "Ban chua dang nhap tai khoan\n";
        } else {
            if (data_download.bad() || data_download.fail()) {
                cout << "An error occured during reading !\n";
            } else {
                do { // lua chon in thong tin ca nhan / toan bo csdl
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Ban muon truy xuat thong tin ca nhan hay toan bo CSDL (0 - Ca nhan / 1 - Toan bo):";
                    cin >> option;
                    if (cin.fail()) {
                        cout << "Ban nhap sai kieu du lieu" << please;
                    } else {
                        if (option != 0 && option != 1) cout << "Gia tri ban nhap khong phu hop" << please;
                    }
                } while (cin.fail() || (option != 0 && option != 1));

                if (option == 0) cout << "THONG TIN CA NHAN\n";
                else cout << "THONG TIN TOAN BO\n";
                while (getline(data_download, com_io)) { // bat dau tim kiem va in theo option
                    if (option == 0) {
                        foutput_cnt++;
                        if (foutput_cnt == fsignin_cnt) {
                            for (auto& i : com_io) {
                                if (i != ',') {
                                    fcut_length++; // lay do dai chuoi can cat
                                    if (fonce_pos) { // lay vi tri can cat
                                        fcut_pos = felement_scroll;
                                        fonce_pos = false;
                                    }
                                } else {
                                    forder++;
                                    cout << "- ";
                                    switch (forder) {
                                        case 1:
                                            cout << "HO VA TEN: ";
                                            break;
                                        case 2:
                                            cout << "MSSV: ";
                                            break;
                                        case 3:
                                            cout << "LOP: ";
                                            break;
                                        case 4:
                                            cout << "KHOA: ";
                                            break;
                                        default:
                                            cout << "TRUONG: ";
                                    }
                                    cout << com_io.substr(fcut_pos, fcut_length) << endl;
                                    fcut_length = 0;
                                    fonce_pos = true;
                                }
                                felement_scroll++;
                            }
                            break;
                        }
                    } else {
                        // TIEP TUC O DAY
                        cout << com_io << endl;
                    }
                }
            }
        }
        data_download.close();
    }
}

string StudentManager::hi_usr() {
    return usr_email;
}

void StudentManager::forget_password() {
    do {
        cout << "Nhap vao ten nguoi dung / email (standard_email: a@b.c):";
        getline(cin, usr_email);
        if (usr_email.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            switch (check_account(true, usr_email)) {
                case '0': // nothing
                case '7': // tim thay ten tai khoan
                    break;
                case 'b':
                    cout << "Khong tim thay user_email nay\n";
                    break;
                case '1':
                    cout << "email chua dat do dai toi thieu\n";
                    break;
                case '2':
                    cout << "email chi cho phep 1 '@'\n";
                    break;
                case '3':
                    cout << "email phai chua toi thieu 2 ky tu '@' va '.'\n";
                    break;
                case '4':
                    cout << "sau '@' bat buoc phai co '.'\n";
                    break;
                case '5':
                    cout << "'@' & '.' khong duoc nam o vi tri dau hoac cuoi email\n";
                    break;
                case '6':
                    cout << "'@' & '.' khong duoc nam lien ke nhau\n";
                    break;
                default: // user_name
                    cout << "user_name khong duoc chua ky tu dac biet\n";
            }
        }
    } while (usr_email.empty() || check_account(true, usr_email) != '0' && check_account(true, usr_email) != '7');

    ifstream searchPass(acc_path);
    ofstream regenerateFile("Temp_Accounts.txt"); // tao file tam, sau day rename ve Accounts.txt (tranh dat ten "CMakeCache.txt")
    if (!searchPass || !regenerateFile) {
        cout << "This file \"" << acc_path << "\" is corrupted !\n";
    } else {
        if (searchPass.bad() || searchPass.fail()) {
            cout << "An error occured during reading !\n";
        } else {
            while (getline(searchPass, com_io)) {
                if (com_io.substr(0, com_io.find(' ')) == usr_email) { // tim thay user_email
                    do { // nhap vao mat khau moi
                        cout << "Nhap vao mat khau moi (toi thieu 1 ky tu: in hoa, dac biet, con so):";
                        getline(cin, pass);
                        if (pass.empty()) {
                            cout << "Ban chua nhap du lieu" << please;
                        } else {
                            if (check_account(false, pass) != '0') {
                                if (check_account(false, pass) == '9') cout << "Mat khau chua du cac dieu kien tren" << please;
                                else cout << "Mat khau khong cho phep dau cach" << please;
                            }
                        }
                    } while (pass.empty() || check_account(false, pass) != '0');
                    regenerateFile << usr_email << ' ' << pass << endl;
                } else {
                    regenerateFile << com_io << endl;
                }
            }
            searchPass.close(); // dong cac stream_file lai truoc khi xoa, doi ten
            regenerateFile.close();
            if (remove(acc_path) != 0) { // xoa file cu
                cout << "This file \"" << acc_path << "\" is not deleted !\n";
            } else {
                if (rename("Temp_Accounts.txt", acc_path) != 0) cout << "Error renaming file !\n";
                else cout << "Mat khau da duoc thay doi thanh cong !\n";
            }
        }
    }
}

istream &operator >> (istream &new_in, StudentManager *data) {
    if (data->option_menu == 0) data->input_information();
    else data->input_account(false);
    return new_in;
}

ostream &operator << (ostream &new_out, StudentManager *data) {
    data->output_information();
    return new_out;
}

#endif //OOP_V10_STUDENTMANAGER_H
