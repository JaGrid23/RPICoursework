void reachability(Board original, Board move_board, History& past, v_vec& visual, char robot, int move, int max_move){
    static std::string directions[4] = {"N", "E", "S", "W"};

    if(move > max_move && max_move != -1){ return; }      //Base Case: Move limitation

    //Trying to move every robot in every possible direction.
    for(int bot = 0; bot<original.numRobots(); bot++){
        for(int direction = 0; direction < 4; direction++){
    
            move_board = original;
            move_board.moveRobot(bot, directions[direction]);
            
            if(original.getRobot(bot) == robot){
                Position pos = original.getRobotPosition(bot);
                v_vec::iterator v_itr = visual.find(pos.row-1);
                if(visual[pos.row-1][pos.col-1] == -1 || (v_itr->second)[pos.col-1] > move){
                    (v_itr->second)[pos.col-1] = move;
                }
            }
            
            string this_state = past.convert_state(move_board);
            if(!past.check_similarity(this_state, move)){  //Base Case: Board repeating
                //Converting and storing the current state of the board.
                past.store_state(this_state, move);
                
                int temp_move = move+1;
                reachability(move_board, move_board, past, visual, robot, temp_move, max_move);
            }
        }
    }
}

//This works with max move, without max_moves it takes forever

