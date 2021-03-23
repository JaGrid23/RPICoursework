"""
Created on Wed Dec 11 10:21:05 2019
@author: jaredgridley

The purpose of this program is to use the created modules (Bear, Tourist, and BerryField) to print the inital field 
"""
import json
from BerryField import *   #Importing all of my modules
from Bear import *
from Tourist import *


def add_object(letter, x, y):                   #This function currently  operates on the assumption that Bears will be added to the field before tourists, which for this part is fine, if I have to change it in a later part I'll do it then. 
    if field.grid[x][y][0] != 'B':
        field.grid[x][y][0] = letter            #Replaces the berry that will be printed with the Letter            
    else:                                       #Checks to see if there is a bear there, if so then it places the X
        field.grid[x][y][0] = 'X'

if __name__ == '__main__':
    #This gets the user input and opens the file
    f_input = input('Enter the json file name for the simulation => ')
    print(f_input, end = '\n\n')
    f = open(f_input)                #Opens the JSON file
    data = json.loads(f.read())                         #Reads JSON file
    
        
    #This creates the Berry Field object
    field = BerryField(data["berry_field"])
    
        
    
    #This creates all of the Bear Objects and places them onto the berry field. 
    active_bears = []           #This is how I am keeping track of my bear objects
    for bear in data["active_bears"]:
        b = Bear(bear[0], bear[1], bear[2])             #Makes an object for the list that represents the bear
        add_object('B', b.row, b.column)                #Calls the function to add the 'B' to the berry field.
        active_bears.append(b)                          #Adds the bear object to the list of active_bears
    
    
    active_tourists = []        #This is keeping track of my tourist objects
    for tourist in data["active_tourists"]:
        t = Tourist(tourist[0], tourist[1])             #Creates tourist objects
        add_object('T', t.row, t.column)                #Adds the T to the berry field
        active_tourists.append(t)                       #Adds to my active_tourist list
    
    
    #PRINT STATEMENTS
    print(field)
    
    print("Active Bears:")
    for bear in active_bears:           #Prints each bear statement for bears in the object list
        print(bear)
    
    print()
    
    print('Active Tourists:')
    for tourist in active_tourists:     #Prints each tourist statement for tourists in object list
        print(tourist)
