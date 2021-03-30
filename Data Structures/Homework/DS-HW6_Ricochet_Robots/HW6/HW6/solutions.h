//
//  solutions.hpp
//  HW6
//
//  Created by Jared Gridley on 3/26/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <vector>
#include <string>
#include <iostream>
#include "board.h"
#include "history.h"
using namespace std;

typedef map<int, pair<int, string> > path_map;
typedef vector<path_map> paths;

#ifndef solutions_h
#define solutions_h

#include <stdio.h>
class Solutions {
public:
    //Constructor: min_solution is 25 (Eberhard Karls University of Tübingen)
    Solutions(){min_solution = 25; }
    
    //Public functions related to a solution path
    bool add_solution(path_map& sol, int move);     //Adds to the found_paths vector
    void print_solutions(Board& board);         //Print function
    void print_1solution(Board& board, int max_moves);
    
private:
    int min_solution;
    paths found_paths;
    
};

#endif /* solutions_hpp */
