//
//  kitchen.cpp
//  HW4Part2
//
//  Created by Jared Gridley on 2/17/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include "kitchen.h"
#include <string>
#include "ingredient.h"
#include "iostream"
using namespace std;

//MARK: Non-member functions
//---------- Sorts kitchen ---------------------------------------------------------------
bool kitchen_sort(const Ingredient &i1, const Ingredient &i2){
    if(i1.getUnits()==i2.getUnits()){            //Sorts least to greatest by units then name
        return i1.getName()<i2.getName();
    }
    else{
        return i1.getUnits()<i2.getUnits();
    }
}



//MARK: Constructor
//---------- Constructs the kitchen object to default ------------------------------------
Kitchen::Kitchen(){}


//MARK: Modifiers
//---------- Adds Ingredient to existing object or creates new one -----------------------
void Kitchen::addIngredient(string &name, int units){
    bool in_kitchen = false;
    
    for(list<Ingredient>::iterator i = Ingreds.begin(); i != Ingreds.end(); i++){
        if(i->getName() == name){
            in_kitchen = true;                      //If already in kitchen,
            i->addIngredient(units);                    //add it to the ingredient object
            break;
        }
    }
    
    if(in_kitchen == false){                        //If not already in kitchen
        Ingredient new_i(name, units);                  //Create new ingredient object
        Ingreds.push_back(new_i);                       //Push back to the Ingredients list
    }
}


//---------- Remove Used Ingredients -----------------------------------------------------
void Kitchen::useIngredients(int amount, string &ingredient){
    list<Ingredient>::iterator k;                       //Iterator for Ingreds lst
    
    for(k = Ingreds.begin(); k!=Ingreds.end(); k++){
        if(k->getName() == ingredient){                 //Find the ingredient to use
            k->useIngredient(amount);                       //Use "amount" of ingredient
        }
    }
}


//MARK: Acessors
//---------- Return Ingredient by Index --------------------------------------------------
string Kitchen::getIngredient(int index) const{
    list<Ingredient>::const_iterator i = Ingreds.begin();
    advance(i, index);                                      //Go to index of ingredient
    return i->getName();                                    //Return Ingredient name
}


//---------- Return Num of Units by Index ------------------------------------------------
int Kitchen::getUnits(int index) const{
    list<Ingredient>::const_iterator u = Ingreds.begin();
    advance(u, index);                                //Got to index of ingredient
    return u->getUnits();                             //Return # of ingredients in kitchen
}


//---------- Return the number of ingredients in Kitchen ---------------------------------
int Kitchen::numIngredients() const{
    return Ingreds.size();                           //Return # of ingredients in kitchen
}


//MARK: Clean Kitchen
//---------- Removes used ingredients and sorts the kitchen ------------------------------
void Kitchen::cleanKitchen(){
    for(list<Ingredient>::iterator i = Ingreds.begin(); i != Ingreds.end(); i++){
        if(i->getUnits() == 0){                     //If # of ingredient is 0:
            Ingreds.erase(i--);                     //Erase Ingredient; move iterator back
        }                                               //one so it doesn't skip one
    }
    Ingreds.sort(kitchen_sort);                     //Sorting the kitchen by number
    
}


//MARK: Print Function
//---------- Print the ingredients in the kitchen ----------------------------------------
void Kitchen::printIngredients(ostream &ostr){
    ostr << "In the kitchen:" << endl;              //Writes the first line
    
    for(list<Ingredient>::const_iterator i = Ingreds.begin(); i != Ingreds.end(); i++){
        //For every ingredient in the kitchen:
        
        if(i->getUnits()>1){                        //Making readability match amount
            ostr<<"  "<<i->getUnits()<<" units of "<<i->getName()<<endl;
        }
        else{
            ostr<<"  "<<i->getUnits()<<" unit of "<<i->getName()<<endl;
        }
    }
}




