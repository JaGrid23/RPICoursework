//  Data Structures Homework 1
//
//  Created by Jared Gridley on 1/17/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//
//  This program will write a user-defined string into a specified shape to create a Moire pattern within the shape.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void square(int height, string characters, string out){
    ofstream out_file(out);
    
    // Printing top row of "*"; starts at 0 and increments until it gets to the height of the square
    for(int star=0; star<height; star++){
        out_file<<"*";
    }
    out_file<<endl;     //Formatting to go to the next line after the top row.
    
    //Printing the middle rows of "*" and characters
    int char_num = 0;                                       //This will increment through the string of characters given by the user.
    for(int column = 0; column<(height-2); column++){       //Increments until it reaches height-2 (-2 is because the top and bottom rows of all "*" are printed seperately.
        out_file<<"*";
        for(int row=0; row<(height-2); row++){              //height-2 becuase the sides of "*" are printed outside of the loop.
            if (char_num == characters.size()){     //Resets the string character to the first one if it reaches the end.
                char_num = 0;
            }
            out_file<<characters[char_num];         //Writes the nth character to the file, n = char_num
            char_num++;
        }
        out_file<<"*"<<endl;
    }
    
    //Printing the bottom row of "*"
    for(int i=0; i<height and height>1; i++){       //height>1 makes it work for height = 1
        out_file<<"*";
    }
}

void right_triangle(int height, string characters, string out){
    ofstream out_file(out);
    
    //Printing the top rows of "*" (only prints this if height = 1)
    if (height>1)
        out_file<<"*"<<endl;

    //Printing the middle rows of "*" and characters
    int char_num = 0;           //Variable for iterating throught the given string.
    int row_len = 2;            //Variable will increase after each row is printed
    
    for(int row =0; row<(height-2) and (height>0); row++){      //iterates through and prints each row except for top and bottom. (height>0 is safeguard for height = 0, 1, or 2)
        out_file<<"*";
        for(int column=0; column<(row_len-2); column++){
            if (char_num == characters.size()){                 //Resets string character when it reaches the end of string.
                char_num = 0;
            }
            out_file<<characters[char_num];                     //Writes the nth character to the file, n = char_num
            char_num++;
        }
        out_file<<"*"<<endl;
        row_len++;
    }
    
    //Printing the bottom row of "*"
    for(int i=0; i<height; i++){                        //Bottom row will be height length
        out_file<<"*";
    }
    
}

void isosceles_triangle(int height, string characters, string out){
    ofstream out_file(out);
    int total_space = (2*height)-1;                                     //This is the total space in a row (incl. "*", characters and spaces)
    int char_space = 1;                          //Initializing it at 1 and will incrememnt by 2 since it grows on each side fo the length.
    int total_whitespace = total_space - char_space;                    //This is whitespace before and after characters.
    int whitespace_before = ((total_whitespace)/2);
    int char_num = 0;
    
    //Loop interating for the height of the triangle
    for(int row=0; row<(height-1); row++){
        
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        char_space+=2;
        whitespace_before--;
        out_file<<endl;

    }
    //Prints the last row of all "*"
    for(int star = 0; star<total_space and total_space>1; star++){          //total_space>1 makes it work for height =1;
        out_file<<"*";
    }
}

void diamond(int height, string characters, string out){
    ofstream out_file(out);
    int char_space = 1;         //Initializing it to 1 and will incrememnt by 2.
    int total_whitespace = height - char_space;             //This is whitespace before and after characters.
    int whitespace_before = ((total_whitespace)/2);
    int whitespace_after = total_whitespace - whitespace_before;
    int char_num = 0;
    int top_height = (height/2);
    if(height%2 == 0){              //This perserves the height of the diamond for even numbers (was having problem where it would reach the height before it printed the last "*" row
        top_height --;
    }
    int bottom_height = (height-top_height);               //This will tell it how much to grow before shrinking.
    
    //Loop interating for TOP half of diamond
    for(int row=0; row<(top_height); row++){
        
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        char_space+=2;
        whitespace_before--;
        whitespace_after--;
        
        //Printing whitespace after the last character
        for(int space = 0; space<(whitespace_after); space++){
            out_file<<" ";
        }
        out_file<<endl;
    }
    
    //Loop interating for BOTTOM half of diamond
    for(int row=0; row<(bottom_height-1); row++){
        
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        //Resetting for the next row, one character added to each side, so one whitespace subtracted from each side.
        char_space-=2;
        whitespace_before++;
        whitespace_after++;
        out_file<<endl;
    }
    
}


void parallelogram(int height, string characters, string out){
    ofstream out_file(out);
    
    int whitespace_before = 1;   //Initialized at 1 because it is not used for the top row of all "*"
    int char_num = 0;
    
    //Printing the top row of "*", no space before
    for(int star=0; star<height; star++){
        out_file<<"*";
    }
    out_file<<endl;
    
    //Printing the characters with appropriate spacing
    for(int row=0; row<(height-1); row++){
        //Printing the space before the characters
        for(int space = 0; space<whitespace_before; space++){
            out_file<<" ";
        }
        out_file<<"*";                      //writes the star before the charaters
        for(int column = 0; column<(height-2); column++){
            //Printing the characters
            if (char_num == characters.size()){
                char_num = 0;
            }
            out_file<<characters[char_num];
            char_num++;

        }
        out_file<<"*";                      //writes the star after the charaters
        //Setting up for the next row.
        whitespace_before++;
        out_file<<endl;
    }
    //Printing the spacing for the bottom row
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //Printing the bottom row of "*"
    for(int star=0; star<height and height>1; star++){      //"and" makes it work for height = 1
        out_file<<"*";
    }
}

void trapezoid(int height, string characters, string out){
    ofstream out_file(out);
    int total_space = (height+(2*height))-1;                //This is formula for the base of the perfect trapezoid given the height.
    int char_space = height;                                //Top layer will be the same as the height, will later be incremented by 2 as the rows increase
    int total_whitespace = total_space - char_space;        //Whitespace before and after the characters.
    int whitespace_before = ((total_whitespace)/2);         //Only need to print spaces before the characters.
    int char_num = 0;
    
    //Printing the spacing for the first row of all "*"
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //setting up for the next row (which includes characters)
    whitespace_before--;
    //Printing the top row of all stars
    for (int star=0; star<char_space; star++){
        out_file<<"*";
    }
    //Setting up for the next row that will include characters
    char_space+=2;
    out_file<<endl;
    
    //Loop interating for the height (minus top and bottom rows) of the triangle
    for(int row=0; row<(height-2); row++){
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";              //Star before the characters
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){             //resets print location when reaches the end of the string.
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";                  //Star after the characters
        }
        //Getting the values ready for the next row
        char_space+=2;
        whitespace_before--;
        out_file<<endl;
    }
    //Prints the last row of all "*"
    for(int star = 0; star<(total_space-1); star++){        //total_space-1 because the incrementation at the end of the loop already takes care of part of the number of values.
        out_file<<"*";
    }
    
}

void hexagon(int height, string characters, string out){                //Essentially two trapezoids
    ofstream out_file(out);
    int total_space = (2*height)-1;                //This is formula for the base of the perfect trapezoid given the height.
    int char_space = height;                                //Top layer will be the same as the height, will later be incremented by 2 as the rows increase
    int total_whitespace = total_space - char_space;        //Whitespace before and after the characters.
    int whitespace_before = ((total_whitespace)/2);         //Only need to print spaces before the characters.
    int char_num = 0;
    int top_height = (height/2);      //Calculates when to stop increasing the trapezoids and start decreasing.
    if(height%2 == 0){              //This perserves the height of the diamond for even numbers (was having problem where it would reach the height before it printed the last "*" row
        top_height --;
    }
    int bottom_height = (height-top_height); bottom_height = (height-top_height);
    
    //Printing the spacing for the first row of all "*"
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //setting up for the next row (which includes characters)
    whitespace_before--;
    //Printing the top row of all stars
    for (int star=0; star<char_space; star++){
        out_file<<"*";
    }
    //Setting up for the next row that will include characters
    char_space+=2;
    out_file<<endl;
    
    //Loop interating for the top part of the hexagon
    for(int row=0; row<(top_height-1); row++){
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){                 //Resets the character printed out if reaches the end of the string.
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        //Getting variables ready for next row
        char_space+=2;
        whitespace_before--;
        out_file<<endl;
    }
    //Loop iterating for the bottom part of the hexagon
    for(int row=0; row<(bottom_height-1); row++){
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";                  //prints the beginning star.
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){                     //Resets character printed when it reaches the end of the string.
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";          //Printing the end star
        }
        char_space-=2;
        whitespace_before++;
        out_file<<endl;
    }
    
    //Printing the space before the bottom row.
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //Printing the stars for the bottom of the trapezoid.
    for (int star=0; star<char_space; star++){
        out_file<<"*";
    }
    
}

void pentagon(int height, string characters, string out){                //Essentially two trapezoids
    ofstream out_file(out);
    int total_space = 0;                //This is formula for the base of the perfect trapezoid given the height.
    int char_space = height;                                //Top layer will be the same as the height, will later be incremented by 2 as the rows increase
    int total_whitespace = total_space - char_space;        //Whitespace before and after the characters.
    int whitespace_before = ((total_whitespace)/2);         //Only need to print spaces before the characters.
    int char_num = 0;
    int top_height = (height/2);      //Calculates when to stop increasing the trapezoids and start decreasing.
    if(height%2 == 0){              //This perserves the height of the diamond for even numbers (was having problem where it would reach the height before it printed the last "*" row
        top_height --;
    }
    int bottom_height = (height-top_height); bottom_height = (height-top_height);
    
    //Printing the spacing for the first row of all "*"
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //setting up for the next row (which includes characters)
    whitespace_before--;
    //Printing the top row of all stars
    for (int star=0; star<char_space; star++){
        out_file<<"*";
    }
    //Setting up for the next row that will include characters
    char_space+=2;
    out_file<<endl;
    
    //Loop interating for the top part of the hexagon
    for(int row=0; row<(top_height-1); row++){
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){                 //Resets the character printed out if reaches the end of the string.
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        //Getting variables ready for next row
        char_space+=2;
        whitespace_before--;
        out_file<<endl;
    }
    //Loop iterating for the bottom part of the hexagon
    for(int row=0; row<(bottom_height-1); row++){
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";                  //prints the beginning star.
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){                     //Resets character printed when it reaches the end of the string.
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";          //Printing the end star
        }
        char_space-=2;
        whitespace_before++;
        out_file<<endl;
    }
    
    //Printing the space before the bottom row.
    for(int space = 0; space<whitespace_before; space++){
        out_file<<" ";
    }
    //Printing the stars for the bottom of the trapezoid.
    for (int star=0; star<char_space; star++){
        out_file<<"*";
    }
    
}



int main(int argc, char* argv[]){
    if(argc<5)                      //Error Check: If incorrect number of arguments are entered
    {
        cout<<"Usage: "<< argv[0]<<" <CHARACTERS> "<<"<INT> <SHAPE> <FILENAME>"<<endl;
        exit(1);
    }
    
    //Initializing the inputs to make it more readable
    int height = atoi(argv[2]);
    string characters = argv[1];
    string shape = argv[3];
    string file = argv[4];
    
    
    //Opening a stream for output to check it.
    ofstream out_file(argv[4]);
    if(!out_file.good())           //Error Check: If the output file stream can be opened
    {
        cerr<<"Can't open "<<argv[4]<<" to read."<<endl;
        exit(1);
    }
    
    //If statements to connect to correct shape.
    if(shape == "square"){
        square(height, characters, file);
    }
    else if(shape == "right_triangle"){
        right_triangle(height, characters, file);
    }
    else if(shape == "isosceles_triangle"){
        isosceles_triangle(height, characters, file);
    }
    else if(shape == "diamond"){
        diamond(height, characters, file);
    }
    else if(shape =="parallelogram"){
        parallelogram(height, characters, file);
    }
    else if(shape == "trapezoid"){
        trapezoid(height, characters, file);
    }
    else if(shape == "hexagon"){
        hexagon(height, characters, file);
    }
    else if(shape == "pentagon"){
        pentagon(height, characters, file);
    }
    else{                                   //Error statement if you enter a shape not available.
        cout<<"Shape not available. Choose from square, right_triangle, isosceles_triangle, diamond, parallelogram, trapezoid, pentagon, or hexagon.";
    }
    
    return 0;
}
