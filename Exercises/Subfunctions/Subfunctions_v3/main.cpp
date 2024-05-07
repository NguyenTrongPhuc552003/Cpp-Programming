#include <iostream>
#include "iomanip"

using namespace std;

float Average_6subs (float a, float b, float c, float d, float e, float f) {
    return ((a + b) * 2 + c + d + e + f) / 8; // Toan, Van he so 2 / 'return' tra lai gia tri
}

void Check_6subs (float a, float b, float c, float d, float e, float f) {
    string subjects_stored[] = {"Toan hoc", "Ngu van", "Tieng Anh", "Vat ly", "Hoa hoc", "Sinh hoc"};
    float marks_stored[] = {a, b, c, d, e, f};
    int subjects_sum = 0, flag = 0;

    cout << "\nTong so mon hoc co diem duoi 5.0: ";
    again:
    for (int i = 0; i < 6; i++) {
        if (marks_stored[i] < 5.0) {
            if (flag == 0) subjects_sum++;
            else cout << subjects_stored[i] << ", ";
        }
    }

    if (flag == 0) {
        if (subjects_sum > 0) {
            cout << subjects_sum << " mon (";
            flag++;
            goto again;
        } else cout << "0 mon"; // het vong for, flag & subjects_sum van bang 0
    } else cout << "\b\b)";
}

void Classify (float avr, float math, float literature) {
    cout << "\nXep loai hoc luc: ";

    if (math < 5.0 || literature < 5.0) goto compulsory;

    if (avr >= 0 && avr < 5.0) {
        compulsory:
        cout << "F";
    } else if (avr < 6.5) {
        cout << "D";
    } else if (avr < 8.0) {
        cout << "C";
    } else if (avr < 9.0) {
        cout << "B";
    } else if (avr < 10.0) {
        cout << "A";
    }

    if (math < 5.0 && literature >= 5.0) cout << " (Ly do: diem mon Toan hoc duoi 5.0, cu the la " << math << ")";
    else if (literature < 5.0 && math >= 5.0) cout << " (Ly do: diem mon Ngu van duoi 5.0, cu the la " << literature << ")";
    else if (math < 5.0 && literature < 5.0) cout << " (Ly do: diem 2 mon Toan hoc & Ngu van deu duoi 5.0. cu the la " << math << " & " << literature << ")";
}

int main() {
    string subjects[] = {"Toan hoc (he so 2)", "Ngu van (he so 2)", "Tieng Anh", "Vat ly", "Hoa hoc", "Sinh hoc"};
    float marks[6], avr; // index (0 - 5): Toan hoc - Sinh hoc
    int n;

    check_again:
    cout << "Diem TB va Xep loai hoc luc cua ban\n";
    for (int i = 0; i < 6; i++) {
        do {
            cout << "Nhap vao diem mon " << subjects[i] << ":";
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 10.0) cout << "Diem cua ban dua tren thang diem 10 [0 - 10.0]. Moi ban nhap lai !\n";
        } while (marks[i] < 0 || marks[i] > 10.0);
    }

    cout << "Diem trung binh 6 mon: " << setprecision(2) << Average_6subs(marks[0], marks[1], marks[2], marks[3], marks[4], marks[5]);

    Check_6subs(marks[0], marks[1], marks[2], marks[3], marks[4], marks[5]); // Kiem tra nhung mon hoc duoi 5.0

    avr = Average_6subs(marks[0], marks[1], marks[2], marks[3], marks[4], marks[5]);
    Classify(avr, marks[0], marks[1]); // Xep loai hoc luc

    retype:
    cout << "\nBan co muon kiem tra lai khong ? (0 - Khong / 1 - Co) =>";
    cin >> n;

    switch (n) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;
        case 1:
            goto check_again;
        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0; // trao quyen dieu hanh lai cho may tinh (return 1: chuong trinh co van de ...)
}
