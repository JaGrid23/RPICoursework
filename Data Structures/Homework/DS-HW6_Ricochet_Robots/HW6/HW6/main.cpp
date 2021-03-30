#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <map>

#include "board.h"
#include "history.h"
#include "solutions.h"
using namespace std;

typedef map<int, vector<int> > v_vec;
typedef vector<pair<char, Position> > GoalVec;
// ==================================================================================
// ==================================================================================

// This function is called if there was an error with the command line arguments
bool usage(const std::string &executable_name) {
    std::cerr << "Usage: " << executable_name << " <puzzle_file>" << std::endl;
    std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#>" << std::endl;
    std::cerr << "       " << executable_name << " <puzzle_file> -all_solutions" << std::endl;
    std::cerr << "       " << executable_name << " <puzzle_file> -visualize <which_robot>" << std::endl;
    std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#> -all_solutions" << std::endl;
    std::cerr << "       " << executable_name << " <puzzle_file> -max_moves <#> -visualize <which_robot>" << std::endl;
    exit(0);
}

// ==================================================================================
// ==================================================================================

// load a Ricochet Robots puzzle from the input file
Board load(const std::string &executable, const std::string &filename) {
    
    // open the file for reading
    std::ifstream istr (filename.c_str());
    if (!istr) {
        std::cerr << "ERROR: could not open " << filename << " for reading" << std::endl;
        usage(executable);
    }
    
    // read in the board dimensions and create an empty board
    // (all outer edges are automatically set to be walls
    int rows,cols;
    istr >> rows >> cols;
    assert (rows > 0 && cols > 0);
    Board answer(rows,cols);
    
    // read in the other characteristics of the puzzle board
    std::string token;
    while (istr >> token) {
        if (token == "robot") {
            char a;
            int r,c;
            istr >> a >> r >> c;
            answer.placeRobot(Position(r,c),a);
        } else if (token == "vertical_wall") {
            int i;
            double j;
            istr >> i >> j;
            answer.addVerticalWall(i,j);
        } else if (token == "horizontal_wall") {
            double i;
            int j;
            istr >> i >> j;
            answer.addHorizontalWall(i,j);
        } else if (token == "goal") {
            std::string which_robot;
            int r,c;
            istr >> which_robot >> r >> c;
            answer.addGoal(which_robot,Position(r,c));
        } else {
            std::cerr << "ERROR: unknown token in the input file " << token << std::endl;
            exit(0);
        }
    }
    
    // return the initialized board
    return answer;
}


void make_goalsVec(Board& original, GoalVec& goalsVec){
    /* This is a function to make an easily searchable vector of the goal information
     Will be passed as an argument in finding all solutions*/
    
    for(int i = 0; i< original.numGoals(); i++){
        //For each goal it stores in a vector as a pair: <Robot char/'?', Position>
        Position robot_pos = original.getGoalPosition(i);
        char robot = original.getGoalRobot(i);
        
        goalsVec.push_back(make_pair(robot, robot_pos));
    }
}


//--------- VISUALIZE FUNCTION ---------------------------------------------------------

void reachability(Board &original, Board move_board, History& past, v_vec& visual, \
                  char robot, int move, int max_move){
    /* Recursive function to find all of the possible locations that the pieces
     can move with the least amount of moves. (Optional max_moves parameter)*/
    
    static std::string directions[4] = {"north", "east", "south", "west"};
    
    if(move > max_move && max_move != -1){ return; }      //Base Case: Move limitation

    vector<Board> dirs;
    /* Trying to move every robot in all new directions, then stores them inside dirs
    Purpose: lowers runtime by building history faster, thus less possible moves */
    
    for(int bot = 0; bot<original.numRobots(); bot++){          //For every robot
        for(int direction = 0; direction < 4; direction++){       //For ever direction
    
            move_board = original;                              //resetting move_board
            move_board.moveRobot(bot, directions[direction]);   //moves 1 robot
            
            //Checks if the robot moves is the one we want to record
            if(move_board.getRobot(bot) == robot){
                Position pos = move_board.getRobotPosition(bot);
                
                v_vec::iterator v_itr = visual.find(pos.row-1);
                
                //If the spot is empty or the num there > current move num
                if(visual[pos.row-1][pos.col-1] == -1 || (v_itr->second)[pos.col-1] > move){
                    (v_itr->second)[pos.col-1] = move;  //Replace with current move num
                }
            }
            
            string this_state = past.convert_state(move_board); //converts state to str
            
            /* Base Case: repeating board ->checks if board state already happened with
            with lower move number to get there */
            if(!past.visual_similarity(this_state, move)){
                past.store_visual(this_state, move);    //Store board state
                dirs.push_back(move_board);             //Store board to recurse through
            }
        }
    }
    //Iterating through the boards to recurse through
    for(int i = 0; i< dirs.size(); i++){
        int temp_move = move+1;
        reachability(dirs[i], dirs[i], past, visual, robot, temp_move, max_move);
    }
}


//--------- FIND ALL SOLUTIONS FUNCTION ------------------------------------------------

void find_solutions(Board& original, Board move_board, History original_past,\
                    History move_past, Solutions& sol, int move, int& max_moves,\
                    GoalVec& goals){
    static std::string directions[4] = {"north", "east", "south", "west"};
    
    if(move > max_moves){ return; }         //Base case: Max_moves specified
    
    int at_goal = 0;
    //Iterates through all the goals and see if all correct robots are at their goal
    for(int j = 0; j<goals.size(); j++){
        for(int k = 0; k<original.numRobots(); k++){
            char robot = original.getRobot(k);
            //Checking if robot char and position match the goal
            if((goals[j].first == robot || goals[j].first == '?') \
               && goals[j].second == original.getRobotPosition(k)){
                at_goal++;
            }
        }
    }
    //If every robot is at thier correct goal
    if(at_goal == goals.size()){
        //1. transfer everything from history and store it as a solution.
        //2. if solution has lower moves, change the max_moves to be the lowest solution
        if(move_past.found_solution(sol, move)){max_moves = move; }
        return;
    }
    
    vector<pair<History, Board> > next;
    
    /* Trying to move every robot in all new directions, then stores them inside dirs
    Purpose: lowers runtime by building history faster, thus less possible moves */
    for(int bot = 0; bot<original.numRobots(); bot++){          //For every robot
        for(int direction = 0; direction < 4; direction++){     //For every direction
            
            move_board = original;          //Reset the board
            move_board.moveRobot(bot, directions[direction]);   //Move 1 robot
            
            move_past = original_past;      //Reset history
            
            string this_state = move_past.convert_state(move_board);
            
            /* Base Case: repeating board ->checks if board state already happened with
            with lower move num to get there, uses string from line above to compare*/
            if(!move_past.visual_similarity(this_state, move)){
                /* Store board state 2x, 1st to compare with other boards, 2nd to bulid
                the history of the path to the solution.*/
                move_past.store_visual(this_state, move);
                move_past.store_solution(move, bot, directions[direction]);
                next.push_back(make_pair(move_past, move_board));
            }
        }
    }
    //Iterates through usine paths vector and recurses each one for next move
    for(int i =0; i<next.size(); i++){
        int temp_move = move+1;
        find_solutions(next[i].second, next[i].second, next[i].first, next[i].first,\
                       sol, temp_move, max_moves, goals);
    }
}



// ==================================================================================
// ==================================================================================

int main(int argc, char* argv[]) {
    
    // There must be at least one command line argument, the input puzzle file
    if (argc < 2) {
        usage(argv[0]);
    }
    
    // By default, the maximum number of moves is unlimited
    int max_moves = -1;
    
    // By default, output one solution using the minimum number of moves
    bool all_solutions = false;
    
    // By default, do not visualize the reachability
    char visualize = ' ';   // the space character is not a valid robot!
    
    // Read in the other command line arguments
    for (int arg = 2; arg < argc; arg++) {
        if (argv[arg] == std::string("-all_solutions")) {
            // find all solutions to the puzzle that use the fewest number of moves
            all_solutions = true;
        } else if (argv[arg] == std::string("-max_moves")) {
            // the next command line arg is an integer, a cap on the  # of moves
            arg++;
            assert (arg < argc);
            max_moves = atoi(argv[arg]);
            assert (max_moves > 0);
        } else if (argv[arg] == std::string("-visualize")) {
            // As a first step towards solving the whole problem, with this
            // option, let's visualize where the specified robot can move
            // and how many steps it takes to get there
            arg++;
            assert (arg < argc);
            std::string tmp = argv[arg];
            assert (tmp.size() == 1);
            visualize = tmp[0];
            assert (isalpha(visualize) && isupper(visualize));
            visualize = toupper(visualize);       //Robot letter to be visualized
        } else {
            std::cout << "unknown command line argument" << argv[arg] << std::endl;
            usage(argv[0]);
        }
    }
    
    // Load the puzzle board from the input file
    Board board = load(argv[0],argv[1]);

    
    if(visualize != ' '){
        v_vec visual;
        History past_boards;
        int rows = board.getRows();
        int cols = board.getCols();
        
        //Initializing all of the board spots to '-1'
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                visual[i].push_back(-1);
            }
        }
        
        //Determinig which bot we want to track on the visual.
        int bot = 0;
        for(int i = 0; i <board.numRobots(); i++){
            if(board.getRobot(i)==visualize){bot = i; break;}
        }
        
        /*Storing the starting state of the board in the history ->recursive function
        will start at move number 1*/
        string temp = past_boards.convert_state(board);
        past_boards.store_visual(temp, 0);
        Position pos = board.getRobotPosition(bot);
        v_vec::iterator v_itr = visual.find(pos.row-1);
        (v_itr->second)[pos.col-1] = 0;
        
        //Setting a max_moves if none specified, maximum possible is 25
        if(max_moves == -1){max_moves = (25);}
        
        //Calling recursive function
        reachability(board, board, past_boards, visual, visualize, 1, max_moves);
        
        //Printing out the visualize board
        cout<<"Reachable by robot "<<visualize<<":"<<endl;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                v_vec::iterator v_itr = visual.find(i);
                if((v_itr->second)[j] == -1){
                    cout<<setw(3)<<".";
                }
                else{
                    cout<<setw(3)<<((v_itr->second)[j]);
                }
            }
            cout<<endl;
        }
    }
    else if(all_solutions){
        //Initializing variables for recursive function
        History past;
        Solutions sol;
        GoalVec goals;
        make_goalsVec(board, goals);
        
        //Storing the starting position of the board in the history.
        string temp = past.convert_state(board);
        past.store_visual(temp, 0);
        
        /*Resetting the max_moves if none specified. According to a research paper
         from Eberhard Karls University of Tübingen, max moves for any board is 24.
         (25 becuase mine starts a move ahead)*/
        if(max_moves == -1){max_moves = 25;}
        else{max_moves +=1;}
        
        //Recursive function call
        find_solutions(board, board, past, past, sol, 1, max_moves, goals);
        
        //Printing the solution
        sol.print_solutions(board);
    }
    else{
        //Initializing variable for recursive function
        History past;
        Solutions sol;
        GoalVec goals;
        make_goalsVec(board, goals);
        
        //Storing the starting position of the board in the history.
        string temp = past.convert_state(board);
        past.store_visual(temp, 0);
        
        /*Resetting max_moves if non are specified. One more than normal b/c mine
         starts one move ahead*/
        if(max_moves == -1){max_moves = 25;}
        else{max_moves+=1;}
        
        //Recursive function call
        find_solutions(board, board, past, past, sol, 1, max_moves, goals);
        
        //Printing the baord
        sol.print_1solution(board, max_moves);
    }
    // for now...  an example of how to use the board print function
    
}

// ================================================================
// ================================================================
