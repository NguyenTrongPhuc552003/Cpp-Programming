//
// Created by Trong_Phuc on 21/04/2024.
//
#include "../headers/Employee.h"

/*SEARCHING & SORTING METHODS*/

int Employee::partition(string *arr, int l, int h) { // a[3] = {"1a", "2b", "3c"}
    double x = stod(arr[h].substr(dashPos(arr[h], 10) + 1));
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (stod(arr[j].substr(dashPos(arr[j], 10) + 1)) <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void Employee::nonRecursion_quickSort(string *data, int h) {
    int *stack; // Create an auxiliary stack
    int top = -1; // initialize top of stack
    int l = 0;

    stack = new int[h - l + 1];
    stack[++top] = l; // push initial values of l and h to stack
    stack[++top] = h;
    while (top >= 0) { // Keep popping from stack while is not empty
        h = stack[top--]; // Pop h and l
        l = stack[top--];
        int p = partition(data, l, h); // Set pivot element at its correct position in sorted array
        if (p - 1 > l) {
            stack[++top] = l; // If there are elements on left side of pivot, then push left side to stack
            stack[++top] = p - 1;
        }
        if (p + 1 < h) { // If there are elements on right side of pivot, then push right side to stack
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int Employee::align_title(string &data, int slashPos) { // taskbar, dau gach xo
    int slashCounter = 0;

    for (int i = 0; i < data.length(); i++) { // dem so luong dau gach xo
        if (data[i] == '|') {
            slashCounter++;
        } else {
            if (slashCounter == slashPos) {
                for (int j = i; j < data.length(); j++) { // dem tu vi tri dau gach xo tro di den khi tim thay dau gach xo tiep theo
                    if (data[j] == '|') return (int) data.substr(i, j - i - 2).length();
                }
                break;
            }
        }
    }
    return 0;
}

unsigned long long Employee::dashPos(string &data, int order) { // co tat ca 10 dau '/'
    unsigned int cnt = 0;
    for (unsigned long long i = 0; i < data.length(); i++) {
        if (data[i] == '/') {
            cnt++;
            if (cnt == order) {
                return i;
            }
        }
    }
    return 0;
}

string Employee::dashPair(string &data, int orderA, int orderB) {
    unsigned long long dashA = dashPos(data, orderA),
            dashB = dashPos(data, orderB);
    return data.substr(dashA + 1, dashB - dashA - 1);
}

/*FEATURE FUNCTIONS*/

int Employee::get_selectionMenu() const { return comInt; }

void Employee::menu() {
    cout << "---> QUAN LY NHAN VIEN <---\n";
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        for (int i = 0; i < amount_menu; i++) {
            cout << "Phim " << i << " - " << features[i];
            if (i != amount_menu - 1) cout << " nhan vien" << endl;
            else cout << endl;
        }
        cout << "Lua chon cua ban la:";
        cin >> comInt;
        if (comInt != amount_menu - 1) system("cls");
        if (cin.fail()) {
            cout << "Ban nhap sai kieu du lieu" << retype_please;
        } else {
            if (comInt < 0 || comInt > amount_menu - 1) {
                cout << "Gia tri ban nhap khong phu hop" << retype_please;
            } else {
                rsm->set_contentFile(str->readFile()); // kiem tra xem co du lieu trong file hay khong
                if (comInt > 0 && comInt < amount_menu - 1 && rsm->get_contentFile().empty()) {
                    cout << "Hien chua co du lieu trong danh sach" << retype_please;
                }
            }
        }
    } while (cin.fail() || comInt < 0 || comInt > amount_menu - 1 ||
             (comInt > 0 && comInt < amount_menu - 1 && rsm->get_contentFile().empty()));
    cin.ignore(100, '\n');
}

void Employee::add() {
    rsm->set_contentFile(str->readFile()); // kiem tra su trung lap id
    rsm->set_id(false);
    rsm->set_name();
    rsm->set_status();
    rsm->set_children();
    rsm->set_eduLevel();
    rsm->set_baseSalary();
    rsm->set_timeKeeping();
    my_list.emplace_back(rsm); // them vao danh sach
    str->writeFile(my_list); // ma hoa danh sach chi tiet va luu vao file
}

void Employee::del() {
    unsigned long long idPos, dashPos;

    rsm->set_contentFile(str->readFile()); // tim thay detail cac nhan vien
    rsm->set_id(true);
    if (distance(my_list.begin(), my_list.end()) > 0) { // xoa trong danh sach truoc (neu co)
        for (auto &i: my_list) {
            if (i->get_id(false) == rsm->get_id(true)) {
                my_list.remove(i);
                break;
            }
        }
    }
    idPos = rsm->get_contentFile().find(rsm->get_id(true));
    dashPos = rsm->get_contentFile().find('-', idPos);
    str->deleteFile(rsm->get_contentFile().erase(idPos, dashPos - idPos + 1));
}

void Employee::find() {
    string foundName, foundEduLevel, foundResult, foundChildren, foundBaseSalary, foundDaysoffAvailable, foundDaysoffUnavailable, foundOverTime, foundTotalSalary;
    char foundStatus = '?';
    int j = 0;

    rsm->set_contentFile(str->readFile()); // tim thay detail cac nhan vien
    rsm->set_id(true);
    for (unsigned long long i = rsm->get_contentFile().find(rsm->get_id(true)) + rsm->get_id(true).length() + 1;
         i < rsm->get_contentFile().length(); i++) { // bat dau tu vi tri tim thay id
        if (rsm->get_contentFile()[i] != '/' && rsm->get_contentFile()[i] != '-') {
            switch (j) {
                case 0:
                    foundName.append(1, rsm->get_contentFile()[i]);
                    break;
                case 1:
                    foundStatus = rsm->get_contentFile()[i];
                    break;
                case 2:
                    foundChildren.append(1, rsm->get_contentFile()[i]);
                    break;
                case 3:
                    foundEduLevel.append(1, rsm->get_contentFile()[i]);
                    break;
                case 4:
                    foundBaseSalary.append(1, rsm->get_contentFile()[i]);
                    break;
                case 5:
                    foundDaysoffAvailable.append(1, rsm->get_contentFile()[i]);
                    break;
                case 6:
                    foundDaysoffUnavailable.append(1, rsm->get_contentFile()[i]);
                    break;
                case 7:
                    foundOverTime.append(1, rsm->get_contentFile()[i]);
                    break;
                case 8:
                    foundResult.append(1, rsm->get_contentFile()[i]);
                    break;
                default:
                    foundTotalSalary.append(1, rsm->get_contentFile()[i]);
            }
        } else {
            j++;
        }
    }
    cout << "- MA SO NHAN VIEN: " << rsm->get_id(true) << endl;
    cout << "- HO VA TEN: " << foundName << endl;
    cout << "- TINH TRANG HON NHAN: " << Resume::get_standardizeStatus(foundStatus) << endl;
    cout << "- SO CON: " << foundChildren << endl;
    cout << "- TRINH DO VAN HOA: " << Resume::get_standardizeEduLevel(foundEduLevel) << endl;
    cout << "- LUONG CAN BAN: " << Resume::get_standardizeMoney(stod(foundBaseSalary)) << " VND" << endl;
    cout << "- SO NGAY NGHI:" << endl;
    cout << "\t+ CO PHEP: " << foundDaysoffAvailable << endl;
    cout << "\t+ KHONG PHEP: " << foundDaysoffUnavailable << endl;
    cout << "- SO NGAY LAM THEM: " << foundOverTime << endl;
    cout << "- KET QUA CONG VIEC: " << Resume::get_standardizeResult(foundResult) << endl;
    cout << "- LUONG THUC LINH: " << Resume::get_standardizeMoney(stod(foundTotalSalary)) << " VND" << endl;
}

void Employee::all() {
    string *sort_contentFile, *default_contentFile, optionView;
    unsigned long long j = 0;
    bool sort_totalSalaries = true, com_contentFile = true;

    rsm->set_contentFile(str->readFile()); // doc du lieu tu file ra ham rsm->get_contentFile()
    while (true) { // qua trinh khoi tao sort_contentFile
        for (auto &i: rsm->get_contentFile()) {
            if (com_contentFile) { // dem so luong thong tin co trong file (so luong dong)
                if (i == '-') j++;
            } else { // bat dau khoi tao mang
                if (i != '-') sort_contentFile[j].append(1, i);
                else j++;
            }
        }
        if (com_contentFile) {
            sort_contentFile = new string[j];
            j = 0;
            com_contentFile = false;
        } else {
            default_contentFile = new string[j];
            for (int i = 0; i < j; i++) default_contentFile[i] = sort_contentFile[i]; // sao chep du lieu tu sort => default
            com_contentFile = true;
            break;
        }
    }
    changeView:
    cout << setw((int)(taskbar.length() / 2 - header.length() / 2)) << ' ' << setw((int)header.length()) << header; // dat header o vi tri CENTER
    cout << taskbar;
    for (int i = 0; i < j; i++) {
        if (com_contentFile) {
            cout << "| " << left << setw(align_title(taskbar, 1)) << default_contentFile[i].substr(0, 8);
            cout << " | " << left << setw(align_title(taskbar, 2)) << Resume::get_shortenName(dashPair(default_contentFile[i], 1, 2));
            cout << " | " << left << setw(align_title(taskbar, 3)) << Resume::get_standardizeMoney(stod(dashPair(default_contentFile[i], 5, 6)));
            cout << " | " << left << setw(align_title(taskbar, 4)) << Resume::get_standardizeMoney(stod(default_contentFile[i].substr(dashPos(default_contentFile[i], 10) + 1))) << " |\n";
        } else { // tang dan
            cout << "| " << left << setw(align_title(taskbar, 1)) << sort_contentFile[i].substr(0, 8);
            cout << " | " << left << setw(align_title(taskbar, 2)) << Resume::get_shortenName(dashPair(sort_contentFile[i], 1, 2));
            cout << " | " << left << setw(align_title(taskbar, 3)) << Resume::get_standardizeMoney(stod(dashPair(sort_contentFile[i], 5, 6)));
            cout << " | " << left << setw(align_title(taskbar, 4)) << Resume::get_standardizeMoney(stod(sort_contentFile[i].substr(dashPos(sort_contentFile[i], 10) + 1))) << " |\n";
        }
    }
    if (j > 1) { // chi sap xep khi co toi thieu 2 thong tin nhan vien trong file
        cout << "Nhan phim Enter de thay doi thu tu sap xep tong luong (phim '/' de thoat):";
        getline(cin, optionView);
        if (optionView.empty()) {
            if (sort_totalSalaries) { // chi thuc hien sap xep 1 lan (thuc hien lai tu dau voi bo du lieu moi: them, xoa ...)
                nonRecursion_quickSort(sort_contentFile, (int)j - 1);
                sort_totalSalaries = false;
            }
            com_contentFile = !com_contentFile; // doi trang thai xem sap xep tong luong cua nhan vien
            system("cls");
            goto changeView;
        }
    }
    delete[] sort_contentFile;
    delete[] default_contentFile;
}