"""
Created on Sat Nov  9 00:05:56 2019
@author: jaredgridley

The purpose of this program is to sort through the movie database based on year and type factors that are given as input
and then return the most popular and least popular movies according to their twitter and IMBD ratings. This will use dictionaries
and will find the best/worst movies using a given equation. 
"""

import json

min_year = int(input('Min year => '))
print(min_year)

max_year = int(input('Max year => '))
print(max_year)

imdb_weight = (input('Weight for IMDB => '))
print(imdb_weight)
imdb_weight = float(imdb_weight)

twitter_weight = input('Weight for Twitter => ')
print(twitter_weight, end ='\n\n')
twitter_weight = float(twitter_weight)

genre = input('What genre do you want to see? ')
print(genre, end = '\n\n')

if __name__ == '__main__':
    while genre.lower() != 'stop':
        #These import data from the JSON files as a dictionary
        movies = json.loads(open("movies.json").read())         #This reads the movies from the file as a dictionary
        ratings = json.loads(open("ratings.json").read())       #This reads the twitter ratings from the file as a dictionary
        
        
        #This will find all the movies within the specified years and put them in a dictionary. 
        movies_within_date = dict()
        for movie in movies:
            if movies[movie]['movie_year'] >= min_year and movies[movie]['movie_year'] <= max_year:
                movies_within_date.update({movie: movies[movie]})                       #Adds the movies key-value pair to the dictionary if within date. 
        
        
        #This finds all the movies within the genre and adds them to a list
        in_genre = dict()
        for cinema in movies_within_date:
            if genre.title() in movies_within_date[cinema]['genre']:                #Checks for a matching genre
                in_genre[cinema] = movies_within_date[cinema]     #Adds to the list as a tuple (rating, title) if genre matches. 
        
        
        #This will compute the ratings for each movie in the movies_within_date dictionary
        movies_final = []               #These are the movies that only have the information to be printed out and sorted by
        for film in in_genre:
            if film in ratings and len(ratings[film]) >= 3:         #If the film is in the twitter ratings and has more than 2 reviews. 
                twitter_rating = sum(ratings[film])/len(ratings[film])
                new_rating = ((imdb_weight * in_genre[film]['rating']) + (twitter_weight * twitter_rating))/(imdb_weight + twitter_weight)     #This is the equation to calculate new rating
                movies_final.append((round(new_rating, 2), in_genre[film]['name'], in_genre[film]['movie_year']))                           #appends the new information to the list
            #if the twitter ratings ar not sufficient it doesn't add it to the list 
        
        final_sorted = sorted(movies_final, reverse = True) 
        
        if len(final_sorted) == 0:
            print('No {0} movie found in {1} through {2}'.format(genre.title(), min_year, max_year), end = '\n\n')        #Prints the no movie found line. 
        else:
            #Prints the best and worst movie found:
            print('Best:\n\tReleased in {0}, {1} has a rating of {2:.2f}'.format(final_sorted[0][2], final_sorted[0][1], float(final_sorted[0][0])), end = '\n\n')              #Best movie with formatting
            print('Worst:\n\tReleased in {0}, {1} has a rating of {2:.2f}'.format(final_sorted[-1][2], final_sorted[-1][1], float(final_sorted[-1][0])), end = '\n\n')          #Worst movie with formatting
        
        #This repeast the genre section to end the while loop upon input. 
        genre = input('What genre do you want to see? ')
        if genre.lower() == 'stop':             #This if statement is to get the spacing right for submitty, other than that it has no meaning
            print(genre)
        else:
            print(genre, end = '\n\n')
