//
// Created by Trong_Phuc on 13/05/2023.
//

#ifndef FINAL_V5_LIBMNG_H
#define FINAL_V5_LIBMNG_H

#include <iostream>
#include <string>
#include <fstream>
#include "BookMng.h"

using namespace std;

class LibMng {
private:
    BookMng* myBook = new BookMng();
    string user = "\0", please = ". Moi ban nhap lai !\n", accs_mng = "Accounts_manager.txt", infors_mng = "Information_manager.txt";
    int i;

public:
    int sign_inup = 0;
    void main_userInterface();
    void input_account(int format);
    void output_account();
    void delete_accounts();
    void user_information();
};

void LibMng::main_userInterface() {
    resign_inup:
    if (cin.fail()) {
        cout << "Ban nhap sai kieu du lieu" << please;
        cin.clear();
        cin.ignore();
    }
    cout << "Welcome to StrongFood's Book Library !";
    cout << "\n0 - Dang nhap vao tai khoan ca nhan";
    cout << "\n1 - Dang ki tai khoan cho ban";
    cout << "\n2 - Xoa du lieu nhung Tai khoan da tao";
    cout << "\n3 - Xuat thong tin tai khoan nguoi dung";
    cout << "\n4 - Roi khoi giao dien dang nhap / dang ki tai khoan";
    cout << "\nLua chon cua ban la:";
    cin >> sign_inup;
    if (!cin.fail()) {
        switch (sign_inup) {
            case 0:
                input_account(0);
                break;
            case 1:
                input_account(1);
                break;
            case 2:
                delete_accounts();
                break;
            case 3:
                output_account();
                break;
            case 4:

                break;
            default:
                cout << "Gia tri ban nhap khong phu hop" << please;
        }
    }
    if (cin.fail() || (sign_inup >= 0 && sign_inup <= 3) || sign_inup < 0 || sign_inup > 4) goto resign_inup;
}

void LibMng::input_account(int format) {
    string input_inup, data_user, data_pass, data_before, file_detail;
    int find_user, find_pass, find_pos = 0;
    char checkFile;

    if (format == 0) {
        ifstream readf(accs_mng);
        readf >> checkFile;
        if (checkFile == '\0') {
            cout << "Ban chua co tai khoan. Moi ban dang ki tai khoan !\n";
            input_inup = "Tao ";
            format = 1;
        } else {
            input_inup = "Nhap vao ";
        }
    } else {
        input_inup = "Tao ";
    }
    cin.ignore(100, '\n');
    fix_account_inf:
    do {
        cout << input_inup + "ten nguoi dung:"; // ten nguoi dung
        getline(cin, data_user);
        if (data_user.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            if (myBook->check_spaceSpam(data_user) == "SPACE1") cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
            else if (myBook->check_spaceSpam(data_user) == "SPACE2") cout << "Khong duoc spam 2 dau cach lien tiep" << please;
            else break;
        }
    } while (data_user.empty() || myBook->check_spaceSpam(data_user) == "SPACE1" || myBook->check_spaceSpam(data_user) == "SPACE2");
    do {
        cout << input_inup + "mat khau:"; // mat khau
        getline(cin, data_pass);
        if (data_pass.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            if (myBook->check_spaceSpam(data_pass) == "SPACE1") {
                cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
            } else if (myBook->check_spaceSpam(data_pass) == "SPACE2") {
                cout << "Khong duoc spam 2 dau cach lien tiep" << please;
            } else {
                if (!myBook->check_pass(data_pass)) cout << "Toi thieu 1: chu cai in hoa, so 0 - 9, noneAlphabet. " << please;
            }
        }
    } while (data_pass.empty() || myBook->check_spaceSpam(data_pass) == "SPACE1" || myBook->check_spaceSpam(data_pass) == "SPACE2" ||
             !myBook->check_pass(data_pass));

    if (format == 0) {
        ifstream readf(accs_mng);
        while (!readf.eof()) readf >> file_detail; // doc vao file_detail
        find_user = file_detail.find(data_user, find_pos);
        find_pass = file_detail.find(data_pass, find_pos);
        if (find_user < 0 || find_user >= file_detail.length() || find_pass < 0 || find_pass >= file_detail.length()) {
            cout << "Ten dang nhap hoac Mat khau khong dung" << please;
            goto fix_account_inf;
        }
        readf.close();
        cout << "Dang nhap vao tai khoan thanh cong !\n";
    } else {
        ifstream readf(accs_mng);
        readf >> checkFile;
        if (checkFile != '\0') {
            while (!readf.eof()) {
                readf >> data_before;
            }
            data_before.pop_back();
        }
        readf.close();
        ofstream writef(accs_mng, ios::app);
        writef << data_before + data_user + '-' + data_pass + "/\n"; // ghi vao file Accounts_manager.txt
        writef.close();
        user_information(); // nhap tiep thong tin ca nhan nguoi dung
        system("cls");
        cout << "Tai khoan khoi tao thanh cong. Moi ban quay lai giao dien Dang nhap !\n";
    }
}

void LibMng::output_account() {
    string user_search, output_console, usr_output[] = {"Ho va ten",
                                                        "Ngay thang nam sinh",
                                                        "Nghe ngiep",
                                                        "Dia chi",
                                                        "Noi cong tac",
                                                        "ID dinh kem"};
    size_t found_cnt = 0, output_cnt = 0, order = 0;
    bool continue_flag = true;

    ifstream userDownload(accs_mng);
    if (userDownload.fail()) {
        cout << "Accounts_manager bi loi !\n";
    } else {
        if (user == "\0") goto out_acc; // chua dang ki
        while (getline(userDownload, user_search)) { // xuat noi dung file ra output_console
            found_cnt++;
            if (user_search == user) { // tim thay ten nguoi dung
                ifstream inforDownload(infors_mng);
                if (inforDownload.fail()) {
                    cout << "Information_manager bi loi !\n";
                } else {
                    cout << "Thong tin tai khoan nguoi dung:\n";
                    while (getline(inforDownload, output_console)) {
                        output_cnt++;
                        if (output_cnt == found_cnt) {
                            for (i = 0; i < output_console.length(); i++) {
                                if (continue_flag) {
                                    order++;
                                    cout << order << '/' << usr_output[i];
                                    continue_flag = false;
                                }
                                if (output_console[i] != '-') {
                                    cout << output_console[i];
                                    if (i == output_console.length() - 1) {
                                        continue_flag = true;
                                        cout << endl;
                                    }
                                } else {
                                    continue_flag = true;
                                    cout << endl;
                                }
                            }
                        }
                    }
                }
                inforDownload.close();
                break;
            }
        }
    }
    out_acc:
    userDownload.close();
}

void LibMng::delete_accounts() {
    ofstream writef(accs_mng);
    if (writef.fail()) {
        cout << "File bi loi !\n";
    } else {
        writef << "";
        cout << "Da xoa du lieu thanh cong !\n";
    }
    writef.close();
}

void LibMng::user_information() {
    string usr_input, usr_inf[] = {"ho va ten",
                                   "ngay thang nam sinh",
                                   "nghe nghiep",
                                   "dia chi",
                                   "noi cong tac"};
    unsigned int rand_num;
    bool error_flag;

    cout << "Moi ban nhap tiep thong tin nguoi dung:\n";
    for (i = 0; i < sizeof(usr_inf) / sizeof(usr_inf[0]); i++) {
        do {
            error_flag = true;
            cout << "- Nhap vao " << usr_inf[i] << ':';
            getline(cin, usr_input);
            switch (i) {
                case 0: // ho va ten
                case 2: // nghe nghiep
                case 3: // dia chi
                case 4: // noi cong tac
                    if (!myBook->check_alphabet(usr_input)) {
                        cout << usr_inf[i] << " phai tuan theo Alphabet Format" << please;
                        error_flag = false;
                    }
                    break;
                default: // ngay thang nam sinh
                    if (!myBook->check_datein(usr_input)) {
                        cout << "Ngay thang nam sinh sai dinh dang" << please;
                        error_flag = false;
                    }
            }
        } while (!error_flag);
        ofstream dataUpload(infors_mng, ios::app);
        if (dataUpload.fail()) {
            cout << "File bi loi !\n";
        } else {
            dataUpload << usr_input;
            if (i != sizeof(usr_inf) / sizeof(usr_inf[0]) - 1) {
                dataUpload << '-';
            } else {
                dataUpload << '-';
                srand(time(nullptr)); // initializing random seed
                for (int j = 0; j < 6; j++) { // tao id gioi han boi 6 so ngau nhien
                    rand_num = rand() % 10;
                    dataUpload << rand_num;
                }
                dataUpload << '/' << endl;
            }
        }
        dataUpload.close();
    }
}

#endif //FINAL_V5_LIBMNG_H
