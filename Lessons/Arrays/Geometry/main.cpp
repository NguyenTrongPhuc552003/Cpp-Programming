#include <iostream>
using namespace std;

int main() {
    int triangle, rectangle[3];
    int n, i, l;

    cout << "Chuong trinh ve hinh hoc voi dau '*' - don vi: cm (1cm = 2'*')\n";
    retype:
    cout << "Ban muon ve hinh tam giac vuong can hay tu giac (3 goc vuong) ? (tam giac - 0 / tu giac - 1) =>";
    cin >> n;

    switch (n) {
        case 0:
            cout << "Nhap vao do dai canh tam giac vuong can:";
            cin >> triangle;
            for (i = 0; i < triangle * 2; i++) { // 6 * 2 dong
                cout << "* ";
                for (l = 1; l < triangle * 2 - i; l++) { // 6 * 2 cot
                    if (l > 0 && l < (triangle * 2) - i - 1) cout << "  ";
                    else if (i == 0) cout << "* ";
                }
                cout << "\n";
            }
            break;
            
        case 4:
            cout << "Nhap vao do dai 2 canh\n";
            for (i = 0; i < 2; i++) {
                cout << "Canh thu " << i + 1 << " :";
                cin >> rectangle[i];
            }

            break;

        default:
            cout << "Hien chung toi chi moi hoc tam giac voi tu giac. Moi ban nhap lai\n";
            goto retype;
    }

    return 0;
}
