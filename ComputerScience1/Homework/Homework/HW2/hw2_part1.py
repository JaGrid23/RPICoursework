#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 17:58:02 2019

@author: jaredgridley

The purpose of this program is to find the optimal size
of a gumball machine (cube) given the radius of a gum 
ball and the length of one side
"""
import math

radius = input("Enter the gum ball radius (in.) => ")
print(radius)
radius = float(radius)

weekly_sales = input("Enter the weekly sales => ")
print(weekly_sales, end = '\n\n')
weekly_sales = int(weekly_sales)


def find_volume_sphere(radius):
    '''
    Finds the volume of a sphere given the radius
    r = 2
    >>> 33.5
    '''
    vol_sphere = (4/3) * math.pi * (radius)**3
    return vol_sphere

def find_volume_cube(side):
    '''
    Finds the volume of a cube given one side
    side = 2
    >>> 8
    '''
    vol_cube = (side)**3
    return vol_cube

#This is calculating the length of one side of the cube
total_gumballs = math.ceil(weekly_sales * 1.25)
balls_per_side = math.ceil((total_gumballs)**(1/3))
side_length = (balls_per_side * (2 * radius))

#Calculations that simplify the print statements
extra_gumballs = (balls_per_side**3) - total_gumballs
total_possible_gumballs = total_gumballs + extra_gumballs

#Finding Volumes of cube and sphere
total_vol_cube = find_volume_cube(side_length)
gumball_vol = find_volume_sphere(radius)

#Calculations hased on volumes
balls_that_fit = (total_vol_cube)/(max(gumball_vol, 0.000001))

wasted_space = total_vol_cube - (total_possible_gumballs * gumball_vol)
wasted_space_target = total_vol_cube - (total_gumballs * gumball_vol)


#Print Statements
print('The machine needs to hold {0} gum balls along each edge.'.format(balls_per_side))
print('Total edge length is {0:.2f} inches.'.format(side_length))
print('Target sales were {0}, but the machine will hold {1} extra gum balls.'.format(total_gumballs, extra_gumballs))
print('Wasted space is {0:.2f} cubic inches with the target number of gum balls,'.format(wasted_space_target))
print('or {0:.2f} cubic inches if you fill up the machine.'.format(wasted_space))
