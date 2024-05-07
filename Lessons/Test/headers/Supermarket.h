//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_SUPERMARKET_H
#define TEST_SUPERMARKET_H

#include "../headers/Product.h"

class Supermarket {
private:
    vector<Product*> products; // List of products in the supermarket

public:
    // Constructor and Destructor
    Supermarket() = default;
    explicit Supermarket(const vector<Product*>&);
    ~Supermarket();

    // Supporting methods
    vector<Product*> getProducts();
    Product* binarySearch(const string&);

    // Main methods
    void addProduct(Product*);
    void removeProduct(const string&);
    void displayProductDetails();
    double calculateTotalRevenue();
    void sortProductsByName();
};

#endif //TEST_SUPERMARKET_H
