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

    RecipeIngredients( string n, double q, string u  );

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
    Recipe(string name, double prepTime, double bakeTime, int batch, int yeild);

    const string getRecName();
    const double getPrepTime();
    const double getBakeTime();
    const int getBatchSize();
    const int getYeildCount();

    //might need a print function too

    const double getTotalTime(); 

    vector<RecipeIngredients>& getIngredient();

    //for testing might need
    const int getIngredientCount();
    void addIngredient(string name, double quantity, string unit);
};

#endif