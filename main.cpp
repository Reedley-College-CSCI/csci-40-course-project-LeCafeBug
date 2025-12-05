// CSCI-40 Final Project
// Author: Edgar Jarquin

/* 
 * Description:
 * This is the core of the program. It houses the various function protypes needed here that arent in a .h file.
 * These include the functions that load inforamtion, fetch information from this info, and do the searching and sorting.
 * 
 * More importantly it houses the menus, with the main menu in the int main and the functions that 
 * display the single and total analysis menus. Along with the menus it has the functions that generates both
 * analysis and out put them to the txt file. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Ingredients.h"
#include "Recipe.h"
#include "Configurations.h"

using namespace std;

//functions 
void loadObjectsInfo(
    Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter,
    Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);
void loadUserConfigs(Configurations& config);
void createIngredientArrays(const Ingredient ingredients[5], double ingredientPQg[5], double ingredientPP[5]);
void calculateBusinessTotals(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins, 
    double& totalCost, double& totalRevenue, double& totalProfit);
vector<Recipe> sortRecipesByCost(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5]);
vector<Recipe> sortRecipesByProfit(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins);
const Recipe* searchRecipeByName(const Recipe recipes[5], const string& target);
const string getBusinessSuggestion(double totalProfit);

// user interface and report generators fucntions 
void displayRecipeList(const Recipe recipes[5]);
void generateSingleRecipeReport(const Recipe* recipe, const double ingredientPQg[5], const double ingredientPP[5], 
    double margin, bool useCustomMargin, ofstream& reportFile);
void generateTotalAnalysisReport(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], 
    const vector<double>& profitMargins, ofstream& reportFile);
void totalAnalysisMenu(Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], Configurations& config);
void singleRecipeAnalysisMenu(Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], Configurations& config);

//test functions
void testIngredientClass(Ingredient& flour, Ingredient& sugar, Ingredient& eggs,Ingredient& yeast, Ingredient& butter);
void testRecipeClass(Recipe& conchas, Recipe& cookies, Recipe& donuts, Recipe& muffins, Recipe& roscas);
void testConfigClass(Configurations& config);
void testCalculteTotal(double& totalCost, double& totalRevenue, double& totalProfit);
void testSortingFunctions(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], const vector<double>& profitMargins);
void testSearchFunction(const Recipe recipes[5], const string& target);

int main() {
    //config declare and load
    Configurations config;
    loadUserConfigs(config);

    //ingredients and recipe object declare and load
    Ingredient flour, sugar, eggs, yeast, butter;
    Recipe conchas, cookies, donuts, muffins, roscas;
    loadObjectsInfo(flour, sugar, eggs, yeast, butter, conchas, cookies, donuts, muffins, roscas);
    
    // Declare and load buissness logic calculations 
  
    Ingredient ingredients[5] = {flour, sugar, eggs, yeast, butter};
    double ingredientPQg[5];  // Purchase Quantity in grams
    double ingredientPP[5];   // Purchase Price
    createIngredientArrays(ingredients, ingredientPQg, ingredientPP);

    Recipe recipes[5] = {conchas, cookies, donuts, muffins, roscas};
    const vector<double>& profitMargins = config.getMargins();

    //Start of program --- 
    
    // Check for output file and if has data tells user before deleting
    ifstream checkFile("profit_analysis.txt");
    bool fileExistsAndNotEmpty = false;
    
    if (checkFile.is_open()) {
        checkFile.seekg(0, ios::end);
        streampos fileSize = checkFile.tellg();
        checkFile.close();
        
        if (fileSize > 0) {
            fileExistsAndNotEmpty = true;
        }
    }
    // Warn user if file has content
    if (fileExistsAndNotEmpty) {
        cout << "⚠️ WARNING: Existing profit_analysis.txt file contains data!" << endl;
        cout << "This program will DELETE all content in the file." << endl;
        cout << "If you want to save this data, copy it else where" << endl << endl;
        cout << "Press Enter to continue (and DELETE file content)..." << endl;
        // Wait for user to press Enter
        cin.ignore(1000, '\n');
        cout << "Deleting old report data..." << endl << endl;
    }
    // Clear output file
    ofstream clearFile("profit_analysis.txt", ios::trunc);
    clearFile.close();

    cout << endl;
    cout << "---------------------------------" << endl;
    cout << "   -Bakery Recipe Analyser-" << endl;
    
    bool exitProgram = false;
    while (!exitProgram) {          // allows the user to do single recipe analysis multiple times

        cout << "---------------------------------" << endl;
        cout << "  MAIN MENU: Enter 1-3" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Single Recipe Analysis" << endl;
        cout << "2. Total Business Analysis" << endl;
        cout << "3. Exit Program" << endl;
        cout << "---------------------------------" << endl;

        int choice;
        cout << "Enter your choice (1-3): ";
        
        do{
            cin >> choice;
            if (choice < 1 || choice > 3){
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            }
            cin.clear();
            cin.ignore(1000, '\n');
        } while (choice < 1 || choice > 3);

        cout << endl;
        switch(choice) {
            case 1:
                // Single recipe analysis
                singleRecipeAnalysisMenu(recipes, ingredientPQg, ingredientPP, config);
                break;
            case 2:
                // Total business analysis (exits after)
                totalAnalysisMenu(recipes, ingredientPQg, ingredientPP, config);
                choice = 3;
                break;
            case 3:
                // Exit program
                cout << "Thank you for using Bakery Business Analyzer!" << endl;
                cout << "Exiting program." << endl << endl;
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
        //pause before main menu reappears
        if (!exitProgram) {
            cout << endl;
            cout << "Press Enter to return to main menu...";
            
            cin.ignore(1000, '\n');
            cout << endl;
        }
    }
    /*test functions
    testIngredientClass(flour, sugar, eggs, yeast, butter);
    testRecipeClass(conchas, cookies, donuts, muffins, roscas);
    testConfigClass(config);

    double totalCost, totalRevenue, totalProfit;    
    calculateBusinessTotals(recipes, ingredientPQg, ingredientPP, profitMargins, totalCost, totalRevenue, totalProfit);
    testCalculteTotal(totalCost, totalRevenue, totalProfit);
    
    testSortingFunctions(recipes, ingredientPQg, ingredientPP, profitMargins);
    
    string target;
    testSearchFunction(recipes, target );
    */

    return 0;
}


// This will display the list of recipe names
void displayRecipeList(const Recipe recipe[5]) {
    cout << "Available Recipes:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i+1 << ". " << recipe[i].getRecName() << endl;
    }
}

//outputs to file a selected recipe report
void generateSingleRecipeReport(const Recipe* recipe, const double ingredientPQg[5], const double ingredientPP[5], 
    double margin, bool useCustomMargin, ofstream& reportFile) 
    {
    reportFile << fixed << setprecision(2);
    reportFile << "---------------------------------" << endl;
    reportFile << "  " << recipe->getRecName() << " ANALYSIS" << endl;
    reportFile << "---------------------------------" << endl; 
    
    // Margin information
    reportFile << "Profit Margin Information:" << endl;
    if (useCustomMargin) {
        reportFile << " - Custom margin: " << margin * 100 << "%" << endl;
    } else {
        reportFile << " - Margin: " << margin * 100 << "%" << endl;
    }
    reportFile << endl;
    
    // Financial calculations
    double cost = recipe->getRC(ingredientPQg, ingredientPP);
    double revenue = cost * (1.0 + margin);
    double profit = revenue - cost;
    double profitPerUnit = profit / recipe->getTotalCount();
    
    // recipe margin suggestion + recipe money break down
    reportFile << "Business Suggestion:" << endl;
    vector<double> tempMargins = {margin, margin, margin, margin, margin, margin};
    string suggestion = "  " + recipe->getSuggestion(ingredientPQg, ingredientPP, tempMargins);
    reportFile << suggestion << endl;
    reportFile << endl;
    
    reportFile << "Financial Analysis:" << endl;
    reportFile << "  Total Cost: $" << cost << endl;
    reportFile << "  Total Revenue: $" << revenue << endl;
    reportFile << "  Total Profit: $" << profit << endl;
    reportFile << "  Profit per Unit: $" << profitPerUnit << endl;
    reportFile << endl;

    // Recipe details
    reportFile << "---------------------------------" << endl;
    reportFile << "Recipe Details:" << endl;
    reportFile << "  Preparation Time: " << recipe->getPrepTime() << " hours" << endl;
    reportFile << "  Baking Time: " << recipe->getBakeTime() << " hours" << endl;
    reportFile << "  Total Time: " << recipe->getTotalTime() << " hours" << endl;
    reportFile << "  Batch Size: " << recipe->getBatchSize() << " batches" << endl;
    reportFile << "  Yield per Batch: " << recipe->getYeildCount() << " units" << endl;
    reportFile << "  Total: " << recipe->getTotalCount() << " units" << endl;
    reportFile << endl;
    
    reportFile << "---------------------------------" << endl;
    reportFile << "     End of Report " << endl;
    reportFile << "---------------------------------" << endl;
}

//outputs to file the full report for all recipes
void generateTotalAnalysisReport(const Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5],
    const vector<double>& profitMargins, ofstream& reportFile) 
    {
    reportFile << fixed << setprecision(2);
    reportFile << "=========================================" << endl;
    reportFile << "      TOTAL BUSINESS REPORT" << endl;
    reportFile << "=========================================" << endl << endl;    
    reportFile << "Profit Margins of:" << endl << endl;
    //shows used marign % with name 
        string marginRecNames[6] = {"Conchas", "Cookies", "Donuts", "Muffins", "Roscas", "Default"};
        for (int i = 0; i < 6; i++) {
            reportFile << marginRecNames[i] << ": " << profitMargins[i] * 100 << "%" << endl;
        }
    reportFile << endl;

    // gets total cost, revenue, and profit of the recipes
    double totalCost, totalRevenue, totalProfit;
    calculateBusinessTotals(recipes, ingredientPQg, ingredientPP, profitMargins, totalCost, totalRevenue, totalProfit);
    
    // Business summary
    reportFile << "---------------------------------" << endl;
    reportFile << "Business Summary:" << endl;
    reportFile << "---------------------------------" << endl;
    reportFile << " Total Cost: $" << totalCost << endl;
    reportFile << " Total Revenue: $" << totalRevenue << endl;
    reportFile << " Total Profits: $" << totalProfit << endl;
    reportFile << " Average Profit per Recipe: $" << totalProfit / 5.0 << endl;
    reportFile << endl;
    
    // Overall suggestion
    reportFile << "Overall Suggestion:" << endl;
    reportFile << " " << getBusinessSuggestion(totalProfit) << endl;
    reportFile << endl;
    
    // Sort and show recommendations
    vector<Recipe> sortedByProfit = sortRecipesByProfit(recipes, ingredientPQg, ingredientPP, profitMargins);
    vector<Recipe> sortedByCost = sortRecipesByCost(recipes, ingredientPQg, ingredientPP);
    
    reportFile << "---------------------------------" << endl;
    reportFile << "Most Profitable Recipe: " << sortedByProfit[0].getRecName() << endl;
    reportFile << "Least Profitable Recipe: " << sortedByProfit[4].getRecName() << endl;
    reportFile << endl;
    reportFile << "Least Costly Recipe: " << sortedByCost[0].getRecName() << endl;
    reportFile << "Most Costly Recipe: " << sortedByCost[4].getRecName() << endl;
    reportFile << "---------------------------------" << endl;
    reportFile << endl;


    // Individual recipe break down
    reportFile << "Individual Recipe Analysis:" << endl;
    reportFile << "============================" << endl;
    
    for (int i = 0; i < 5; i++) {
        double cost = recipes[i].getRC(ingredientPQg, ingredientPP);
        double revenue = recipes[i].getRR(ingredientPQg, ingredientPP, profitMargins);
        double profit = revenue - cost;
        
        reportFile << recipes[i].getRecName() << ":" << endl;
        reportFile << " Suggestion: " << endl;
        reportFile << " " << recipes[i].getSuggestion(ingredientPQg, ingredientPP, profitMargins) << endl;
        reportFile << endl;
        reportFile << "  Cost: $" << cost << endl;
        reportFile << "  Revenue: $" << revenue << endl;
        reportFile << "  Profit: $" << profit << endl;
        reportFile << "  Margin: " << profitMargins[i] * 100 << "%" << endl;
        reportFile << " --- --- --- " << endl;
    }


    reportFile << "=========================================" << endl;
    reportFile << "           End of Report" << endl;
    reportFile << "=========================================" << endl;
}

// function that runs when choosing to only do a single recipe analysis 
void singleRecipeAnalysisMenu(Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], Configurations& config) {
    cout << endl;
    cout << "=========================================" << endl;
    cout << "        SINGLE RECIPE ANALYSIS" << endl;
    cout << "-----------------------------------------" << endl;
    
    string recipeName;
    displayRecipeList(recipes);
    
    cout << "Enter the recipe name youd like to see" << endl;
    cout << " (as shown above): ";
    const Recipe* foundRecipe = nullptr;
    do{
        getline(cin, recipeName);
        
        //incase user inputs number instead of name
        if (recipeName == "1") {recipeName = recipes[0].getRecName();} 
        if (recipeName == "2") {recipeName = recipes[1].getRecName();}
        if (recipeName == "3") {recipeName = recipes[2].getRecName();}
        if (recipeName == "4") {recipeName = recipes[3].getRecName();} 
        if (recipeName == "5") {recipeName = recipes[4].getRecName();}

        // Search for recipe using existing function
        foundRecipe = searchRecipeByName(recipes, recipeName);
        if (foundRecipe == nullptr) {
            cout << "Recipe not found! Please try again." << endl;
        }
    } while (foundRecipe == nullptr);
    
    cout << endl;
    cout << "Selected Recipe: " << foundRecipe->getRecName() << endl;
    cout << "--------------------------------------" << endl;
    
    // Get profit margin option
    cout << "PROFIT MARGIN OPTIONS:" << endl;
    cout << "1. Use saved margin" << endl;
    cout << "2. Use default margin" << endl;
    cout << "3. Enter custom margin" << endl;
    cout << "Enter your choice (1-3): ";
    
    int marginChoice;
    double margin = 0.0;
    bool useCustomMargin = false;
    do{
        cin >> marginChoice;
        cin.clear();
        cin.ignore(1000, '\n');

        if (marginChoice < 1 || marginChoice > 3) {
            cout << "Invalid margin! Please try again." << endl;
        }

    } while (marginChoice < 1 || marginChoice > 3);
        
    switch(marginChoice) {
        case 1: // saved margin
            {
            int marginIndex = 5;
            string recName = foundRecipe->getRecName();
        
            if (recName == "Conchas" || recName == "conchas") { marginIndex = 0; }
            else if (recName == "Cookies" || recName == "cookies") { marginIndex = 1; }
            else if (recName == "Donuts" || recName == "donuts") { marginIndex = 2; }
            else if (recName == "Muffins" || recName == "muffins") { marginIndex = 3; } 
            else if (recName == "Roscas" || recName == "roscas") { marginIndex = 4; }

            margin = config.getMargins()[marginIndex];
            cout << "Using saved margin: " << fixed << setprecision(2) << margin * 100 << "%" << endl;
            }
            break;

        case 2: // default margin
            {
            margin = 0.25;
            cout << "Using default margin: 25%" << endl;
            }
            break;

        case 3: // custom margin
            {    
            useCustomMargin = true;
            cout << "Enter custom profit margin (1-100%): ";
            do{
                cin >> margin;
                cin.clear();
                cin.ignore(1000, '\n');

                if (margin < 1 || margin > 100) {
                    cout << "Invalid margin! Please try again." << endl;
                    }
            } while (margin < 1 || margin > 100);
            margin = margin / 100.0;
            }
            break;

        default:
            cout << "Invalid choice! Try again" << endl;
    }
    
    // Generates report
    ofstream reportFile("profit_analysis.txt", ios::app);
    if (!reportFile.is_open()) {
        cout << "ERROR: Cannot open report file!" << endl;
        exit(1);
    }
    
    generateSingleRecipeReport(foundRecipe, ingredientPQg, ingredientPP, margin, useCustomMargin, reportFile);
    
    reportFile.close();
    
    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "Report generated successfully!" << endl;
    cout << "Check 'profit_analysis.txt' for details." << endl;
    cout << "=========================================" << endl;
}

// function that runs when choosing to run a full analysis of all recipes
void totalAnalysisMenu(Recipe recipes[5], const double ingredientPQg[5], const double ingredientPP[5], Configurations& config) {
    cout << "=========================================" << endl;
    cout << "        TOTAL BUSINESS ANALYSIS" << endl;
    cout << "=========================================" << endl;
    
    vector<double>& margins = config.getMargins();
    
    double globalMargin;
    cout << "Enter global profit margin for all recipes (1-100%): ";    
    
    do{
        cin >> globalMargin;
        cin.clear();
        cin.ignore(1000, '\n');
    
        if (globalMargin < 1 || globalMargin > 100) {
            cout << "Invalid margin! Try again." << endl;
        }
    } while (globalMargin < 1 || globalMargin > 100); 

    margins[5] = globalMargin / 100.0; // Default margin
    
    cout << endl;
    cout << "Global margin set to: " << fixed << setprecision(2) << globalMargin << "%" << endl;
    cout << endl;
    
    // Ask about custom individual recipes
    cout << "Do you want to customize margins for individual recipes? (y/n): ";
    char customizeChoice;
    do{
        cin >> customizeChoice;
        cin.clear();
        cin.ignore(1000, '\n');
        customizeChoice = tolower(customizeChoice);
        
        if (customizeChoice != 'y' && customizeChoice != 'n') 
            {cout << "Invalid! try again." << endl;}

    } while (customizeChoice != 'y' && customizeChoice != 'n');
    
    if (tolower(customizeChoice) == 'y') {

        cout << endl;
        // list of options to customize from
        displayRecipeList(recipes);
        cout << "6. Default" << endl;
        cout << "0. Done customizing" << endl;

        bool continueCustomizing = true;
        while (continueCustomizing) {
            
            cout << "Select recipe to customize (0-6): ";
            int recipeChoice;
            
            do {
                cin >> recipeChoice;
                cin.clear();
                cin.ignore(1000, '\n');
                if (recipeChoice < 0 || recipeChoice > 6 ) {
                    cout << "Invalid choice! Please select 0-6." << endl;
                }
            } while (recipeChoice < 0 || recipeChoice > 6 );

            
            if (recipeChoice == 0) {
                continueCustomizing = false;
                continue;
            }
            
            if (recipeChoice >= 1 && recipeChoice <= 6) {
                int index = recipeChoice - 1;
                
                cout << "Enter new profit margin for ";
                string marginRecNames[6] = {"Conchas", "Cookies", "Donuts", "Muffins", "Roscas", "Default"};
                cout << marginRecNames[index] << " (1-100%): ";
                
                double customMargin;

                do{
                    cin >> customMargin;
                    cin.clear();
                    cin.ignore(1000, '\n');
                
                    // Validate and set custom margin
                    if (customMargin >= 1 && customMargin <= 100) {
                        margins[index] = customMargin / 100.0;
                        cout << "Margin updated to " << customMargin << "%!" << endl;
                    } 
                    else {
                        cout << "Invalid margin! Try again." << endl;
                    }

                } while (customMargin < 1 || customMargin > 100); 
            } 
            else {
                cout << "Invalid choice! Please select 0-6." << endl;
            }
        }
    }
    
    // Save the updated configuration
    cout << endl;
    config.saveConfig();
    
    // Generate total analysis report
    ofstream reportFile("profit_analysis.txt", ios::app);
    if (!reportFile.is_open()) {
        cout << "ERROR! Cannot find report file!" << endl;
        exit(1);
    }
    
    // generates total report
    generateTotalAnalysisReport(recipes, ingredientPQg, ingredientPP, margins, reportFile);
    
    reportFile.close();
    
    cout << endl;
    cout << "=========================================" << endl;
    cout << "Total analysis report generated!" << endl;
    cout << "Check 'profit_analysis.txt' for business insights." << endl;
    cout << "=========================================" << endl;
}