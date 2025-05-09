//
//  InventoryManager.cpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/11/24.
//

#include "InventoryManager.hpp"
#include "Product.hpp"
#include "Tobacco.hpp"
#include "LotteryTickets.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Loads inventory data from a file.
// It reads each product's details and adds them to the inventory.
// Supports Tobacco and LotteryTickets-specific data as well.
void InventoryManager::loadInventoryFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error ("Could not open the file!");
        return;
    }

    string id, category, name, expDate, line;
    double price, tax1, tax2;

    // Read the file line by line and create product objects based on their category.
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> id >> category >> name >> expDate >> price;
        if (category == "Tobacco") {
            ss >> tax1;
            inventory.push_back(make_shared<Tobacco>(id, category, name, expDate, price, tax1));
        } else if (category == "LotteryTickets") {
            ss >> tax1 >> tax2;
            inventory.push_back(make_shared<LotteryTickets>(id, category, name, expDate, price, tax1, tax2));
        } else {
            inventory.push_back(make_shared<Product>(id, category, name, expDate, price));
        }
    }

    file.close();
    cout << "Inventory loaded from " << filename << endl;
}

// Saves the current inventory to a file.
// Includes extra data for specialized products like Tobacco and LotteryTickets.
void InventoryManager::saveInventoryToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error( "Error: Could not open the file for saving!");
        return;
    }

    for (const auto& product : inventory) {
        // Write common product details first.
        file << product->getId() << " " << product->getCategory() << " " << product->getName() << " "
             << product->getExpDate() << " " << product->computePrice();

        // Check if it's a specialized product and write additional details.
        if (auto tobacco = dynamic_pointer_cast<Tobacco>(product)) {
            file << " " << tobacco->getSpecialTax();
        } else if (auto lottery = dynamic_pointer_cast<LotteryTickets>(product)) {
            file << " " << lottery->getCityTax() << " " << lottery->getCountyTax();
        }

        file << endl;
    }

    file.close();
    cout << "Inventory saved to " << filename << endl;
}

// Adds a new product to the inventory.
void InventoryManager::addProduct(shared_ptr<Product> product) {
    inventory.push_back(product);
    cout << "Product added successfully.\n";
}

// Removes a product from the inventory based on its ID.
void InventoryManager::removeProduct() {
        string productId;
        cout << "Enter product ID to remove: ";
        cin >> productId;

        auto it = find_if(inventory.begin(), inventory.end(),
            [&productId](const shared_ptr<Product>& product) {
                return product->getId() == productId;
            });

        if (it != inventory.end()) {
            cout << "Product removed: " << (*it)->getName() << endl;
            inventory.erase(it);  // Remove product from inventory
        } else {
            throw runtime_error ("Product not found in inventory.\n");
        }
    }


// Searches for a product by ID or name.
void InventoryManager::searchInventory(const string& searchTerm) const {
    bool found = false;

    for (const auto& product : inventory) {
        if (product->getId() == searchTerm || product->getName() == searchTerm) {
            product->display();
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        throw runtime_error("This product not found " );
    }
}

// Searches for products by category.
void InventoryManager::searchByCategory(const string& category) const {
    bool found = false;
    cout << "\nProducts in Category: " << category << endl;
    for (const auto& product : inventory) {
        if (product->getCategory() == category) {
            product->display();
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No products found in this category");
    }
}

// Searches for products within a price range.
void InventoryManager::searchByPriceRange(double minPrice, double maxPrice) const {
    bool found = false;
    cout << "\nProducts in Price Range: " << minPrice << " - " << maxPrice << endl;
    for (const auto& product : inventory) {
        if (product->computePrice() >= minPrice && product->computePrice() <= maxPrice) {
            product->display();
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        throw runtime_error ("No products found in this price range ");
    }
}

// Processes the sale of a product by removing it from the inventory.
void InventoryManager::sellProduct() {
    string productId;
    cout << "\nEnter product ID to sell: ";
    cin >> productId;

    // Find the product to sell and remove it from the inventory.
    auto it = find_if(inventory.begin(), inventory.end(),
                      [&productId](const shared_ptr<Product>& product) {
                          return product->getId() == productId;
                      });

    if (it != inventory.end()) {
        cout << "Product sold: ";
        (*it)->display(); // Show details of the sold product.
        cout << endl;
        inventory.erase(it);
    } else {
        throw runtime_error ("Product not found in inventory.\n");
    }
}
