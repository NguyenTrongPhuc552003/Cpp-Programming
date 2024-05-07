//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_ELECTRONIC_H
#define TEST_ELECTRONIC_H

#include "../headers/Product.h"
#include "../headers/Invoice.h"

class Electronic : public Product, public Invoice {
public:
    // Constructor for Electronic class that takes a name, price, and quantity
    Electronic(const string&, double, int);

    // Constructor for Electronic class that takes an invoice number
    Electronic(int);

    // Function prototypes
    void displayDetails() override;
    double calculateTotalPrice() override;
    bool type() override;
    double calculateTotalAmount() const override;
};

#endif //TEST_ELECTRONIC_H
