#include "Configurations.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
// 0-5 is Conchas, Cookies, Donuts, Muffins, Roscas, Default

Configurations::Configurations() {
    // Start all margins at 25% (0.25)
    profitMargins = vector<double>(TOTAL_CONFIGS, 0.25);
}

void Configurations::saveConfig() {
    ofstream configFile("config.txt");
    
    if (!configFile.is_open()) {
        cout << "ERROR: Cannot find config.txt" << endl;
        return;
    }
    
    configFile << fixed << setprecision(2);

    for (double margin : profitMargins) {
        configFile << margin << endl;
    }

    configFile.close();
    cout << "Profit margins saved." << endl;
}

void Configurations::setMargin(int index, double newMargin) {
    newMargin = newMargin/100; 

    if (index >= 0 && index < TOTAL_CONFIGS) {

        if (newMargin >= 0.01 && newMargin <= 1.0) {
            profitMargins[index] = newMargin;
            cout << " - Margin updated" << endl;
        } 
        else {
            cout << "ERROR! Margin must be between 1 and 100!" << endl;
        }
    } 
    else {
        cout << "ERROR! Invalid choice. Use 1-6." << endl;
    }
}

vector<double>& Configurations::getMargins() {
    return profitMargins;
}

const int Configurations::getMarginVectorSize() {
    return profitMargins.size();
}

const void Configurations::displayMargin(int index) {
    if (index < 0 || index >= profitMargins.size()) {
        cout << "ERROR! Invalid index " << endl;
        return;
    }
    string recipeNames[6] = {"Conchas", "Cookies", "Donuts", "Muffins", "Roscas", "Default"};
    
    cout << recipeNames[index] << ": " << fixed << setprecision(2)  << profitMargins[index] * 100 << "%";
    
}