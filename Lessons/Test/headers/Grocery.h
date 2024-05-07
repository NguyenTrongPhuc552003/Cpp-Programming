//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_GROCERY_H
#define TEST_GROCERY_H

#include "../headers/Product.h"
#include "../headers/Invoice.h"

class Grocery : public Product, public Invoice {
public:
    // Constructor for Grocery class that takes a name, price, and quantity
    Grocery(const string&, double, int);

    // Constructor for Grocery class that takes an invoice number
    Grocery(int);

    // Function prototypes
    void displayDetails() override;
    double calculateTotalPrice() override;
    bool type() override;
    double calculateTotalAmount() const override;
};

#endif //TEST_GROCERY_H
