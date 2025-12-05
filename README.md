[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - Bakery Recipe Analyser 

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  

This program allows small bakeries to easily break down there cost and profit for recipes 
all while also giving them suggestions based on what the numbers say.

It allows the user to analysis a single recipe or to analysis every recipe at once. 
The user can also set custom margins for their single recipe or even every recipe if they’d like. 
Once the user runs through the customization they can then see their analysis in the output file. 
They can then without restarting the program run as many analysis as they’d like.

---

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  
- Why did you choose to structure your data using structs?  
- How did you implement searching and sorting? What algorithms did you use and why?  
- How do you ensure data persistence between program runs?  
- Did you consider alternative approaches? If so, why did you not use them?  

I choose to make 3 main classes. One just for user configuration. The two other way more important an ingrediants and recipe
class. I also decided to use multiple files to allow for easier navigation throught the program.

I choose to use structs for storing recipe ingredient information as it allowed me to have a vector in the recipe class that held all 
the ingredient inforamtion specific to that recipe.

I implemented searching by having a search function called: searchRecipeByName which allowed me to find a users input and return a pointer to it.
It is a simple linear search as for me it was the easier to implement and not have it break to easily.
As for sorting I did a selection sort for my two froms of sorting recipes. One sorted by profit and the other cost. I did this for much the same 
reason as the searching function.

I ensured data persitence by saving the inputs of the margins a seperate txt file that is read and load at the begining of the program.

I did consider it for multiple things like the classes and there object declartions. Particularly for the searching and sorting algorithms
I thought about making faster more complex algorithms like the bubble sorting but I due to the time consraint I felt that using 
my time to do so would eat at time I needed to for the rest of things and the trade off wasnt worth it.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

While writing the program I made various test functions after completing certain aspects of the code. One examples is after each
class compeletion I tested them out by making test functions. This allowed me to test various aspects of the code in combination 
with others. This was especially important as the user interface was the last thing I did. 

Test ID	|   Description	        Input	                Expected Output	            Actual Output	                Pass/Fail   

        Main Menu Input				
TC-01.1	|   valid 	        "1" for the first	Displays single             Shows single recipe menu              P  
        |   menu option          option                 recipe analysis menu	
        |
TC-01.2	|   invalid	        “Shjdbf” then           Shows errors, reprompts     "Invalid choice! Please               P
        |   menu option         "7" then "2"            and accepts valid input	    enter 1, 2, or 3:" 2 times   	
        |                                                                           then accepts "2" showing total menu

	Recipe Search Test				
TC-02.1	|   Valid  Search 	"Muffins" or ”2”	Finds recipe object         Returns pointer to recipe and         P
        |                                       	                            message saying recipe name
        |	
TC-2.2	|   Invalid Search	“Amtak”	                Shows error and wait        Returns:"Recipe not found!            P
        |                                               for new input	            Please try again.” and waits 
        |                                                                           for next input	

        Data Persistence Test				
TC-03.1	|   File warning	profit_analysis.txt	Shows file warning          Displays "⚠️ WARNING: Existing 	  P
        |   when file isn’t     has data when first     message allowing the user   profit_analysis.txt file 
        |   empty               starting program        to copy and paste out       contains data! . . . ”
        |                                               before wiping the file
        |
TC-03.2	|   Saves custom	“1” for which recipe	Once done customizing	    Displays: “Profit margins saved.”     P
        |   margins             then “42” for margin    it tells user it saved      And the config.txt file has 
        |                       and “0” to stop         and config.txt file has     the updated margins for the 1st
        |                       customizing             new margins along with      recipe along using the margin 
        |                                               the analysis using them     in new report
	
        Edge Case Margin Input				
TC-04	|   Minimum valid   	"1"% whenever asked     Accepts 1% margin	    Uses 1% in calculations	          P
        |   margin              for a margin

        Recipe sorting test				
TC-05	|   Custom margins 	“100” for margin of	In the Total Business 	    Displays: “Most Profitable  	  P
	|   change the profit   Muffins and “12” for    Summary: Muffins and        Recipe: Muffins Least Profitable 
        |   sorted list         conchas                 Conchas show as most        Recipe: Chonchas"
        |                                               and least profitable

---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

When the program runs it starts by loading all the information from the files. The program checks for the critical 
files and if theres an issue it'll say so and automatically stop. Otherwise it tells the user there aren't any. Once 
everything is loaded it'll display the main menu from which the user can select a single or total recipe analysis or to 
stop the program.

If one selects the 1st option it'll bring up a list of recipes to choose from. Regardless of which recipe they can then 
select to use the saved, default, or enter a custom margin. If selecting saved or default it'll display the margin and 
generate an analysis. If selecting custom they can then enter one and once it generates. Regardless of option it sends the 
user back to the main menu. 

If selecting a total recepies analysis it ask for a global/default margin for all the recipes. Once doing that the user is
asked if they want to enter custom margin or used saved. For custom they are presented with a list from which to customize 
as well as a 0 to stop customizing. It'll then save the margins both custom and global and generate a report. It then sends
the user back to the main menu.

If selecting 0 or to exit the program they are told thank you and the program stops.

https://youtu.be/484JE24hrEk

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- What key lessons did you learn about programming and problem-solving?  

I faced many challenges while working on the project. Of the many was the how I was gonna do what I was looking to do. 
In particualer the issue I had was not being more thoughtfull in my over all plan. I really learned how much was needed
to execute a program of such magnitude. I had originally planned certian functions and what they'd do but once I began to 
make my way through my original plan I found that each step in the plan actually had multiple steps to them. For all the 
headaches, I did end up having to learn a lot in terms of how to do things and how not to. One of the things I learned to
use was what I think is called a for-each loop or a ranged based for loop. It looks like: for (variable : container); 

---

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  

Many of the things I orignially planeed to do I was unable to get to doing, hopefully I'll be able to get to doing soon
after the semester ends. Here are a few:
    Adding a profit per hour calculation.
    Adding monthly overhead input and allocation.
    Adding exceptions 
    Validate that ingredients in ingredient_recipes.csv actually exist in ingredients.csv.
    Validate that a list of ingrediants for a recipe exist in ingredient_recipes.csv
    Automatically create obects for ingrediants and recipes based on the files
    Allow for variable amounts of ingrediants in recipes
    Allow the user to choose how to sort end analysis

My biggest thing however is cleaning up the program as right now because of the time restraint the need for changing plans 
caused a lot of unproper planning.
