HOMEWORK 1: MOIRE STRINGS


NAME:  < Jared Gridley >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

cplusplus.com -> looking up how to parse command line input data and checking some other miscellaneous syntax things.
Josh Park/Lauren Lee/Cat Chu - Talked about what extra shapes we were doing, didn't talk about code though.

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  7.5 hours



EXTRA CREDIT SHAPES: (5)

DIAMOND -> This is the diamond as in the playing card, not the crystalline arrangement of carbon-12 atoms. Had a lot of trouble with even numbers, needed to add if statements to alter variables if the height was even because it wouldn't print the last row of just one "*".
./run "abcde" 5 diamond out.txt
  * 
 *a*
*bcd* 
 *e*  
  *   

./run "abcde" 8 diamond out.txt
   *   
  *a*  
 *bcd* 
*eabcd*
 *eab*
  *c*
   *


PARALLELOGRAM -> All sides are the same amount of stars, but it's essentially a slanted square
./run "::..." 6 parallelogram out.txt
******
 *::..*
  *.::.*
   *..::*
    *...:*
     *:...*
      ******

./run "::..." 9 parallelogram out.txt
*********
 *::...::*
  *...::..*
   *.::...:*
    *:...::.*
     *..::...*
      *::...::*
       *...::..*
        *.::...:*
         *********



TRAPEZOID -> I used the isosceles triangle idea and just cut off a proportional part of the top. 
./run "abcde" 11 trapezoid out.txt
          ***********
         *abcdeabcdea*
        *bcdeabcdeabcd*
       *eabcdeabcdeabcd*
      *eabcdeabcdeabcdea*
     *bcdeabcdeabcdeabcde*
    *abcdeabcdeabcdeabcdea*
   *bcdeabcdeabcdeabcdeabcd*
  *eabcdeabcdeabcdeabcdeabcd*
 *eabcdeabcdeabcdeabcdeabcdea*
*******************************

./run "abcde" 6 trapezoid out.txt
     ******
    *abcdea*
   *bcdeabcd*
  *eabcdeabcd*
 *eabcdeabcdea*
****************


HEXAGON -> two trapezoids stitched together. It may look weird for even numbers but to maintain the height I needed to make one half a row shorter than the other (for even numbers only)

./run "::..." 5 hexagon out.txt
  *****
 *::...*
*::...::*
 *...::*
  *****

./run "::..." 10 hexagon out.txt
    **********
   *::...::...*
  *::...::...::*
 *...::...::...:*
*:...::...::...::*
 *...::...::...:*
  *:...::...::.*
   *..::...::.*
    *..::...:*
     ********


PENTAGON -> This is 5 sides. Like a lot of the others, with even numbers it comes out shorter on one side because the symmetry doesn't work out perfectly. Either way, the 5 sides are preserved.

./run "::..." 10 pentagon out.txt
**********
*::...::...*
*::...::...::*
*...::...::...:*
*:...::...::...::*
*...::...::...:*
*:...::...::.*
*..::...::.*
*..::...:*
********

./run "::..." 7 pentagon out.txt
*******
*::...::*
*...::...:*
*:...::...::*
*...::...:*
*:...::.*
*******


MISC. COMMENTS TO GRADER:  
For Extra Shapes - the "run" is the executable.


