#include "Recipe.h"
#include <string>
#include <vector>

using namespace std;

// getters
const string Recipe::getRecName() {
    return recName;
    }
const double Recipe::getPrepTime() {
    return prepTime;
    }
const double Recipe::getBakeTime() {
    return bakeTime;
    }
const int Recipe::getBatchSize() {
    return batchSize;
    }
const int Recipe::getYeildCount(){
   return yeildCount; 
}


//constructors 
Recipe::Recipe(){
    recName = "NA";
    prepTime = 0.0;
    bakeTime = 0.0;
    batchSize = 0;
    yeildCount = 0;
}
Recipe::Recipe(string n, double prep, double bake, int batch,  int yeild){
    recName = n;
    prepTime = prep;
    bakeTime = bake;
    batchSize = batch;
    yeildCount = yeild;
}

RecipeIngredients::RecipeIngredients(){
    name = "NA";
    quantity = 0.0;
    unit = "NA";    
}
RecipeIngredients::RecipeIngredients(string n, double q, string u) {
    name = n;
    quantity = q;
    unit = u;    
}
//functions
const double Recipe::getTotalTime() {
        return prepTime + bakeTime;
}
void Recipe::addIngredient(string name, double quantity, string unit) {
    Ingredient.push_back(RecipeIngredients( name, quantity, unit ));
}
vector<RecipeIngredients>& Recipe::getIngredient() {
    return Ingredient;
}
const int Recipe::getIngredientCount() {
    return Ingredient.size();
}