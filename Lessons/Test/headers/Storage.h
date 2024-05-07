//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_STORAGE_H
#define TEST_STORAGE_H

#include "../headers/Product.h"

const string fileName = "products.csv"; // File name to save/load products

class Storage {
protected:
    // Function to process content of a line
    static string contentProcessor(const string&, size_t, size_t);

public:
    // Function prototypes
    static bool saveProductsToFile(const vector<Product*>&);
    static bool loadProductsFromFile(vector<Product*>&);
    static bool updateProductsFromFile(vector<Product*>&);
    static bool clearProductsFile();
};

#endif //TEST_STORAGE_H
