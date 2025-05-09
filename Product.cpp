//
//  Product.cpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//

#include "Product.hpp"
#include <iomanip> // For formatting output

// Constructor: Initializes the product with all the details passed as arguments.
Product::Product(const string& id, const string& category, const string& name, const string& expDate, double price)
    : id(id), category(category), name(name), expDate(expDate), price(price) {}

// Destructor: Doesn't do much here, but it's good practice to have it in case we extend this class later.
Product::~Product() {}

// Display method: Prints all the important details about the product in a neat format.
void Product::display() const {
    cout << "ID: " << id
         << "\nCategory: " << category
         << "\nName: " << name
         << "\nExp. Date: " << expDate
         << "\nPrice: $" << fixed << setprecision(2) << price << endl;
}

// Compute price: Right now, it just returns the base price.
// In subclasses, this could include discounts, taxes, or other factors.
double Product::computePrice() const {
    return price;
}

// Getter for the product ID.
string Product::getId() const {
    return id;
}

// Getter for the product category.
string Product::getCategory() const {
    return category;
}

// Getter for the product name.
string Product::getName() const {
    return name;
}

// Getter for the product expiration date.
string Product::getExpDate() const {
    return expDate;
}
