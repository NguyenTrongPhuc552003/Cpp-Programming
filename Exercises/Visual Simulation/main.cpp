#include "Simulator.h"

int main() {
    /*
     * 0 - Binary Searching
     * 1 - Shaker Sort
     * 2 - Quick Sort
     * 3 - Heap Sort
     * 4 - Radix Sort
     * */
    Simulator *simulator;
    const int myAmount = 5; // so luong phan tu khoi tao
    int mySelection;

    simulator = new Simulator(myAmount);
    mySelection = simulator->modeSelection(); // chon che do (0 - 4)
    simulator->option(mySelection);
    delete simulator;
    return 0;
}
