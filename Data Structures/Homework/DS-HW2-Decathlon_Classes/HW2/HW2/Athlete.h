//
//  Athlete.h
//  HW2
//
//  Created by Jared Gridley on 1/27/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <cmath>
using namespace std;


class Athlete{
private:
    string first_name;
    string last_name;
    string country;
    //Creating an array of the results and points values in this order:
    //100, LJ, SP, HJ, 400, 110H, DT, PV, JT, 1500
    float results[10];
    int points_list[10];
    int total_points;
    
public:
    Athlete(string first, string last, string origin){
        first_name = first;
        last_name = last;
        country = origin;
        //Initializing all of the results and points to 0.
        for(int k = 0; k<10; k++){
            results[k] = 0;
            points_list[k] = 0;
        }
        total_points = 0;
    }
    
    //GETTERS
    float getresults(int result_place) const{
        return results[result_place];
    }
    
    int getpoints(int points_place) const{
        return points_list[points_place];
    }
    
    int gettotalpoints() const{
        return total_points;
    }
    
    string getCountry() const{
        return country;
    }
    
    string getLastName() const{
        return last_name;
    }
    
    string getFirstName() const{
        return first_name;
    }
    
    
    //SETTERS
    void setresult(int result_place, float result){
        results[result_place] = result;
    }
    
    void setpoints(int points_place, int points){
        points_list[points_place] = points;
    }
    
    void settotalpoint(int total){
        total_points = total;
    }
    

    
};
