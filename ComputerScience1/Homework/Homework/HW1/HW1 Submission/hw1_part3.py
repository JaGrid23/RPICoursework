#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 17 21:47:48 2019

@author: jaredgridley
The purpose of this program is to make a framed box based on the input specifications. 
"""
import math

character = input("Enter frame character ==> ")
print(character)

height = int(input("Height of box ==> "))
print(height)

width = int(input("Width of box ==> "))
print(width)


dimensions_text = str(width) + "x" + str(height)


#These three variables all have to do with contructing the vertical part of the box

top_border = "{0}\n".format(character * width)
bottom_border = character * width
emptyspace_length = (" " * (width - 2))
text_vertical = math.floor(height / 2)
heightlines_top = "{0}{1}{2}\n".format(character, emptyspace_length, character) * ((height - 2) - text_vertical)
heightlines_bottom = "{0}{1}{2}\n".format(character, emptyspace_length, character) * ((height - 2) - (math.ceil(height/2) - 1))


#Making the horizontal part of the text line of the box

length_left = math.floor((width / 2) - (len(dimensions_text) / 2))
left_filling = "{0}{1}".format(character, (" " * (length_left - 1)))
length_right = width - (length_left + len(dimensions_text))
right_filling = "{0}{1}".format((" " * (length_right - 1)), character)

text_horizontal = "{0}{1}{2}".format(left_filling, dimensions_text, right_filling)

#This is all just setting up the print statement
above_text = ("{0}".format(top_border)) + heightlines_top
text = "{0}\n".format(text_horizontal)
below_text = heightlines_bottom + bottom_border

print("\nBox:")
print(above_text + text + below_text)