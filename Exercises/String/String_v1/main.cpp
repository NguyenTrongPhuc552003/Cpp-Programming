#include <iostream>
#include <string>
using namespace std;

bool Alphabet (char kytu) {
    if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z')) return true;
    else return false;
}

int main() {
    char keyboard, vowels[] = { 'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I' };
    string paragraphs;
    int m, n = 0, vowel_counter = 0, consonant_counter = 0;

    check_others:
    cout << "Nhap vao 1 chu bat ki de kiem tra ky tu Alphabet =>";
    cin >> keyboard;

    if (Alphabet(keyboard)) cout << "Day la ky tu Alphabet";
    else cout << "Day khong phai la ky tu Alphabet";

    cout << "\nNhap vao 1 chuoi bat ki de kiem tra so luong nguyen am & phu am =>";
    cin.ignore(100, '\n'); // or "fflush(stdin);"
    getline(cin, paragraphs);

    for (char paragraph : paragraphs) {
        for (char vowel : vowels) {
            if (paragraph != ' ') {
                if (paragraph == vowel) {
                    vowel_counter++;
                } else {
                    n++;
                    if (n == sizeof(vowels) / sizeof(vowels[0])) consonant_counter++;
                }
            }
        }
        n = 0;
    }
    cout << "Chuoi ban vua nhap co " << vowel_counter << " nguyen am & " << consonant_counter << " phu am";

    retype:
    cout << "\nBan co muon thuc hien lai chuong trinh khong ? (0 - Khong / 1 - Co) =>";
    cin >> m;

    switch (m) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh !\n";
            system("pause");
            break;

        case 1:
            vowel_counter = 0;
            consonant_counter = 0;
            goto check_others;

        default:
            cout << "Gia tri ban nhap khong phu hop. Moi ban nhap lai !";
            goto retype;
    }

    return 0;
}
