//
//  AthleteFunctions.cpp
//  HW2
//
//  Created by Jared Gridley on 1/31/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "Athlete.h"

void add_result(Athlete &player, float result, string event){
    if(event=="POLE_VAULT"){
        player.setresult(7, result);
    }
    else if(event == "JAVELIN_THROW"){
        player.setresult(8, result);
    }
    else if(event=="1500_METERS"){
        player.setresult(9, result);
    }
    else if(event=="SHOT_PUT"){
        player.setresult(2, result);
    }
    else if(event == "HIGH_JUMP"){
        player.setresult(3, result);
    }
    else if(event == "400_METERS"){
        player.setresult(4, result);
    }
    else if(event == "110_METERS_HURDLES"){
        player.setresult(5, result);
    }
    else if(event == "DISCUS_THROW"){
        player.setresult(6, result);
    }
    else if(event == "100_METERS"){
        player.setresult(0, result);
    }
    else if(event == "LONG_JUMP"){
        player.setresult(1, result);
    }
}

bool sortingAthletes_scores(const Athlete& a, const Athlete& b){
    //Sorting the vector for the scores, sorts by country and then last name
    if(a.getCountry() < b.getCountry() or (a.getCountry()==b.getCountry() and a.getLastName()<b.getLastName())){
        return true;
    }
    else{
        return false;
    }
}

bool sortingAthletes_points(const Athlete& a, const Athlete& b){
    //Sorting the vector for the points, Most to least amount of points.
    if(a.gettotalpoints() > b.gettotalpoints()){
        return true;
    }
    else{
        return false;
    }
}


void print_scores(string outfile, vector<Athlete>A){        //'A' is for Athletes
    ofstream out(outfile);
    //Write the first line of the titles.
    out<<"DECATHLETE SCORES                   100     LJ     SP     HJ    400   110H     DT     PV     JT     1500"<<endl;
    
    //Printing Athlete Data.
    for(unsigned int i = 0; i<A.size(); i++){
        
        //Printing athlete FirstName, LastName, and Country
        out<<left<<setw(14)<<setfill(' ')<<A[i].getFirstName()<<setw(15)<<setfill(' ')<<A[i].getLastName()<<A[i].getCountry();
        
        //Printing out the results (excluding 1500)
        for(int j=0; j<9; j++){
            if(A[i].getresults(j) ==0){                  //Checks if value is zero (meaning DQ or DNR), and replaces it with blank
                out<<"       "; }
            else{
                out<<fixed<<setprecision(2)<<setw(7)<<setfill(' ')<<right<<A[i].getresults(j);   }
        }
        
        //Printing out the 1500, reconstrucing minutes:seconds.miliseconds
        int min = A[i].getresults(9)/60;
        float sec = A[i].getresults(9) - (min*60);
        if(A[i].getresults(9) ==0){                      //Special case for when they DNF or DQ in the 1500
            out<<"         "<<endl;
        }
        else{                                            //Regular Output
            out<<fixed<<setprecision(2)<<setw(3)<<setfill(' ')<<right<<min<<":";
            if(sec< 10){
                out<<0<<sec<<endl;  }
            else{
                out<<sec<<endl;     }
        }
    }
}

void calculate_points(Athlete &person){
    //100m
    if(person.getresults(0)==0){person.setpoints(0, 0);}
    else{person.setpoints(0, int(25.4347 * pow((18 - (person.getresults(0))), 1.81)));}
    //Long Jump
    if(person.getresults(1) == 0){person.setpoints(1, 0);}
    else{person.setpoints(1, int(0.14354 * pow(((person.getresults(1)*100) - 220), 1.4)));}
    //Shot put
    if(person.getresults(2) == 0){person.setpoints(2, 0);}
    else{person.setpoints(2, int(51.39 * pow(((person.getresults(2)) - 1.5), 1.05)));}
    //High Jump
    if(person.getresults(3) == 0){person.setpoints(3, 0);}
    else{person.setpoints(3, int(0.8465 * pow(((person.getresults(3)*100) - 75), 1.42)));}
    //400m
    if(person.getresults(4) ==0){person.setpoints(4, 0);}
    else{person.setpoints(4, int(1.53775 * pow(82 - (person.getresults(4)), 1.81)));}
    //100m Hurdles
    if(person.getresults(5) ==0){person.setpoints(5, 0);}
    else{person.setpoints(5, int(5.74352 * pow(28.5 - (person.getresults(5)), 1.92)));}
    //Discus Throw
    if(person.getresults(6) == 0){person.setpoints(6, 0);}
    else{person.setpoints(6, int(12.91 * pow((person.getresults(6) - 4), 1.1)));}
    //Pole Vault
    if(person.getresults(7)==0){person.setpoints(7, 0);}
    else{person.setpoints(7, int(0.2797 * pow(((person.getresults(7)*100) - 100), 1.35)));}
    //Javelin Throw
    if(person.getresults(8)==0){person.setpoints(8,0);}
    else{person.setpoints(8, int(10.14 * pow((person.getresults(8) - 7), 1.08)));}
    //1500m
    if(person.getresults(9)==0){person.setpoints(9, 0);}
    else{person.setpoints(9, int(0.03768 * pow(480 - (person.getresults(9)), 1.85)));}
    
    //Total Points
    int total = 0;
    for(int i = 0; i<10; i++){
        total+=person.getpoints(i);
    }
    person.settotalpoint(total);
}


void print_points(string outfile, vector<Athlete>P){    //'P' is for Player/Points
    ofstream out(outfile);
    
    //Printing the Header
    out<<"DECATHLETE POINTS                   100     LJ     SP     HJ    400   110H     DT     PV     JT   1500    TOTAL"<<endl;
    
    //Calculating and printing the points for every athlete in the vector
    for(unsigned int l = 0; l<P.size(); l++){
        
        //Prints FirstName, LastName, and Country
        out<<left<<setw(14)<<setfill(' ')<<P[l].getFirstName()\
        <<setw(15)<<setfill(' ')<<P[l].getLastName()<<P[l].getCountry();
        
        //Prints the points for each event for the Athlete
        for(int m=0; m<10; m++){
            out<<fixed<<setw(7)<<setfill(' ')<<right<<P[l].getpoints(m);
        }
        out<<setw(7)<<setfill(' ')<<right<<P[l].gettotalpoints()<<endl;
    }
}

void print_WinningCountries(string outfile, vector<Athlete>Olympian){
    ofstream out(outfile);
    
    //Array of the largest points values by event
    int Largest_points[10] = {0,0,0,0,0,0,0,0,0,0};
    //Array of the countries corresponding ot largest point list;
    string winning_countries[10];
    //Calculating the winning countries
    for(int m = 0; m<Olympian.size(); m++){
        for(int i = 0; i<10; i++){
            cout<<Olympian[m].getpoints(i)<<endl;
            if(Olympian[m].getpoints(i) > Largest_points[i]){
                Largest_points[i] = Olympian[m].getpoints(i);
                winning_countries[i] = Olympian[m].getCountry();
                cout<<"In Functions"<<endl;
            }
        }
    }
    
    
    //Printing out the top bar of event titles
    out<<"WINNING COUNTRIES     100     LJ     SP     HJ    400   110H     DT     PV     JT   1500"<<endl;
    //PRINTING OUT SPACING
    out<<"                  ";
    //Printing out the winning countries.
    for (int n = 0; n<10; n++){
        out<<fixed<<setw(7)<<setfill(' ')<<right<<winning_countries[n];
    }
}


