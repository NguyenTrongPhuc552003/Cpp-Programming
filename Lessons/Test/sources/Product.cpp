//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Product.h"

// Constructor for Product class that takes a name, price, and quantity
Product::Product(string name, double price, int quantity) : name(std::move(name)), price(price), quantity(quantity) {}

// Return the type of the product
double Product::getDiscount() const {
	return 0.0;
}

// Return the tax of the product
double Product::getTax() const {
	return 0.0;
}

// Return the warranty cost of the product
double Product::getWarrantyCost() const {
	return 0.0;
}

// Update the price of the product
void Product::setPrice(double newPrice) {
    price = newPrice;
}

// Update the quantity of the product < May be unnecessary !>
void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

// Get the name of the product
string Product::getName() const {
    return name;
}

// Get the price of the product
double Product::getPrice() const {
    return price;
}

// Get the quantity of the product
int Product::getQuantity() const {
    return quantity;
}

// Overload operator < for sorting
bool Product::operator < (const Product& other) const {
    return name < other.name;
}