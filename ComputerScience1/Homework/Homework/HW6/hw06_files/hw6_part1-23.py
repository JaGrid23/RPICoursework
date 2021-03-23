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


def found(misspelled_word):
    if misspelled_word in dictionary_set:
        return (misspelled_word, 'FOUND')
    else:
        return 'Not found'


def drop(misspelled_word):
    drop_output = []
    for letter in range(len(misspelled_word)):
        dropped_word = misspelled_word[:letter] + misspelled_word[letter+1:]
        print(dropped_word)
        print(dropped_word in dictionary_set)
        if dropped_word in dictionary_set:
            drop_output.append((dropped_word, 'DROP'))
            print('hi')
    print(drop_output)
    if len(drop_output) > 0:
        return max(drop_output)
    else:
        return 'Not dropped'
    
    
def swap(misspelled_word):
    swap_output = []
    for i in range(len(misspelled_word)-1):
        first_letter_swap = misspelled_word[i]
        second_letter_swap = misspelled_word[i+1]
        swapped_word = misspelled_word[:i] + second_letter_swap + first_letter_swap + misspelled_word[i+2]
        
        if swapped_word in dictionary_set:
            swap_output.append((swapped_word, 'SWAP'))
            
    if len(swap_output) > 0:
        return sorted(swap_output)[0]
    else:
        return 'Not swapped'
    

def replace(misspelled_word):
    replace_output = []
    letters = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    for i in range(len(misspelled_word)-1):
        for letter in letters:
            replaced_word = misspelled_word[:i] + letter + misspelled_word[i+1:]
            
            if replaced_word in dictionary_set:
                replace_output.append(replaced_word)
    if len(replace_output) > 0:
        return max(replace_output)
    else:
        return 'Not replaced'



if __name__ == '__main__':
    #This is putting all of the dictionary words from the 'dictionary' file into a set 
    dictionary_set = set()
    for line in open(dictionary, 'r'):
        line = line.strip()                #Removes whitespace from line
        dictionary_set.add(line)     #Adds to dictionary if not already there
    
    
    
    #This opens the incorrect words and runs each of them through the correction fucntion and then prints out the suggested words
    f_misspelled_words = open(misspelled_words, 'r')
    for line in f_misspelled_words:
        line = line.strip()
        auto_correction = tuple #runs each word through my correction function
        if found(line) != 'Not Found':
            auto_correction = found(line)
        elif drop(line) != 'Not dropped':
            auto_correction = drop(line)
            print('sup')
        elif swap(line) != 'Not swapped':
            auto_correction = swap(line)
        elif replace(line) != 'Not replaced':
            auto_correction = replace(line)
        else:
            auto_correction = ((line, 'Not Found'))
        print('{0:15} -> {1:15} :{2}'.format(line, auto_correction[0], auto_correction[1]))     #Prints with 15 spaces after each {}.format()
        
        
