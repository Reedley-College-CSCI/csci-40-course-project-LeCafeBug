#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

using namespace std;

/*
 *  Description:
 * 
*/

class Recipe {            

private:
    string recName;      // For the name of the recipe
    double prepTime;       
    double bakeTime;      
    int batchSize;        
    int yeidCount;

public:
    // Constructor to set object info
    Recipe(string name, double prepTime, double bakeTime, int batch, int yeilld);

    const string getRecName();
    const double getPrepTime();
    const double getBakeTime();
    const int getBatchSize();
    const int getYeildCount();

    //might need a print function too

    const double getTotalTime(); 
};

#endif