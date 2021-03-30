//
// PROVIDED CODE FOR HOMEWORK 4: GROCERY LISTS
//
// You may use none, a little, or all of this, as you choose, but we
// strongly urge you to examine it carefully.  You may modify this
// code as you wish to complete the assignment.
//


#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>

#include "recipe.h"
#include "kitchen.h"


// Helper functions
void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen);
void printRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes);
void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen);

// The main loop parses opens the files for I/O & parses the input
int main(int argc, char* argv[]) {
    
    // Check the number of arguments.
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
        return 1;
    }
    // Open and test the input file.
    std::ifstream istr(argv[1]);
    if (!istr) {
        std::cerr << "Could not open " << argv[1] << " to read\n";
        return 1;
    }
    // Open and test the output file.
    std::ofstream ostr(argv[2]);
    if (!ostr) {
        std::cerr << "Could not open " << argv[2] << " to write\n";
        return 1;
    }
    
    // the kitchen & recipe list
    Kitchen kitchen;
    std::list<Recipe> recipes;
    
    // some variables to help with parsing
    char c;
    while (istr >> c) {
        if (c == 'r') {
            // READ A NEW RECIPE
            readRecipe(istr,ostr,recipes);
            
        } else if (c == 'a') {
            // ADD INGREDIENTS TO THE KITCHEN
            addIngredients(istr, ostr, kitchen);
            
        } else if (c == 'p') {
            // PRINT A PARTICULAR RECIPE
            printRecipe(istr, ostr, recipes);
            
        } else if (c == 'm') {
            // MAKE SOME FOOD
            makeRecipe(istr,ostr,recipes,kitchen);
            
        } else if (c == 'k') {
            // PRINT THE CONTENTS OF THE KITCHEN
            kitchen.cleanKitchen();
            kitchen.printIngredients(ostr);
            
        } else {
            std::cerr << "unknown character: " << c << std::endl;
            exit(0);
        }
    }
}

//========== READ RECIPE FUNCTION =======================================================
void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
    std::string name, name2;
    int units;
    istr >> name;

    bool in_recipes = false;
    //---------- Check if Recipe Already Exists ---------------------------------
    for(std::list<Recipe>::const_iterator r = recipes.begin(); r != recipes.end(); ++r){
        if(r->getName() == name){                       //If recipe name == in name
            in_recipes = true;                          //Change boolean to true
        }
    }
    
    //---------- Recipe Already Exists ------------------------------------------
    if(in_recipes == true){
        ostr<<"Recipe for "<<name<< " already exists"<<std::endl;
        
        while (1) {                                     //Reads all the data until 0
                   istr >> units;
                   if (units == 0) break;
                   assert (units > 0);
                   istr >> name2;
        }                                               //Istr will be ready to read
    }                                                   //next command instead of num
    
    //---------- Recipe Does Not Exist ------------------------------------------
    else{
        Recipe r(name);                                 //Create new recipe object
        
        while (1) {
            istr >> units;                              //Reading the recipe ingredients
            if (units == 0) break;                      //Check if end of ingredients
            assert (units > 0);
            istr >> name2;
            
            r.addIngredient(name2,units);               //Adds ingredients to recipe
        }
        recipes.push_back(r);                           //Add recipe to the recipes list
        
        ostr << "Recipe for " << name << " added" << std::endl;
    }
}


//========== ADD INGREDIENTS TO KITCHEN ==================================================
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
    int units;
    std::string name;
    
    int count = 0;                                      //Track # of ingredients added
    
    while (1) {                                         //Reading ingredient information
        istr >> units;
        if (units == 0) break;                          //Check if end of ingredients
        assert (units > 0);
        istr >> name;
        // add the ingredients to the kitchen
        kitchen.addIngredient(name,units);              //Add Ingredient to kitchen
        count++;                                        //Incremement ingredient # tracker
    }
    
    if(count>1){                               //Printing with readability
        ostr << count << " ingredients added to kitchen" << std::endl;
    }
    else{
        ostr << count << " ingredient added to kitchen" << std::endl;
    }
}

//========== PRINTS RECIPE ===============================================================
void printRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes){
    std::string name;
    istr >> name;
    
    bool in_recipes = false;
    
    for(list<Recipe>::const_iterator i = recipes.begin(); i !=recipes.end(); ++i){
        if(i->getName()==name){
            
            in_recipes = true;                              //Setting the boolean
            
            //---------- Printing the first Line -----------------------
            ostr << "To make "<< name << ", mix together:"<<endl;
            
            //---------- Printing all the Ingredients ------------------
            for(int j = 0; j<i->numIngredients(); j++){
                
                string ingredient = i->getIngredient(j);    //Get printing variables
                int amount = i->getUnits(j);
                
                if(amount>1){                               //Printing with readability
                    ostr<<"  "<<amount<<" units of "<<ingredient<<endl;
                }
                else{
                    ostr<<"  "<<amount<<" unit of "<<ingredient<<endl;
                }
            }
        }
    }
    if(in_recipes == false){                                //Checks if recipe doesn't exist
        ostr << "No recipe for "<< name<<endl;
    }
}

//========== MAKE A RECIPE ================================================================
void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen){
    std::string name;
    istr >> name;
    bool in_recipes = false;
    for(list<Recipe>::const_iterator r = recipes.begin(); r != recipes.end(); r++){
        
        //---------- Checking if the recipe is in the list of recipies ---------------
        if(name == r->getName()){
            in_recipes = true;
            list<string> missing_ingredients;
            list<int> missing_amounts;
            
            //---------- Checking if the ingredients are available ---------------
            for(int j = 0; j<r->numIngredients(); j++){             //Recipe Ingredients
                for(int k = 0; k< kitchen.numIngredients(); k++){   //Kitchen Ingredients
                    
                    //Checks for matching ingredient for recipe in kitchen
                    if(r->getIngredient(j) == kitchen.getIngredient(k)){
                        int required_units = r->getUnits(j);
                        int available_units = kitchen.getUnits(k);
                        int missing_units = required_units - available_units;
                        
                        //Check if there is enough ingredientes
                        if(available_units>=required_units){
                            break;                  //If enough, move to next r ingredient
                        }
                        
                        //If there is not enough ingredients
                        else{                                       //Add to missing lists
                            missing_ingredients.push_back(r->getIngredient(j));
                            missing_amounts.push_back(missing_units);
                            break;                                  //Move to next ingredient
                        }
                    }
                    
                    //Check if recipe ingredient is not it the kitchen
                    if(k == (kitchen.numIngredients()-1)){         //Add to missing lists
                        missing_ingredients.push_back(r->getIngredient(j));
                        missing_amounts.push_back(r->getUnits(j));
                    }
                }
            }
            
            //---------- If have ingredients, then make it -----------------------
            if(missing_amounts.size()==0){
                for(int j = 0; j<r->numIngredients(); j++){             //Recipe Ingredients
                    for(int k = 0; k< kitchen.numIngredients(); k++){   //Kitchen Ingredients
                        
                        //Finding the ingredient in the kitchen
                        if(r->getIngredient(j) == kitchen.getIngredient(k)){
                            int required_units = r->getUnits(j);
                            string ingredient = kitchen.getIngredient(k);
                            
                            //Using "required_units" of ingredient in the kitchen
                            kitchen.useIngredients(required_units, ingredient);
                        }
                    }
                }
                ostr << "Made " << name << endl;
            }
            
            //---------- If we do not ingredients, then print missing -----------
            else{
                ostr<<"Cannot make "<<name<<", need to buy:"<<endl;         //Print Title
                
                //Iterate through the ingredients and amounts:
                list<string>::const_iterator ingred;
                list<int>::const_iterator amt = missing_amounts.begin();
                for(ingred = missing_ingredients.begin(); ingred != missing_ingredients.end(); ingred++, amt++){
                    
                    //Print out the missing ingredients and missing amounts
                    if(*amt>1){
                        ostr<<"  "<<*amt<<" units of "<<*ingred<<endl;
                    }
                    else{
                        ostr<<"  "<<*amt<<" unit of "<<*ingred<<endl;
                    }
                }
            }
        }
    }
    if(in_recipes == false){                                //Checking if not recipe exist
        ostr << "Don't know how to make " << name << endl;
    }
}
        
        
