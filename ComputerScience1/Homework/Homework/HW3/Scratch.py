#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 16 14:03:09 2019

@author: jaredgridley
The purpose of this part is to solve the sudoku board with out code

"""

import lab06_util

filename = input('Enter a filename => ')

file_list = lab06_util.read_sudoku(filename)
print(file_list)

#print(len(bd)) Height
#print(len(bd[0])) Length

def ok_to_add(row, column, c, bd):
    
    #may need to define our add functions here if they don't work
    if c == '.':
        return 'nope'
    
    elif (int(c)-1) < 9 and row < 9 and column < 9: #Verifying that the value is valid
        
        for i in bd[row]: #Checking the rows for repeats. 
            if str(c) == i:
                row_add = False
                break
            else:
                row_add = True
        j = 0 #Checking the columns and for the value
        while j < 9:
            if str(c) == bd[j][column]: #Compares the value to the already placed value
                column_add = False
                break
            else:
                column_add = True
            j += 1
        
        
        #Checks for the box
        start_check = ((row // 3) * 3, (column // 3) * 3)
        start_row = start_check[0]
        start_column = start_check[1]
        i = 0
        j= 0
        while i < 4:
            while j < 4:
                if bd[start_row][start_column] == c:
                    box_add = False
                    break
                else:
                    box_add = True
                start_column += 1
                j += 1
            start_row +=1 
            i+=1
            
            
            
        if column_add == False or row_add == False or box_add == False:  #Final Analysis of the if the value can be placed
            return "nope"
            
        else:
            return 'yep'


            
    else:
        return 'Invalid values, max value is 9'



def verify_board(file_list):
    
    for value in file_list:  #checks for dots
        for string in value:
            if string  == '.':
                return ('Not Finished')
            
    for value in file_list:
        for strng in value:
            if ok_to_add(file_list.index(value), value.index(strng), strng, file_list) == 'nope':
                completed = False
                break
            else:
                completed = True
    if completed == False:
        return 'Not Finished'
    else:
        return 'Finished'
    
    
    

while True:
    if verify_board(file_list) == 'Not Finished':
        user_number = int(input('Enter a number to try => '))
        user_placement_row = int(input('Enter the row you want to try => '))
        user_placement_column = int(input('Enter the column you want to try => '))
    

        if ok_to_add(user_placement_row - 1, user_placement_column - 1, user_number, file_list) == 'yep':
            file_list[user_placement_row - 1][user_placement_column -1] = str(user_number)
    
        #Prints out the new board
            for i in range(0, len(file_list)):  #prints the board
                if i%3 == 0:     #Uses the repeat number to split horizontally
                    print(25 * '-')
                print('| ', end = '')
        
                for j in range(0, len(file_list[i])):
                    if j % 3 ==0 and j != 0:     #Uses j to find where to split vertically
                        print('|', end = ' ')  
                    print(file_list[i][j], end = ' ') #Prints the value at inex i,j
                print('|')
            print('-' *25)


        else:
            print('That number does not work')  
    else:
        print('Finished')



    
    
