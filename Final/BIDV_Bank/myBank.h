//
// Created by Trong_Phuc on 21/06/2023.
//

#ifndef BIDV_BANK_MYBANK_H
#define BIDV_BANK_MYBANK_H

#include <cstring> // strlen
#include <iostream>
#include <fstream> // storing user's information
#include <ctime>
#include <string>

/*QUAN LI NGAY THANG NAM*/

class myDates {
private:
    const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
    int d, m, y;

    static unsigned int countLeapYears(myDates *data);

public:
    myDates(int d, int m, int y) {
        this->d = d;
        this->m = m;
        this->y = y;
    }
    unsigned long distanceDates(myDates *data_a, myDates *data_b);
};

unsigned int myDates::countLeapYears(myDates *data) { // dem nam nhuan
    int my_years = data->y;

    if (data->m <= 2) my_years--;
    return my_years / 4 - my_years / 100 + my_years / 400;
}

unsigned long myDates::distanceDates(myDates *data_a, myDates *data_b) {
    unsigned long n_a = data_a->y * 365 + data_a->d, n_b = data_b->y * 365 + data_b->d;

    for (int i = 0; i < data_a->m - 1; i++) n_a += monthDays[i];
    n_a += countLeapYears(data_a);
    for (int i = 0; i < data_b->m - 1; i++) n_b += monthDays[i];
    n_b += countLeapYears(data_b);
    if (n_b < n_a) return -1; // ngay truy xuat nho hon ngay gui tien
    return n_b - n_a;
}

/*QUAN LI CAC THONG TIN CA NHAN*/

class myUsers {
private:
    std::string name;
    int id{};
    int cif[4]{};
    int acc[5]{};

protected:
    static bool valid_name(const std::string& data);
    static bool valid_id(int data);
    static bool valid_number(std::string &data, bool type);
    static bool check_date(int &d, int &m, int& y);
    static bool valid_date(std::string data);
    static size_t searching_data(std::string &data, std::string &path);

public:
    static bool available_data(std::string &path);
    void put_name() { std::getline(std::cin, name); }
    void put_id() { std::cin >> id; }
    std::string get_name() { return name; }
    int get_id() { return id; }
    int *get_cif() { return cif; }
    int *get_acc() { return acc; }
};

bool myUsers::valid_name(const std::string& data) {
    for (auto& i : data) {
        if (!isalpha(i) && !isblank(i)) return false;
    }
    return true;
}

bool myUsers::valid_id(int data) {
    if (std::to_string(data).length() != 8) return false;
    return true;
}

bool myUsers::valid_number(std::string &data, bool type) {
    if (data.length() != 4 && data.length() != 5 && type) { // type == true => check cif, acc
        return false;
    } else {
        for (auto& i : data) {
            if (!isdigit(i)) return false;
        }
    }
    return true;
}

bool myUsers::check_date(int &d, int &m, int& y) {
    unsigned int AD = 0;

    if (m == 4 || m == 6 || m == 9 || m == 11) { // nhung thang co 30 ngay
        if (d > 30) return true;
    } else if (m == 2) {
        while (AD < y) AD += 4; // nam Cong Nguyen tien dan ve nam hien tai, chu ky 4 nam
        if (y == AD) { // nam nhuan => thang 2 co 29 ngay
            if (d > 29) return true;
        } else { // nam ko nhuan => thang 2 co 28 ngay
            if (d > 28) return true;
        }
    } else { // nhung thang co 31 ngay
        if (d > 31) return true;
    }
    return false;
}

bool myUsers::valid_date(std::string data) {
    bool flag = true;
    int m, m_pos, num, day, month, year;
    int flat = 0, counter = 0, minimize_num = 0;

    data.push_back('/'); // => x/x/x/
    for (m = 0; m < data.length(); m++) {
        if (data[m] != '/') {
            minimize_num++;
        } else {
            flat++;
            if (flat == 1 || flat == 2) {
                if (minimize_num < 2) return false;
            } else {
                if (minimize_num < 4) return false;
            }
            minimize_num = 0;
        }
    }
    for (m = 0; m < data.length(); m++) { // 05/05/2003/
        if (data[m] != '/') {
            counter++;
            if (flag) { // lay gia tri m dau tien hoac sau dau '/'
                m_pos = m;
                flag = false;
            }
            if (data[m] < '0' || data[m] > '9') return false; // vd: 5-/05/2003
        } else {
            num = stoi(data.substr(m_pos, counter)); // quy doi sang dang so nguyen
            if (m == 2) {
                if (num > 0 && num < 31) day = num;
            } else {
                if (num > 0 && num < 12) month = num;
                else year = num;
            }
            counter = 0;
            flag = true;
        }
    }
    if (check_date(day, month, year)) return false;
    return true;
}

bool myUsers::available_data(std::string &path) {
    char dataReceived;

    std::ifstream dataRead(path);
    if (!dataRead) {
        return false;
    } else {
        if (dataRead.fail() || dataRead.bad()) {
            return false;
        } else {
            dataRead >> dataReceived;
            if (dataReceived == '\0') return false; // trong file khong co du lieu
        }
    }
    return true;
}

size_t myUsers::searching_data(std::string &data, std::string &path) {
    std::string data_cut;
    size_t data_pos;

    std::ifstream dataUpload(path);
    if (!dataUpload) {
        return std::string::npos;
    } else {
        if (dataUpload.fail() || dataUpload.bad()) {
            return std::string::npos;
        } else {
            while (getline(dataUpload, data_cut)) {
                data_pos = data_cut.find(data);
                if (data_pos != std::string::npos) return data_pos;
            }
        }
    }
    return std::string::npos;
}

/*QUAN LI / TRUY XUAT DU LIEU TRONG NGAN HANG*/

class myBank : protected myDates, public myUsers { // ke thua nhieu lop
private:
    std::string menu_bank[5] = {"Them ma so CIF", // dang nhap
                                "Tao giao dich moi", // tao giao dich
                                "Tra cuu tien lai", // dang nhap
                                "Xoa du lieu trong Ngan hang",
                                "Thoat MENU"};
    std::string date_send, error_notify = ". Moi ban nhap lai !\n", accounts_path = "BIDV_Accounts.txt";;
    int money_send = 0, menu_amount = sizeof(menu_bank) / sizeof(menu_bank[0]);

    static int date_numbers(std::string &data, char type);
    static void create_cif(myBank *data, bool writing);

public:
    int menu_option = 0;
    void bank_selections();
    void lookup_money();
    void cleanup_data();
    void add_cif();
    friend std::istream& operator >> (std::istream &new_cin, myBank *data_in);
    friend std::ostream& operator << (std::ostream &new_cout, myBank *data_out);
};

int myBank::date_numbers(std::string &data, char type) { // data: dd/mm/yyyy - type == {'d', 'm', 'y'}
    int my_num;

    if (type == 'd') my_num = stoi(data.substr(0, 2));
    else if (type == 'm') my_num = stoi(data.substr(3, 2));
    else if (type == 'y') my_num = stoi(data.substr(6, 4));
    else return -1;
    return my_num;
}

void myBank::create_cif(myBank *data, bool writing) { // TIEP TUC O DAY !!!
    for (int i = 0; i < std::strlen(reinterpret_cast<char *>(data->get_cif())); i++) {
        if (writing) data->get_cif()[i] = rand() % 10;
        std::cout << data->get_cif()[i];
    }
    std::cout << std::endl;
}

void myBank::bank_selections() {
    srand(time(nullptr)); // khoi tao sinh so ngau nhien
    my_loop:
    for (int i = 0; i < menu_amount; i++) std::cout << i << " - " << menu_bank[i] << std::endl;
    do {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout << "Lua chon cua ban la:";
        std::cin >> menu_option;
        if (std::cin.fail()) {
            std::cout << "Ban nhap sai kieu du lieu" << error_notify;
        } else {
            if (menu_option < 0 || menu_option > menu_amount - 1) std::cout << "Gia tri khong hop le" << error_notify;
        }
    } while (std::cin.fail() || (menu_option < 0 || menu_option > menu_amount - 1));
    if (!available_data(accounts_path) && menu_option != 1 && menu_option != menu_amount - 1) {
        std::cout << "Ban chua co tai khoan trong ngan hang. Hay tao tai khoan !\n";
    }
    if (menu_option != menu_amount - 1) {
        system("pause");
        system("cls");
        goto my_loop;
    } else {
        do {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
            }
            std::cout << "Ban co muon thuc hien lai giao dich khac ? (0 - Khong / !0 - Co) =>";
            std::cin >> menu_option;
            if (std::cin.fail()) std::cout << "Ban nhap sai kieu du lieu" << error_notify;
        } while (std::cin.fail());
        if (menu_option != 0) {
            goto my_loop;
        } else {
            menu_option = menu_amount - 1; // ket thuc chuong trinh
            std::cout << "Cam on ban da su dung chuong trinh !\n";
        }
        system("pause");
    }
}

void myBank::lookup_money() {
    myDates *firstDate, *secondDate;
    std::string comStr, accStored, dateSend_Stored, moneySend_Stored;
    size_t moneySend_Pos;
    unsigned long distanceDates_Stored;
    bool nextDate = true;

    do {
        std::cout << "Nhap vao ma so CIF / so Tai khoan cua ban:";
        std::cin >> comStr;
        if (comStr.empty()) {
            std::cout << "Ban chua nhap du lieu" << error_notify;
        } else {
            if (!valid_number(comStr, true)) {
                std::cout << "Du lieu dau vao phai la cac con so" << error_notify;
            } else {
                if (searching_data(comStr, accounts_path) == std::string::npos) std::cout << "File's path bi loi hoac Ma so CIF / so Tai khoan khong tim thay !\n";
                else accStored = comStr; // vi tri tai khoan trong file
            }
        }
    } while (comStr.empty() || !valid_number(comStr, true) || searching_data(comStr, accounts_path) == std::string::npos);
    do {
        std::cout << "Nhap vao ngay " << (nextDate ? "gui tien:" : "truy cuu:");
        std::cin >> comStr;
        if (comStr.empty()) {
            std::cout << "Ban chua nhap du lieu" << error_notify;
        } else {
            if (!valid_date(comStr)) {
                std::cout << "Ban nhap sai dinh dang cmnr" << error_notify;
            } else {
                if (nextDate) {
                    if (searching_data(comStr, accounts_path) == std::string::npos) {
                        std::cout << "Khong tim thay ngay gui tien nay" << error_notify;
                    } else {
                        firstDate = new myDates(date_numbers(comStr, 'd'), date_numbers(comStr, 'm'), date_numbers(comStr, 'y'));
                        dateSend_Stored = comStr; // luu lai ngay gui tien
                        nextDate = false;
                    }
                } else {
                    secondDate = new myDates(date_numbers(comStr, 'd'), date_numbers(comStr, 'm'),date_numbers(comStr, 'y'));
                    if (distanceDates(firstDate, secondDate) < 0) {
                        std::cout << "Ngay tra cuu phai lon hon ngay gui tien" << error_notify;
                    } else {
                        distanceDates_Stored = distanceDates(firstDate, secondDate); // luu lai khoang cach giua 2 ngay gui tien va tra cuu
                        break;
                    }
                }
            }
        }
    } while (comStr.empty() || !valid_date(comStr) || searching_data(comStr, accounts_path) == std::string::npos || !nextDate);
    std::cout << "So tien lai theo ngay: "; // = Số tiền gửi x lãi suất (%năm) x số ngày gửi / 360
    std::ifstream dataDownload(accounts_path);
    if (!dataDownload) {
        std::cout << "This file \"" << accounts_path << "\" is corrupted !\n";
    } else {
        if (dataDownload.fail() || dataDownload.bad()) {
            std::cout << "An error occurred during reading !\n";
        } else {
            while (getline(dataDownload, comStr)) {
                if (comStr.find(accStored) != std::string::npos) { // tim thay tai khoan
                    moneySend_Pos = comStr.find(dateSend_Stored) + dateSend_Stored.length() + 1; // abc,500,
                    moneySend_Stored = comStr.substr(moneySend_Pos, comStr.length() - 1 - moneySend_Pos);
                    break;
                }
            }
            dataDownload.close();
            if (!valid_number(moneySend_Stored, false)) std::cout << "ERROR\n";
            else std::cout << stof(moneySend_Stored) * (float)(7.4 / 100) * (float)distanceDates_Stored / 360 << " VND\n";
        }
    }
}

void myBank::cleanup_data() {
    int clearSelection;

    do {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
        }
        std::cout << "Ban co chac muon thuc hien ? (0 - Khong / !0 - Co) =>";
        std::cin >> clearSelection;
        if (std::cin.fail()) std::cout << "Ban nhap sai kieu du lieu" << error_notify;
    } while (std::cin.fail());
    std::ofstream cleanall(accounts_path);
    if (!cleanall) {
        std::cout << "This file \"" << accounts_path << "\" is corrupted !\n";
    } else {
        if (cleanall.fail() || cleanall.bad()) {
            std::cout << "An error occurred during writing !\n";
        } else {
            cleanall << "";
            cleanall.close();
            std::cout << "Xoa du lieu thanh cong !\n";
        }
    }
}

void myBank::add_cif() {
    std::string digit_input, dataProcess;
    size_t digit_pos, dataPos;
    long long ftell_get;
    bool more_cif = true;

    do {
        std::cout << "Nhap vao ma so CIF " << (more_cif ? "/ so Tai khoan" : "moi") << " cua ban:";
        std::cin >> digit_input;
        if (digit_input.empty()) {
            std::cout << "Ban chua nhap du lieu. Moi ban nhap lai !\n";
        } else {
            if (!valid_number(digit_input, true)) {
                std::cout << "Du lieu dau vao phai la cac con so !\n";
            } else {
                if (more_cif) {
                    if (searching_data(digit_input, accounts_path) == std::string::npos) {
                        std::cout << "File's path bi loi hoac Ma so CIF / so Tai khoan khong tim thay !\n";
                    } else {
                        digit_pos = searching_data(digit_input, accounts_path);
                        more_cif = false;
                    }
                } else {
                    break;
                }
            }
        }
    } while (digit_input.empty() || !valid_number(digit_input, true) || searching_data(digit_input, accounts_path) == std::string::npos || !more_cif);

    std::fstream dataBoth(accounts_path, std::ios::in | std::ios::out);
    if (!dataBoth) {
        std::cout << "This file \"" << accounts_path << "\" is corrupted !\n";
    } else {
        if (dataBoth.fail() || dataBoth.bad()) {
            std::cout << "An error occurred during writing !\n";
        } else {
            while (getline(dataBoth, dataProcess)) {
                dataPos = dataProcess.find(digit_input);
                if (dataPos != std::string::npos) { // tim thay cif, acc de them vao
                    dataProcess.insert(digit_pos, digit_input);
                    dataBoth.seekp(ftell_get); // dat con tro file vao vi tri can thay doi van ban
                    dataBoth << dataProcess;
                    std::cout << "Them Ma so CIF thanh cong !\n";
                    break;
                }
                ftell_get = dataBoth.tellg(); // lay vi tri con tro file truoc khi nhay sang dong tiep theo
            }
        }
    }
}

std::istream& operator >> (std::istream &new_cin, myBank *data_in) {
    std::string myName;
    int accept_cif;

    std::cout << "Ma so CIF chung toi tao cho ban: ";
    do {
        if (new_cin.fail()) {
            new_cin.clear();
            new_cin.ignore();
        } else {
            data_in->create_cif(data_in, true);
            /*for (int& i : data.manual.cif) {
                i = rand() % lim_cif; // tao ma so cif
                cout << i;
            }*/
        }
        std::cout << "Ban co dong y voi ma so tren ? (0 - Khong / !0 - Co) =>";
        new_cin >> accept_cif;
        if (new_cin.fail()) {
            std::cout << "Ban nhap sai kieu du lieu" << data_in->error_notify;
        } else {
            if (accept_cif == 0) std::cout << "Chung toi da tao cho ban ma so khac: ";
        }
    } while (new_cin.fail() || accept_cif == 0);

    new_cin.ignore(100, '\n');
    do {
        std::cout << "Nhap vao ho va ten (theo chuan Alphabet):";
        data_in->put_name();
        if (data_in->get_name().empty()) {
            std::cout << "Ban chua nhap du lieu" << data_in->error_notify;
        } else {
            if (!myBank::valid_name(data_in->get_name())) std::cout << "Chi chap nhan cac ky tu Alphabet" << data_in->error_notify;
        }
    } while (data_in->get_name().empty() || !myBank::valid_name(data_in->get_name()));
    do {
        if (new_cin.fail()) {
            new_cin.clear();
            new_cin.ignore();
        }
        std::cout << "Nhap vao so CCCD (8 chu so ngau nhien):";
        data_in->put_id();
        if (new_cin.fail()) {
            std::cout << "Ban nhap sai kieu du lieu" << data_in->error_notify;
        } else {
            if (!myBank::valid_id(data_in->get_id())) std::cout << "CCCD yeu cau 8 chu so ngau nhien." << data_in->error_notify;
        }
    } while (new_cin.fail() || !myBank::valid_id(data_in->get_id()));

    new_cin.ignore(100, '\n');
    do {
        std::cout << "Nhap vao ngay gui tien (dd/mm/yyyy):";
        getline(new_cin, data_in->date_send);
        if (data_in->date_send.empty()) {
            std::cout << "Ban chua nhap du lieu" << data_in->error_notify;
        } else {
            if (!myBank::valid_date(data_in->date_send)) std::cout << "Ngay thang nam chua dung dinh dang" << data_in->error_notify;
        }
    } while (data_in->date_send.empty() || !myBank::valid_date(data_in->date_send));
    do {
        if (new_cin.fail()) {
            new_cin.clear();
            new_cin.ignore();
        }
        std::cout << "Nhap vao so tien can gui (50.000 VND <= so tien <= 10.000.000 VND):";
        new_cin >> data_in->money_send;
        if (new_cin.fail()) {
            std::cout << "Ban nhap sai kieu du lieu" << data_in->error_notify;
        } else {
            if (data_in->money_send < 50000 || data_in->money_send > 10000000) std::cout << "So tien khong thoa dieu kien tren" << data_in->error_notify;
        }
    } while (new_cin.fail() || data_in->money_send < 50000 || data_in->money_send > 10000000);
    std::cout << data_in;
    return new_cin;
}

std::ostream& operator << (std::ostream &new_cout, myBank *data_out) {
    new_cout << "* Ma so CIF cua ban: ";
    data_out->create_cif(data_out, false);
//    for (int i = 0; i < std::strlen(reinterpret_cast<char *>(data_out->my_usrManager.get_cif())); i++) new_cout << data_out->my_usrManager.get_cif()[i];
    new_cout << "\n  - Ho va ten: " << data_out->get_name();
    new_cout << "\n  - So CCCD: " << data_out->get_id();
    new_cout << "\n* So Tai khoan cua ban: ";
    for (int i = 0; i < std::strlen(reinterpret_cast<char *>(data_out->get_acc())); i++) { // tao so tai khoan
        data_out->get_acc()[i] = rand() % 10;
        new_cout << i;
    }
    new_cout << "\n* Ngay gui tien: " << data_out->date_send << std::endl;
    return new_cout;
}

#endif //BIDV_BANK_MYBANK_H
