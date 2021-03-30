//
//  kitchen.h
//  HW4Part2
//
//  Created by Jared Gridley on 2/17/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <string>
#include <list>
#include "ingredient.h"
using namespace std;

class Kitchen{
public:
    //Constructor
    Kitchen();
    
    //Modifiers
    void addIngredient(string& name, int units);
    void useIngredients(int amount, string& ingredient);
    
    //Acessors
    string getIngredient(int index)const;
    int getUnits(int index)const;
    int numIngredients() const;
    
    //Functions to remove 0's and sort kitchen
    void cleanKitchen();
    
    //Print the ingredients
    void printIngredients(ostream &ostr);
    
    
private:
    string name;
    list<Ingredient> Ingreds;
    
};
