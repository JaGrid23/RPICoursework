//
//  Recipe.cpp
//  HW4Part2
//
//  Created by Jared Gridley on 2/17/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <string>
#include "recipe.h"
using namespace std;


//MARK: Constructor
//---------- Constructor: sets name to input----------------------------------------------
Recipe::Recipe(const string& name){
    recipe_name = name;
}


//MARK: Modifiers
//---------- Insert new ingredient objects in sorted index -------------------------------
void Recipe::addIngredient(string& name, int units){
    list<Ingredient>::const_iterator i;
    for(i = Ingreds.begin(); i!= Ingreds.end(); i++){
        if(i->getName() > name){                //Finds spot to insert, so its sorted
            break;
        }
    }
    Ingredient new_i(name, units);              //creates new ingredient object
    Ingreds.insert(i, new_i);                   //Inserts at spot, so its sorted
}


//MARK: Acessors
//---------- Return Ingredient name ------------------------------------------------------
const string Recipe::getIngredient(int index)const{
    list<Ingredient>::const_iterator k = Ingreds.begin();
    advance(k, index);                          //Iterates to ingredients spot in the list
    return k->getName();                        //Returns the ingredient name
}


//---------- Return ingredient amount ----------------------------------------------------
int Recipe::getUnits(int index) const{
    list<Ingredient>::const_iterator k = Ingreds.begin();
    advance(k, index);                          //Iterates to the ingredients spot in list
    return k->getUnits();                       //Returns ingredient amount

}


//---------- Return Ingredient amount ----------------------------------------------------
const string Recipe::getName() const{
    return recipe_name;
}


//---------- Returns Number of Ingredients -----------------------------------------------
int Recipe::numIngredients() const{
    return Ingreds.size();
}
