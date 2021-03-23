"""
Created on Tue Dec  3 19:39:45 2019

@author: jaredgridley
This is the Bear Module.
Contains all of the functions for the Bear Module
"""
from BerryField import *

class Bear(object):
    def __init__(self, row, column, direction):
        self.row = row
        self.column = column
        self.direction = direction
        self.status = [0, 'awake']      #[number of turns asleep, awake/asleep/gone]
        
        
    def __str__(self):
        if self.status[1] == 'asleep' and self.status[0] != 2:
            return 'Bear at ({0},{1}) moving {2} - Asleep for {3} more turns'.format(self.row, self.column, self.direction, (2 - self.status[0]))
        else:
            return 'Bear at ({0},{1}) moving {2}'.format(self.row, self.column, self.direction)
    
    def move(self): 
        '''
        This moves the bear in its cardinal direction 
        Does not return anything, alters the Bear's row and column value to 
        then alter its position
        '''
        if self.direction == 'N':
            self.row -=1
        elif self.direction == 'NE':
            self.column +=1
            self.row -=1
        elif self.direction == 'E':
            self.column +=1
        elif self.direction == 'SE':
            self.row +=1
            self.column += 1
        elif self.direction == 'S':
            self.row +=1 
        elif self.direction == 'SW':
            self.row += 1
            self.column -= 1
        elif self.direction == 'W':
            self.column -= 1
        elif self.direction == 'NW':
            self.row -=1
            self.column -= 1
    




    def eat(self, field):
        '''
        This is how the bear moves to eat berries
        Does not return anything, alters the bear's status and position. Does 
        contain print statements for when the Bear leaves the field. 
        '''
        if self.status[1] == 'awake':           #Checks to see if the bear is awake
            eaten = 0
            while eaten <30 and self.status[1] == 'awake':      #
                if self.row < 0 or self.row >= len(field.grid) or self.column < 0 or self.column >= len(field.grid): #Checks to see if it goes off the page
                    print('Bear at ({0},{1}) moving {2} - Left the Field'.format(self.row, self.column, self.direction)) #Prints that is left the page
                    self.status[1] = 'gone'     #Changes status to later remove it from the active_list
                elif field.grid[self.row][self.column][0] == 'T' or field.grid[self.row][self.column][0] == 'X': #Checks to see if it runs into tourist
                    field.grid[self.row][self.column][0] = '*'      #Sets it to the * so that in the tourist class, the tourist can be set to 'gone' and removed from active_list
                    self.status = [0, 'asleep']                     #Sets the first turn of the bears sleep cycle
                else:               #Eat the berries on thier spot and then move
                    if field.grid[self.row][self.column][1]!=0:                 #if there are berries at the current spot:
                        if eaten + field.grid[self.row][self.column][1] <= 30:  #And the bear can eat all of the berries without going over 30
                            eaten += field.grid[self.row][self.column][1]           #adds present berries to eaten
                            field.grid[self.row][self.column][1] = 0                #changes the Berry Value ot zero
                            if eaten < 30:                                          #If it's total eaten is less than 30:
                                Bear.move(self)                                         #the bear will move again
                        else:
                            field.grid[self.row][self.column][1] -= (30 - eaten) #otherwise the bear will eat all of the berries that it can to reach 30 and subtract that number from the Berry Value
                            eaten = 30
                    else: #if there are no berries at teh current spot
                        Bear.move(self)
        elif self.status[1] == 'asleep':        #Checks to see if the bear is asleep
            Bear.sleep(self, field)                 #If so calls the sleep function
                        

        
                
    def sleep(self, field):
        '''
        This is the sleep function, it decides what to do with the bear based on 
        what it's sleep status is. 
        Does not return anything, alters status and calls eat when appropriate
        '''
        if self.status[0]< 2:               #if the bear has slept for less than 2 turns
            self.status[0] += 1                 #Adds on turn to the status
        elif self.status[0] == 2:           #If the bear is at it's last day 
            self.status = [0, 'awake']          #Change the status
            Bear.eat(self, field)               #Call the eat function, with the updated status it will move again. 
            
                
                
                
                