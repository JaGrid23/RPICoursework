#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct  9 14:47:25 2019

@author: jaredgridley

The purpose of this program is to analyze the difficulty of a given
sentance and print out the calculationsof determining the sentance 
difficulty
"""

import syllables

paragraph = input('Enter a paragraph => ')
print(paragraph)

sentances = paragraph.split('.')

# Calculating a list with all the words in them

word_lst2 = paragraph.replace('\n', ' ').split(' ')



#Finding the ASL (Oh yeah, I found the simpler way to do this)
words = 0
word_lst = []
n=0  #arbitrary variable for counting
for word in sentances:
    word_split = sentances[n].strip().split(' ')
    for wort in word_split:
        word_lst.append(wort)
    words = words + len(word_split)
    n+=1
total_words = words-1   #the '-1' accounts for the empty string after the last period

ASL = total_words/(len(sentances)-1) 



#Finding the Percent of Hard Words (Wort is german for word)
complex_words = 0
for wort in word_lst:
    if syllables.find_num_syllables(wort) >= 3 and wort.count('-') == 0:
        complex_words += 1
    elif syllables.find_num_syllables(wort) == 3 and wort.count('es') == 0 and wort.count('ed') == 0:
        complex_words += 1
        
PHW = (complex_words / total_words) * 100


 #Cleans up the list of complex words for repeats
yingyu_lst = []
for zi in word_lst2:
    if syllables.find_num_syllables(zi) >= 3 and zi.count('-') == 0:
        yingyu_lst.append(zi)
    elif syllables.find_num_syllables(zi) == 3 and zi.count('es') == 0 and zi.count('ed') == 0:
        yingyu_lst.append(zi)

 #Cleans up the list of complex words for repeats
seen = set() #I've been reading ahead in the book and already saw the set function
complex_words_lst = []
for item in yingyu_lst:
    if item not in complex_words_lst:
        seen.add(item)
        complex_words_lst.append(item)
        
        
# Finding the Average number of syllables (Mot is french for word)
total_syllables = 0
for mot in word_lst:
    syll = syllables.find_num_syllables(mot)
    total_syllables += syll

ASYL = (total_syllables-1) / (total_words) # the -1 is because I was dumb when I made my earlier list, it removes the space at the end of the list.


#GFRI Calculation
GFRI = 0.4*(ASL + PHW)


#FKRI Calculation
FKRI = 206.835 - (1.015 * ASL) - (86.4 * ASYL)

#Print Statements
print('Here are the hard words in this paragraph:')
print(complex_words_lst)
print('Statistics: ASL:{0:.2f} PHW:{1:.2f}% ASYL:{2:0.2f}'.format(ASL, PHW, ASYL))
print('Readability index (GFRI): {0:.2f}'.format(GFRI))
print('Readability index (FKRI): {0:.2f}'.format(FKRI))
