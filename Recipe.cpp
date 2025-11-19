#include "Recipe.h"
#include <string>
#include <vector>

using namespace std;

// getters
const string Recipe::getRecName() {
    return recName;
    }
const double Recipe::getPrepTime() {
    return prepTime;
    }
const double Recipe::getBakeTime() {
    return bakeTime;
    }
const int Recipe::getBatchSize() {
    return batchSize;
    }
const int Recipe::getYeildCount(){
   return yeidCount; 
}


//constructors 
Recipe::Recipe( string n, double prep, double bake, int batch,  int yeild){
    recName = n;
    prepTime = prep;
    bakeTime = bake;
    batchSize = batch;
    yeidCount = yeild;
}

//functions
const double Recipe::getTotalTime(){
        return prepTime + bakeTime;

}