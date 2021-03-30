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


Recipe::Recipe(string name){
    recipe_name = name;
    
    
}

void Recipe::addIngredient(string name, int units){
    list<string>::const_iterator i;                             //Initializing the ingredients list itr
    list<int>::const_iterator j = ingredient_amounts.begin();   //Initializing the units list iterator
    for(i = ingredients.begin(); i!=ingredients.end(); i++, j++){
        if(*i > name){
            break;
        }
    }
    ingredients.insert(i, name);
    ingredient_amounts.insert(j, units);
    
}

string Recipe::getIngredient(int index)const{
    list<string>::const_iterator r = ingredients.begin();
    advance(r, index);
    return *r;
}


int Recipe::getUnits(int index) const{
   //********** Returning the amount of the ingredient for the recipe *********
    list<int>::const_iterator k = ingredient_amounts.begin();
    advance(k, index);
    return *k;

}

string Recipe::getName() const{
    return recipe_name;
}


int Recipe::numIngredients() const{
    return ingredients.size();
}
