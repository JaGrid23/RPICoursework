"""
Created on Fri Nov  1 21:24:13 2019
@author: jaredgridley

The purpose of this program is to simulate an autocorrect algorithm by using 
perscribed rules to check and see if any of the possible spellings are in the
file of correct words... or our dictionary :-).
"""

dictionary = input('Dictionary file => ')
print(dictionary)

misspelled_words = input('Input file => ')
print(misspelled_words)


def correction(misspelled_word):
    #Testing FOUND
    if misspelled_word in dictionary_set:
        return (misspelled_word, 'FOUND')
    
    #Testing DROP
    drop_output = []
    for letter in range(len(misspelled_word)):
        dropped_word = misspelled_word[0:letter]+misspelled_word[letter+1:]     #Creates the dropped word
        if dropped_word in dictionary_set:
            drop_output.append((dropped_word, 'DROP'))
    if len(drop_output) > 0:                #If there is something in the list it returns the first sorted value in the list
        return sorted(drop_output)[0]
    
    #Testing SWAP
    swap_output = []
    for i in range(len(misspelled_word) -1):
        first_letter_swap = misspelled_word[i]
        second_letter_swap = misspelled_word[i+1]
        swapped_word = misspelled_word[:i] + second_letter_swap + first_letter_swap + misspelled_word[i+2:]     #Creating the swapped word
        
        if swapped_word in dictionary_set:
            swap_output.append((swapped_word, 'SWAP'))      #Appends to the swap_output list if it is in the dictionary set
    if len(swap_output) > 0:
        return sorted(swap_output)[0]
    
    #Testing REPLACE
    replace_output = []
    letters = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    for i in range(len(misspelled_word)):
        for letter in letters:
            replaced_word = misspelled_word[:i] + letter + misspelled_word[i+1:]        #Creates the misspelled word
            if replaced_word in dictionary_set:
                replace_output.append((replaced_word, 'REPLACE'))       #Checks if in the dictionary set and then appends to list
    if len(replace_output) > 0:
        return sorted(replace_output)[0]
    
    #Executing the NO MATCH protocol
    else:
        return (misspelled_word, 'NO MATCH')
    

if __name__ == '__main__':
    #This is putting all of the dictionary words from the 'dictionary' file into a set 
    dictionary_set = set()
    for line in open(dictionary, 'r'):
        line = line.strip()                #Removes whitespace from line
        dictionary_set.add(line)     #Adds to dictionary if not already there
    
    
    
    #This opens the incorrect words and runs each of them through the correction fucntion and then prints out the suggested words
    f_misspelled_words = open(misspelled_words)
    
    for line in f_misspelled_words:
        line = line.strip()
        auto_correction = correction(line)   
        #runs each word through my correction function
        print('{0:15} -> {1:15} :{2}'.format(line, auto_correction[0], auto_correction[1]))     #Prints with 15 spaces after each {}.format()
        
        