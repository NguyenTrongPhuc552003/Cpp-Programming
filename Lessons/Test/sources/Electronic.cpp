//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Electronic.h"

// Constructor for Electronic class that initializes the name, price, and quantity of the product
Electronic::Electronic(const string& name, double price, int quantity) : Product(name, price, quantity) {}

// Constructor for Electronic class that initializes the invoice number
Electronic::Electronic(int invoiceNumber) : Invoice(invoiceNumber) {}

// Display the details of the product
void Electronic::displayDetails() {
    cout << "Electronic: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
}

// Calculate the total price of the product
double Electronic::calculateTotalPrice() {
    return price * quantity;
}

// Return true if the product is an electronic product
bool Electronic::type() {
    return true;
}

// Calculate the total amount of the invoice
double Electronic::calculateTotalAmount() const {
    double total = 0.0;
    for (const auto& product : products) {
        // Electronic items may have additional taxes or warranties
        total += product->getPrice() + product->getTax() + product->getWarrantyCost();
    }
    return total;
}