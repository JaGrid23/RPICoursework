HOMEWORK 3: CONNECT FOUR


NAME:  Jared Gridley


COLLABORATORS AND OTHER RESOURCES:
cplusplus.com/cppreference.com/Stackoverflow.com
Lauren Lee
Catherine Chu
Joshua Park


Remember: Your implementation for this assignment must be done on your
own, as described in the "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  17


ORDER NOTATION:
For each of the functions below, write the order notation O().
Write each answer in terms of m = the number of rows and n = the
number of columns.  You should assume that calling new [] or delete []
on an array will take time proportional to the number of elements in
the array.

insert (excluding checking for connected four) --> O(m + n)

insert (including checking for connected four) --> O(m + n + mn)

numTokensInColumn --> O(1)

numTokensInRow --> O(1)

numColumns --> O(1)

numRows --> O(1)

print --> O(mn)

clear --> O(m + n)


TESTING & DEBUGGING STRATEGY: 
Discuss your strategy for testing & debugging your program.  

For Debugging I used mainly used lldb and drmemory. When it cam to segmentation faults, I would set breakpoints around the major chucks of my code and then see when it error. From there, I would make breakpoints within the section with the error to find the line where the segmentation fault was occurring. Then I made a diagram of what the error part of code was doing and used that to find where the error was occurring in the program logic. For example, when checking the row for a winner, I had an error where it didn't reset the count if the space was blank, so I made a diagram and ran through it like my program would and printed out any changing variable to make sure the data was correct and found that it was a problem with my if statement logic. 

To test for the corner cases, I created test cases for each case. For example, when adding the columns if they inserted a token at a spot not on the board yet, I wrote my function to be dependent on the column number they want to insert at, so that it will create how ever many new columns to insert at that column. As opposed to incrementing my 1 whenever they went over the size of the board. 


MISC. COMMENTS TO GRADER:  
column_tracker/row_tracker keeps track of how many elements in the rows(horizontal)/column(vertical)
"grid" ~synonymous to m_data


