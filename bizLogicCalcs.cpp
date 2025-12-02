#include "Ingredients.h"
#include "Recipe.h"
#include <iostream>
#include <vector>

using namespace std;

//  This file stores functions that do calculations based on loaded info.

// gets both Purchase Quantity in grams and Purchase Price for each ingredient and adds to two seperate arrays 
void createIngredientArrays(const Ingredient ingredients[5], double ingredientPQg[5], double ingredientPP[5]) {
    for (int i = 0; i < 5; i++) {
        ingredientPQg[i] = ingredients[i].getPQg();
        ingredientPP[i] = ingredients[i].getPP();
    }
}