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
void createAndLoadObjects(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);

//test functions
void testIngredientClass();
void testRecipeClass();

int main() {
    cout << "place holder name" << endl;
    cout << "-==±==-∞-===±∆±===-∞-==±==-" << endl;
    
    //object declartions
    Ingredient flour, sugar, eggs, yeast, butter;
    Recipe conchas, cookies, donuts, muffins, roscas;

    //test functions
    testIngredientClass();
    testRecipeClass();
    
    cout << flour.getPrice();
   
    

    return 0;
}
