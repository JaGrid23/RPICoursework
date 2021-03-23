"""
Created on Tue Dec  3 19:39:45 2019

@author: jaredgridley
This is the BerryField Module.
Contains all of the class functions for the BerryField
"""


class BerryField(object):
    def __init__(self, grid):
        '''
        Initializes the grid of berry values from a list of lists
        self.grid is a list of lists with each spot on the grid as a pair of 
        [DISPLAY, BERRY VALUE]
        '''
        self.grid = grid                #Initializes the grid
        
        
        for i in range(len(self.grid)):             #Sets up the format to keep track of values and display (See next comment for pair organization)       
            for j in range(len(self.grid[i])):
                self.grid[i][j] = [self.grid[i][j], self.grid[i][j]]        #Creates a pair of values for each spot in the format: [what is printed, number of berries]
        
        
        
    def __str__(self):        
        #This calculates the total number of berries in the field with the bears and tourists          
        total = 0
        for i in self.grid:
            for j in i:
                total += j[1]                               #j[1] is referring to the data at each spot that holds the number of berries there
        out = 'Field has {0} berries.\n'.format(total)
                
        #Creates a string output that includes where the bears, tourists, and both are also gives the number of berries if no bears or tourists present.
        for i in self.grid:                                 #Creates the string output that will be returned and printed
            for j in i:                                     #Iterates through the list of lists and adds each number to the 'out' string, in print ready form
                out = out + ('{0:>4}'.format(j[0]))
            out = out + '\n'                                #Seperates the rows. 
        
        return out                                          #At this point, out is one long string that is formatted to display the total berries and the grid.  

    def grow_berries(self):
        '''
        This iterates through the list and for every berry value that is between
        1 and 9, it will add one more berry to its value spot.
        Does not return anything, alters the grid in the BerryField class.
        '''
        for b in range(len(self.grid)):
            for f in range(len(self.grid[b])):
                if self.grid[b][f][1] < 10 and self.grid[b][f][1] > 0:  #if Berry Value is between 1 and 9
                    self.grid[b][f][1]+=1                               #Adds one berry to berry value
                    
                    
    def spread_berries(self):
        '''
        This will spread berries by looking at all of the points with a zero value 
        and check to see if any of the surrounding squares have a berry value of 
        10. If so it willl add one berry. 
        Does not return anything, alters the grid in BerryField class
        '''
        for r in range(len(self.grid)):
            for c in range(len(self.grid[r])):
                if self.grid[r][c][1] == 0:             #Checks all 8 positions to see of any of them are 10
                    if self.grid[min(r+1, len(self.grid)-1)][c][1] ==10 or \
                    self.grid[max(r-1, 0)][c][1] == 10 or \
                    self.grid[r][min(c+1, len(self.grid)-1)][1] == 10 or \
                    self.grid[r][max(c-1, 0)][1] == 10 or \
                    self.grid[min(r+1, len(self.grid)-1)][min(c+1, len(self.grid)-1)][1] == 10 or \
                    self.grid[min(r+1, len(self.grid)-1)][max(c-1, 0)][1] == 10 or \
                    self.grid[max(r-1, 0)][min(c+1, len(self.grid)-1)][1] == 10 or \
                    self.grid[max(r-1, 0)][max(c-1, 0)][1] == 10:
                        self.grid[r][c][1] = 1          #Adds one to the berry value if one of surrounding berry values is 10

    def reset(self):
        '''
        This function resets the field after the bears have been moved and the 
        tourists have been checked. It sets the display value to the berry value.
        Active bears and tourists will be added after this. This essentially cleans the grid.
        Does not return anything, alters the grid in the berry class.
        '''
        for b in range(len(self.grid)):
            for f in range(len(self.grid[b])):
                self.grid[b][f][0] = self.grid[b][f][1]         #Sets Display value equal to berry Value, Bears and tourists will be added on later