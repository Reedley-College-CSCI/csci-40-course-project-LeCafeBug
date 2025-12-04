[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7mdzU3H2)
# CS1 Final Project - Bakery Recipe Analyser 

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  

This program allows small bakeries to easily break down there cost and profit for recipes 
all while also giving them suggestions based on what the numbers say.

It allows the user to analysis a single recipe or to analysis every recipe at once. 
The user can also set custom margins for there single recipe or even every recipe if they’d like. 
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
As for sorting I did a selection sort for my two froms of sorting recipes. One sorted by profit and the other cost. 

I ensured data persitence

I did consider it for multiple things like the classes and there object declartions. Particularly for the searching and sorting algorithms
I thought about making faster more complex algorithms like the bubble sorting but I due to the time consraint I felt that using 
my time to do so would eat at time I needed to for the rest of things and the trade off wasnt worth it.

---

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

Test ID    Description        input    Expected Output    Actual Output     Pass/Fail
TC-01    Select from main     1           
          menu options
TC-01
TC-01
TC-01
TC-01
TC-01
TC-01
TC-01
TC-01
TC-01


---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

---

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- What key lessons did you learn about programming and problem-solving?  

I faced many challenges while working on the project. Of the many was the how I was gonna do what I was looking to do. 
In particualer the issue I had was not being more thoughtfull in my over all plan. I really learned how much was needed
to exectue a program of such magnitude. I had orignially planned certian functions and what they'd do but once I began to 
make my way through my oringal plan I found that each step in the plan actually had multiple steps to them. For all the 
headaches, I did end up having to learn a lot in terms of how to do things and how not to.
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
