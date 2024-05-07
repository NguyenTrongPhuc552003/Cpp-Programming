//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Invoice.h"

// Constructors
Invoice::Invoice(int invoiceNumber) : invoiceNumber(invoiceNumber) {}

// Methods
void Invoice::addProduct(Product* product) {
    products.push_back(product);
}

// Virtual Methods
double Invoice::calculateTotalAmount() const {
    double total = 0.0;
    for (const auto& product : products) {
        total += product->getPrice();
    }
    return total;
}

void Invoice::displayInvoiceDetails() const {
    cout << "Invoice Number: " << invoiceNumber << endl;
    cout << "Products:\n";
    for (const auto& product : products) {
        cout << " - " << product->getName() << ": $" << product->getPrice() << endl;
    }
    cout << "Total Amount: $" << calculateTotalAmount() << endl;
}