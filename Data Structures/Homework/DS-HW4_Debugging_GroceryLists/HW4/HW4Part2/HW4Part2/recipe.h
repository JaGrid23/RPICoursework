//
//  Recipe.h
//  HW4Part2
//
//  Created by Jared Gridley on 2/17/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include <list>
#include <string>
#include "ingredient.h"
using namespace std;

class Recipe{
public:
    //Constructor
    Recipe(const string& name);
    
    //Modifier
    void addIngredient(string& name, int units);
    
    //Acessors
    const string getIngredient(int index)const; //This one isn't reference b/c it uses a local iterator
    int getUnits(int index)const;
    int numIngredients() const;
    const string getName() const;
    
    
private:
    string recipe_name;
    list<Ingredient> Ingreds;
};
