#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H
#include <vector>
#include <string>

using namespace std;

/*
 * Description:
 * This class mananages all user congfigurations. It contains a vector of numbers that come from the config.txt file.
 * It allow the program to set, get, and save margins for the 5 recipes as well as a default margin incase its needed.
 */

class Configurations {
private:
    vector<double> profitMargins;  // 0-5 is Conchas, Cookies, Donuts, Muffins, Roscas, Default
    const int NUM_RECIPES = 5;
    const int TOTAL_CONFIGS = NUM_RECIPES + 1;  // recipes + default
    
public:
    // Constructor
    Configurations();
    
    // Core functions
    void saveConfig();
    void setMargin(int index, double newMargin); 
    
    // test functions
    vector<double>& getMargins();
    const int getMarginVectorSize();
    const void displayMargin(int index);
};

#endif