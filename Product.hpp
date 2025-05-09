//
//  Product.hpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
using namespace std;

// This is the base class for products in Bushra's Bazaar.
// It has all the basic info you'd expect a product to have, like its ID, category, name, expiration date, and price.
class Product {
protected:
    string id;           // Every product gets its own unique ID.
    string category;     // What kind of product is it? (e.g., Electronics, Groceries)
    string name;         // The product’s name—nice and descriptive.
    string expDate;      // If it’s perishable, when does it expire?
    double price;        // How much does it cost (before any magic happens)?

public:
    // Constructor: Used to create a new Product with all its details.
    Product(const string& id, const string& category, const string& name, const string& expDate, double price);
    
    // Destructor: Cleans up when we’re done with the product.
    // It’s virtual because we might have other types of products that extend this one.
    virtual ~Product();

    // Displays all the important details about a product.
    // This is virtual, so child classes can spice it up if needed.
    virtual void display() const;

    // Calculates the price. Default is just returning the base price, but subclasses can do their own thing.
    virtual double computePrice() const;
    
    // Getter functions: These let you peek at the private stuff without breaking encapsulation.
    string getId() const;       // Gives you the product ID.
    string getCategory() const; // Tells you what category this product belongs to.
    string getName() const;     // What’s the product called?
    string getExpDate() const;  // When does this product expire?
};

#endif
