/*
	Title:  Driver.cpp
	Author:  April Crockett
	Date:  11/7/2017
	Purpose:  To demonstrate the Movies, Movie, and Text structure code working
	by allowing the user to add, save, delete, and edit movies to/from a library.
*/

#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include <iostream>
using namespace std;

int main()
{
	int menuChoice;
	int movieChoice;
	
	char filename[25];
	
	
	Movies* movieLibrary = new Movies();
	
	do
	{
		cout << "\n\nWhat would you like to do?\n";
		cout << "1.  Read movies from file.\n";
		cout << "2.  Save movies to a file.\n";
		cout << "3.  Add a movie.\n";
		cout << "4.  Delete a movie.\n";
		cout << "5.  Edit a movie.\n";
		cout << "6.  Print all movies.\n";
		cout << "7.  Delete ALL movies and end the program.\n";
		cout << "CHOOSE 1-7:  ";
		cin >> menuChoice;
		while(menuChoice < 1 || menuChoice > 7)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-7:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:	cout << "\n\nWhat is the name of the file? (example.txt):  ";
					cin >> filename;
					movieLibrary->readMoviesFromFile(filename);
					break;
					
			case 2: cout << "\n\nWhat do you want to name the file? (example.txt):  ";
					cin >> filename;
					movieLibrary->saveToFile(filename); 
					break;
					
			case 3:	//add a movie
					movieLibrary->addMovieToList();
					break;
					
			case 4:	//delete a movie if there is more than one movie in the library.
					movieLibrary->removeMovieFromList();
					break;
					
			case 5: //edit a movie
					movieLibrary->editMovieInList();
					break;
					
			case 6: //print all movies
					movieLibrary->displayMovies();
					break;
					
			case 7: //delete all movies
					delete movieLibrary;
					break;
					
		}
		
	} while(menuChoice != 7);
	
	cout << "\n\nGOODBYE!\n\n";
	
	return 0;
}
