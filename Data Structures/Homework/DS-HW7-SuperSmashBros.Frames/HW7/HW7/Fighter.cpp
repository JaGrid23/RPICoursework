//
//  Fighter.cpp
//  HW7
//
//  Created by Jared Gridley on 3/31/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include <stdio.h>
#include "Fighter.h"
using namespace std;

//Constructor
Fighter::Fighter(string name, int jab_, int forward_t, int up_t, int down_t, int forward_s, int up_s, int down_s){
    fighter_name = name;
    jab = jab_;
    forward_tilt = forward_t;
    up_tilt = up_t;
    down_tilt = down_t;
    forward_smash = forward_s;
    up_smash = up_s;
    down_smash = down_s;
}


//Output function for the '-q' command
void Fighter::printMoveData(string& move, ofstream& outfile) const{
    if(move == "all"){
        outfile<<fighter_name<<" down-smash: "<<down_smash<<endl;
        outfile<<fighter_name<<" down-tilt: "<<down_tilt<<endl;
        outfile<<fighter_name<<" forward-smash: "<<forward_smash<<endl;
        outfile<<fighter_name<<" forward-tilt: "<<forward_tilt<<endl;
        outfile<<fighter_name<<" jab: "<<jab<<endl;
        outfile<<fighter_name<<" up-smash: "<<up_smash<<endl;
        outfile<<fighter_name<<" up-tilt: "<<up_tilt<<endl<<endl;
    }
    else if(move == "jab"){
        outfile << fighter_name <<" "<< move <<": "<< jab << endl <<endl;
    }
    else if(move == "forward-tilt"){
        outfile << fighter_name <<" "<< move <<": "<< forward_tilt << endl << endl;
    }
    else if(move == "up-tilt"){
        outfile << fighter_name <<" "<< move <<": "<< up_tilt << endl << endl;
    }
    else if(move == "down-tilt"){
        outfile << fighter_name <<" "<< move <<": "<< down_tilt << endl << endl;
    }
    else if(move == "forward-smash"){
        outfile << fighter_name <<" "<< move <<": "<< forward_smash << endl << endl;
    }
    else if(move == "up-smash"){
        outfile << fighter_name <<" "<< move <<": "<< up_smash << endl << endl;
    }
    else if(move == "down-smash"){
        outfile << fighter_name <<" "<< move <<": "<< down_smash << endl << endl;
    }
}
