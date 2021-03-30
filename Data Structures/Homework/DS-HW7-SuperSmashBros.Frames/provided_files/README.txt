HOMEWORK 7: SUPER SMASH BROS. FRAMES


NAME: Jared Gridley


COLLABORATORS AND OTHER RESOURCES:

cplusplus.com

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  7



ORDER NOTATION ANALYSIS:
Consider the following variables and give the complexity for both running
time AND space along with a short justification for each of the queries below.
For the commands, do not count the space occupied by the database in the space
complexity analysis.

f: The total number of fighters
m: The number of different moves
t: The highest number of moves that have the same starting frame

reading the database/populating your initial data structure:

-q (specific move): 	Time: O(log(f) + m)		Storage: f + m

-q (all): 		Time: O(log(f) + m)		Storage: f + m

-f: 			Time: O(m + t)			Storage: f + m

-s: 			Time: O(m + t + log(f))		Storage: f + m

-d: 			Time: O(m + f)			Storage: f + m

The storage complexity for my program is the same for all of the commands because
of the way I set up the data storage. I used a map to store all of the fighters 
names and their class objects. I then use this to create sets of pairs for each 
move. This way I can take in a user command and only have to access the correct 
set. When working with small data sets this can prove to be inefficient as it would 
be easier to just make the set that is asked for, with the time to create repeated 
sets mostly negligible. However, to avoid this problem I only create the move sets 
once and then worry about accessing them correctly for the given command. While this
may have a slower storage rate with smaller data sets, it would have a better rate
for large sets while maintaining the same runtime.


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)






