#include <iostream>
#include <malloc.h>
#include "myBank.h"

using namespace std;

int main() {
    myBank* my_usr;

    my_usr = (myBank*)malloc(sizeof(myBank));
    if (my_usr == nullptr) {
        cout << "Error dynamic allocating !\n";
        return 1;
    }
    my_usr->bank_selections();
    switch (my_usr->menu_option) {
        case 0:
            my_usr->add_cif();
            break;
        case 1:
            cin >> my_usr;
            break;
        case 2:
            my_usr->lookup_money();
            break;
        case 3:
            my_usr->cleanup_data();
            break;
    }
    return 0;
}
