//
//  LotteryTickets.hpp
//  Bushra's_Bazaar
//
//  Created by Bushra Khanom on 12/05/24.
//
#ifndef LOTTERY_TICKETS_HPP
#define LOTTERY_TICKETS_HPP

#include "Product.hpp"
#include <string>
using namespace std;

// The LotteryTickets class represents products in the lottery ticket category.
// It extends the Product class and adds city and county taxes specific to lottery tickets.
class LotteryTickets : public Product {
private:
    double cityTax;  // Additional tax charged by the city.
    double countyTax; // Additional tax charged by the county.

public:
    // Constructor: Sets up a lottery ticket product with its attributes, including city and county taxes.
    LotteryTickets(const string& id, const string& category, const string& name, const string& expDate, double price, double cityTax, double countyTax);

    // Display method: Prints the details of the lottery ticket, overriding the base class display.
    void display() const override;

    // Compute price: Calculates the total price including city and county taxes, overriding the base computePrice.
    double computePrice() const override;

    // Getters to retrieve tax values.
    double getCityTax() const;  // Returns the city tax.
    double getCountyTax() const; // Returns the county tax.
};

#endif
