#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include <string>

using namespace std;

/*
 *  Description:
 * This class is used for every ingredient found in its matching file Ingredients.cvs
 * to store and get the name, price, quantity, unit, as well as caculate and get
 * the cost per unit of the ingredient
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
    const double getPP() const;   // PP means → Purchase Price 

    //might need a print function 

    const double getCostPerUnit(); 


};

#endif