//
//  Tobacco.cpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//
#include "Tobacco.hpp"
#include <iostream>
using namespace std;

// Constructor: Initializes a Tobacco product by calling the base Product constructor
// and setting the special tax.
Tobacco::Tobacco(const string& id, const string& category, const string& name, const string& expDate, double price, double specialTax)
    : Product(id, category, name, expDate, price), specialTax(specialTax) {}

// Display method: Prints the details of the tobacco product.
// It first calls the Product's display method and then adds the special tax info.
void Tobacco::display() const {
    Product::display(); // Reuse the base class display for shared attributes.
    cout << " | Special Tax: $" << specialTax; // Add the special tax detail.
}

// Compute price: Returns the total price, which is the base price plus the special tax.
double Tobacco::computePrice() const {
    return price + specialTax;
}

// Getter for the special tax: Lets us see how much extra tax is added for tobacco products.
double Tobacco::getSpecialTax() const {
    return specialTax;
}
