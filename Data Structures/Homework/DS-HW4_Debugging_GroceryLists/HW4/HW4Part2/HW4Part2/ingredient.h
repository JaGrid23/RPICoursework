//
//  ingredient.hpp
//  HW4Part2
//
//  Created by Jared Gridley on 2/19/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#ifndef ingredient_h
#define ingredient_h
#include <string>
using namespace std;

class Ingredient{
public:
    //Constructor
    Ingredient( const string& food, int units);
    
    //Acessors
    const string getName() const;
    int getUnits() const;
    
    //Modifiers
    void useIngredient(int used);
    void addIngredient(int more);
    
private:
    string name;
    int amount;
};


#endif /* ingredient_h */
