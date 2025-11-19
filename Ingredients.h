#ifndef INGREDIENTS.H
#define INGREDIENTS.H

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

public:
    // Constructor to set object info
    Ingredient(string name, double price, double quantity, string unit);

    const string getName();
    const double getPrice();
    const double getQuantity();
    const string getUnit();

    //might need a print function 

    const double getCostPerUnit(); 
};

#endif