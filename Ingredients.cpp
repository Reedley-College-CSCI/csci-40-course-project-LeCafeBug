#include "Ingredients.h"
#include <string>

using namespace std;

// getters
const string Ingredient::getName() {
    return InName;
    }
const double Ingredient::getPrice() {
    return price;
    }
const double Ingredient::getQuantity() {
    return quantity;
    }
const string Ingredient::getUnit() {
    return unit;
    }

//constructors 
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