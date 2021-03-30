//
//  history.cpp
//  HW6
//
//  Created by Jared Gridley on 3/25/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include "board.h"
#include "history.h"
using namespace std;

string History::convert_state(const Board& board){
    /* converts the board state to a string to comapare with
     past boards faster*/
    string board_state = "";
    
    //Appends each robot and their position to board_state string
    for(int i = 0; i<board.numRobots(); ++i){
        char bot_id = board.getRobot(i);
        string bot_row = to_string(board.getRobotPosition(i).row);
        string bot_col = to_string(board.getRobotPosition(i).col);
        
        board_state = board_state + bot_id + bot_row +"-"+ bot_col;
    }
    
    return board_state;
}


void History::store_visual(string& state, int move_num){
    //Adds board state to the visual_history vector
    visual_history.push_back(make_pair(move_num, state));
}

bool History::visual_similarity(string state, int move_num){
    //Returns true if board string already exists, false if it does not
    for(int i = 0; i<visual_history.size(); ++i){
        if(visual_history[i].second == state){
            if(move_num >= visual_history[i].first){
                return true;
            }
            else{
                visual_history[i].first = move_num;
                return false;
            }
        }
    }
    return false;
}

void History::store_solution(int move, int robot, string& direction){
    //Adds the next part of the path to the solution_history map
    solution_history.insert(make_pair(move, make_pair(robot, direction)));
}

bool History::found_solution(Solutions& sol, int move){
    //Adds solution path_map to the solutions vector
    return sol.add_solution(solution_history, move);
}
