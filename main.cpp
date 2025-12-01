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
#include "Ingredients.h"
#include "Recipe.h"

using namespace std;

//functions 
void loadObjectsInfo(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);

//test functions
void testIngredientClass(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void testRecipeClass(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);

int main() {
    cout << "place holder name" << endl;
    cout << "-==±==-∞-===±∆±===-∞-==±==-" << endl;
    
    //object declartions
    Ingredient flour, sugar, eggs, yeast, butter;
    Recipe conchas, cookies, donuts, muffins, roscas;

    loadObjectsInfo(flour, sugar, eggs, yeast, butter, conchas, cookies, donuts, muffins, roscas);

    //test functions
    testIngredientClass(flour, sugar, eggs, yeast, butter);
    testRecipeClass(conchas, cookies, donuts, muffins, roscas);
    

    cout << endl << flour.getPrice() << endl;
   
    

    return 0;
}
