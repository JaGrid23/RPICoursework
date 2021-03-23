"""
Created on Tue Dec  3 19:39:45 2019

@author: jaredgridley
This is the Tourist Module.
"""


class Tourist(object):
    def __init__(self, row, column):
        self.row = row                  #Initializing row
        self.column = column            #Initializing column
        self.turn_not_seen_bear = 0
        self.status = 'present'
        
    def __str__(self):
        return 'Tourist at ({0},{1}), {2} turns without seeing a bear.'.format(self.row, self.column, self.turn_not_seen_bear)
    
    def check(self, field, active_bears):
        '''
        This is the function to check on the tourists. It will determine if they
        flee our of fear, are eaten by a bear or leave out of boredom. 
        Does not return anythign but does contain print statments for when they
        leave the field.
        '''
        bears_in_sight = 0
        for bear in active_bears:           #Checks the distance each bear is away from the tourist    
            if ((bear.row-self.row)**2 + (bear.column-self.column)**2)**(0.5) <= 4.0:
                bears_in_sight +=1          #If a bear is too close then it will add it to the Bears_in_sight value
        
        if field.grid[self.row][self.column][0] == '*' or field.grid[self.row][self.column][0] == 'X':      #Checks if a tourist was eaten by a bear (from the '*' placed by Bear's eat function, or 'X' from initial condition.)
            print('Tourist at ({0},{1}), {2} turns without seeing a bear. - Left the Field'.format(self.row, self.column, self.turn_not_seen_bear))
            self.status = 'gone'        #Changes the status so that it will be taken out of the active bears list. 
        else:       #If the tourist was not eaten by a bear
            if bears_in_sight == 0 and self.turn_not_seen_bear !=2: #If they don't see any bears and it hasn't been 3 turns yeat
                self.turn_not_seen_bear += 1        #Add one to the turns without seeing a bear
            elif bears_in_sight == 0 and self.turn_not_seen_bear ==2:   #If there are no bears in sight and this is their 3rd turn
                self.turn_not_seen_bear += 1            #Adds one 
                self.status = 'gone'                    #Changes status so that it is removed from the active_tourists list
                print('Tourist at ({0},{1}), {2} turns without seeing a bear. - Left the Field'.format(self.row, self.column, self.turn_not_seen_bear)) #Print statement for tourist leaving
            elif bears_in_sight >= 3:   #If there are more than 3 bears in sight and the tourist gets frightened:
                self.status = 'gone'        #Change the status so that it is removed from active_tourist list.
                print('Tourist at ({0},{1}), {2} turns without seeing a bear. - Left the Field'.format(self.row, self.column, self.turn_not_seen_bear)) #Print for tourist leaving
            else:   #If the tourist did see a bear but not enought of them to scare them away
                self.turn_not_seen_bear = 0     #reset the turns without seeing a bear.
    
    
    