#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 14:33:47 2019

@author: jaredgridley
The purpose of this program is to rum simulations a specificed number of times and then reporting statistics about the data.

"""

import random

size = int(input('Enter the integer grid size => '))
print(size)

p = input('Enter a probability (0.0 - 1.0) => ')
print(p)
p = float(p)

repeat = int(input('Enter the number of simulations to run => '))
print(repeat)


#This sets the random seed before any of the random functions are called. 
random.seed(10 * size + size)

def move_trainer():
    '''
    return a tuple, (direction, seen), where direction is one of 
    'N', 'E', 'S', or 'W' and seen is a random number between 
    0.0 and 1.0 that determines if a pokemon is seen.
    '''
    directions = ['N', 'E', 'S', 'W']
    movement = random.choice(directions)
    return (movement, random.random())
    
def throw_pokeball(num_false, num_true):
    '''
    num_false is the number of False entries at the start of a catch list 
    num_true is the number of True entries at the end of a catch list
    '''
    l = []                      #This and the following 2 'for' loops create the list of True and False values. 
    for i in range(num_false):
        l.append(False)
    for i in range(num_true):
        l.append(True)
    return random.choice(l)


#This initializes the number of turns per simulation. 
turns = []  #This will be used for the max/min
total_turns = 0 #This will be used for the average


#This creates the tables, starting with filling every spot with a zero.
table_as_list = []
for i in range(0, size):
    table_as_list.append([])
    for j in range(0, size):
        table_as_list[i].append(0)



if __name__ == '__main__':
    for simulation_number in range(0, repeat):
        #This sets the starting location on the grid
        trainer_location = (size//2, size//2)
        
        
        #This check the locations, calls the move_trainer function, determines if a pokeball needs to be thrown adn throws the pokeball. 
        turn = 0
        caught_pokemon = 0
        seen_pokemon = 0
        t = 1               #Starting Trues
        f = 3               #Starting Falses
        
        while True:
            movement = move_trainer()  #gets data for one movement of the trainer
            turn+=1
            
            #This series of if statements determines the movement of the trainer based on the output of move_trainer
            if movement[0] == 'N':
                trainer_location = (trainer_location[0]-1, trainer_location[1])
            elif movement[0] == 'S':
                trainer_location = (trainer_location[0]+1, trainer_location[1])
            elif movement[0] == 'E':
                trainer_location = (trainer_location[0], trainer_location[1]+1)
            elif movement[0] == 'W':
                trainer_location = (trainer_location[0], trainer_location[1]-1)
            
            #Runs through the process of checking to see if you found a pokemon and caught/missed it. 
            if movement[1] <= p:
                seen_pokemon += 1
                if throw_pokeball(f, t) == True:
                    caught_pokemon +=1
                    table_as_list[trainer_location[0]][trainer_location[1]] +=1 #If caught, it adds 1 to the place on the grid
                    t+=1
                else:
                    table_as_list[trainer_location[0]][trainer_location[1]] -=1 #if missed, it subtracts 1 from the place on the grid
            
            
            if trainer_location[0] == 0 or trainer_location[1] == 0 or trainer_location[0] == size-1 or trainer_location[1] == size-1:
                turns.append((turn, simulation_number)) #before it breaks the loop, it add the turn data to the lists to be analyzed later. 
                total_turns+=turn
                break

#This calculates the average number of turns. 
avg_num_turns = total_turns/repeat

#Calculates the max/min number of turns
max_turn = max(turns)
min_turn = min(turns)

#Calculates the data on the pokemon caught at each spot. 
data_per_spot = []
for w in table_as_list:
    for num in w:
        data_per_spot.append(num)


#This prints out all of the required data for the table. 
#This prints out the final table.
for i in table_as_list:
    print(end = '\n')
    for j in i:
        print('{0: >5}'.format(j), end = '')
        
print('\nAverage number of turns in a simulation was {0:.2f}'.format(avg_num_turns))
print('Maximum number of turns was {0} in simulation {1}'.format(max_turn[0], max_turn[1]+1))
print('Minimum number of turns was {0} in simulation {1}'.format(min_turn[0], min_turn[1]+1))
print('Best net missed pokemon versus caught pokemon is {0}'.format(max(data_per_spot)))
print('Worst net missed pokemon versus caught pokemon is {0}'.format(min(data_per_spot)))

