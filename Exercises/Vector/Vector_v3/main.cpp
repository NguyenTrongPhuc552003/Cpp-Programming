#include <iostream>
#include "vector"

using namespace std;

void assign_to_array(int array[], int& data) {
    for (int i = 0; i < data; i++) array[i] = i;
}

int main() {
    int static_array[10], amount = 10;

    assign_to_array(static_array, amount); // gan du lieu vao static_array

    return 0;
}
