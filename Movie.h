/*
	Title:  Movie.h
	Author:  April Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Movie
{
	private: 
		Text* movieTitle;  //title of movie
		int movieLength; //length of movie in minutes
		int movieYear; //year released
		Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
		Text* movieRating; //G, PG, PG-13, R, MA
		int movieOscars; //number of oscars won
		float movieNumStars; //taken from IMDB on 10 star scale
		
	public:
		/*
			Function name:  Movie constructor(overloaded function)
			Parameters:  	1) A pointer to a Text variable, containing a c-string and the length of the string.
							2) An integer containing the length of the movie
			Purpose:  		This function should be called when only the title of the movie and the length of
							the movie is known and it will create a new movie with this information.
		*/
		Movie(Text*, int); 

		/*
			Function name:  Movie constructor (overloaded function)
			Parameters:  	1) A pointer to a Text variable, containing the title of the movie
							2) An integer containing the length of the movie
							3) An integer containing the year the movie was released
							4) A pointer to a Text variable, containing the genre of the movie
							5) A pointer to a Text variable, containing the rating of the movie
							6) An integer containing the number of oscars the movie won
							7) A float containing the IMDB rating of the movie (out of 10 stars)
			Purpose:  		This function should be called when all movie information is known and 
							it will create a new movie with this information.
		*/
		Movie(Text*, int, int, Text*, Text*, int, float); 

		
		/*
			Function name:  ~Movie destructor 
			Purpose:  		This function is automatically called when a Movie object is destroyed.
							This function releases the dynamically allocated text arrays in the Movie.
		*/
		~Movie();


		
		/*
			Function name:  editMovie 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to edit a single
							movie's data
		*/
		void editMovie();

		

		/*
			Function name:  printMovieDetails 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to print ALL
							the movie information to the screen.
		*/
		void printMovieDetails();

		
		
		/*
			Function name:  printMovieDetailsToFile 
			Parameters:  	a file stream object (sent by reference)
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to print ALL
							the movie information to the file.
		*/
		void printMovieDetailsToFile(ofstream &outFile);

		
		
		
		//accessor functions to get the attribute values
		Text* getMovieTitle() const;
		int getMovieLength() const;
		int getMovieYear() const;
		Text* getMovieGenre() const;
		Text* getMovieRating() const;
		int getMovieOscars() const;
		float getMovieNumStars() const;

		//mutator functions to change the attribute values to a new value, which is a parameter of each function
		void setMovieTitle(Text*);
		void setMovieLength(int);
		void setMovieYear(int);
		void setMovieGenre(Text*);
		void setMovieRating(Text*);
		void setMovieOscars(int);
		void setMovieNumStars(int);
};







#endif