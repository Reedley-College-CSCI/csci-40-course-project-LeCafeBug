// CSCI-40 Final Project
// Author: Edgar Jarquin

/* 
 * Description:
 *
 * Add instruciton on how to open with CMake
 * 
 * clean up lines -====...
 * 
 * add test for create load and add/make config file
 * 
 * !!!need to fix abilty to use classes
*/

#include <iostream>
#include <iomanip>
#include "Ingredients.h"
#include "Recipe.h"
#include "Configurations.h"

using namespace std;

//functions 
void loadObjectsInfo(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);
void loadUserConfigs(Configurations& config);
void createIngredientArrays(const Ingredient ingredients[5], double ingredientPQg[5], double ingredientPP[5]);

//test functions
void testIngredientClass(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void testRecipeClass(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);
void testConfigClass(Configurations& config);

int main() {
    cout << "place holder name" << endl;
    cout << "-==±==-∞-===±∆±===-∞-==±==-" << endl;
    
    //object declartions
    Ingredient flour, sugar, eggs, yeast, butter;
    Recipe conchas, cookies, donuts, muffins, roscas;
    Configurations config;

    loadObjectsInfo(flour, sugar, eggs, yeast, butter, conchas, cookies, donuts, muffins, roscas);
    loadUserConfigs(config);

    // Arrays 
    Ingredient ingredients[5] = {flour, sugar, eggs, yeast, butter};
    double ingredientPQg[5];  // Purchase Quantity in grams
    double ingredientPP[5];   // Purchase Price

    /*test functions
    testIngredientClass(flour, sugar, eggs, yeast, butter);
    testRecipeClass(conchas, cookies, donuts, muffins, roscas);
    testConfigClass(config);
    */

    cout << endl << "DONE ALL" << endl;
   
    

    return 0;
}
