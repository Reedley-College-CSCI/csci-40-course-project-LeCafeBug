#include "Ingredients.h"
#include "Recipe.h"
#include <string>

using namespace std;

void createAndLoadObjects(){
    //Ingredients objects
        Ingredient flour("Flour", 0.0, 0.0, "NA");
        Ingredient sugar("Sugar", 0.0, 0.0, "NA");
        Ingredient eggs("Eggs", 0.0, 0.0, "NA");
        Ingredient yeast("Yeast", 0.0, 0.0, "NA");
        Ingredient butter("Butter", 0.0, 0.0, "NA");

    //Conchas recipe
    Recipe conchas("Conchas", 0.0, 0.0, 0, 0);


    //Cookies recipe
    Recipe cookies("Cookies", 0.0, 0.0, 0, 0);
    

    //Donuts recipe
    Recipe dounts("Dounts", 0.0, 0.0, 0, 0);


    //Muffins recipe
    Recipe muffins("Muffins", 0.0, 0.0, 0, 0);


    //Rosca recipe
    Recipe Roscas("Roscas", 0.0, 0.0, 0, 0);


}