//
//  InventoryManager.hpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//

#ifndef INVENTORYMANAGER_HPP
#define INVENTORYMANAGER_HPP

#include <vector>
#include <memory>
#include <string>
#include "Product.hpp"
#include "Tobacco.hpp"
#include "LotteryTickets.hpp"

using namespace std;

// The InventoryManager class handles everything related to the store's inventory.
// It keeps track of products, allows for searches, and manages sales and updates.
class InventoryManager {
private:
    vector<shared_ptr<Product>> inventory; // A list of products, stored as smart pointers for flexibility.

public:
    // Loads product data from a file into the inventory.
    void loadInventoryFromFile(const string& filename);

    // Saves the current inventory data to a file.
    void saveInventoryToFile(const string& filename) const;

    // Adds a new product to the inventory.
    void addProduct(shared_ptr<Product> product);

    // Removes a product from the inventory based on its ID.
    void removeProduct();

    // Searches for all products in a specific category and displays them.
    void searchByCategory(const string& category) const;

    // Finds products within a specified price range and displays them.
    void searchByPriceRange(double minPrice, double maxPrice) const;

    // Searches for a product by a term (like name or ID).
    void searchInventory(const string& searchTerm) const;

    // Handles the sale of a product by removing it from the inventory.
    void sellProduct();

    // Displays the entire inventory. Great for getting an overview of all products.
    void displayInventory() const;
};

#endif
