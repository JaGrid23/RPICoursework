"""
Created on Wed Dec 11 15:01:52 2019

@author: jaredgridley
The purpose of this program is building on the second part of the homework
This will print out the state of the simulation every 5 turns until the end confition is met 
(This includes growing the berries, moving the bears and checking on the tourists and then printing out the information for each turn)
"""

import json
from BerryField import *   #Importing all of my modules
from Bear import *
from Tourist import *


def add_object(letter, x, y):                   #This function currently  operates on the assumption that Bears will be added to the field before tourists, which for this part is fine, if I have to change it in a later part I'll do it then. 
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

def count_berries(field):
    '''
    This function serves to count the total number of berries in the field at any given
    time.
    Returns the total amount of berries
    '''
    total = 0
    for i in field.grid:
        for j in i:             #iterates thorught the list
            total += j[1]       #Adds Berry Value to the total
    return total
    
    
    

if __name__ == '__main__':
    #This gets the user input and opens the file
    f_input = input('Enter the json file name for the simulation => ')
    print(f_input, end = '\n\n')
    f = open(f_input)                #Opens the JSON file
    data = json.loads(f.read())      #Reads JSON file
    
        
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
    
    reserve_bears = []          #This stores the reserve_bears to be called on later
    for bear in data['reserve_bears']:
        b = Bear(bear[0], bear[1], bear[2])             #Creates the bear object
        reserve_bears.append(b)                         #Adds it to the end of the reserve bears list
    
    reserve_tourists = []       #This stores the reserve_tourists to be called on later
    for tourist in data['reserve_tourists']:
        t = Tourist(tourist[0], tourist[1])             #Creates a tourist object
        reserve_tourists.append(t)                      #Adds it to the end of the reserve tourist list
    
    
    #=============PRINT STATEMENTS FOR INITIAL CONDITION======================
    print('Starting Configuration')
    print(field)

    print("Active Bears:")
    for bear in active_bears:           #Prints each bear statement for bears in the object list
        print(bear)
    
    print()
    
    print('Active Tourists:')
    for tourist in active_tourists:     #Prints each tourist statement for tourists in object list
        print(tourist)
    
    print()


    #===========PRINTING THE TURN UNTIL END ==================================
    
    turn = 1

    while True:
        print('Turn: {0}'.format(turn))
        field.grow_berries()
        field.spread_berries()
            
        for bear in active_bears:
                bear.eat(field)
        
        active_bears = bear_reset(active_bears)
        
        for tourist in active_tourists:
            tourist.check(field, active_bears)
                
        active_tourists = tourist_reset(active_tourists)
        
        if len(reserve_bears) > 0 and count_berries(field) >= 500:
            active_bears.append(reserve_bears.pop(0))
            print('Bear at ({0},{1}) moving {2} - Entered the Field'.format(active_bears[-1].row, active_bears[-1].column, active_bears[-1].direction))
        
        if len(reserve_tourists) > 0 and len(active_bears)> 0:
            active_tourists.append(reserve_tourists.pop(0))
            print('Tourist at ({0},{1}), {2} turns without seeing a bear. - Entered the Field'.format(active_tourists[-1].row, active_tourists[-1].column, active_tourists[-1].turn_not_seen_bear))
        
        field.reset()
        
        for b in active_bears:
            add_object('B', b.row, b.column)
        
        for t in active_tourists:
            add_object('T', t.row, t.column) 
        

        if turn % 5 == 0:
            print(field)
        
            print("Active Bears:")
            for bear in active_bears:           #Prints each bear statement for bears in the object list
                print(bear)
            
            print()     #Getting the right spacing
            
            print('Active Tourists:')
            for tourist in active_tourists:     #Prints each tourist statement for tourists in object list
                print(tourist)
            
              
        turn+=1
        
        if (len(active_bears) == 0 and len(reserve_bears) == 0) or (len(active_bears) == 0 and count_berries(field) == 0):
            print()         #Getting the spacing right
            break
        else:
            print('\n')     #Getting the spacing right
    
    print(field)
        
    print("Active Bears:")
    for bear in active_bears:           #Prints each bear statement for bears in the object list
        print(bear)
    
    print()             #Getting the right spacing
    
    print('Active Tourists:')
    for tourist in active_tourists:     #Prints each tourist statement for tourists in object list
        print(tourist)
    
    
    
    
    
    
    
    
    
    
    
