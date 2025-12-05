#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

using namespace std;

/*
 *  Description:
 * This is a class for recipes
 * It stores a recipes basic information along with various functions.
 * The majortiy of the functions are ones that get this informatio or get a 
 * calcuation based on the recipes information.
 * The only other function adds ingrediant info specifc to the recipe
*/

//struct for vector list of Ingredients
struct RecipeIngredients {
    string name;
    double quantity;
    string unit;

    RecipeIngredients();
    RecipeIngredients(string n, double q, string u);

};

class Recipe {            
private:
    string recName;      // For the name of the recipe
    double prepTime;       
    double bakeTime;      
    int batchSize;        
    int yeildCount;

    vector<RecipeIngredients> Ingredient;

public:
    // Constructor to set object info
    Recipe();
    Recipe(string name, double prepTime, double bakeTime, int batch, int yeild);

    //getters
    const string getRecName() const;
    const double getPrepTime() const;
    const double getBakeTime() const;
    const int getBatchSize() const;
    const int getYeildCount() const;
    const double getTotalTime() const; // prep + bake times
    const int getTotalCount() const; // batch * yeild

    //Functions
    // gets the cost to make the recipe
    double getRC(const double ingredientPQg[5], const double ingredientsPP[5]) const; 
    // gets revenue for the recipe    
    double getRR(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const;
    // gets profit for the recipe
    double getRP(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const;
     // gets recipe suggestion
    const string getSuggestion(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const;

    //might need a print function too

    //List of ingredients
    vector<RecipeIngredients>& getIngredient();

    //for testing might need
    const int getIngredientCount();
    void addIngredient(string name, double quantity, string unit);
};

#endif