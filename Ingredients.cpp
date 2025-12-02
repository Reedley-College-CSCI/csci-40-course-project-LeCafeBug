#include "Ingredients.h"
#include <string>
#include <iostream>

using namespace std;

// getters
const string Ingredient::getName() const{
    return InName;
    }
const double Ingredient::getPrice() const{
    return price;
    }
const double Ingredient::getQuantity() const{
    return quantity;
    }
const string Ingredient::getUnit() const{
    return unit;
    }

const double Ingredient::getPQg() const{
    return convertToGrams(quantity, unit);
}
const double Ingredient::getPP() const{
    return price;
}

//constructors 
Ingredient::Ingredient(){
    InName = "NA";
    price = 0.0;
    quantity = 0.0;
    unit = "NA";
}

Ingredient::Ingredient( string n, double p, double q, string u ){
    InName = n;
    price = p;
    quantity = q;
    unit = u;
}

//functions
const double Ingredient::getCostPerUnit() {
    if (quantity == 0) {
        return 0.00;
    }
    
    return price / quantity;
}

// Private helper function
double Ingredient::convertToGrams(double q, const string fromUnit) const{
    string unitLower = fromUnit;

    for (char& c : unitLower) {
        c = tolower(c);
    }
    
    // Conversion to grams
    if (unitLower == "g" || unitLower == "gram" || unitLower == "grams") {
        return q;
    } 
    else if (unitLower == "oz" || unitLower == "ounce" || unitLower == "ounces") {
        return q * 28.3495;
    }
    else if (unitLower == "lb" || unitLower == "lbs") {
        return q * 453.592;
    }
    else if (unitLower == "count" || unitLower == "counts" ) {
        return q;
    }
    else {
        // Unknown unit - return original amount with warning
        cout << "Warning: Unknown unit for ingredient '" << InName << endl;
        return q;
    }
}
