//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Supermarket.h"

// Constructor to initialize products
Supermarket::Supermarket(const vector<Product*>& products) : products(products) {}

// Destructor to delete all products
Supermarket::~Supermarket() {
    for (Product* product : products) {
        delete product;
    }
    products.clear();
}

// Getter for products
vector<Product*> Supermarket::getProducts() {
    return products;
}

// Binary search for product by name
Product* Supermarket::binarySearch(const string& productName) { // None Recursive Binary search for product by name
    Supermarket::sortProductsByName(); // Ensure products are sorted before binary search
    int left = 0;
    int right = (int)products.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (products[mid]->getName() == productName) {
            return products[mid];
        }
        if (products[mid]->getName() < productName) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return nullptr; // Product not found
}

// Add product to supermarket
void Supermarket::addProduct(Product* product) {
    products.push_back(product);
}

// Remove product from supermarket
void Supermarket::removeProduct(const string& productName) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i]->getName() == productName) {
            delete products[i];
            products.erase(products.begin() + i);
            return;
        }
    }
}

// Display details of all products
void Supermarket::displayProductDetails() {
    cout << "Available Products:\n";
    unsigned int i = 1;
    for (Product* product : products) {
        cout << i++ << ". ";
        product->displayDetails();
    }
}

// Calculate total revenue of all products
double Supermarket::calculateTotalRevenue() {
    double totalRevenue = 0.0;
    for (Product* product : products) {
        totalRevenue += product->calculateTotalPrice();
    }
    return totalRevenue;
}

// Sort products by name
void Supermarket::sortProductsByName() {
    sort(products.begin(), products.end(), [](Product* a, Product* b) {
        return *a < *b;
        });
}