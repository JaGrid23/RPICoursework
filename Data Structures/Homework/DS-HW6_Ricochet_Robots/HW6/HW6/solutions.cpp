//
//  solutions.cpp
//  HW6
//
//  Created by Jared Gridley on 3/26/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include "solutions.h"

bool Solutions::add_solution(path_map& sol, int move){
    if(move > min_solution){
        return false;
    }
    else if(move < min_solution){
        found_paths.clear();
        min_solution = move;
    }
    found_paths.push_back(sol);
    return true;
}


void Solutions::print_solutions(Board& board){
    //Prints all of the solution for the puzzle
    
    board.print();      //Print the board
    
    //Print out how many solutions were found
    unsigned long solutions_found = found_paths.size();
    cout << solutions_found << " different " << min_solution-1 << " move solutions:" \
    << endl << endl;
    
    //Print out the recorded paths
    for(int i = 0; i<found_paths.size(); i++){
        if(found_paths[i].size() == min_solution-1){
            path_map curr = found_paths[i];
            for(path_map::iterator itr = curr.begin(); itr!= curr.end(); ++itr){
                cout << "robot " << board.getRobot(itr->second.first) << " moves "\
                << itr->second.second<<endl;
            }
            cout << "All goals are satisfied after " << min_solution-1 << " moves"\
            << endl << endl;
        }
    }
}


void Solutions::print_1solution(Board& board, int max_moves){
    /*Prints out path to one solution (as specified), iterates through the path
    and moves the robot through the path, printing the board as it moves. */
    board.print();
    if(found_paths.size() ==0){
        cout << "no solutions with " << max_moves-1 << " or fewer moves" \
        << endl;
    }
    else{
        //Print out the recorded paths
        path_map curr = found_paths[0];
        for(path_map::iterator itr = curr.begin(); itr!=curr.end(); ++itr){
            int robot = itr->second.first;
            string direction = itr->second.second;
            cout << "robot " << board.getRobot(itr->second.first) << " moves " << \
            itr->second.second<<endl;
            board.moveRobot(robot, direction);
            board.print();
        }
        cout << "All goals are satisfied after " << min_solution-1 << " moves" << endl << endl;
    }
}
