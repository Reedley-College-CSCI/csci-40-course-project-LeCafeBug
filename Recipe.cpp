#include "Recipe.h"
#include <string>
#include <vector>

using namespace std;

// getters
const string Recipe::getRecName() const{
    return recName;
    }
const double Recipe::getPrepTime() const{
    return prepTime;
    }
const double Recipe::getBakeTime() const{
    return bakeTime;
    }
const int Recipe::getBatchSize() const{
    return batchSize;
    }
const int Recipe::getYeildCount() const{
   return yeildCount; 
}
const double Recipe::getTotalTime() const{
    return prepTime + bakeTime;
}
const int Recipe::getTotalCount() const{
    return batchSize * yeildCount; 
}

//constructors 
Recipe::Recipe(){
    recName = "NA";
    prepTime = 0.0;
    bakeTime = 0.0;
    batchSize = 0;
    yeildCount = 0;
}
Recipe::Recipe(string n, double prep, double bake, int batch,  int yeild){
    recName = n;
    prepTime = prep;
    bakeTime = bake;
    batchSize = batch;
    yeildCount = yeild;
}

RecipeIngredients::RecipeIngredients(){
    name = "NA";
    quantity = 0.0;
    unit = "NA";    
}
RecipeIngredients::RecipeIngredients(string n, double q, string u) {
    name = n;
    quantity = q;
    unit = u;    
}

//functions
double Recipe::getRC(const double ingredientPQg[5], const double ingredientPP[5]) const{        //decide on what want dont really need loop since all ing same 0-4
    const double LABOR_RATE_PER_HOUR = 18.0;  // $18 per hour
    double totalIngredientCost = 0.0;
    // need loop that does adds 5 IC then IC = (NQg/PQg)PP lastly add to 5IC labor which is TT * LABOR_RATE_PH or 18
    // so loop in have ifs for each 5 then do IC calc last add LR       list index: 0=Flour, 1=Sugar, 2=Eggs, 3=Yeast, 4=Butter
    for (const auto& recIng : Ingredient) {     //loops through each ingredient and does IC += (NQg/PQg)PP
        if (recIng.name == "Flour" || recIng.name == "flour") {
            totalIngredientCost += (recIng.quantity / ingredientPQg[0]) * ingredientPP[0];
            }
        else if (recIng.name == "Sugar" || recIng.name == "sugar") {
            totalIngredientCost += (recIng.quantity / ingredientPQg[1]) * ingredientPP[1];
            }
        else if (recIng.name == "Eggs" || recIng.name == "eggs") {
            totalIngredientCost += (recIng.quantity / ingredientPQg[2]) * ingredientPP[2];
            }
        else if (recIng.name == "Yeast"|| recIng.name == "yeast") {
            totalIngredientCost += (recIng.quantity / ingredientPQg[3]) * ingredientPP[3];
            }
        else if (recIng.name == "Butter" || recIng.name == "butter") {
            totalIngredientCost += (recIng.quantity / ingredientPQg[4]) * ingredientPP[4];
            }
    }  
    double laborCost = getTotalTime() * LABOR_RATE_PER_HOUR;

    // Total recipe cost = ingredient cost + labor cost
    return totalIngredientCost + laborCost;
}

double Recipe::getRR(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const {
    // need (BY=count) (RC*(1+PM)) pm is the profit margin for recipes
    double recipeCost = getRC(ingredientPQg, ingredientPP);

    int marginIndex = 5;  // Default 5 for default margin
    if (recName == "Conchas" || recName == "conchas") {
        marginIndex = 0;
        }
    else if (recName == "Cookies" || recName == "cookies") {
        marginIndex = 1;
        }
    else if (recName == "Donuts" || recName == "donuts") {
        marginIndex = 2;
        }
    else if (recName == "Muffins" || recName == "muffins") {
        marginIndex = 3;
        }
    else if (recName == "Roscas" || recName == "roscas") {
        marginIndex = 4;
        }

    double profitMargin = profitMargins[marginIndex];
    
    return recipeCost * (1.0 + profitMargin);
    
    
}

double Recipe::getRP(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const{
    double recRevenue = getRR(ingredientPQg, ingredientPP, profitMargins);
    double recCost = getRC(ingredientPQg, ingredientPP);
    
    return recRevenue - recCost;
}

const string Recipe::getSuggestion(const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins) const {
    double recipeProfit = getRP(ingredientPQg, ingredientPP, profitMargins);
    
    //thresholds for margin analysis
    const double lowMargin = 17.0;   // $17 profit
    const double highMargin = 30.0;   // $30 profit
    
    if (recipeProfit < lowMargin) {
        return "Low Profit - Consider increasing price as at current cost the profit is minimal";
    } 
    else if (recipeProfit > highMargin) {
        return "High Profit - Good margin but monitor market and consider decrease if low buy rate";
    } 
    else {
        return "Good Profit - Healthy margin, no changes needed";
    }
}



void Recipe::addIngredient(string name, double quantity, string unit) {
    Ingredient.push_back(RecipeIngredients( name, quantity, unit ));
}

vector<RecipeIngredients>& Recipe::getIngredient() {
    return Ingredient;
}
const int Recipe::getIngredientCount() {
    return Ingredient.size();
}

