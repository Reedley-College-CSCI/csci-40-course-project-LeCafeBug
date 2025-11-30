#include "Ingredients.h"
#include "Recipe.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// need to test if works / update test file 

void createAndLoadIngredients(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void createAndLoadRecipes(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);


void createAndLoadObjects(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas)
    {
    createAndLoadIngrediants(flour, sugar, eggs, yeast, butter);
    createAndLoadRecipes(conchas, cookies, donuts, muffins, roscas);

    cout << "Ingrediant and Recipe data loaded." << endl << endl;
}

void createAndLoadIngrediants(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter){
  //Ingredient objects
    ifstream ingredientsFile("Ingredients.csv");
        if (!ingredientsFile.is_open()) {                                   //exception?
            cout << "ERROR! Cannot open or find Ingrediants.csv" << endl;
        exit(1);
        }

    //skip first line
    string line;
    getline(ingredientsFile,line);

    string name, unit;
    double price, quantity;
    char com;

    while(ingredientsFile >> name >> com >> price >> com >> quantity >> com >> unit) {
        if (name == "Flour" || name == "flour") {
            flour = Ingredient(name, price, quantity, unit); 
            }
        else if (name == "Sugar" || name == "sugar") {
            sugar = Ingredient(name, price, quantity, unit);
            }
        else if (name == "Eggs" || name == "eggs") {
            eggs = Ingredient(name, price, quantity, unit);
            }
        else if (name == "Yeast"|| name == "yeast") {
            yeast = Ingredient(name, price, quantity, unit);
            }
        else if (name == "Butter" || name == "butter") {
            butter = Ingredient(name, price, quantity, unit);
            }
        else {
            cout << "ERROR: Unknown ingredient in file: " << name << endl;
            exit(2);
        }
    }
    ingredientsFile.close();
}

void createAndLoadRecipes(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas){
  //Recipe objects
    ifstream recipesFile("Recipes.csv");
    if (!recipesFile.is_open()) {
        cout << "ERROR! Cannot open or find Recipes.csv" << endl;
        exit(1);
    }

    //skip first line
    string line;
    getline(recipesFile, line);

    string name;
    double prepTime, bakeTime;
    int batchSize, yieldCount;
    char com;

    while (recipesFile >> name >> com >> prepTime >> com >> bakeTime >> 
           com >> batchSize >> com >> yieldCount) {
        
        // Remove characters
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
            }
        
        if (name == "Conchas" || name == "conchas") {
            conchas = Recipe(name, prepTime, bakeTime, batchSize, yieldCount);
            }
        else if (name == "Cookies" || name == "cookies") {
            cookies = Recipe(name, prepTime, bakeTime, batchSize, yieldCount);
            }
        else if (name == "Donuts" || name == "donuts") {
            donuts = Recipe(name, prepTime, bakeTime, batchSize, yieldCount);
            }
        else if (name == "Muffins" || name == "muffins") {
            muffins = Recipe(name, prepTime, bakeTime, batchSize, yieldCount);
            }
        else if (name == "Roscas" || name == "roscas") {
            roscas = Recipe(name, prepTime, bakeTime, batchSize, yieldCount);
            }
        else {
            cout << "ERROR! Unknown recipe in file: " << name << endl;
            exit(2);
            }
    }
    recipesFile.close();

//Loading from recipe ingredient file
    ifstream recipeIngredientsFile("Recipe.Ingredients.csv");
    if (!recipeIngredientsFile.is_open()) {
        cout << "ERROR! Cannot open or find Recipes.Ingredients.csv" << endl;
        exit(1);
    }
    
    getline(recipeIngredientsFile, line);

    string recipeName, ingredientName, unit;
    double quantityPR;               // Needed quantity per recipe


    while (recipeIngredientsFile >> recipeName >> com >> ingredientName >> com >> quantityPR >> com >> unit) {
        
        // Remove characters
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
            }
        
        if (recipeName == "Conchas" || recipeName == "conchas") {
            conchas.addIngredient(ingredientName, quantityPR, unit);
        }
        else if (recipeName == "Cookies" || recipeName == "cookies") {
            cookies.addIngredient(ingredientName, quantityPR, unit);
        }
        else if (recipeName == "Donuts" || recipeName == "donuts") {
            donuts.addIngredient(ingredientName, quantityPR, unit);
        }
        else if (recipeName == "Muffins" || recipeName == "muffins") {
            muffins.addIngredient(ingredientName, quantityPR, unit);
        }
        else if (recipeName == "Roscas" || recipeName == "roscas") {
            roscas.addIngredient(ingredientName, quantityPR, unit);
        }
        else {
            cout << "ERROR! Unknown recipe ingredient in file: " << recipeName << endl;
            exit(2);
        }
    }

    recipeIngredientsFile.close();

}

void loadUserConfigs(){


}
