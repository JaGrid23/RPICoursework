"""
Created on Wed Nov  6 00:08:34 2019
@author: jaredgridley

The purpose of this program is to read a title from the user of a 
Harry Potter production and then print all the beasts associated with
that title as well as all the other titles that have a beast that matches 
one of the beasts associated with the given title. 
"""
import textwrap
title = input('Enter a title (stop to end) => ')
print(title, end = '\n\n')

if __name__ == '__main__':
    while title.lower() != 'stop':
        
        title_words = ''
        common_titles = set()
        #This opens the file and reads each line and then makes a list of the titles and the words in the title and a words with the titles and their beasts. 
        words_in_title = []
        title_beasts = []
        for line in open('titles.txt'):
            line = line.strip()
            list_line = line.split('|')
            words_in_title.append([list_line[0], list_line[0].strip().split(' ')])
            title_beasts.append((list_line[0], set(list_line[1:])))
            
        for i in range(len(words_in_title)):
            for words in words_in_title[i][0]:         #This adds the title words to teh set to later check for the word will return "Title not found"
                title_words = title_words + words.lower()
                
                
        #This if statement will check to see if the title is found in the set of title words. 
        if title.lower() in title_words:
            #This will find the beasts associated with a particular title by using loops
            for i in range(len(words_in_title)):
                if title.lower() in words_in_title[i][0].lower():
                    print('Found the following title: {0}'.format(words_in_title[i][0]), end = '\n')
                    production = words_in_title[i][0]   #This is the title found
                    common_titles.add(production)       #This adds the title to the common_titles set to make manipulating the list easier later. 
                    break
            
            
            #This will find the beasts and then print out the beasts associated with the movies   
            for prod in range(len(title_beasts)):
                if title_beasts[prod][0] == production:
                    beasts = sorted(title_beasts[prod][1])      #These are the beasts only in the found title
                    p_foundb = 'Beasts in this title: ' + ', '.join(beasts)
                    p_foundb_lines = textwrap.wrap(p_foundb)
                    for line in p_foundb_lines:
                        print(line)
                    print(end='\n')
            
            
            comparison_beast = set()            #This will make a set to be used to find the beasts only appearin in the given title later. 
            #This will find the titles that have beasts in common with the given title and then print out the titles in lexographic order
            for beast in beasts:    
                #This will run through and compare the beast to the beasts in other titles using for loops
                for i in range(len(title_beasts)):
                    if title_beasts[i][0] == production:
                        continue
                    elif beast in list(title_beasts[i][1]):
                        for b in title_beasts[i][1]:
                            comparison_beast.add(b) #Adds all the beasts not already in the comparison_beasts set to the set
                        common_titles.add(title_beasts[i][0])
                        
                        
            #This will print out all of the titles with a matching beasts
            common_titles.discard(production)
            p_matchbeasts='Other titles containing beasts in common: ' + ', '.join(sorted(common_titles))
            p_matchbeasts_lines = textwrap.wrap(p_matchbeasts)
            for line in p_matchbeasts_lines:
                print(line)
            print(end = '\n')
            
            #This will print out the beasts only appearing in the given title. 
            difference_beasts = set(beasts).difference(comparison_beast)
            p_bonly = 'Beasts appearing only in this title: ' + ', '.join(sorted(difference_beasts))
            p_bonly_lines = textwrap.wrap(p_bonly)
            for line in p_bonly_lines:
                print(line)
            print(end = '\n')
            
        else:
            print('This title is not found!', end = '\n\n')
        
        #This will allow the loop to continue until the user enters 'stop' with any casing. 
        title = input('Enter a title (stop to end) => ')
        if title.lower() == 'stop':
            print(title)
        else:
            print(title, end = '\n\n')