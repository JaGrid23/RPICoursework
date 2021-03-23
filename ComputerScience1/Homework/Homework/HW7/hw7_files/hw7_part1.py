"""
Created on Fri Nov  8 21:51:14 2019
@author: jaredgridley

This program is an improved version of the autocorrect algorithm. It will use
dictionaries to sort the contents of the words files as well as to perform operations. 
"""
f_wordsfile = input('Dictionary file => ')
print(f_wordsfile)

i_file = input('Input file => ')
print(i_file)

k_file = input('Keyboard file => ')
print(k_file)

#These are all the letters in the alphabet, they are using in the insert and replace functions, they are assigned at the top to make sure they are defined before any function call, whether local or global. 
letters = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def drop(bad_word):
    for letter in range(len(bad_word)):
        dropped_word = bad_word[:letter] + bad_word[letter+1:]      #Uses slicing to make a new string of the letters around the dropped letter
        if dropped_word in complete_dictionary:                     #Checks if its in the dictionary, if so it adds it to the list. 
            corrected_words.append((complete_dictionary[dropped_word], dropped_word))       #Appends to the list of words found in the dictionary
    
    insert(bad_word)                                                #Calls the next function (insert)


def insert(bad_word):
    for character in range(len(bad_word)+1):
        for letter in letters:
            inserted_word = bad_word[:character] + letter + bad_word[character:]        #Uses slicing to run through all the possible ways to insert a wor using the letters list form below
            
            if inserted_word in complete_dictionary:                                                        #Checks to see if the word is in the dictionary
                corrected_words.append((complete_dictionary[inserted_word], inserted_word))       #If in dictionary, it adds it to the found words list. 
    
    swap(bad_word)                                                #Calls the next function (swap)


def swap(bad_word):
    for char in range(len(bad_word)-1):
        first_swap = bad_word[char]             #First Character that will be swapped
        second_swap = bad_word[char+1]            #Character that will be swapped with the first one
        swapped_word = bad_word[:char] + second_swap + first_swap + bad_word[char+2:]            #Uses slicing to create all the possible ways to swap a word
        
        if swapped_word in complete_dictionary:                                                 #Checks to see if its in the dictionary
            corrected_words.append((complete_dictionary[swapped_word], swapped_word))   #If so it appends the data to the found words list. 
    
    replace(bad_word)               #Calls the next function (replace)


def replace(bad_word):
    for character in range(len(bad_word)):
        for letter in keyboard[bad_word[character]]:
            replaced_word = bad_word[:character] + letter + bad_word[character+1:]          #Uses slicing to replace each character in a word with every letter in the alphabet using letters list below 
            
            if replaced_word in complete_dictionary:                                        #Checks to see if its in the dictionary
                corrected_words.append((complete_dictionary[replaced_word], replaced_word))     #appends the found word in the corrected_word list
    
if __name__ == '__main__':   
    #This will read the english dictionary into a python dictionary file
    complete_dictionary = dict()
    for line in open(f_wordsfile):
        line = line.strip().split(',')
        complete_dictionary[line[0]] = line[1]      #Adds each line key:value pair to the dictionary
    
    #This reads the into a set
    input_words = []
    for line in open(i_file):
        line = line.strip()
        input_words.append(line)                       #Adds the stripped word from the input file to the set
    
    #This will read the keyboard file into a python dictionary
    keyboard = dict()
    for line in open(k_file):
        line = line.strip().split(' ')
        keyboard[line[0]] = line[1:]                #Adds to dictionary based on the first character and then the rest of the characters
    
    #This perfoms all the operations for the autocorrect algortihm with the data that has been established above.
    
    for word in input_words:
        corrected_words = []           #resets the list for all of the words in the set
        if word in complete_dictionary:                             #Checks to see if the word is in the dictionary
            print('{0:15} -> {0:15} :{1}'.format(word, 'FOUND'))    #if so prints the FOUND output
        else:
            drop(word)                     #runs through all the functions, altering the list above
            if len(corrected_words) == 0:                               #Checks for the NO OUTPUT in the Corrected_words
                print('{0:15} -> {0:15} :{1}'.format(word, 'NO MATCH'))
            else:
                s = sorted(set(corrected_words), reverse = True)                   #Sorts the corrected words with highest first 
                for i in range(min(len(s), 3)):
                    print('{0:15} -> {1:15} :MATCH {2}'.format(word, s[i][1], i+1))   #Prints the number of corrected_words or 3, whicever is smaller using the 15 space format. 