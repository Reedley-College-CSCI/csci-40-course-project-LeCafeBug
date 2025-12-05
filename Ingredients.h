#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>

using namespace std;

/*
 *  Description:
 * This class is used for ingredients that come from the file Ingredients.cvs.
 * It stores and get the name, price, quantity, and unit fromt his file.
 * It also calculates things based of this info like the the cost per unit and 
 * the purchase quantity in grams.
*/

class Ingredient {            

private:
    string InName;      // For the name of ingredients
    double price;   
    double quantity;
    string unit;

    double convertToGrams(double quantity, const string fromUnit) const;

public:
    // Constructor to set object info
    Ingredient();
    Ingredient(string name, double price, double quantity, string unit);

    const string getName() const;
    const double getPrice() const;
    const double getQuantity() const;
    const string getUnit() const;

    const double getPQg()const;  // PQg means → Purchase Quantity in grams
    const double getPP() const;   // PP means → Purchase Price -Unnessery as getPrice already exist 

    //might need a print function 

    const double getCostPerUnit(); 


};

#endif