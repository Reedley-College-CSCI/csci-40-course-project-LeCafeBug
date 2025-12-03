// CSCI-40 Final Project
// Author: Edgar Jarquin

/* 
 * Description:
 *
 * Add instruciton on how to open with CMake
 * 
 * clean up lines -====...
 * 
 * add test for new biz calcs
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
void calculateBusinessTotals(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins, 
    double& totalCost, double& totalRevenue, double& totalProfit);
vector<Recipe> sortRecipesByCost(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5]);
vector<Recipe> sortRecipesByProfit(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins);
const Recipe* searchRecipeByName(const Recipe recipes[5], const string& target);
const string getBusinessSuggestion(double totalProfit);

//test functions
void testIngredientClass(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void testRecipeClass(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);
void testConfigClass(Configurations& config);
void testCalculteTotal(double& totalCost, double& totalRevenue, double& totalProfit);
void testSortingFunctions(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins);
void testSearchFunction(const Recipe recipes[5], const string& target);

int main() {
    cout << "place holder name" << endl;
    cout << "-==±==-∞-===±∆±===-∞-==±==-" << endl;
    
    //config declare and load
    Configurations config;
    loadUserConfigs(config);

    //ingredients and recipe object declare and load
    Ingredient flour, sugar, eggs, yeast, butter;
    Recipe conchas, cookies, donuts, muffins, roscas;
    loadObjectsInfo(flour, sugar, eggs, yeast, butter, conchas, cookies, donuts, muffins, roscas);
    
    // Declare and load buissness logic calculations 
  
    Ingredient ingredients[5] = {flour, sugar, eggs, yeast, butter};
    double ingredientPQg[5];  // Purchase Quantity in grams
    double ingredientPP[5];   // Purchase Price
    createIngredientArrays(ingredients, ingredientPQg, ingredientPP);

    Recipe recipes[5] = {conchas, cookies, donuts, muffins, roscas};
    const vector<double>& profitMargins = config.getMargins();
    double totalCost, totalRevenue, totalProfit;    
    calculateBusinessTotals(recipes, ingredientPQg, ingredientPP, profitMargins, totalCost, totalRevenue, totalProfit);

    string target;

    // cin >> target;
    
    
    int n = 0;
    vector<Recipe> sortedByProfit = sortRecipesByProfit(recipes, ingredientPQg, ingredientPP, profitMargins);    
    vector<Recipe> sortedByCost = sortRecipesByCost(recipes, ingredientPQg, ingredientPP);
    if (n = 1) {
        cout << sortedByCost[0].getRecName();
    }
    else if (n = 2 ) {
        cout << sortedByProfit[0].getRecName();
    }
    else {
        cout << "error";
    }
    
    string mostProfitable = sortedByProfit[0].getRecName();
    
    /*test functions
    testIngredientClass(flour, sugar, eggs, yeast, butter);
    testRecipeClass(conchas, cookies, donuts, muffins, roscas);
    testConfigClass(config);
    testCalculteTotal(totalCost, totalRevenue, totalProfit);
    testSortingFunctions(recipes, ingredientPQg, ingredientPP, profitMargins);
    */
    testSearchFunction(recipes, target );


    cout << endl << "DONE ALL" << endl;
   
    

    return 0;
}
