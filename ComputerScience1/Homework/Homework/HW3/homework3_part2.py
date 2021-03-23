#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 20:03:23 2019

@author: jaredgridley
The purpose of this program is to create a simulation of pikachu running into other
pokemon and battling them in a virtual adventure.
"""

turns = int(input("How many turns? => "))
print(turns)

name = input('What is the name of your pikachu? => ')
print(name)

often = int(input('How often do we see a Pokemon (turns)? => '))
print(often)


def move_pokemon(coordinates, direction, steps):
    if direction.lower == 'n':
        pikachu_position = (coordinates[0], coordinates[1]+steps)
        return pikachu_position
    elif direction.lower == 's':
        pikachu_position = (coordinates[0], coordinates[1]-steps)
        return pikachu_position
    elif direction.lower == 'w':
        pikachu_position = (coordinates[0]-steps, coordinates[1])
        return pikachu_position
    elif direction.lower == 'e':
        pikachu_position = (coordinates[0]+steps, coordinates[1])
        return pikachu_position

def battle(fight):
    if fight.lower == "w":
        print('{0} wins and moves to {1}'.format(name, move_pokemon(pikachu_position, direction, 1)))
    elif fight.lower == "g":
        print('Turn {0}, {1} at {2}'.format(turn_number-1, ))    
        print('{0} runs away to {1}'.format(name, move_pokemon(pikachu_position, direction, -10)))

pikachu_position = (75, 75)
turn_number = 1
while (turn_number-1) < turns:
    if (turn_number-1) % often != 0:
        direction = input('What direction does {0} walk? => '.format(name))
        print(direction)
        pikachu_position = move_pokemon(pikachu_position, direction, 5)
        print(pikachu_position)
    else:
        battle(input('What type of pokemon do you meet (W)ater, (G)round? => '))
    turn_number+=1
        
    
    
