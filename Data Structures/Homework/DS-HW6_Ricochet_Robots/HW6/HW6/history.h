//
//  history.hpp
//  HW6
//
//  Created by Jared Gridley on 3/25/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#ifndef history_h
#define history_h

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include "board.h"
#include "solutions.h"

#include <stdio.h>
typedef map<int, pair<int, string> > path_map;
using namespace std;


class History {
public:

    //Public functions related to an storing board history
    string convert_state(const Board& board);   //Converts board state to a string

    bool visual_similarity(string state, int move_num); //Check if board already exists
    void store_visual(string& state, int move);     //Stores in visual_history
    
    
    //Public function related to the solution path
    void store_solution(int move, int robot, string& direction);
    bool found_solution(Solutions& sol, int move);
    
private:
    vector<pair<int, string> > visual_history;
    
    path_map solution_history;
};


#endif /* history_h */
