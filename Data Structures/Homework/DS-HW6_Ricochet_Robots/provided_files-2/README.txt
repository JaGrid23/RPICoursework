HOMEWORK 6: RICOCHET ROBOTS RECURSION


NAME:  Jared Gridley



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Catherine Chu
Lauren Lee
Davis Piercy

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  32



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)

i & j = dimensions of the board
    r = number of robots on the board
    g = number of goals
    w = number of interior walls
    m = maximum total number of moves allowed


O(n)   ->    m * (r ^ (g*r + r))

The order notation for my algorithm is largely dependent on the number of robots.
In determining the goal, I iterate through the goals and check each robot to see 
if it matches with the goal. I then try to recurse with new boards. First, I try
and move each robot in each direction. I then store that board in the history 
(hence the + (4)r). This is to reduce my run time by building the history of boards
quicker. That way if a board later down the chain matches, it will know that 
there is a faster way to the solution as that state of the board was already reached 
with a lower number of moves. I then recurse through each of these "unique" boards.
This recursion will keep going until it reaches m recursions.




SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
Correctness & approximate wall clock running time for various command
line arguments.

Clock times for correct outputs:
Puzzle 1, visualize A, max_moves = 11	-> 0m50.693s
Puzzle 1, visualize A, max_moves = 15	-> 5m11.160s
Puzzle 1, one_solution			-> 0m0.123s
Puzzle 1, one_solution, max_moves = 10	-> 0m0.029s
Puzzle 1, all_solutions			-> 0m14.595s
Puzzle 1, all_solutions, max_moves = 10 -> 0m5.351s
Puzzle 4, visualize A			-> 0m0.004s
Puzzle 6, visualize A			-> 0m1.153s


When a max_moves is not specified, the run time for the visualize can be upwards of 10 minutes. According to a research paper by a researcher at Eberhard Karls University of Tübingen, the max moves to reach any goal is 24, so it would make sense that the max possible moves to reach a goal at any spot would also be 24. Even with this limitation, the program still takes upwards of 10 minutes. However, this is largely dependent on the number of robots, as seen in "Puzzle 4, visualize A" and "Puzzle 6, visualize A", the run time is significantly lower as they have less than 3 robots. 



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


