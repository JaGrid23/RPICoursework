#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 10 22:26:03 2019

@author: jaredgridley
The purpose of this program is to track the population changes between berries, tourists, and bears
"""
import math

bears = int(input('Number of bears => '))
print(bears)

berry_area = input('Size of berry area => ')
print(berry_area)

def num_tourists(bears):
    if bears < 4 or bears > 15:
        tourists = 0
    elif bears >= 4 and bears <= 10:
        tourists = 10000 * bears
    else:
        tourists = (10000 * 10) + (20000 * (bears-10))
    return tourists


def bears_next(bears, berries, tourists):
    return berries/(50*(bears+1)) + bears*0.60 - (math.log(1+tourists,10)*0.1)


def berries_next(bears, berries, tourists):
    return (berries*1.5) - (bears+1)*(berries/14) - (math.log(1+tourists,10)*0.05)


def find_next(bears, berries, tourists):
    bearPop_next = bears_next(bears, berries, tourists)
    berriesPop_next = berries_next(bears, berries, tourists)
    
    return (max(0, (math.floor(bearPop_next))), max(0, berriesPop_next))

#Lists for min and max
bears_ls = []
berry_ls = []
tourists_ls = []

bears_ls.append(bears)
berry_ls.append(float(berry_area))
tourists_ls.append(num_tourists(bears))

#print statement header
print('Year\tBears\tBerry\tTourists')
print('1\t{0}\t{1}\t{2}'.format(bears, float(berry_area), num_tourists(bears)))


for data in range(2,11):
    year = data
    
    tourists_next = num_tourists(bears)
    bear = find_next(bears, float(berry_area), tourists_next)[0]
    berry = find_next(bears, float(berry_area), tourists_next)[1]
    tourists = num_tourists(bear)
    
    bears_ls.append(bear)
    berry_ls.append(berry)
    tourists_ls.append(tourists)
    
    print('{0}\t{1}\t{2:.1f}\t{3}'.format(year, bear, berry, tourists))
    
    berry_area = berry
    bears = bear

#printing min and max data
print('\nMin:\t{0}\t{1:.1f}\t{2}'.format(min(bears_ls), min(berry_ls), min(tourists_ls)))
print('Max:\t{0}\t{1:.1f}\t{2}'.format(max(bears_ls), max(berry_ls), max(tourists_ls)))
    


