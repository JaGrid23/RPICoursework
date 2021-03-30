HOMEWORK 4: DEBUGGING & GROCERY LISTS

NAME:  Jared Gridley


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT PART 1:  6
ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT PART 2:  11


COLLABORATORS AND OTHER RESOURCES:

Davis Piercy
Lauren Lee
Catherine Chu
Josh Park


Remember: All finding and fixing bugs for this assignment must be done
on your own, as described in "Academic Integrity for Homework"
handout.  You may not discuss the bugs in this assignment with other
students in the course.



PART 2 ORDER NOTATION:
For each request/command,

i = # of different ingredients in the kitchen
u = maximum units of a single ingredient in the kitchen
r = # of different recipes
k = maximum # of different ingredients in a single recipe
v = maximum units of single ingredient in a single recipe
a = maximum # of different ingredients added with a single ’a’ command 
w = maximum units of a single ingredient added with a single ’a’ command


command 'r' / add a recipe: O(r + k^3)

command 'a' / add ingredients to the kitchen: O(a * i)

command 'p' / print a recipe: O(r * k^3)

command 'm' / make a recipe: O(r * i * k^2)

command 'k' / print the contents of the kitchen: O(i * ilog(i))


MISC. COMMENTS TO GRADER:
Optional, please be concise!
