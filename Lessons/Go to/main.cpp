#include <iostream>
using namespace std;

int main() {
    float math, phys, chem, avr;
    float min = 0.0;
    float max = 10.0;
    string rank = "=> Ban thuoc loai ";

    retype: { // Nhap lai diem cho phu hop
        cout << "Nhap vao lan luot diem toan - ly - hoa cua ban [0 - 10]: \n";
        cout << "Diem toan:";
        cin >> math;
        cout << "Diem ly: ";
        cin >> phys;
        cout << "Diem hoa: ";
        cin >> chem;
    }

    if ((math < min || math > max) || (phys < min || phys > max) || (chem < min || chem > max)) { // 3 mon thuoc [0 - 10]
        cout << "Ao that day ! Moi ban nhap lai:\n";
        goto retype; // Nhay den retype
    }

    avr = (math + phys + chem) / 3; // Tinh diem trung binh
    cout << "Diem trung binh cua ban la: " << avr << endl;
    if (avr >= 0.0 && avr < 5.0) cout << rank << "F";
    if (avr >= 5.0 && avr < 6.5) cout << rank << "D";
    if (avr >= 6.5 && avr < 8.0) cout << rank << "C";
    if (avr >= 8.0 && avr < 9.0) cout << rank << "B";
    if (avr >= 9.0 && avr <= 10.0) cout << rank << "A";

    return 0;
}
