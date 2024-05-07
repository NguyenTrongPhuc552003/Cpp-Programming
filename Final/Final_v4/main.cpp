#include <iostream>
#include "string"
using namespace std;

bool invalid_date(int d, int m, int y) {
    int AD = 0;

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

bool check(const string& element, string data) {
    bool flag = true;
    int m, m_pos, num, day, month, year;
    int counter = 0, minimize_flat = 0, minimize_num = 0;

    if (element == "ngay thang nam sinh") { // " #/#/# "
        if (data[0] == ' ') {
            for (m = 0; m < data.length(); m++) {
                data[m] = data[m + 1];
            }
            data.pop_back();
            data.pop_back();
        }
        for (m = 0; m < data.length(); m++) {
            if (data[m] != '/') minimize_num++;
            else minimize_flat++;
        }
        if (minimize_num < 3 || minimize_flat != 2) return true; // format toi thieu: x/x/x

        data.push_back('/'); // => x/x/x/
        for (m = 0; m < data.length(); m++) { // 05/05/2003 - 05/5/2003 - 5/05/2003 - 5/5/2003
            if (data[m] != '/') {
                counter++;
                if (flag) { // lay gia tri m dau tien hoac sau dau '/'
                    m_pos = m;
                    flag = false;
                }
                if (data[m] < '0' || data[m] > '9') return true; // vd: 5-/05/2003

            } else {
                if (m == 0) return true; // vd: /05/2003
                num = stoi(data.substr(m_pos, counter)); // quy doi sang dang so nguyen
                if (m == 1 || m == 2) {
                    if (num > 0 && num < 31) day = num;
                } else {
                    if (num > 0 && num < 12) month = num;
                    else year = num;
                }
                counter = 0;
                flag = true;
            }
        }
        if (invalid_date(day, month, year)) return true;

    } else if (element == "ho va ten" || element == "khoa" || element == "truong") { // Khong xet truong hop "lop"
        for (m = 0; m < data.length(); m++) {
            if (data[m] != ' ' && (data[m] < 'a' || data[m] > 'z') && (data[m] < 'A' || data[m] > 'Z')) return true;
        }
    }
    return false;
}

int main() {
    string per_inf_input, check_data, replace_element, saved_data[10];
    string per_inf[] = {"ho va ten", "ngay thang nam sinh", "lop", "khoa", "truong"};
    string please = ". Moi ban nhap lai !\n";
    unsigned long long per_inf_pos;
    int i, option, max_str, amount_data, replace_pos, saved_pos[10], space_date = 0;

    check_others:
    cout << "Nhap vao thong tin ca nhan (bao gom: ho va ten, ngay thang nam sinh (dd/mm/yyyy), lop, khoa, truong)\nNhap o day:";
    getline(cin, per_inf_input);
    for (i = 0; i < per_inf_input.length(); i++) per_inf_input[i] = (char)tolower(per_inf_input[i]); // doi ve chu cai thuong

    max_str = sizeof(per_inf) / sizeof(per_inf[0]); // kich thuoc cua personnal information
    for (i = 0; i < max_str; i++) { // kiem tra so labels co du hay khong
        per_inf_pos = per_inf_input.find(per_inf[i], 0);
        if (per_inf_pos < per_inf_input.length()) {
            saved_data[i] = per_inf[i];
            saved_pos[i] = (int)per_inf_pos;
        } else {
            if (per_inf_input.empty()) cout << "Ban chua nhap du lieu" << please;
            else cout << "Thieu sot thong tin" << please;
            goto check_others;
        }
    }

    for (i = 0; i < max_str - 1; i++) { // doi vi tri thanh min => max kem theo cac thuoc tinh (khong xet index cuoi cung)
        for (int l = i + 1; l < max_str; l++) {
            if (saved_pos[i] > saved_pos[l]) {
                replace_pos = saved_pos[i];
                saved_pos[i] = saved_pos[l];
                saved_pos[l] = replace_pos;
                replace_element = saved_data[i];
                saved_data[i] = saved_data[l];
                saved_data[l] = replace_element;
            }
        }
    }

    for (i = 0; i < max_str; i++) { // kiem tra du lieu dang sau moi thuoc tinh
        if (i != max_str - 1) amount_data = saved_pos[i + 1];
        else amount_data = (int)per_inf_input.length();
        check_data = per_inf_input.substr(saved_pos[i] + saved_data[i].length(), amount_data - (saved_pos[i] + saved_data[i].length()));

        if (check_data == " ") {
            cout << "Ban chua nhap du lieu sau \"" << saved_data[i] << "\"" << please;
            goto check_others;
        } else {
            for (int l = 0; l < check_data.length(); l++) {
                if (check_data[l] == ' ') {
                    if (saved_data[i] == "ngay thang nam sinh") space_date++;
                    if (check_data[l + 1] == ' ') { // du lieu bi spam boi dau ' ', vd: "  ntp "
                        cout << "Khong duoc nhap 2 dau cach lien ke trong \"" << check_data << "\"" << please;
                        space_date = 0;
                        goto check_others;
                    }
                }
            }
            if (space_date > 2) {
                cout << "Dau cach trong du lieu sau \"ngay thang nam sinh\" nhieu hon 2" << please;
                space_date = 0;
                goto check_others;
            }
            if (check(saved_data[i], check_data)) { // du lieu phu hop (" abc... ") => kiem tra dinh dang
                cout << "\"" << check_data << "\" => Du lieu nay chua dung dinh dang" << please;
                goto check_others;
            }
        }
    }

    for (i = 0; i < max_str; i++) {
        per_inf_pos = per_inf_input.find(per_inf[i], 0);
        per_inf[i][0] = (char)toupper(per_inf[i][0]);
        for (int l = 0; l < max_str; l++) {
            if (per_inf_pos == saved_pos[l]) {
                check_data = per_inf_input.substr(saved_pos[l] + per_inf[i].length(), saved_pos[l + 1] - (saved_pos[l] + per_inf[i].length()));
                cout << per_inf[i] << ":" << check_data << "\n";
            }
        }
    }

    // doi cac ki tu dau tien trong tung phan tu cua per_inf ve chu cai thuong
    for (i = 0; i < max_str; i++) per_inf[i][0] = (char)tolower(per_inf[i][0]);
    retype:
    cout << "Ban co muon kiem tra lai chuong trinh voi chuoi thong tin khac ? (0 - Khong / 1 - Co):";
    cin >> option;
    switch (option) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            cin.ignore(100, '\n');
            space_date = 0;
            per_inf_input = '\0';
            for (i = 0; i < 10; i++) saved_data[i] = '\0';
            system("cls");
            goto check_others;
        default:
            cout << "Gia tri ban vua nhap khong phu hop" << please;
            goto retype;
    }

    return 0;
}
