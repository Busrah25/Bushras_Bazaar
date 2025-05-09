//
//  main.cpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/11/24.
//

#include "InventoryManager.hpp"
#include <iostream>
#include <memory>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Displays the main menu with some cool colors for better readability.
void displayMenu() {
    // Some pastel and soft colors for a nice user experience.
    const string HEADER = "\033[38;5;117m"; // Light Blue
    const string OPTION = "\033[38;5;147m"; // Soft Pink
    const string PROMPT = "\033[38;5;151m"; // Pastel Green
    const string RESET = "\033[0m";

    // Header for the application
    cout << HEADER
         << "\n+-----------------------------------+"
         << "\n|     Welcome to Bushra's Bazaar    |"
         << "\n+-----------------------------------+"
         << RESET << endl;

    // Menu options
    cout << OPTION << " 1. Search Inventory" << RESET << endl;
    cout << OPTION << " 2. Sell Products" << RESET << endl;
    cout << OPTION << " 3. Add New Inventory" << RESET << endl;
    cout << OPTION << " 4. Remove Inventory" << RESET << endl;
    cout << OPTION << " 5. Exit" << RESET << endl;

    cout << PROMPT << "\nEnter your choice: " << RESET;
}

int main() {
    // Create an InventoryManager instance to handle all inventory operations.
    InventoryManager manager;

    // Load inventory from a file at startup.
    manager.loadInventoryFromFile("/Users/bushra/Documents/Bushra's_Bazaar/Bushra's_Bazaar/Bushra's_Bazaar/Inventory.txt");

    int choice; // Variable to store the user's menu choice.
    try {
        do {
            displayMenu(); // Show the menu to the user.
            cin >> choice; // Get the user's choice.
            
            switch (choice) {
                case 1: { // Search inventory.
                    int searchType;
                    cout << "Select Search Type: 1. By Category 2. By Exact Product 3. By Price Range: ";
                    cin >> searchType;
                    
                    if (searchType == 1) {
                        string category;
                        cout << "Enter Category: ";
                        cin >> category;
                        manager.searchByCategory(category);
                    } else if (searchType == 2) {
                        string product;
                        cout << "Enter Product Name or ID: ";
                        cin >> product;
                        manager.searchInventory(product);
                    } else if (searchType == 3) {
                        double minPrice, maxPrice;
                        cout << "Enter Minimum Price: ";
                        cin >> minPrice;
                        cout << "Enter Maximum Price: ";
                        cin >> maxPrice;
                        manager.searchByPriceRange(minPrice, maxPrice);
                    } else {
                        cout << "Invalid search type.\n";
                    }
                    break;
                }
                case 2: // Sell a product.
                    manager.sellProduct();
                    break;
                case 3: { // Add new products to inventory.
                    int type;
                    cout << "Select Product Type: 1. Regular 2. Tobacco 3. Lottery Tickets: ";
                    cin >> type;
                    
                    if (type == 1) { // Adding a regular product.
                        string id, category, name, expDate;
                        double price;
                        cout << "Enter ID, Category, Name, ExpDate (YYYY-MM-DD), and Price: ";
                        cin >> id >> category >> name >> expDate >> price;
                        manager.addProduct(make_shared<Product>(id, category, name, expDate, price));
                    } else if (type == 2) { // Adding a tobacco product.
                        string id, category, name, expDate;
                        double price, specialTax;
                        cout << "Enter ID, Category, Name, ExpDate (YYYY-MM-DD), Price, and Special Tax: ";
                        cin >> id >> category >> name >> expDate >> price >> specialTax;
                        manager.addProduct(make_shared<Tobacco>(id, category, name, expDate, price, specialTax));
                    } else if (type == 3) { // Adding a lottery ticket.
                        string id, category, name, expDate;
                        double price, cityTax, countyTax;
                        cout << "Enter ID, Category, Name, ExpDate (YYYY-MM-DD), Price, City Tax, and County Tax: ";
                        cin >> id >> category >> name >> expDate >> price >> cityTax >> countyTax;
                        manager.addProduct(make_shared<LotteryTickets>(id, category, name, expDate, price, cityTax, countyTax));
                    } else {
                        cout << "Invalid type.\n";
                    }
                    break;
                }
                case 4: // Remove a product.
                    manager.removeProduct();
                    break;
                case 5: // Exit the application.
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 5);
        
        // Save the inventory to a file before exiting.
        manager.saveInventoryToFile("Inventory.txt");
    }
        
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    
    return 0;
}
