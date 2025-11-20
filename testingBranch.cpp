#include <iostream>
#include "Ingredients.h"
#include "Recipe.h"

using namespace std;

//once file implemtntion need to add for this-
void testIngredientClass() {
    cout << "=±= Testing Ingredient Class =±=" << endl << endl;
    
    // Create test ingredient info
    Ingredient flour( "Flour", 9.99, 10.0, "Lbs" );
    Ingredient sugar( "Sugar", 3.99, 4.0, "Oz" );
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
    cout << "Quantity: " << sugar.getQuantity() << " " << flour.getUnit() << endl;
    cout << "Cost per unit: $" << sugar.getCostPerUnit() << " per " << sugar.getUnit() << endl << endl;

    // Test zero quantity
    cout << "- - Testing Zero Quantity Protection - -" << endl;
    cout << "Cost per unit (0): $" << zeroTest.getCostPerUnit() << endl << endl;

    cout << "=≠= Testing for Ingredient class done =≠=" << endl;
}

void testRecipeClass() {
    cout << "=±= Testing Recipe Class =±=" << endl << endl;

    //Creates test recipe classes
    Recipe cookies( "Cookies", 0.25, 1.30, 2, 12);
    Recipe conchas( "Conchas", 0.40, 2.00, 4, 8);

    //test cookies
    cout << "- - Testing Cookies - -" << endl;
    cout << "Name: " << cookies.getRecName() << endl;
    cout << "Prep Time: " << cookies.getPrepTime() << " hours" << endl;
    cout << "Bake Time: " << cookies.getBakeTime() << " hours" << endl;
    cout << "Total Time: " << cookies.getTotalTime() << " hours" << endl;
    cout << "Total: " << cookies.getBatchSize() << " batches of " << cookies.getYeildCount() << cookies.getRecName() << endl << endl;

    //test conchas
    cout << "- - Testing Conchas - -" << endl;
    cout << "Name: " << conchas.getRecName() << endl;
    cout << "Prep Time: " << conchas.getPrepTime() << " hours" << endl;
    cout << "Bake Time: " << conchas.getBakeTime() << " hours" << endl;
    cout << "Total Time: " << conchas.getTotalTime() << " hours" << endl;
    cout << "Total: " << conchas.getBatchSize() << " batches of " << conchas.getYeildCount() << conchas.getRecName() << endl << endl;

    //test struct vector on conchas
    cout << "Initial ingredient count: " << conchas.getIngredientCount() << endl;

    conchas.addIngredient("Flour", 500, "G");
    conchas.addIngredient("Sugar", 100, "g");
    conchas.addIngredient("Eggs", 1, "Count");
    
    cout << "After adding: " << conchas.getIngredientCount() << endl;
    
    const vector<RecipeIngredients>& ingredients = conchas.getIngredient();
    cout << "Ingredients list:" << endl;
    for (const auto& ing : ingredients) {
        cout << " - " << ing.name << ": " << ing.quantity << " " << ing.unit << endl;
    }
    cout << endl;

    cout << "=≠= Testing for Recipe class done =≠=" << endl;
}