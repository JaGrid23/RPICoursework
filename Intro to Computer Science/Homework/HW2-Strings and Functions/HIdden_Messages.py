#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  3 19:25:06 2019

@author: jaredgridley

The purpose of this program is to encrypt a segment
of text and then decode it, all the while comparing 
the two messages (coded and decoded)
"""

before_text = input('Enter a string to encode ==> ')
print(before_text, end = '\n\n')

def encrypt(before_text):
    '''
    Encrypts a string
    before_text = 'methan'
    >>> m2(*2(!@+3-?2(*2(
    '''
    #This is repetitive, but it makes it easier to see the encryption rules, so I did it this way
    encrypted_text = before_text.replace(' a', '%4%')
    encrypted_text = encrypted_text.replace('he', '7!')
    encrypted_text = encrypted_text.replace('e', '9(*9(')
    encrypted_text = encrypted_text.replace('y', '*%$')
    encrypted_text = encrypted_text.replace('u', '@@@')
    encrypted_text = encrypted_text.replace('an', '-?')
    encrypted_text = encrypted_text.replace('th', '!@+3')
    encrypted_text = encrypted_text.replace('o', '7654')
    encrypted_text = encrypted_text.replace('9', '2')
    encrypted_text = encrypted_text.replace('ck', '%4')
    
    return encrypted_text

def decrypt(encrypted_text):
    '''
    Decrypts the encrypted string
    encrypted_text = ba%47654ff m-? I%4%m%4% sci2(*2(ntist
    >>> backoff man Ick%mck% scientist
    '''
    #This is repetitive, but it makes it easier to see the encryption rules, so I did it this way
    decrypted_text = encrypted_text.replace('%4', 'ck')
    decrypted_text = decrypted_text.replace('2', '9')
    decrypted_text = decrypted_text.replace('7654', 'o')
    decrypted_text = decrypted_text.replace('!@+3', 'th')
    decrypted_text = decrypted_text.replace('-?', 'an')
    decrypted_text = decrypted_text.replace('@@@', 'u')
    decrypted_text = decrypted_text.replace('*%$', 'y')
    decrypted_text = decrypted_text.replace('9(*9(', 'e')
    decrypted_text = decrypted_text.replace( '7!', 'he')
    decrypted_text = decrypted_text.replace('%4%', ' a')
        
    return decrypted_text

#Assigning variables for the print statements
encrypted_text = encrypt(before_text)

decrypted_text = decrypt(encrypted_text)


#Calculations for the print statements
length_difference = abs(len(before_text) - len(encrypted_text))

if decrypted_text == before_text:
    status = 'Operation is reversible on the string.'
else:
    status = 'Operation is not reversible on the string.'


#Print Statements
print('Encrypted as ==> {0}'.format(encrypted_text))
print('Difference in length ==> {}'.format(length_difference))
print('Deciphered as ==> {}'.format(decrypted_text))
print(status)
