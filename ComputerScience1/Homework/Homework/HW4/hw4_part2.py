#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 16 20:28:39 2019

@author: jaredgridley
The purpose of this program is to create a table that compares universities
based off of a ranking.
"""

import hw4_util

uname = input('University name => ')
print(uname)

compare_1 = int(input('Line number for first university to compare (1-1000) => '))
print(compare_1)

compare_2 = int(input('Line number for second university to compare (1-1000) => '))
print(compare_2)


data = hw4_util.read_university_file("university_data.csv")


def find_university(data, uname):
    for universities in data:
        if uname == universities[0]:
            your_rank = universities[1]
            break
        else:
            your_rank = 'University not found'
    return your_rank


def make_comparison(compare_1, compare_2, your_rank):
    print('First university: {0}'.format(data[compare_1][0]))
    print('Second university: {0}'.format(data[compare_2][0], end = '\n'))
    print(end = '\n')
    print('{0:>25}{1:>12}{2:>12}{3:>12}'.format('','First', 'Second', 'Yours'))
    for i in range(1, len(data[0])):
        print('{0:>25}{1:>12}{2:>12}{3:>12}'.format(data[0][i], data[compare_1][i], data[compare_2][i], data[your_rank][i]))



if find_university(data, uname) == 'University not found':
    print('University not found')
else: 
    make_comparison(compare_1, compare_2, find_university(data, uname))  #How would I make it so I don't have to run through the first loop 2x
    