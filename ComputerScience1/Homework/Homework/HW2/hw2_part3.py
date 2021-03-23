#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 20:05:19 2019

@author: jaredgridley

The purpose of this program is to mimic natural
language processing in the way that they recognize
happy and sad sentances.

Actually, this weekend I'm going to a hackathon in NYC
based on artifical intelligence and one of the talks I
signed up for is natural language processing with python

Good thing I've been keeping up on Hackarrank. 

Sorry for the side note, let's get coding!!!!!!!!!
"""

sentence = input('Enter a sentence => ')
print(sentence)
sentence = sentence.lower()

def number_happy(sentence):
    '''
    Counts the number of happy words in the sentence and returns the number
    sentence = I laughed and laughed at her excellent joke.
    >>> 3
    '''
    laugh = sentence.count('laugh')
    happiness = sentence.count('happiness')
    love = sentence.count('love')
    excellent = sentence.count('excellent')
    good = sentence.count('good')
    smile = sentence.count('smile')
    
    total_happy = laugh + happiness + love + excellent + good + smile
    
    return total_happy

def number_sad(sentence):
    '''
    Counts the number of sad words in the sentence and returns the number
    sentence = Dr. Horrible's Sing-Along Blog is an excellent show.
    >>> 1
    '''
    bad = sentence.count('bad')
    sad = sentence.count('sad')
    terrible = sentence.count('terrible')
    horrible = sentence.count('horrible')
    problem = sentence.count('problem')
    hate = sentence.count('hate')
    
    total_sad = bad + sad + terrible + horrible + problem + hate
    
    return total_sad


#Preparing variables for the print statement
sentiment = (number_happy(sentence) * '+') + (number_sad(sentence) * '-')

if sentiment.count('+') > sentiment.count('-'):
    statement = 'This is a happy sentence.'
elif sentiment.count('+') < sentiment.count('-'):
    statement = 'This is a sad sentence.'
else:
    statement = 'This is a neutral sentence.'
    
#Print Statements
print('Sentiment: {0}'.format(sentiment))
print(statement)