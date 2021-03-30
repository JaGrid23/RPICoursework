//
//  main.cpp
//  HW7
//
//  Created by Jared Gridley on 3/31/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include "Fighter.h"
#include "Sorting.h"
using namespace std;
//You may add additional typedefs, includes, etc. up here

typedef map<string, Fighter> character_map;
typedef character_map::iterator Iter;
typedef set<pair<int, string> > move_set;


//This is the only array you are allowed to have in your program.
const std::string move_names[7] = {"jab", "forward-tilt", "up-tilt", "down-tilt", "forward-smash", "up-smash", "down-smash"};


void f_cmd(move_set& players, ostream& outfile, int limit, string& move){
    //This is the function to output the information for the '-f' command
    outfile << "-f " << move <<" "<< limit << endl;
    
    move_set::iterator itr = players.begin();
    int players_size = players.size();
    int itr_max = min(limit, players_size);     //Sets the max to output
    
    for(int i = 0; i<itr_max; i++){             //outputs itr_max fighters
        outfile << itr->second << " " << itr->first << endl;
        itr++;
    }
    outfile << endl;                            //extra line for outfile formatting
}


void s_cmd(move_set& players, ostream& outfile, int limit, string& move){
    //This is the function to output the information for the '-s' command
    outfile << "-s " << move <<" "<< limit << endl;
    
    set<pair<int, string> , s_sort> n_players;    //Creates new reverse sorted set
    for(move_set::iterator i = players.begin(); i!=players.end(); i++){
        n_players.insert(*i);          //Adding everything from original set to new set
    }
    
    move_set::iterator ritr = n_players.begin();
    int players_size = n_players.size();
    int itr_max = min(limit, players_size);     //Sets the max to output
    
    for(int i = 0; i<itr_max; i++){             //outputs itr_max fighters
        outfile << ritr->second << " " << ritr->first << endl;
        ritr++;
    }
    outfile << endl;                            //Extra line for output formatting
}


void d_cmd(move_set& players, ostream& outfile, int frame, string& move){
    //This is the function to output the information for the '-d' command
    outfile << "-d " << move <<" "<< frame << endl;
    
    move_set::iterator itr = players.begin();
    while(itr->first != frame){             //Iterating to first 'frame' key in set
        itr++;
    }
    while(itr->first == frame){             //Printing all fighters with 'frame' key
        outfile << itr->second << endl;
        itr++;
    }
    outfile << endl;                        //Extra line for output formatting
}



int main(int argc, char** argv){
    // Argument parsing
    if(argc != 4){
        std::cerr << "Proper usage is " << argv[0] << " [database file] [input file] [output file]" << std::endl;
        return -1;
    }

    std::ifstream dbfile(argv[1]);
    if(!dbfile){
        std::cerr << "Failed to open database " << argv[1] << " for reading." << std::endl;
    }

    std::ifstream infile(argv[2]);
    if(!infile){
        std::cerr << "Failed to open input " << argv[2] << " for reading." << std::endl;
    }

    std::ofstream outfile(argv[3]);
    if(!outfile){
        std::cerr << "Failed to open output " << argv[3] << " for writing." << std::endl;
    }

    //Initializing the map of fighters
    character_map fighters;
    
    //Parsing through the database
    string character, place;
    int _jab, _f_tilt, _u_tilt, _d_tilt, _f_smash, _u_smash, _d_smash;
    while(dbfile >> character){
        if(character == "character-name"){
            for(int i = 0; i<7; i++){           //Skipping over the title line
                dbfile >> place;
            }
        }
        else{
            dbfile >> place;    _jab = stoi(place);     //storing jab data
            dbfile >> place;    _f_tilt = stoi(place);  //storing f-tilt data
            dbfile >> place;    _u_tilt = stoi(place);  //storing u-tilt data
            dbfile >> place;    _d_tilt = stoi(place);  //storing d-tilt data
            dbfile >> place;    _f_smash = stoi(place); //storing f-smash data
            dbfile >> place;    _u_smash = stoi(place); //storing u-smash data
            dbfile >> place;    _d_smash = stoi(place); //storing d-smash data
            
            //Creating a Fighter class object with stored variables (from above_
            Fighter temp(character, _jab, _f_tilt, _u_tilt, _d_tilt, _f_smash,\
                         _u_smash, _d_smash);
            fighters.insert(make_pair(character, temp));    //Adding to fighters map
        }
    }
    
    //Initializing all the sets for each type of data: map<int data, string name>
    move_set jabs, forward_t, up_t, down_t, forward_s, up_s, down_s;
    
    //Creating all of the different sets - adding specific data from map to each set
    for(Iter it = fighters.begin(); it != fighters.end(); it++){
        jabs.insert(make_pair(it->second.getJab(), it->first));
        forward_t.insert(make_pair(it->second.getForwardTilt(), it->first));
        up_t.insert(make_pair(it->second.getUpTilt(), it->first));
        down_t.insert(make_pair(it->second.getDownTilt(), it->first));
        forward_s.insert(make_pair(it->second.getForwardSmash(), it->first));
        up_s.insert(make_pair(it->second.getUpSmash(), it->first));
        down_s.insert(make_pair(it->second.getDownSmash(), it->first));
    }
    
    
    

    //Parsing through the commands on the input file
    string command, name, move, s_limit, s_frame;
    while(infile >> command){
        if(command == "-q"){
            infile >> name;
            infile >> move;
            
            //Finding the character name in the map
            character_map::iterator found = fighters.find(name);
            
            //Checking if the name/move doesn't exist
            if(found == fighters.end()){
                outfile << "Invalid character name: " << name << endl << endl;
            }
            else if(move != "all" && find(move_names, move_names+7, move) == move_names+7){
                outfile << "Invalid move name: "<< move << endl << endl;
            }
            else{
                found->second.printMoveData(move, outfile);
            }
        }
        else if(command == "-f"){
            infile >> move;
            infile >> s_limit;
            
            int limit = stoi(s_limit);
            /*Checking the if the move is valid, if so then finds the right set and
             calls the function for -f. */
            if(find(move_names, move_names+7, move) == move_names+7){
                outfile << "Invalid move name: "<< move << endl << endl; }
            else if(move == "jab"){ f_cmd(jabs, outfile, limit, move); }
            else if(move == "forward-tilt"){ f_cmd(forward_t, outfile, limit, move); }
            else if(move == "up-tilt"){ f_cmd(up_t, outfile, limit, move); }
            else if(move == "down-tilt"){ f_cmd(down_t, outfile, limit, move); }
            else if(move == "forward-smash"){ f_cmd(forward_s, outfile, limit, move); }
            else if(move == "up-smash"){ f_cmd(up_s, outfile, limit, move); }
            else if(move == "down-smash"){ f_cmd(down_s, outfile, limit, move); }
            
        }
        else if(command == "-s"){
            infile >> move;
            infile >> s_limit;
            int limit = stoi(s_limit);
            
            /*Checking the if the move is valid, if so then finds the right set and
             calls the function for -s. */
            if(find(move_names, move_names+7, move) == move_names+7){
                outfile << "Invalid move name: "<< move << endl << endl; }
            else if(move== "jab"){ s_cmd(jabs, outfile, limit, move); }
            else if(move== "forward-tilt"){s_cmd(forward_t, outfile, limit, move);}
            else if(move== "up-tilt"){ s_cmd(up_t, outfile, limit, move); }
            else if(move== "down-tilt"){ s_cmd(down_t, outfile, limit, move); }
            else if(move== "forward-smash"){ s_cmd(forward_s, outfile, limit, move); }
            else if(move== "up-smash"){ s_cmd(up_s, outfile, limit, move); }
            else if(move== "down-smash"){ s_cmd(down_s, outfile, limit, move); }
        }
        else if(command == "-d"){
            infile >> move;
            infile >> s_frame;
            int frame = stoi(s_frame);
            
            /*Checking the if the move is valid, if so then finds the right set and
             calls the function for -d. */
            if(find(move_names, move_names+7, move) == move_names+7){
                outfile << "Invalid move name: "<< move << endl << endl; }
            else if(move == "jab"){ d_cmd(jabs, outfile, frame, move); }
            else if(move == "forward-tilt"){ d_cmd(forward_t, outfile, frame, move); }
            else if(move == "up-tilt"){ d_cmd(up_t, outfile, frame, move); }
            else if(move == "down-tilt"){ d_cmd(down_t, outfile, frame, move); }
            else if(move == "forward-smash"){ d_cmd(forward_s, outfile, frame, move); }
            else if(move == "up-smash"){ d_cmd(up_s, outfile, frame, move); }
            else if(move == "down-smash"){ d_cmd(down_s, outfile, frame, move); }
            
        }
    }

    return 0;
}
