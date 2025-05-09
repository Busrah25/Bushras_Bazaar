//
//  Tobacco.hpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//
#ifndef TOBACCO_HPP
#define TOBACCO_HPP

#include "Product.hpp"
#include <string>
using namespace std;

// The Tobacco class represents products in the tobacco category.
// It extends the Product class and adds a special tax specific to tobacco products.
class Tobacco : public Product {
private:
    double specialTax; // Extra tax applied to tobacco products.

public:
    // Constructor: Sets up a tobacco product with all its attributes, including the special tax.
    Tobacco(const string& id, const string& category, const string& name, const string& expDate, double price, double specialTax);

    // Display method: Prints the tobacco product details, overriding the base Product display.
    void display() const override;

    // Compute price: Calculates the price including the special tax, overriding the base computePrice.
    double computePrice() const override;

    // Getter for the special tax.
    double getSpecialTax() const;
};

#endif
