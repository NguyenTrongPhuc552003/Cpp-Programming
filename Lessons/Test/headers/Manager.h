//
// Created by Trong_Phuc on 21/04/2024.
//

#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include "../headers/Supermarket.h"

class Manager {
private:
    Supermarket& supermarket;
    string menuOptions[11] = {
            "1.  Add Product",
            "2.  Remove Product",
            "3.  Sort Products by Name",
            "4.  Search Product",
            "5.  Display Product Details",
            "6.  Calculate Total Revenue",
            "7.  Load Products from File",
            "8.  Save Products to File",
            "9.  Update Product from File",
            "10. Clear Products File",
            "0.  Exit"
    };
    int menuOptionsSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

public:
    // Constructor for Manager class that takes a reference to a Supermarket object
    Manager(Supermarket&);

    // Main methods of Manager class
    void loop();
    void displayMainMenu();

    // Function prototypes
    void addProduct();
    void removeProduct();
    void sortProductsByName();
    void searchProduct();
    void displayProductDetails();
    void calculateTotalRevenue();
    void loadProductsFromFile();
    void saveProductsToFile();
    static void updateProductFromFile();
    static void clearProductsFile();
};

#endif //TEST_MANAGER_H
