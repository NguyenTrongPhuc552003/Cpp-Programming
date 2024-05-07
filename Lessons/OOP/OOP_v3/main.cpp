#include <iostream>
#include "Animals.h"

using namespace std;

int main() {
    Animals* my_pet = new Dog;
    my_pet->sound();
    delete my_pet;
    return 0;
}
