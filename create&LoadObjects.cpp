#include "Ingredients.h"
#include "Recipe.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

void createAndLoadObjects(){
    createAndLoadIngrediants();
    createAndLoadRecipes();
    
    cout << "Ingrediant and Recipe data loaded." << endl << endl;
}

void createAndLoadIngrediants(){
  //Ingredient objects
    Ingredient flour("Flour", 0.0, 0.0, "NA");
    Ingredient sugar("Sugar", 0.0, 0.0, "NA");
    Ingredient eggs("Eggs", 0.0, 0.0, "NA");
    Ingredient yeast("Yeast", 0.0, 0.0, "NA");
    Ingredient butter("Butter", 0.0, 0.0, "NA");

    ifstream ingredientsFile("Ingrediants.csv");
        if (!ingredientsFile.is_open()) {                                   //exception?
            cout << "ERROR! Cannot open or find Ingrediants.csv" << endl;
        exit(1);
        }

    //skipe first line
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

void createAndLoadRecipes(){
  //Recipe objects
    Recipe conchas("Conchas", 0.0, 0.0, 0, 0);
    Recipe cookies("Cookies", 0.0, 0.0, 0, 0);
    Recipe donuts("Donuts", 0.0, 0.0, 0, 0);
    Recipe muffins("Muffins", 0.0, 0.0, 0, 0);
    Recipe Roscas("Roscas", 0.0, 0.0, 0, 0);



}