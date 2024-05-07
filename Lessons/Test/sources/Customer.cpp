//
// Created by Trong_Phuc on 21/04/2024.
//

#include <utility>

#include "../headers/Customer.h"

// Constructor
Customer::Customer(string name, string address, string email) : name(std::move(name)), address(std::move(address)), email(std::move(email)) {}

// Getter
const string& Customer::getName() const {
	return name;
}

const string& Customer::getAddress() const {
	return address;
}

const string& Customer::getEmail() const {
	return email;
}