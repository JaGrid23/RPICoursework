#include <iostream>
#include <string>
#include <cassert>
#include "Board.h"

void SimpleTest(); //Some basic tests
void StudentTest(); //Write your own test cases here

int main(){
    SimpleTest();
    std::cout << "Completed all simple tests." << std::endl;

    StudentTest();
    std::cout << "Completed all student tests." << std::endl;

    return 0;
}

// Do not modify this function - a fresh copy will be used on Submitty
void SimpleTest(){
    Board b("R","Y",".");

    std::cout << "Initial board:" << std::endl << b << std::endl;
    std::cout << "Row 0 has " << b.numTokensInRow(0) << std::endl;
    std::cout << "Row 4 has " << b.numTokensInRow(4) << std::endl;
    std::cout << "Row 5 has " << b.numTokensInRow(5) << std::endl;
    std::cout << "Column 0 has " << b.numTokensInColumn(0) << std::endl;
    std::cout << "Column 3 has " << b.numTokensInColumn(3) << std::endl;
    std::cout << "Column 4 has " << b.numTokensInColumn(4) << std::endl;

    b.insert(0,true);
    std::cout << "Second handout figure" << std::endl << b << std::endl;

    b.insert(1,false);
    b.insert(2,true);
    b.insert(3,true);
    std::cout << "Third handout figure" << std::endl << b;
    std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
              << std::endl << std::endl;

    b.insert(1,true);
    b.insert(1,false);
    b.insert(1,true);
    b.insert(1,false);
    b.insert(1,true);
    std::cout << "Fourth handout figure" << std::endl << b;
    std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
              << std::endl << std::endl;

    b.insert(4,true);
    std::cout << "Fifth handout figure" << std::endl << b;
    std::cout << "Dimensions are " << b.numRows() << " X " << b.numColumns()
              << std::endl << std::endl;

    //Looks ugly if we don't make all tokens the same length, but not required
    Board b2("Puppy","Kitty","-----");
    std::string result;
    std::cout << "Starting a new board!" << std::endl;
    std::cout << "Board is now" << std::endl << b2 << std::endl;
    result = b2.insert(1,true);
    std::cout << "Board is now" << std::endl << b2 << std::endl;
    if(result == "-----"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    result = b2.insert(1,true);
    std::cout << "Board is now" << std::endl << b2 << std::endl;
    if(result == "-----"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    result = b2.insert(1,true);
    std::cout << "Board is now" << std::endl << b2 << std::endl;
    if(result == "-----"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    result = b2.insert(1,true);
    std::cout << "Board is now" << std::endl << b2 << std::endl;
    if(result == "-----"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
}

////////STUDENT CODE//////

//Write your own test cases here
void StudentTest(){
    std::string result;

    //---------- Testing Column winner ----------------------------------
    std::cout << std::endl << "Testing Column Winner: ";
    Board b3("orange", "yellow", "------");
    b3.insert(0, true);
    b3.insert(1, false);
    b3.insert(2, true);
    b3.insert(3, false);
    b3.insert(4, true);
    std::cout << std::endl << "Board after 5 plays: " << std::endl << b3 << std::endl;
    if(result == "------"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    b3.insert(1, false);
    result = b3.insert(1, false);
    std::cout << std::endl << "Board after 7 plays: " << std::endl << b3 << std::endl;
    if(result == "------"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    result = b3.insert(1, false);
    std::cout << std::endl << "Board after 8 plays: " << std::endl << b3 << std::endl;
    if(result == "------"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    //---------- Testing Row winner -------------------------------------
    /*Inserting 5 tokens to a column, then inserts the same token in the first row for 4\
        consecutive rows and checks when it declares the winner.*/
    std::cout << std::endl << "Testing Row Winner: ";
    Board b4("pepper", "cookie", "~~~~~~");
    
    b4.insert(3, true);                                         //5 tokens inserted in column
    b4.insert(3, false);
    b4.insert(3, true);
    b4.insert(3, false);
    b4.insert(3, true);
    std::cout << std::endl << "Board after 5 plays: " << std::endl << b4 << std::endl;

    b4.insert(2, true);                                         //Insert 2 more, 3 in row 0
    result = b4.insert(1, true);
    std::cout << std::endl << "Board after 7 plays: " << std::endl << b4 << std::endl;
    if(result == "~~~~~~"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    result = b4.insert(4, true);                                //Insert winning token
    std::cout << std::endl << "Board after 8 plays: " << std::endl << b4 << std::endl;
    if(result == "~~~~~~"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    
    //---------- Testing adding more that one column --------------------
    /*Places 5 tokens on the board in random spots and then place a token in column 9,
        making the board 4 columns longer that the previous insertion. Also testing to
        make sure that row winner doesn't run when there are spaces between tokens.*/
    std::cout << std::endl << "Testing Adding more than 1 Column: ";
    Board b5("...", "xxx", "___");
    b5.insert(0, true);
    b5.insert(0, false);
    b5.insert(1, false);
    b5.insert(3, false);
    result = b5.insert(4, false);                               //5 token inserted
    std::cout << std::endl << "Board after 5 plays: " << std::endl << b5 << std::endl;
    if(result == "___"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    result = b5.insert(9, false);                               //Token inserted at column 9
    std::cout << std::endl << "Board after 6 plays: " << std::endl << b5 << std::endl;
    if(result == "___"){
        std::cout << "No winner yet." << std::endl;
    }
    else{
        std::cout << "The winner is: " << result << std::endl;
    }
    
    //---------- Testing Copy Constructor -------------------------------
    std::cout << std::endl << "Testing Copy Constructor: ";
    
    Board b6("IBM", "AWS", "...");
    b6.insert(1, false);
    b6.insert(0, 0);
    b6.insert(1, true);
    b6.insert(3, false);
    b6.insert(3, false);
    b6.insert(5, true);
    
    std::cout << std::endl << "Initial Board: " << std::endl << b6 << std::endl;
    
    Board b7(b6);
    std::cout << std::endl << "New Board made from Copy Constructor " << std::endl << b7 << std::endl;
    
    
    //---------- Testing Assignment Operator ----------------------------
    std::cout << std::endl << "Testing Copy Constructor: ";
    
    Board b8("Google", "Microsoft", "Nope");
    b8 = b6;
    
    std::cout << std::endl << "Assigned IBM/AWS Board from Copy Constructor test:" << std::endl << b8 << std::endl;
    
    //---------- Testing Clear Function ---------------------------------
    std::cout << std::endl << "Testing Clear Function: ";
    
    b8.clear();
    std::cout << std::endl << "Clearing the IBM/AWS Board:" << std::endl << b8 << std::endl;
    


}

