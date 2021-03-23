#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 27 19:50:47 2019

@author: jaredgridley
The purpose of this program is to set up the environment of a wandering pokemon.
HW5 P1
"""

import random

size = int(input('Enter the integer grid size => '))
print(size)
f = int(input('Enter the integer number of Falses => '))
print(f)
t = int(input('Enter the integer number of Trues => '))
print(t)



def move_trainer():
    directions = ['N', 'E', 'S', 'W']
    print('Directions: {0}'.format(directions))
    print('Selected {0}, value {1:.2f}'.format(random.choice(directions), random.random()))
    
def throw_pokeball(num_false, num_true):
    l = []                      #This and the following 2 'for' loops create the list of True and False values. 
    for i in range(num_false):
        l.append(False)
    for i in range(num_true):
        l.append(True)
    print('Booleans: {0}'.format(l))
    print('Selected {0}'.format(random.choice(l)))

#this sets the seed and prints what it was set to
random.seed(10 * size + size)
print('Setting seed to {}'.format(10*size+size))

#these are the specific test cases from the HW, it moves the trainer 5 times and throws a ball 5 times. 
s = 0
while s<5:
  move_trainer()
  s+=1

w=0
while w<5:
    throw_pokeball(f, t)
    w+=1