#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 22:05:18 2019

@author: jaredgridley
The purpose of this program is to create the grid that the pokemon user with use
to navigate. It also sets up the porbability calculations for the journey. 
"""

import random

size = int(input('Enter the integer grid size => '))
print(size)

p = input('Enter a probability (0.0 - 1.0) => ')
print(p)
p = float(p)


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

if __name__ == '__main__':
    #This sets the starting location on the grid
    trainer_location = (size//2, size//2)
    
    
    #This check the locations, calls the move_trainer function, determines if a pokeball needs to be thrown adn throws the pokeball. 
    turn = 0
    caught_pokemon = 0
    seen_pokemon = 0
    t = 1
    f = 3
    while True:
        if trainer_location[0] == 0 or trainer_location[1] == 0 or trainer_location[0] == size-1 or trainer_location[1] == size-1:          
            print('Trainer left the field at turn {0}, location {1}.\n{2} pokemon were seen, {3} of which were captured.'.format(turn, trainer_location, seen_pokemon, caught_pokemon))
            break
        
        movement = move_trainer()
        turn+=1
        if movement[0] == 'N':                  #This series of if statements determines the movement of the trainer based on the output of move_trainer
            trainer_location = (trainer_location[0]-1, trainer_location[1])
        elif movement[0] == 'S':
            trainer_location = (trainer_location[0]+1, trainer_location[1])
        elif movement[0] == 'E':
            trainer_location = (trainer_location[0], trainer_location[1]+1)
        elif movement[0] == 'W':
            trainer_location = (trainer_location[0], trainer_location[1]-1)
        

        if movement[1] <= p:            #Runs through the process of checking to see if you found a pokemon and caught/missed it. 
            print('Saw a pokemon at turn {0}, location {1}'.format(turn, trainer_location))
            seen_pokemon += 1
            if throw_pokeball(f, t) == True:
                print('Caught it!')
                caught_pokemon +=1
                t+=1
            else:
                print('Missed ...')
                
        
        
