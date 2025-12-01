#include "Ingredients.h"
#include "Recipe.h"
#include "Configurations.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void loadIngredientsInfo(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void loadRecipeInfo(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);


void loadObjectsInfo(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas)
    {
    loadIngredientsInfo(flour, sugar, eggs, yeast, butter);
    loadRecipeInfo(conchas, cookies, donuts, muffins, roscas);

    cout << "Ingrediant and Recipe data loaded." << endl << endl;
}

void loadIngredientsInfo(Ingredient& flour, Ingredient& sugar, Ingredient& eggs, Ingredient& yeast, Ingredient& butter){
  //Ingredient objects
    ifstream ingredientsFile("Ingredients.csv");
        if (!ingredientsFile.is_open()) {                                   //exception?
            cout << "ERROR! Cannot open or find Ingrediants.csv" << endl;
            exit(1);
        }

    //skip first line
    string line;
    getline(ingredientsFile,line);

    while(getline(ingredientsFile, line)) {
        stringstream ss(line);
        string name, priceStr, quantityStr, unit;
        
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr, ',');
        getline(ss, unit, ',');
        
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
            }
        //change from string to correct data type
        double price = stod(priceStr);
        double quantity = stod(quantityStr);
        
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

void loadRecipeInfo(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas){
  //Recipe objects
    ifstream recipesFile("Recipes.csv");
    if (!recipesFile.is_open()) {
        cout << "ERROR! Cannot open or find Recipes.csv" << endl;
        exit(3);
    }

    //skip first line
    string line;
    getline(recipesFile, line);

    while (getline(recipesFile, line)) {
        stringstream ss(line);
        string name, prepTimeStr, bakeTimeStr, batchSizeStr, yieldCountStr;

        getline(ss, name, ',');
        getline(ss, prepTimeStr, ',');
        getline(ss, bakeTimeStr, ',');
        getline(ss, batchSizeStr, ',');
        getline(ss, yieldCountStr, ',');

        // Remove characters
        if (!name.empty() && name.back() == '\r') {
            name.pop_back();
            }
            
        //change from string to correct data type
        double prepTime = stod(prepTimeStr);
        double bakeTime = stod(bakeTimeStr);
        int batchSize = stoi(batchSizeStr);
        int yieldCount = stoi(yieldCountStr);

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
            exit(4);
            }
    }
    recipesFile.close();

//Loading from recipe ingredient file
    ifstream recipeIngredientsFile("Recipe.Ingredients.csv");
    if (!recipeIngredientsFile.is_open()) {
        cout << "ERROR! Cannot open or find Recipes.Ingredients.csv" << endl;
        exit(5);
    }
    
    getline(recipeIngredientsFile, line);

    while (getline(recipeIngredientsFile, line)) {
        stringstream ss(line);
        string recipeName, ingredientName, quantityStr, unit;
    
    // Parse CSV line properly
        getline(ss, recipeName, ',');
        getline(ss, ingredientName, ',');
        getline(ss, quantityStr, ',');
        getline(ss, unit, ',');

        // Remove characters
        if (!recipeName.empty() && recipeName.back() == '\r') {
            recipeName.pop_back();
            }
        //change from string to correct data type
        double quantityPR = stod(quantityStr);

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
            exit(6);
        }
    }

    recipeIngredientsFile.close();

}

void loadUserConfigs(Configurations& config) {
    ifstream configFile("config.txt");
    
    if (!configFile.is_open()) {
        cout << "Config file not found. Starting with default margins." << endl;
        return;
    }
    
    vector<double>& margins = config.getMargins();
    int expectedCount = margins.size();
    int actualCount = 0;
    
    // Read only expected number of margins 
    for (int i = 0; i < expectedCount; i++) {
        if (configFile >> margins[i]) {
            actualCount++;
        } else {
            break; // Stops if can't read any more numbers
        }
    }
    
    configFile.close();
    
    if (actualCount == expectedCount) {
        cout << "Profit margins loaded." << endl;   // all margins found
    } 
    else if (actualCount > 0) {
        cout << "Warning: Config file has less values then expected. Remaining margins use default margin." << endl; // Some margins found
    } 
    else {
        cout << "Warning: Config file is empty or contains no valid numbers. Using default margins." << endl; //no margins found
    }
}
