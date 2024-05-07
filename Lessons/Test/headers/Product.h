//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_PRODUCT_H
#define TEST_PRODUCT_H

// Include necessary libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Product {
protected:
    // Declare attributes
    string name;
    double price{};
    int quantity{};

public:
    // Constructor and Destructor
    Product() = default;
    Product(string, double, int);
    virtual ~Product() = default;

    // Pure virtual functions
    virtual void displayDetails() = 0; // Pure virtual function for displaying product details
    virtual double calculateTotalPrice() = 0; // Pure virtual function for calculating total price
    virtual bool type() = 0; // Pure virtual function for checking product type
    virtual double getDiscount() const; // Pure virtual function for getting discount
    virtual double getTax() const; // Pure virtual function for getting tax
    virtual double getWarrantyCost() const; // Pure virtual function for getting warranty cost

    // Getter and setter methods
    void setPrice(double);
    void setQuantity(int); // May be unnecessary !
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Overload operator < for sorting
    bool operator < (const Product&) const;
};

#endif //TEST_PRODUCT_H
