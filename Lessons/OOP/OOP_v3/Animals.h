//
// Created by Trong_Phuc on 16/05/2023.
//

#ifndef OOP_V3_ANIMALS_H
#define OOP_V3_ANIMALS_H

#include <iostream>
#include <string>

using namespace std;

class Animals {
public:
    virtual void sound() {
        cout << "Animals Sound\n";
    }
};

class Dog : public Animals {
public:
    void sound() {
        cout << "Gau Gau\n";
    }
};

class Cat : public Animals {
public:
    void sound() {
        cout << "Meo Meo\n";
    }
};

#endif //OOP_V3_ANIMALS_H
