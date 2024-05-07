//
// Created by Trong_Phuc on 29/06/2023.
//

#ifndef FINAL_V5_BOOKMNG_H
#define FINAL_V5_BOOKMNG_H

#include <fstream>

using namespace std;

class BookMng {
private:
    unsigned int id{}; // book id (4 chu so ngau nhien)
    string name; // book name
    string datein; // dd/mm/yyyy
    string author; // tac gia
    bool status{}; // co san, khong co san

    string book_elements[5] = {"Ma cua sach (ID)",
                              "Ten sach",
                              "Ngay nhap",
                              "Tac gia",
                              "\tTrang thai (0 - Khong co san / 1 - Co san)"};
    string sort_dates[50], general_search, file_io, user, write_io, read_io, id_error, please = ". Moi ban nhap lai !\n";
    int i{}, l{}, n{}, e{}, k{}, id_search{}, book_exist = 0, tracing = 0, amount = sizeof(book_elements) / sizeof(book_elements[0]);
    unsigned int array_id[50]{}, sort_numbers[50]{};
    bool flag_search = true, flag_id = true;
    
protected:
    static void found_book(BookMng *&data);
    static void output_list(BookMng *&data, unsigned int order);
    static bool invalid_date(int &d, int &m, int &y);
    static bool check_id(unsigned int data);

    unsigned int get_id();
    string get_name();
    string get_datein();
    string get_author();
    bool get_status();

public:
    string check_spaceSpam(string &data);
    static bool check_pass(string &data);
    static bool check_alphabet(string &data);
    static bool check_datein(string data);

    void add();
    void list();
    void search();
    void sort();
    void print_all();
    void numberic_sorting(BookMng *sort[], unsigned int data[], int total_elements, int total_book, int mission);
    void datein_sorting(BookMng *sort[], string data[], int total_elements, int total_book);
};

/*CHECKING IO DATA METHODS*/

void BookMng::found_book(BookMng *&data) {
    cout << "ID: " << data->get_id() << " / ";
    cout << "Ten sach: " << data->get_name() << " / ";
    cout << "Ngay nhap: " << data->get_datein() << " / ";
    cout << "Tac gia: " << data->get_author() << " / ";
    cout << "Trang thai: " << data->get_status() << endl;
}

void BookMng::output_list(BookMng *&data, unsigned int order) {
    cout << " " << order + 1 << " ";
    cout << "\t      " << data->get_id();
    cout << "\t\t" << data->get_name();
    cout << "\t\t" << data->get_datein();
    cout << "\t" << data->get_author();
    cout << "\t\t\t  " << data->get_status() << endl;
}

string BookMng::check_spaceSpam(string &data) {
    for (i = 0; i < data.length(); i++) {
        if (data[i] == ' ') {
            if (i == 0) {
                return "SPACE1"; // dau cach vi tri dau tien
            } else {
                if (data[i + 1] == ' ') return "SPACE2"; // 2 dau cach lien tiep
            }
        }
    }
    return "SPACE0";
}

bool BookMng::check_pass(string &data) { // 10ThungTiger$
    unsigned int num_cnt = 0, nonechar_cnt = 0, upperchar_cnt = 0;

    for (auto &j: data) {
        if (j < 'a' || j > 'z') {
            if (j > '0' && j < '9') num_cnt++;
            else if (j >= 'A' && j <= 'Z') upperchar_cnt++;
            else nonechar_cnt++;
        }
    }
    if (num_cnt == 0 || nonechar_cnt == 0 || upperchar_cnt == 0) return false;
    return true;
}

bool BookMng::invalid_date(int &d, int &m, int &y) {
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

bool BookMng::check_alphabet(string &data) {
    for (auto &j : data) {
        if (j != ' ' && !isalpha(j)) return false;
    }
    return true;
}

bool BookMng::check_id(unsigned int data) {
    unsigned int counter_id = 0;

    while (data > 0) { // kiem tra do dai cua ma sach
        counter_id++;
        data /= 10;
    }
    if (counter_id != 4) return false;
    return true;
}

bool BookMng::check_datein(string data) {
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
    if (invalid_date(day, month, year)) return false;
    return true;
}

/*GETTER METHODS*/

unsigned int BookMng::get_id() { return id; }

string BookMng::get_name() { return name; }

string BookMng::get_datein() { return datein; }

string BookMng::get_author() { return author; }

bool BookMng::get_status() { return status; }

/*FEATURE FUNCTIONS*/

void BookMng::add() {
    cout << "Thu vien cua ban hien dang co " << book_exist << " cuon sach !\n";
    cout << "Ban muon quyen gop bao nhieu cuon sach ? =>"; // nhap vao so luong sach
    cin >> n;

    for (i = book_exist; i < book_exist + n; i++) {
        cout << "Thong tin sach thu " << i + 1 << ":\n"; // thong tin sach
        do {
            id_error = '\0';
            cout << "Nhap vao ma sach (4 chu so ngau nhien 1000 - 9999):"; // ma cua sach (duy nhat)
            cin >> id;
            if (!check_id(id)) {
                cout << "Ban nhap ma cua sach bi thieu hoac du thua" << please;
            } else {
                if (book_exist != 0) {
                    for (l = 0; l < book_exist; l++) { // kiem tra xem ID sach co bi trung lap
                        if (id == get_id()) {
                            cout << "Sach da co san trong thu vien (trung ID)" << please;
                            id_error = "AVAILABLE";
                            break;
                        }
                    }
                } else {
                    array_id[tracing] = id;
                    if (tracing != 0) {
                        for (l = 0; l < tracing; l++) {
                            for (int f = l; f < tracing; f++) {
                                if (array_id[f] == array_id[f + 1]) {
                                    cout << "Ban vua moi nhap ID nay roi" << please;
                                    id_error = "AVAILABLE";
                                    flag_id = false;
                                    break;
                                }
                            }
                            if (!flag_id) break;
                        }
                    }
                    if (!flag_id) flag_id = true;
                    else tracing++;
                }
            }
        } while (!check_id(id) || id_error == "AVAILABLE");

        cin.ignore(100, '\n'); // xoa dau '\n' trong bo nho dem

        do {
            cout << "Nhap vao ten sach:"; // ten cua sach
            getline(cin, name);
            if (name.empty()) {
                cout << "Ban chua nhap du lieu" << please;
            } else {
                if (check_spaceSpam(name) == "SPACE1")
                    cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
                else if (check_spaceSpam(name) == "SPACE2")
                    cout << "Khong duoc spam 2 dau cach lien tiep" << please;
                else break;
            }
        } while (name.empty() || check_spaceSpam(name) == "SPACE1" ||
                 check_spaceSpam(name) == "SPACE2");

        do {
            cout << "Nhap vao ngay nhap sach (dd/mm/yyyy):"; // ngay nhap sach
            getline(cin, datein);
            if (datein.empty()) {
                cout << "Ban chua nhap du lieu" << please;
            } else {
                if (check_spaceSpam(datein) == "SPACE1") {
                    cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
                } else if (check_spaceSpam(datein) == "SPACE2") {
                    cout << "Khong duoc spam 2 dau cach lien tiep" << please;
                } else {
                    if (!check_datein(datein)) cout << "Du lieu ban nhap chua dung dinh dang" << please;
                    else break;
                }
            }
        } while (datein.empty() || check_spaceSpam(datein) == "SPACE1" ||
                 check_spaceSpam(datein) == "SPACE2" || !check_datein(datein));

        do {
            cout << "Nhap vao ten tac gia:"; // ten tac gia
            getline(cin, author);
            if (author.empty()) {
                cout << "Ban chua nhap du lieu" << please;
            } else {
                if (check_spaceSpam(author) == "SPACE1")
                    cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
                else if (check_spaceSpam(author) == "SPACE2")
                    cout << "Khong duoc spam 2 dau cach lien tiep" << please;
                else break;
            }
        } while (author.empty() || check_spaceSpam(author) == "SPACE1" ||
                 check_spaceSpam(author) == "SPACE2");

        do {
            cout << "Nhap vao trang thai cua sach (0 - Khong co san / 1 - Co san):"; // trang thai ton kho
            cin >> status;
            if (status != 0 && status != 1) cout << "Trang thai ban nhap khong phu hop" << please;
        } while (status != 0 && status != 1);
    }
    book_exist += n; // cong don sach vao kho
}

void BookMng::list() {
    auto** book = reinterpret_cast<BookMng **>(new BookMng());

    cout << "Thu vien hien co " << book_exist << " cuon sach, bao gom:\nSTT";
    for (i = 0; i < amount; i++) cout << "\t" << book_elements[i];
    cout << "\n";
    for (i = 0; i < book_exist; i++) output_list(book[i], i);
}

void BookMng::search() {
    auto** book = reinterpret_cast<BookMng **>(new BookMng());
    categories_search:
    do {
        cout << "Ban muon tim kiem theo danh muc nao ?";
        cout << "\n0 - ID";
        cout << "\n1 - Ten sach";
        cout << "\n2 - Ngay nhap sach";
        cout << "\n3 - Tac gia";
        cout << "\nLua chon cua ban la:";
        cin >> e;
        if (e != 0 && e != 1 && e != 2 && e != 3) cout << "Khong ton tai danh muc nay" << please;
    } while (e != 0 && e != 1 && e != 2 && e != 3);

    if (e == 0) { // tim kiem ID
        cout << "Nhap vao ID cua sach ban can tim:";
        cin >> id_search;
        for (i = 0; i < book_exist; i++) {
            if (book[i]->id == id_search) {
                cout << "Day la sach ban can tim => ";
                found_book(book[i]);
                flag_search = false;
                break;
            }
        }
        if (flag_search) {
            cout << "ID cua sach khong co trong thu vien\nBan co muon tim kiem lai voi danh muc khac ? (# - Khong / 1 - Co) =>";
            cin >> k;
            if (k == 1) goto categories_search;
        }
    } else { // tim kiem ten sach, ngay nhap, tac gia
        cin.ignore(100, '\n');
        do {
            if (e == 1) cout << "Nhap vao ten sach ban can tim:";
            else if (e == 2) cout << "Nhap vao ngay nhap sach (dd/mm/yyyy) ban can tim:";
            else cout << "Nhap vao ten tac gia ban can tim:";
            getline(cin, general_search);
            if (general_search.empty()) {
                cout << "Ban chua nhap du lieu" << please;
            } else {
                if (check_spaceSpam(general_search) == "SPACE1") {
                    cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
                } else if (check_spaceSpam(general_search) == "SPACE2") {
                    cout << "Khong duoc spam 2 dau cach lien tiep" << please;
                } else {
                    if (e == 2) {
                        if (!check_datein(general_search))
                            cout << "Du lieu ban nhap chua dung dinh dang" << please;
                        else break;
                    } else {
                        break;
                    }
                }
            }
        } while (general_search.empty() || check_spaceSpam(general_search) == "SPACE1" ||
                 check_spaceSpam(general_search) == "SPACE2" || !check_datein(general_search));

        for (i = 0; i < book_exist; i++) {
            if (general_search == book[i]->name || general_search == book[i]->datein ||
                general_search == book[i]->author) {
                if (flag_search) {
                    cout << "Day la sach ban can tim: ";
                    flag_search = false;
                }
                found_book(book[i]);
            }
        }
        if (flag_search) {
            if (e == 1) cout << "Ten cua sach";
            else if (e == 2) cout << "Ngay nhap sach";
            else cout << "Ten tac gia";
            cout
                    << " khong co trong thu vien\nBan co muon tim kiem lai voi danh muc khac ? (# - Khong / 1 - Co) =>";
            cin >> k;
            if (k == 1) goto categories_search;
        }
    }
}

void BookMng::sort() {
    auto** book = reinterpret_cast<BookMng **>(new BookMng());

    do {
        cout << "Ban muon sap xep theo danh muc nao ?";
        cout << "\n0 - ID (tang dan)";
        cout << "\n1 - Ngay nhap sach (tu cu den moi)";
        cout << "\n2 - Trang thai (uu tien co san)";
        cout << "\nLua chon cua ban la:";
        cin >> e;
        if (e != 0 && e != 1 && e != 2) cout << "Khong ton tai danh muc nay" << please;
    } while (e != 0 && e != 1 && e != 2);

    for (i = 0; i < book_exist; i++) {
        if (e == 0) sort_numbers[i] = book[i]->id; // dung de sap xep theo id tang dan
        else if (e == 1) sort_dates[i] = book[i]->datein; // sap xep ngay thang nam tang dan
        else sort_numbers[i] = book[i]->status; // dung de sap xep theo trang thai, uu tien co san
    }
    if (e == 0 || e == 2)
        numberic_sorting(book, sort_numbers, amount, book_exist, e); // sap xep va in ra du lieu id, trang thai
    else datein_sorting(book, sort_dates, amount, book_exist);
}

void BookMng::print_all() {
    auto** book = reinterpret_cast<BookMng **>(new BookMng());
    ofstream write_to_file;

    cin.ignore(100, '\n');
    do {
        cout << "Moi ban nhap vao ten file:";
        getline(cin, file_io);
        if (file_io.empty()) {
            cout << "Ban chua nhap du lieu" << please;
        } else {
            if (check_spaceSpam(file_io) == "SPACE1")
                cout << "Khong duoc nhap dau cach o vi tri dau tien" << please;
            else if (check_spaceSpam(file_io) == "SPACE2")
                cout << "Khong duoc spam 2 dau cach lien tiep" << please;
            else break;
        }
    } while (file_io.empty() || check_spaceSpam(file_io) == "SPACE1" || check_spaceSpam(file_io) == "SPACE2");

    write_to_file.open(file_io + ".txt");
    if (!write_to_file) {
        cout << "File Error !\n";
    } else {
        write_to_file << "Thu vien hien co " << book_exist << " cuon sach, bao gom:\nSTT";
        for (i = 0; i < amount; i++) write_to_file << "\t" << book_elements[i];
        write_to_file << "\n";
        for (i = 0; i < book_exist; i++) {
            write_to_file << " " << i + 1 << " ";
            write_to_file << "\t      " << book[i]->id;
            write_to_file << "\t\t" << book[i]->name;
            write_to_file << "\t\t" << book[i]->datein;
            write_to_file << "\t" << book[i]->author;
            write_to_file << "\t\t\t  " << book[i]->status << "\n";
        }
        write_to_file.close();
        cout << "Da xuat file thanh cong !\n";
    }
}

void BookMng::numberic_sorting(BookMng **sort, unsigned int *data, int total_elements, int total_book, int mission) {
    string sort_elements[] = {"Ma cua sach (ID)", "Ten sach", "Ngay nhap", "Tac gia",
                              "\tTrang thai (0 - Khong co san / 1 Co san)"};
    unsigned int temp;
    bool flag = true, other = true;

    selection:
    for (i = 0; i < total_book; i++) {
        if (flag) {
            if (mission == 0) { // sap xep cac cuon sach theo ID tang dan
                if (i != total_book - 1) {
                    for (l = i; l < total_book; l++) {
                        if (data[i] > data[l + 1]) {
                            temp = data[i];
                            data[i] = data[l + 1];
                            data[l + 1] = temp;
                        }
                    }
                }
            } else { // sap xep cac cuon sach voi trang thai, uu tien co san
                goto skip;
            }
        } else {
            if (mission == 0) {
                for (l = 0; l < total_book; l++) {
                    if (data[i] == sort[l]->get_id()) output_list(sort[l], i);
                }
            } else {
                if (other) {
                    if (sort[i]->get_status() == 1) output_list(sort[i], i);
                } else {
                    if (sort[i]->get_status() == 0) output_list(sort[i], i);
                }
            }
        }
    }
    skip:
    if (flag) {
        if (mission == 0) {
            cout << "Day la danh sach cac cuon sach duoc sap theo ID tang dan:\nSTT";
        } else {
            cout << "Day la danh sach cac cuon sach duoc sap xep theo trang thai, uu tien co san:\nSTT";
        }
        for (i = 0; i < total_elements; i++) cout << "\t" << sort_elements[i];
        cout << "\n";
        flag = false;
        goto selection;
    } else {
        if (mission != 0) {
            if (other) {
                other = false;
                goto selection;
            }
        }
    }
}

void BookMng::datein_sorting(BookMng **sort, string *data, int total_elements, int total_book) {
    string temp, date_cut, sort_elements[] = {"Ma cua sach (ID)", "Ten sach", "Ngay nhap", "Tac gia",
                                              "\tTrang thai (0 - Khong co san / 1 Co san)"};
    int replace, day_stored[50], month_stored[50], year_stored[50];
    int option = 0;
    bool flag = true, other = true;

    next_sort:
    for (i = 0; i < total_book; i++) {
        if (flag) {
            if (option == 0) { // year_cut
                year_stored[i] = stoi(data[i].substr(6, 4));
            } else if (option == 1) { // month_cut
                month_stored[i] = stoi(data[i].substr(3, 2));
            } else { // day_cut
                day_stored[i] = stoi(data[i].substr(0, 2));
            }
        } else {
            if (other) {
                if (i != total_book - 1) {
                    for (l = i; l < total_book; l++) {
                        if (option == 0) { // year_sort
                            if (year_stored[i] > year_stored[l + 1]) {
                                temp = data[i];
                                data[i] = data[l + 1];
                                data[l + 1] = temp;
                                replace = year_stored[i];
                                year_stored[i] = year_stored[l + 1];
                                year_stored[l + 1] = replace;
                            }
                        } else if (option == 1) { // month_sort
                            if (year_stored[i] == year_stored[l + 1]) {
                                if (month_stored[i] > month_stored[l + 1]) {
                                    temp = data[i];
                                    data[i] = data[l + 1];
                                    data[l + 1] = temp;
                                    replace = month_stored[i];
                                    month_stored[i] = month_stored[l + 1];
                                    month_stored[l + 1] = replace;
                                }
                            }
                        } else { // day_sort
                            if (year_stored[i] == year_stored[l + 1] && month_stored[i] == month_stored[l + 1]) {
                                if (day_stored[i] > day_stored[l + 1]) {
                                    temp = data[i];
                                    data[i] = data[l + 1];
                                    data[l + 1] = temp;
                                }
                            }
                        }
                    }
                }
            } else {
                for (l = 0; l < total_book; l++) {
                    if (data[i] == sort[l]->get_datein()) output_list(sort[l], i);
                }
            }
        }
    }
    if (flag) {
        flag = false;
        goto next_sort;
    } else {
        if (option < 2) {
            option++;
            flag = true;
            goto next_sort;
        } else {
            if (other) {
                cout << "Day la danh sach cac cuon sach duoc sap xep theo ngay nhap (cu nhat => moi nhat):\nSTT";
                for (i = 0; i < total_elements; i++) cout << "\t" << sort_elements[i];
                cout << "\n";
                other = false;
                goto next_sort;
            }
        }
    }
}

#endif //FINAL_V5_BOOKMNG_H
