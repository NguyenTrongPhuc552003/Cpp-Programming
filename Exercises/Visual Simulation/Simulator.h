//
// Created by Trong_Phuc on 21/07/2023.
//

#ifndef VISUAL_SIMULATION_SIMULATOR_H
#define VISUAL_SIMULATION_SIMULATOR_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Simulator {
private:
    const string modes[5] = {"Binary Searching",
                             "Shaker Sort",
                             "Quick Sort",
                             "Heap Sort",
                             "Radix Sort"};
    int *myArray = nullptr;
    int n = 0, randomMode = 0;

    int partition(int *arr, int low, int high);
    void heapify(int *arr, int m, int i);
    static int getMax(const int *arr, int m);
    static void countSort(int *arr, int m, int exp);

public:
    Simulator(int n);
    ~Simulator();
    int modeSelection();
    void option(int mode);
    void binarySearching(int target);
    void shakerSort(int left, int right);
    void quickSort(int *arr, int low, int high);
    void heapSort(int *arr, int amount);
    void radixSort(int *arr, int amount) const;
};

/*SUPPORT METHODS*/

int Simulator::partition(int *arr, int low, int high) {
    static int counter = 0;
    int pivot = arr[high], i = low - 1;

    cout << "* Lan thu " << ++counter << ": " << "Diem chot = " << pivot << endl << "=> ";
    for (int j = 0; j < n; j++) cout << myArray[j] << ' ';
    cout << endl;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Simulator::heapify(int *arr, int m, int i) {
    static int counter = 0;
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    cout << "* Lan thu " << ++counter << ": ";
    for (int j = 0; j < n; j++) cout << myArray[j] << ' ';
    cout << "\n- Largest = " << largest;
    cout << ", Left = " << left;
    cout << ", Right = " << right << endl;
    if (left < m && arr[left] > arr[largest]) {
        cout << "- arr[left] (" << arr[left] << ") > arr[largest] (" << arr[largest] << ") ";
        cout << "-> largest = " << left << endl;
        largest = left;
    }
    if (right < m && arr[right] > arr[largest]) {
        cout << "- arr[right] (" << arr[right] << ") > arr[largest] (" << arr[largest] << ") ";
        cout << "-> largest = " << right << endl;
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        cout << "- largest != i, so we swap values of them\n";
        heapify(arr, m, largest);
    }
}

int Simulator::getMax(const int *arr, int m) {
    int mx = arr[0];

    for (int i = 1; i < m; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void Simulator::countSort(int *arr, int m, int exp) {
    string unit = to_string(exp), units[] = {"don vi", "chuc", "tram",
                                                 "nghin", "chuc nghin", "tram nghin",
                                                 "trieu", "chuc trieu", "tram chieu",
                                                 "ti", "chuc ti", "tram ti"}; // 1-0, 10-1, 100-2, ...
    static int counter = 0;
    int *output = new int[m]; // Output array
    int i, count[10] = {0}, zeroCounter = 0;

    for (i = 0; i < m; i++) count[(arr[i] / exp) % 10]++; // Store count of occurrences in count[]
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = m - 1; i >= 0; i--) { // Build the output array
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < unit.length(); i++) {
        if (unit[i] == '0') zeroCounter++;
    }
    cout << "* Lan thu " << ++counter << ": hang " << units[zeroCounter] << endl << "=> ";
    for (i = 0; i < m; i++) {
        arr[i] = output[i];
        cout << arr[i] << ' ';
    }
    cout << endl;
}

/*MAIN METHODS*/

Simulator::Simulator(int n) {
    int inputMethod, lowerBound, upperBound;

    srand(time(nullptr));
    this->n = n;
    myArray = new int[n];
    cout << "--> SETTING UP DATA <--\n";
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Ban muon nhap lieu thu cong hay random ? (0 - Thu cong / !0 - Random) =>";
        cin >> inputMethod;
        if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
    } while (cin.fail());
    randomMode = inputMethod;
    if (inputMethod == 0) {
        for (int i = 0; i < n; i++) {
            do {
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                }
                cout << "Nhap vao phan tu thu " << i + 1 << ':';
                cin >> myArray[i];
                if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
            } while (cin.fail());
        }
    } else {
        do {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            cout << "Nhap vao gioi han duoi:";
            cin >> lowerBound;
            if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
        } while (cin.fail());
        do {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            cout << "Nhap vao gioi han tren:";
            cin >> upperBound;
            if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
        } while (cin.fail());
        for (int i = 0; i < n; i++) myArray[i] = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    }
    system("cls");
}

Simulator::~Simulator() { delete[] myArray; }

int Simulator::modeSelection() {
    int selection = 0;

    cout << "--> MODE SELECTION <--\n";
    for (int i = 0; i < sizeof(modes) / sizeof(modes[0]); i++) cout << i << " - " << modes[i] << endl;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cout << "Lua chon cua ban la:";
        cin >> selection;
        if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
    } while (cin.fail());
    return selection;
}

void Simulator::option(int mode) {
    system("cls");
    switch (mode) {
        case 0:
            int tar;

            cout << "--> BINARY SEARCHING <--\n";
            if (randomMode == 0) {
                do {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Nhap vao phan tu can tim:";
                    cin >> tar;
                    if (cin.fail()) cout << "Ban nhap sai kieu du lieu. Moi ban nhap lai !\n";
                } while (cin.fail());
            } else {
                tar = myArray[rand() % n];
                cout << "Phan tu can tim duoc chon ngau nhien: " << tar << endl;
            }
            binarySearching(tar);
            break;
        case 1:
            cout << "--> SHAKER SORT <--\n";
            shakerSort(0, n - 1);
            break;
        case 2:
            cout << "--> QUICK SORT <--\n";
            quickSort(myArray, 0, n - 1);
            break;
        case 3:
            cout << "--> HEAP SORT <--\n";
            heapSort(myArray, n);
            break;
        case 4:
            cout << "--> RADIX SORT <--\n";
            radixSort(myArray, n);
            break;
        default:
            cout << "Hay chon mode thuoc [0; 4] !\n";
    }
}

void Simulator::binarySearching(int target) {
    int mid, left = 0, right = n - 1, counter = 0;
    bool notFound = true;

    sort(myArray, myArray + n); // sorting an unsorted array before binary searching
    while (left <= right) {
        cout << "* Lan thu " << ++counter << ':';
        mid = left + (right - left) / 2;
        for (int i = 0; i < n; i++) {
            if (myArray[i] != myArray[mid]) cout << "  " << myArray[i] << "  ";
            else cout << " >" << myArray[i] << "< ";
        }
        if (myArray[mid] == target) {
            cout << "(Found !)\n";
            notFound = false;
            break;
        } else {
            if (myArray[mid] < target) left = mid + 1;
            else right = mid - 1;
            cout << "(Left: " << left << (left < right ? " <" : " >") << " Right: " << right << ")\n";
        }
    }
    if (notFound) cout << "* This element \"" << target << "\" is not found in your array !\n";
}

void Simulator::shakerSort(int left, int right) {
    int counter = 0;
    bool swapped = true;

    while (swapped) {
        cout << "* Lan thu " << ++counter << ":\n";
        swapped = false;
        cout << "- Left side:\n";
        for (int i = left; i < right; i++) {
            if (myArray[i] > myArray[i + 1]) {
                cout << "+ arr[i] (" << myArray[i] << ") > arr[i + 1] (" << myArray[i + 1] << ") => Swapping them !\n";
                swap(myArray[i], myArray[i + 1]);
                swapped = true;
            }
        }
        right--;
        cout << "- Right side:\n";
        for (int i = right; i > left; i--) {
            if (myArray[i] < myArray[i - 1]) {
                cout << "+ arr[i] (" << myArray[i] << ") < arr[i - 1] (" << myArray[i - 1] << ") => Swapping them !\n";
                swap(myArray[i], myArray[i - 1]);
                swapped = true;
            }
        }
        left++;
        cout << "=> ";
        for (int i = 0; i < n; i++) cout << myArray[i] << ' ';
        cout << endl;
    }
}

void Simulator::quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Simulator::heapSort(int *arr, int amount) {
    cout << "BUILD HEAP\n";
    for (int i = amount / 2 - 1; i >= 0; i--) {
        heapify(arr, amount, i);
    }
    cout << "ONE BY ONE EXTRACT AN ELEMENT FROM HEAP\n";
    for (int i = amount - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // move current root to end
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
}

void Simulator::radixSort(int *arr, int amount) const {
    int max = getMax(arr, amount);

    cout << "So lon nhat trong mang: " << max << endl; // co bao nhieu don vi => lap lai bay nhieu lan
    for (int exp = 1; max / exp > 0; exp *= 10) countSort(arr, n, exp);
}

#endif //VISUAL_SIMULATION_SIMULATOR_H
