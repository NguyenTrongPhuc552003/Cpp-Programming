//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Grocery.h"

// Constructor for Grocery class that initializes the name, price and quantity of the product
Grocery::Grocery(const string& name, double price, int quantity) : Product(name, price, quantity) {}

// Constructor for Grocery class that initializes the invoice number
Grocery::Grocery(int invoiceNumber) : Invoice(invoiceNumber) {}

// Display the details of the product
void Grocery::displayDetails() {
    cout << "Grocery: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
}

// Calculate the total price of the product
double Grocery::calculateTotalPrice() {
    return price * quantity;
}

// Return the type of the product
bool Grocery::type() {
    return false;
}

// Calculate the total amount of the invoice
double Grocery::calculateTotalAmount() const {
    double total = 0.0;
    for (const auto& product : products) {
        // Grocery items may have discounts or special offers
        total += product->getPrice() * (1 - product->getDiscount()); // Assuming discount is in percentage
    }
    return total;
}