//
//  LotteryTickets.cpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//
#include "LotteryTickets.hpp"
#include <iostream>
using namespace std;

// Constructor: Initializes a lottery ticket product by calling the base Product constructor
// and setting the city and county taxes.
LotteryTickets::LotteryTickets(const string& id, const string& category, const string& name, const string& expDate, double price, double cityTax, double countyTax)
    : Product(id, category, name, expDate, price), cityTax(cityTax), countyTax(countyTax) {}

// Display method: Shows all the details of the lottery ticket.
// First, it uses the Product's display method, then adds city and county tax info.
void LotteryTickets::display() const {
    Product::display(); // Reuse the base class display for the shared attributes.
    cout << " | City Tax: $" << cityTax << " | County Tax: $" << countyTax; // Add tax details.
}

// Compute price: Adds up the base price, city tax, and county tax to get the total price.
double LotteryTickets::computePrice() const {
    return price + cityTax + countyTax;
}

// Getter for the city tax: Returns how much extra is charged by the city.
double LotteryTickets::getCityTax() const {
    return cityTax;
}

// Getter for the county tax: Returns how much extra is charged by the county.
double LotteryTickets::getCountyTax() const {
    return countyTax;
}
