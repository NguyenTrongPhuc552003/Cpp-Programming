#include "headers/Manager.h"

int main() {
    Supermarket supermarket;
    Manager manager(supermarket);
    manager.loop();
    return 0;
}