//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Special.h"

// Constructor
Special::Special(const string& name, const string& address, const string& email) : Customer(name, address, email) {}

// Method
double Special::applyDiscount(double totalPrice) const {
    // Special customers get 10% discount
    return totalPrice * 0.9;
}

// Getter
string Special::getType() const {
    return "Special";
}