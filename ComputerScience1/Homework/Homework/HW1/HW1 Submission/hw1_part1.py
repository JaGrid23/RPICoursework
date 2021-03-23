#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 11 15:03:10 2019

@author: jaredgridley

The purpose of this program is to create a Mad Libs using Python
"""

print("Let's play Mad Libs for Homework 1 \nType one word responses to the following:\n")

proper_name = input('proper_name ==> ')
print(proper_name)

adjective1 = input('adjective ==> ')
print(adjective1)

noun1 = input('noun ==> ')
print(noun1)

verb1 = input('verb ==> ')
print(verb1)

verb2 = input('verb ==> ')
print(verb2)

noun2 = input('noun ==> ')
print(noun2)

emotion1 = input('emotion ==> ')
print(emotion1)

verb3 = input('verb ==> ')
print(verb3)

noun3 = input('noun ==> ')
print(noun3)

season = input('season ==> ')
print(season)

adjective2 = input('adjective ==> ')
print(adjective2)

emotion2 = input('emotion ==> ')
print(emotion2)

team_name = input('team-name ==> ')
print(team_name)

noun4 = input('noun ==> ')
print(noun4)

adjective3 = input('adjective ==> ')
print(adjective3, end = '\n')

print("\nHere is your Mad Lib...", end = '\n\n')

print("Good morning {0}!".format(proper_name), end = '\n\n')
print('  This will be a/an {0} {1}! Are you {2} forward to it?'.format(adjective1, noun1, verb1))
print('  You will {0} a lot of {1} and feel {2} when you do.'.format(verb2, noun2, emotion1))
print('  If you do not, you will {0} this {1}.\n'.format(verb3, noun3))
print('  This {0} was {1}. Were you {2} when {3} won\n  the {4}?\n'.format(season, adjective2, emotion2, team_name, noun4))
print('  Have a/an {0} day!'.format(adjective3))