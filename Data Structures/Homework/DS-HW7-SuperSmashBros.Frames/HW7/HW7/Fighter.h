//
//  Fighter.h
//  HW7
//
//  Created by Jared Gridley on 3/31/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <string>
#include <fstream>

using namespace std;
#ifndef Fighter_h
#define Fighter_h

typedef pair<int, string>  fighter;

class Fighter{
public:
    //Constructor
    Fighter(string name, int jab, int forward_t, int up_t, int down_t, \
            int forward_s, int up_s, int down_s);
    
    //Acessors for to create the sets from the map of Fighter Objects
    string getName() const { return fighter_name; }
    int getJab() const { return jab; }
    int getForwardTilt() const { return forward_tilt; }
    int getUpTilt() const { return up_tilt; }
    int getDownTilt() const { return down_tilt; }
    int getForwardSmash() const { return forward_smash; }
    int getUpSmash() const { return up_smash; }
    int getDownSmash() const { return down_smash; }
    
    //Output function for the '-q' function
    void printMoveData(string& move, ofstream& outfile) const;
    
private:
    int jab, forward_tilt, up_tilt, down_tilt, forward_smash, up_smash, down_smash;
    string fighter_name;
    
};

#endif /* Fighter_h */
