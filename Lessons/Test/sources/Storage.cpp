//
// Created by Trong_Phuc on 21/04/2024.
//

#include "../headers/Storage.h"
#include "../headers/Electronic.h"
#include "../headers/Grocery.h"
#include "../headers/Supermarket.h"

// Function to process content of a line
string Storage::contentProcessor(const string& line, size_t commaPos1, size_t commaPos2) {
    string result;
    size_t commaCounter = 0;
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            commaCounter++;
        }
        else {
            if (commaCounter == commaPos1) {
                result += line[i];
            }
            if (commaCounter == commaPos2) {
                break;
            }
        }
    }
    return result;
}

// Function to save products to file
bool Storage::saveProductsToFile(const vector<Product*>& products) {
    ofstream outFile(fileName, ios::app | ios::out);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing: " << fileName << endl;
        return false;
    }
    if (products.empty()) {
		cout << "No products to save!\n";
		return false;
	}
    for (const auto& product : products) {
        outFile << product->type() << ',' << product->getName() << ',' << product->getPrice() << "," << product->getQuantity() << endl;
    }
    outFile.close();
    cout << "Products saved to CSV file: " << fileName << endl;
    return true;
}

// Function to load products from file
bool Storage::loadProductsFromFile(vector<Product*>& products) {
    ifstream inFile(fileName);
    bool checkEmpty = true;

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file for reading: " << fileName << endl;
        return false;
    }

    products.clear(); // Clear products vector before loading new products
    string line;
    while (getline(inFile, line)) {
        if (checkEmpty) checkEmpty = false; // Check if file is empty
        istringstream iss(line);
        string name = contentProcessor(line, 1, 2);
        double price = stod(contentProcessor(line, 2, 3));
        int quantity = stoi(line.substr(line.find_last_of(',') + 1));
        if (line.find_first_of('1') != string::npos) products.push_back(new Electronic(name, price, quantity));
        else products.push_back(new Grocery(name, price, quantity));
    }

    inFile.close();
    if (checkEmpty) {
		cout << "File is empty!\n";
		return false;
    }
    return true;
}

// Function to update products data
bool Storage::updateProductsFromFile(vector<Product*>& loadedProducts) {
    if (Storage::loadProductsFromFile(loadedProducts)) { // Check if file is empty
        cout << "Enter product name to update: ";
        string name;
        cin >> name;

        // Search for product by name
        Supermarket supSearcher(loadedProducts); // Create a temporary supermarket to search for products
        Product* product = supSearcher.binarySearch(name); // Search for product by name
        if (product) { // If product is found
            // Update product details
            cout << "Enter new price for " << product->getName() << ": ";
            double price;
            cin >> price;

            cout << "Enter new quantity for " << product->getName() << ": ";
            int quantity;
            cin >> quantity;

            for (const auto& pro : loadedProducts) { // Update pro details
                if (pro->getName() == name) {
					pro->setPrice(price);
					pro->setQuantity(quantity);
                    break;
				}
			}

            // Clear file and save updated products
            return (Storage::clearProductsFile() && Storage::saveProductsToFile(loadedProducts));
        } else {
            cout << "Product not found!\n";
            return false;
        }
    }
    else {
        return false;
    }
}

// Function to clear products file
bool Storage::clearProductsFile() {
    ofstream outFile(fileName, ios::out);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing: " << fileName << endl;
        return false;
    }
    outFile.close();
    return true;
}