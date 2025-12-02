#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

using namespace std;

/*
 *  Description:
 * 
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
    const double getTotalTime() const; 
    const int getTotalCount() const; // just batch * yeild

    //Functions
    double getRC(const double ingredientPQg[5], const double ingredientsPP[5]) const; // gets the cost to make the recipe
    double getRR(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const; // gets revenue for the recipe
    double getRP(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const; // gets profit for the recipe


    //might need a print function too
    //need a batch times yeild function for total count

    vector<RecipeIngredients>& getIngredient();

    //for testing might need
    const int getIngredientCount();
    void addIngredient(string name, double quantity, string unit);
};

#endif