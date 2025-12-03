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

void calculateBusinessTotals(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins, 
    double& totalCost, double& totalRevenue, double& totalProfit) {

    totalCost = 0.0;
    totalRevenue = 0.0;
    
    for (int i = 0; i < 5; i++) {
        totalCost += recipes[i].getRC(ingredientPQg, ingredientPP);
        totalRevenue += recipes[i].getRR(ingredientPQg, ingredientPP, profitMargins);
    }

    totalProfit = totalRevenue - totalCost;
    }

//gets the total cost of all recipes 
double getTC(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5]) {
    double totalCost = 0.0;
    
    for (int i = 0; i < 5; i++) {
        totalCost += recipes[i].getRC(ingredientPQg, ingredientPP);
    }
    
    return totalCost;
}

//gets the total revenue for all recipes
double getTR(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) {
    double totalRevenue = 0.0;
    for (int i = 0; i < 5; i++) {
        totalRevenue += recipes[i].getRR(ingredientPQg, ingredientPP, profitMargins);
    }
    return totalRevenue;
}

//gets the total profit for all the recipes
double getTP(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) {

    double totalRevenue = getTR(recipes, ingredientPQg, ingredientPP, profitMargins);
    double totalCost = getTC(recipes, ingredientPQg, ingredientPP);

    return totalRevenue - totalCost;
}

//sort a new vector of recipes by cost ( Lowest to Hightest)
vector<Recipe> sortRecipesByCost(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5]) {
    // make a copy of recipe array into a vector
    vector<Recipe> sortedRecipes;
    for (int i = 0; i < 5; i++) {
        sortedRecipes.push_back(recipes[i]);
    }
    // Selection sorting 
    int vectS = sortedRecipes.size();
    for (int i = 0; i < vectS - 1; i++) {
     
        int minIndex = i;
        double minCost = sortedRecipes[i].getRC(ingredientPQg, ingredientPP);
        
        for (int mi = i + 1; mi < vectS; mi++) {
            double currentCost = sortedRecipes[mi].getRC(ingredientPQg, ingredientPP);
            if (currentCost < minCost) {
                minCost = currentCost;
                minIndex = mi;
            }
        }
        
        if (minIndex != i) {
            swap(sortedRecipes[i], sortedRecipes[minIndex]);
        }
    }
    
    return sortedRecipes;
}

//sort a new vector of recipes by profit (Highest to lowest)
vector<Recipe> sortRecipesByProfit(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) {
    // make a copy of recipe array into a vector
    vector<Recipe> sortedRecipes;
    for (int i = 0; i < 5; i++) {
        sortedRecipes.push_back(recipes[i]);
    }
    
    // Selection sorting 
    int vectS = sortedRecipes.size();
    for (int i = 0; i < vectS - 1; i++) {
        
        int maxIndex = i;
        double maxProfit = sortedRecipes[i].getRP(ingredientPQg, ingredientPP, profitMargins);
        
        for (int mi = i + 1; mi < vectS; mi++) {
            double currentProfit = sortedRecipes[mi].getRP(ingredientPQg, ingredientPP, profitMargins);
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
                maxIndex = mi;
            }
        }
        
        if (maxIndex != i) {
            swap(sortedRecipes[i], sortedRecipes[maxIndex]);
        }
    }
    
    return sortedRecipes;
}

