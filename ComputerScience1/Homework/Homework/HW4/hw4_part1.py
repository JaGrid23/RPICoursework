#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 16 19:08:37 2019

@author: jaredgridley
The purpose of this program is to determine if a password is valid according to the given rules
For whomever is grading this, the questions in the comments are the stuff I'm going to ask professor Mushtaque
"""
password = input('Enter a password => ')
print(password)


#RULE 1
if len(password) > 10 and len(password) <= 25 and (password[0].lower() in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']):
    print('Rule 1 is satisfied')
    rule_1 = True
else:
    print('Rule 1 is not satisfied')
    rule_1 = False


#RULE 2
if (password.count('@') > 0 or password.count('$') > 0) and password.count('%') == 0:
    print('Rule 2 is satisfied')
    rule_2 = True
else:
    print('Rule 2 is not satisfied')
    rule_2 = False


#RULE 3
     #Is there a way to make this less repetative and to make it work
is_num1_4 = password.count('1') > 0 or password.count('2') > 0 or password.count('3') > 0 or password.count('4') > 0
if any(x.islower() for x in password) and any(x.isupper() for x in password) or is_num1_4:
    print('Rule 3 is satisfied')
    rule_3 = True
else:
    print('Rule 3 is not satisfied')
    rule_3 = False


#RULE 4
for char in password:
    if  (char == '_' and password[password.index(char) -1].isupper()) or not char.isupper():
        four = 'Rule 4 is satisfied'
        rule_4 = True
    else:
        four = 'Rule 4 is not satisfied'
        rule_4 = False
        break #is it ok to use breaks, book said not to
print(four)


#RULE 5
for char in password:
    #Is there a way to make this less repetative without a loop?
    if char != '5' and char != '6' and char != '7' and char != '8'and char != '9':
        five = 'Rule 5 is satisfied'
        rule_5 = True
    else:
        five = 'Rule 5 is not satisfied'
        rule_5 = False
        break
print(five)


if rule_1 and rule_2 and rule_3 and rule_4 and rule_5:
    print("The password is valid")
elif password[0].lower() not in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']:
    # ^^ how would I not hardcode this? ^^
    print('The password is not valid')
elif rule_1 or rule_2 or rule_3 or rule_4 or rule_5:
    print('A suggested password is: {0}'.format(password[:8] + '42' + password[-8:]))