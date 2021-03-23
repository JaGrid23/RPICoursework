#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 11 09:59:47 2019

@author: jaredgridley
"""

grid = [[0, 0, 0, 0, 9, 0, 9, 9, 9, 0], [0, 0, 0, 0, 0, 0, 9, 9, 9, 9], [0, 0, 0, 0, 0, 0, 9, 9, 9, 9], [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], [9, 9, 9, 9, 9, 9, 9, 0, 9, 9], [9, 9, 9, 9, 9, 9, 9, 9, 9, 0], [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], [0, 9, 9, 9, 9, 9, 9, 9, 9, 9], [0, 9, 9, 9, 9, 0, 9, 9, 9, 0]]

c = grid.copy()
for i in range(len(c)):                     #Goes through the list of lists and prints out the berry field. 
    for j in range(len(c[i])):
        c[i][j] = [c[i][j], c[i][j]]

def grow_berries(grid):
    for b in range(len(grid)):
        for f in range(len(grid[b])):
            if grid[b][f][1] < 10 and grid[b][f][1] > 0:
                grid[b][f][1]+=1
                grid[b][f][0] = grid[b][f][1]
            elif grid[b][f][1] == 0:
                
                
                if grid[b+1][f][1] == 0:
                    grid[b+1][f][1] +=1
                    grid[b][f][0] == grid[b][f][1]
                if grid[b-1][f][1] == 0:
                    grid[b-1][f][1] +=1
                    grid[b][f][0] == grid[b][f][1]
                if grid[b][f+1][1] == 0:
                    grid[b][f+1][1] += 1
                    grid[b][f][0] == grid[b][f][1]
                if grid[b][f-1][1] == 0:
                    grid[b][f-1][1] +=1
                    grid[b][f][0] == grid[b][f][1]



grow_berries(c)

for i in c:                                 #Creates the string output that will be returned and printed
    for j in i:                                     #Iterates through the list of lists and adds each number to the 'out' string, in print ready form
        print('{0:>4}'.format(j[0]), end = ' ')
    print()
    
    
    
    
    
    
    
    
        def eat(bear, field):
        eaten = 0
        while eaten <30: 
            if self.row < 0 or self.row > 9 or self.column < 0 or self.column > 9:
                print('Bear at ({0},{1}) moving {2} - Left the Field'.format(self.row, self.column, self.direction))
                self.status[1] = 'gone'
                break
            elif field[self.row][self.column][0] == 'T':
                self.status[1] = 0
                field[self.row][self.column][0] = '*' #This allows the eat function to communicate with the tourist function
                break
            else:
                if field[self.row][self.column][1] !=0:
                    if eaten + field[self.row][self.column][1] <= 30:
                        eaten +=field[self.row][self.column][1]
                        field[self.row][self.column][1] = 0
                        Bear.move(self)
                    else:
                        field[self.row][self.column][1] - (30 - eaten)
                        eaten = 30
                else:
                    Bear.move(self)
                    
                    
                    
                    
                    
                    