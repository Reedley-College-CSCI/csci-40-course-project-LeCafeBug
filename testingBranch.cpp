#include <iostream>
#include <iomanip>
#include "Ingredients.h"
#include "Recipe.h"
#include "Configurations.h"

using namespace std;

vector<Recipe> sortRecipesByCost(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5]);
vector<Recipe> sortRecipesByProfit(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins);

//once file implemtntion need to add for this-
void testIngredientClass(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter) {
    cout << "=±= Testing Ingredient Class =±=" << endl << endl;
    
    // Create test ingredient info
    Ingredient zeroTest( "Test", 10.0, 0, "NA" );

    // Test flour
    cout << "- - Testing Flour - -" << endl;
    cout << "Name: " << flour.getName() << endl;
    cout << "Price: $" << flour.getPrice() << endl;
    cout << "Quantity: " << flour.getQuantity() << " " << flour.getUnit() << endl;
    cout << "Cost per unit: $" << flour.getCostPerUnit() << " per " << flour.getUnit() << endl << endl;
    
    // Test sugar
    cout << "- - Testing Sugar - -" << endl;
    cout << "Name: " << sugar.getName() << endl;
    cout << "Price: $" << sugar.getPrice() << endl;
    cout << "Quantity: " << sugar.getQuantity() << " " << sugar.getUnit() << endl;
    cout << "Cost per unit: $" << sugar.getCostPerUnit() << " per " << sugar.getUnit() << endl << endl;

    // Test zero quantity
    cout << "- - Testing Zero Quantity Protection - -" << endl;
    cout << "Cost per unit (0): $" << zeroTest.getCostPerUnit() << endl << endl;

    cout << "=≠= Testing for Ingredient class done =≠=" << endl;
}

void testRecipeClass(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas) {
    cout << "=±= Testing Recipe Class =±=" << endl << endl;

    //Create test recipe classes

    //test cookies
    cout << "- - Testing Cookies - -" << endl;
    cout << "Name: " << cookies.getRecName() << endl;
    cout << "Prep Time: " << cookies.getPrepTime() << " hours" << endl;
    cout << "Bake Time: " << cookies.getBakeTime() << " hours" << endl;
    cout << "Total Time: " << cookies.getTotalTime() << " hours" << endl;
    cout << "Total: " << cookies.getBatchSize() << " batches of " << cookies.getYeildCount() << " " << cookies.getRecName() << endl << endl;

    //test conchas
    cout << "- - Testing Conchas - -" << endl;
    cout << "Name: " << conchas.getRecName() << endl;
    cout << "Prep Time: " << conchas.getPrepTime() << " hours" << endl;
    cout << "Bake Time: " << conchas.getBakeTime() << " hours" << endl;
    cout << "Total Time: " << conchas.getTotalTime() << " hours" << endl;
    cout << "Total: " << conchas.getBatchSize() << " batches of " << conchas.getYeildCount() << " " << conchas.getRecName() << endl << endl;

    //test struct vector on conchas
/*  Not needed rn ... future?  
    cout << "Initial ingredient count: " << conchas.getIngredientCount() << endl;
    conchas.addIngredient("Flour", 500, "G");
    conchas.addIngredient("Sugar", 100, "g");
    conchas.addIngredient("Eggs", 1, "Count");
    cout << "After adding: " << conchas.getIngredientCount() << endl;
*/    
    const vector<RecipeIngredients>& MufIngList = muffins.getIngredient();
    cout << "Roscas Ingredients list:" << endl;
    for (const auto& ing : MufIngList) {
        cout << " - " << ing.name << ": " << ing.quantity << " " << ing.unit << endl;
    }
    cout << endl;

    const vector<RecipeIngredients>& RosIngList = roscas.getIngredient();
    cout << "Roscas Ingredients list:" << endl;
    for (const auto& ing : RosIngList) {
        cout << " - " << ing.name << ": " << ing.quantity << " " << ing.unit << endl;
    }
    cout << endl;    
    
    cout << "=≠= Testing for Recipe class done =≠=" << endl;
}

void testConfigClass(Configurations& config) {
    cout << "=±= Testing Configurations Class =±=" << endl << endl;

    cout << "- - Testing Default Values - -" << endl;
    // test config object
    Configurations testConfig;
    cout << "Default margins: " << endl;

    for (int i = 0; i < testConfig.getMarginVectorSize(); i++) {
        cout << "  ";
        testConfig.displayMargin(i); 
        cout << endl;
    }
    cout << endl;

    cout << "- - Testing setMargin - -" << endl;
    
    cout << "Valid margins: " << endl;
    testConfig.setMargin(0, 5);     // Set 0 to 5%
    testConfig.setMargin(5, 45.0);  // Set Default to 45%
    cout << "  ";
    testConfig.displayMargin(0);
    cout << endl;
    cout << "  ";
    testConfig.displayMargin(5);
    cout << endl;

    cout << "invalid margins: " << endl;
    testConfig.setMargin(0, 0.0);  // Set 0 to 0%
    testConfig.setMargin(5, 150);  // Set Default to 150%
    cout << "  ";
    testConfig.displayMargin(0);
    cout << endl;
    cout << "  ";
    testConfig.displayMargin(5);
    cout << endl;

    cout << "- - Testing saveConfig - -" << endl;
    testConfig.saveConfig();
    cout << "1st number and last number in config file should be 0.05 and .45" << endl;
    cout << endl;
    
    //place stop here and look at file 

    cout << "- - Undoing Save and Checking load- -" << endl;
    config.saveConfig();
    cout << "1st number and last number in config file should be .3 and .26" << endl;
    cout << endl;    
    
    cout << "=≠= Testing for Config class done =≠=" << endl;
}

void testCalculteTotal(double& totalCost, double& totalRevenue, double& totalProfit){
    cout << "=±= Testing calculate Total =±=" << endl << endl;

    cout << fixed << setprecision(2);
    cout << "Total Cost: $" << totalCost << endl;
    cout << "Total Revenue: $" << totalRevenue << endl;
    cout << "Total Profit: $" << totalProfit << endl;

    cout << "=≠= Testing for calculating total done =≠=" << endl;
}

void testSortingFunctions(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) {
    cout << "=±= Testing Sorting Functions =±=" << endl << endl;
    
    cout << "- - Unsorted - -" << endl;
    for (int i = 0; i < 5; i++) {
        cout << recipes[i].getRecName() << endl;
    }
    cout << endl;
    
    // Test cost sorting
    vector<Recipe> sortedByCost = sortRecipesByCost(recipes, ingredientPQg, ingredientPP);

    cout << "- - Sorted by Cost - -" << endl;
    for (const auto& recipe : sortedByCost) {
        cout << recipe.getRecName() << endl;
    }
    cout << endl;
    
    // Test profit sorting  
    
    vector<Recipe> sortedByProfit = sortRecipesByProfit(recipes, ingredientPQg, ingredientPP, profitMargins);
    cout << "- - Sorted by Profit - -" << endl;
    for (const auto& recipe : sortedByProfit) {
        cout << recipe.getRecName() << endl;
    }
    cout << endl;
    
    cout << "=≠= Testing Sorting Functions done =≠=" << endl;
}