"""
Created on Wed Dec 11 15:01:52 2019

@author: jaredgridley
The purpose of this program is building on the first part of the homework
This will print out the state of the simulation as it runs through 5 simulations 
(This includes growing the berries, moving the bears and checking on the tourists and then printing it out.)
"""

import json
from BerryField import *   #Importing all of my modules
from Bear import *
from Tourist import *


def add_object(letter, x, y):
    '''
    This function will add the identifiers to the display portion of each spot on
    the field for the object that is passed through the function
    '''
    if field.grid[x][y][0] != 'B':
        field.grid[x][y][0] = letter            #Replaces the berry that will be printed with the Letter            
    else:                                       #Checks to see if there is a bear there, if so then it places the X
        field.grid[x][y][0] = 'X'
    
def bear_reset(l):
    '''
    This updates the active_bears list so that it only contains the the bears whose
    status does not have 'gone' as the second part of its list. 
    Returns the updated list to be assigned to the active_bears list.
    '''
    b=[]
    for bear in l:
        if bear.status[1] != 'gone':        #if status not equal to 'gone', then it is still active
            b.append(bear)
    return b

def tourist_reset(l):
    '''
    This updates the active_tourists list after all of the tourist movements 
    have completed. It resets the active_tourist list so that it is back at only 
    the active tourists. An active tourist is one whose status is set to "present"
    Returns the updated list to be assigned to the active_tourist list.
    '''
    t = []
    for tourist in l:
        if tourist.status != 'gone':        #If status not equal to 'gone', then it is stiall active
            t.append(tourist)
    return t
    

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
    
    
    
    #=============PRINT STATEMENTS FOR INITIAL CONDITION======================
    print('Starting Configuration')
    #Prints the starting field
    print(field)
    #Prints the statement for each Active Bear (Initial condition)
    print("Active Bears:")
    for bear in active_bears:           #Prints each bear statement for bears in the object list
        print(bear)
    
    print()             #Spacing
    
    #Prints the statement for each Active Tourist (initial condition)
    print('Active Tourists:')
    for tourist in active_tourists:     #Prints each tourist statement for tourists in object list
        print(tourist) 
    
    print()             #Spacing
    
    #===========PRINTING THE 5 TURNS =========================================
    turn = 1

    while turn <= 5:
        print('Turn: {0}'.format(turn))
        #Grows the berry field and spread the berries
        field.grow_berries()
        field.spread_berries()
        #Moves each bear and updates the active_bears list
        for bear in active_bears:
                bear.eat(field)
        active_bears = bear_reset(active_bears)
        #Checks each tourists and updates the active tourist list. 
        for tourist in active_tourists:
            tourist.check(field, active_bears)
        active_tourists = tourist_reset(active_tourists)
        #Updates the field to the number pairs to be displayed
        field.reset()
        #Adds All of the active bears to the display part of the field
        for b in active_bears:
            add_object('B', b.row, b.column)
        #Adds all of the active tourists to the display part of the field.
        for t in active_tourists:
            add_object('T', t.row, t.column) 
        #Prints the updated display part of the field, from string function in field class
        print(field)
        #Prints all of the active bears and all of thier associated data
        print("Active Bears:")
        for bear in active_bears:           #Prints each bear statement for all of the active bears 
            print(bear)
        
        print()             #This is to get the spacing right
        
        #Prints all of the active tourists and all of thier associated data
        print('Active Tourists:')
        for tourist in active_tourists:     #Prints each tourist statement for all the active tourists
            print(tourist)
        
        if turn == 5:                   #This will make sure that the spacing is correct for whenever it is printed out, that way I can get the extra point
            print()  
        else:
            print('\n')
            
            
        turn+=1

    
    
    
    
    
    
    
    
    
    
    
