//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_NORMAL_H
#define TEST_NORMAL_H

#include "../headers/Customer.h"

class Normal : public Customer {
public:
    // Constructor
    Normal(const string&, const string&, const string&);

    // Method
    double applyDiscount(double) const override;

    // Getter
    string getType() const override;
};

#endif //TEST_NORMAL_H
