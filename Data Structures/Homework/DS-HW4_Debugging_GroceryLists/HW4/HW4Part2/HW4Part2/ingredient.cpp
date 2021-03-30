//
//  ingredient.cpp
//  HW4Part2
//
//  Created by Jared Gridley on 2/19/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include "ingredient.h"


//Constructor
Ingredient::Ingredient(const string &food, int units){
    name = food;
    amount = units;
}


//Acessor: Ingredient Name
const string Ingredient::getName() const{
    return name;
}


//Acessor: Ingredient Amount
int Ingredient::getUnits()const{
    return amount;
}


//Modifier: subtracts given amount of ingerdient from available amounts
void Ingredient::useIngredient(int used){
    amount-=used;
}


//Modifier: adds a given amount of ingredient to the amount present
void Ingredient::addIngredient(int more){
    amount += more;
}

