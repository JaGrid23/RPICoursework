//Header file that houses all of the functions for the Board Class. 

#include <string>
using namespace std;

class Board{
public:
    //Constructor - pass by reference: string >= 8 bytes
    Board(const string& p1, const string& p2, const string& empty);
    //Copy Constructor
    Board(const Board &bd);
    //Assignment Operator
    Board& operator = (const Board &t);
    
    
    //Modifiers
    string insert(int column_num, bool player);           //Inserts the token and prints out the board.
    void increase_columns(int column_num);
    
    //Acessors
    int numRows() const;
    int numColumns() const;
    int numTokensInColumn(int column_num) const;
    int numTokensInRow(int row_num) const;
    string getToken(int column, int row) const;
    string getBlank() const;
    string getToken1() const;
    string getToken2() const;
    
    
    //Clear the board
    void clear();
    
    //Checks for matches
    string CheckWinners(int column_num, string player);
    
    //Destructor
    ~Board();
    
    
private:
    int row_length, column_length;
    string token1, token2, blank;
    string **grid;
    int *row_tracker, *column_tracker;
};

//Non-Member Functions
//1)Printing out the board
ostream& operator<<(ostream& out, const Board &b);

