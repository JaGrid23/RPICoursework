//  Board.cpp
//  HW3
//
//  Created by Jared Gridley on 2/8/20.
// Implementation file for the Board class. Houses all of the functions that are in the Board class. Makes up the inner workings of class functions.


//CLEAR FUNCTION - delete all of the m_data and then run the constructor again

#include "Board.h"
#include <string>
#include <iostream>
using namespace std;

//=========== Constructor for the Board class ============================================
Board::Board(const string& p1, const string& p2, const string& empty){
    token1 = p1;
    token2 = p2;
    blank = empty;
    row_length = 5;
    column_length = 4;
    
    grid = new string*[column_length]();        //Creates 4 columns of null pointers
    
    row_tracker = new int[row_length]();        //Initialized to 0
    column_tracker = new int[column_length]();  //Initialized to 0
}


//=========== Copy Constructor for the board class =======================================
Board::Board(const Board &bd){
    //-----------Copying over stack elements -----------------------------------
    token1 = bd.getToken1();
    token2 = bd.getToken2();
    blank = bd.getBlank();
    row_length = bd.numRows();
    column_length = bd.numColumns();

    //----------Copying over row_tracker data ----------------------------------
    row_tracker = new int[bd.numRows()]();              //Initialized to 0
    for(int k = 0; k<bd.numRows(); k++){
        row_tracker[k] = bd.numTokensInRow(k);
    }
    
    //----------Copying over column_tracker data -------------------------------
    column_tracker = new int[bd.numColumns()]();        //Initialized to 0
    for(int m = 0; m<bd.numColumns(); m++){
        column_tracker[m] = bd.numTokensInColumn(m);
    }
    
    //----------Copying over the grid ------------------------------------------
    grid = new string*[column_length]();
    for(int i = 0; i<column_length; i++){
        grid[i] = new string[column_tracker[i]]();
        for(int j = 0; j<column_tracker[i]; j++){
            grid[i][j] = bd.getToken(i, j);
        }
    }
}

//========== Destructor ==================================================================
Board::~Board(){
    //-----------Destroys All Data------------------------
    for(int g = 0; g<column_length; g++){
        delete[] grid[g];
    }
    delete[] grid;
    delete[] row_tracker;
    delete[] column_tracker;
    
}

//========== Clear Function - Destroy and Reset ==========================================
void Board::clear(){
    //-----------Destroys Old Data------------------------
    for(int g = 0; g<column_length; g++){
        delete[] grid[g];
    }
    delete[] grid;
    delete[] row_tracker;
    delete[] column_tracker;
    
    //-----------Resets the Board-------------------------
    column_length = 5;
    row_length = 4;
    grid = new string*[column_length]();        //Creates 4 columns of null pointers
    row_tracker = new int[row_length]();        //Initialized to 0
    column_tracker = new int[column_length]();  //Initialized to 0
}

//========== Acessor Implementations ======================================================
int Board::numRows() const{
    return row_length;
}

int Board::numColumns() const{
    return column_length;
}

int Board::numTokensInRow(int row_num) const{
    if(row_num<row_length){
        return row_tracker[row_num];
    }
    else{               //Checking for Null pointer
        return -1;
    }
}

int Board::numTokensInColumn(int column_num) const{
    if(column_num<column_length){
        return column_tracker[column_num];
    }
    else{               //Checking for Null pointer
        return -1;
    }
}

string Board::getToken(int column, int row) const{
    return grid[column][row];
}


string Board::getBlank()const{
    return blank;
}

string Board::getToken1() const{
    return token1;
}

string Board::getToken2() const{
    return token2;
}


//========== Increase Columns Function ====================================================
void Board::increase_columns(int column_num){
    //increases the number of columns if the player goes over the numColumns value
    
    int num_of_columns = column_num+1;
    
    //----------COPYING OLD VALUES TO NEW ARRAY/UPDATING TRACKER ARRAY-----------------
    string **temp_grid;
    temp_grid = new string*[num_of_columns]();  //Creates temporary array of null pointers
    
    int *temp_tracker;
    temp_tracker = new int[num_of_columns]();   //Create new tracker, size = (old_size)+1
    
    for(int i = 0; i< column_length; i++){      //Copies column to the temp_grid if not null
        if(column_tracker[i]>0){
            temp_grid[i] = grid[i];             //Assign temp grid pointer to grid pointer
            temp_tracker[i] = column_tracker[i];//Copying tracker values to the temporary one
        }
    }
    delete[] grid;                              //Deleting the old array of pointers for grid
    grid = temp_grid;                           //Assigning new grid to the grid variable.
    
    delete[] column_tracker;                    //Deleting old pointer array for tracker
    column_tracker = temp_tracker;              //Setting column_tracker to the updated tracker
    
    //----------ADJUSTING COLUMN LENGTH NUMBER-----------------------------------------
    column_length = num_of_columns;
}


//========== Check for Winners ============================================================
string Board::CheckWinners(int column_num, string player){
    int row_matches = 0;
    int column_matches = 0;
    
    //----------Checking for the rows--------------------------------------------------
    //Checks every row, if there is a blank or the opposite token, it resets the count
    for(int i = 0; i<row_length; i++){
        for(int j = 0; j<column_length; j++){
            if(column_tracker[j] <= i or grid[j][i] != player){
                row_matches = 0;
            }
            else{
                row_matches++;
            }
            if(row_matches >=4){                                //Check for 4 in row
                return player;
            }
        }
    }
    
    //----------Checking for columns---------------------------------------------------
    //Checks the top most columnar win, if one non-matching chip detected, it breaks
    if(column_tracker[column_num] >=4){
        for(int k = column_tracker[column_num]-1; k>=0; k--){    //Starting at top of column
            if(grid[column_num][k] ==player){
                column_matches += 1;
                if(column_matches>=4){                          //Check for 4 in a row
                    return player;
                }
            }
            else{
                break;
            }
        }
    }
    
    return blank;                   //If no winners, return the blank space string
}



//========== Insert A Token Function ====================================================
string Board::insert(int column_num, bool player){
    //----------Check if the number of columns needs to be increased---------------
    if((column_num+1)>column_length){
        increase_columns(column_num);
    }

    //----------Check if number of rows needs to be increased----------------------
    if((column_tracker[column_num] + 1) > row_length){
        row_length+=1;           //Adds one to the length value
        
        //------Copy the Row_tracker values to one that has one more--------------
        int *temp_tracker;
        temp_tracker = new int[row_length]();       //Create Temporary tracker
        
        for(int l = 0; l< (row_length-1); l++){
            temp_tracker[l] = row_tracker[l];
        }
        delete[] row_tracker;                       //Delete old tracker
        row_tracker = temp_tracker;                 //Assign tracker ptr to new tracker
    }
    
    //----------Creating spot for the new token----------------------------------------
    if(grid[column_num] == nullptr){
        grid[column_num] = new string[1];   //Adding an array if pointer is null
    }
    else{
        
        //Adding space to top of column for new value:
        int new_ColumnLength = column_tracker[column_num]+1;
        
        string* temp_column;
        temp_column = new string[new_ColumnLength]();       //Create new column, all 0's
        
        for(int k = 0; k< column_tracker[column_num]; k++){
            temp_column[k] = grid[column_num][k];           //Copying column values
        }
        delete[] grid[column_num];                          //Deleting old grid column
        grid[column_num] = temp_column;                     //Assigning grid column to the new column
    }
    
    //----------Adjusting the trackers-------------------------------------------------
    row_tracker[column_tracker[column_num]]+=1;     //Adds 1 to row counter token was inserted at.
    column_tracker[column_num] +=1;                 //Adds 1 to column counter token was inserted at.
    
    //----------Inserting the token into the place-------------------------------------
    if(player == true){
        grid[column_num][column_tracker[column_num]-1] = token1;    //Inserting token
        return CheckWinners(column_num, token1);                    //Checking for winners
    
    }
    else{
        grid[column_num][column_tracker[column_num]-1] = token2;    //Inserting token
        return CheckWinners(column_num, token2);                    //Checking for winners
    }

}


//========== Printing out the board with the operator << ================================
ostream& operator<<(ostream& out, const Board &b){
    for(int i = b.numRows()-1; i>=0; i--){           //Iterates through every grid spot
        for(int j = 0; j<b.numColumns(); j++){
            if(b.numTokensInColumn(j) < i+1){        //No Token present --> prints blank str
                out<< b.getBlank();
            }
            else{                                    //Token present --> prints token
                out<< b.getToken(j, i);
            }
            if(j != b.numColumns()-1){               //Getting the spacing right
                out<<" ";
            }
        }
        out<< endl;
    }
    return out;
}

                
//========== Assignment Operator ========================================================
Board& Board::operator = (const Board& t){
    //----------Deleting all of the old data-------------------------
    for(int g = 0; g<column_length; g++){
        delete[] grid[g];
    }
    delete[] grid;
    delete[] row_tracker;
    delete[] column_tracker;
    
    //----------Copying over the stack data -------------------------
    token1 = t.getToken1();
    token2 = t.getToken2();
    blank = t.getBlank();
    row_length = t.numRows();
    column_length = t.numColumns();
    
    //----------Copying over row_tracker data -----------------------
    row_tracker = new int[t.numRows()]();           //Initialized to 0
    for(int k = 0; k<t.numRows(); k++){             //Copies Everything over
        row_tracker[k] = t.numTokensInRow(k);
    }
    
    //----------Copying over column_tracker data --------------------
    column_tracker = new int[t.numColumns()]();     //Initialized to 0
    for(int m = 0; m<t.numColumns(); m++){          //Copies everything over
        column_tracker[m] = t.numTokensInColumn(m);
    }
    //----------Copying over the grid -------------------------------
    grid = new string*[column_length]();            //Creates new array
    for(int i = 0; i<column_length; i++){           //Copies everythong over
        grid[i] = new string[column_tracker[i]]();
        for(int j = 0; j<column_tracker[i]; j++){
            grid[i][j] = t.getToken(i, j);
        }
    }
    return *this;
}

