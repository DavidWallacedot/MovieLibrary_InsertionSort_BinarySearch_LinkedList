/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"

Movies::Movies()
{
	 linkedList = new LinkedList<Movie*>;
	}


Movies::~Movies()
{
	
for(int x = 0; x < linkedList->getLength();x++){
	 delete linkedList->getNodeValue(x)->getMovieTitle();
	 delete linkedList->getNodeValue(x)->getMovieGenre();
	 delete linkedList->getNodeValue(x)->getMovieRating();
	
	}
	
}


void Movies::addMovieToList() 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//add a movie
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	
		cout << "\nMOVIE LENGTH (in minutes): ";
		cin >> length;
		cout << "\nMOVIE YEAR: ";
		cin >> year;
		cin.ignore();
		cout << "\nMOVIE GENRE: ";
		cin.getline(tempString, 100);
		genre = new Text(tempString);
		cout << "\nMOVIE RATING: ";
		cin.getline(tempString, 100);
		rating = new Text(tempString);
		cout << "\nNUMBER OF OSCARS WON: ";
		cin >> numOscars;
		cout << "\nSTAR RATING (out of 10): ";
		cin >> numStars;
		
		//create the movie
		if(-1==binarySearch(title)){
		Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);
		
		
		linkedList->appendNode(oneMovie);
		insertionSort();
		}
		
	
	else{
		cout<<"I'm sorry ";
		title->displayText();
		cout<< " is already in your movie library so it will not be added again";	
		delete title;
		delete rating;
		delete genre;
	}
	
}	



void Movies::removeMovieFromList()
{
	int movieChoice;
	
	if(linkedList->getLength() <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << linkedList->getLength() << ":  ";
		cin >> movieChoice;
		
		while(movieChoice < 1 || movieChoice > linkedList->getLength())
		{
			cout << "\nOops!  You must enter a number between 1 & " << linkedList->getLength() << ":  ";
			cin >> movieChoice;
		}

		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = linkedList->getNodeValue(movieIndexToBeRemoved)->getMovieTitle();
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		//destroy this movie
		
		int numElementsToMoveBack = (linkedList->getLength()) - 1;
		
		linkedList->deleteNode(movieIndexToBeRemoved);
		
	}
}



void Movies::editMovieInList()
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles();
	
	cout << "\nChoose a movie to edit between 1 & " << linkedList->getLength() << ":  ";
	cin >> movieChoice;
	
	while(movieChoice < 1 || movieChoice > linkedList->getLength())
	{
		cout << "\nOops!  You must enter a number between 1 & " <<linkedList->getLength() << ":  ";
		cin >> movieChoice;
	}
	
	Movie* oneMovie = linkedList->getNodeValue(movieChoice-1);
	
	oneMovie->editMovie();
}



void Movies::displayMovies()//start here!!
{
	if(linkedList->getLength() > 0)
	{
		for(int x=0; x < linkedList->getLength(); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			linkedList->getNodeValue(x)->printMovieDetails(); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles()
{
	Text* movieTitle;
	
	for(int x=0; x<linkedList->getLength(); x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieTitle =linkedList->getNodeValue(x)->getMovieTitle();
		movieTitle->displayText();
	}
}

void Movies::readMoviesFromFile(char *filename)
{ 	
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			
			title = new Text(temp);//create a text for the movie title
			
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
					if(-1!=binarySearch(title)){
				title->displayText(); 
				cout<<" was not added because it was already in the movie library."<<endl;
				delete title;
				delete rating;
				delete genre;
					}
			else{
			//one movie has been read from the file.  Now create a movie object
			// title->displayText();
			cout<<" movie is being added";
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//now add this movie to the library
			
			linkedList->appendNode(oneMovie);
			
			
			
			//confirm addition to user
			cout << endl;
			title->displayText();
			cout << " was added to the movie library!\n";
			numMoviesReadFromFile++;
			}
						
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
	insertionSort();
}

void Movies::saveToFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x<linkedList->getLength(); x++)
	{
		linkedList->getNodeValue(x)->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}


int Movies::getNumMovies() const
{
	return linkedList->getLength();
}


int Movies::binarySearch(Text* title){
	int found = -1;
	if(linkedList->getLength() == 0){return found;}
	
	for(int x = 0; x<= linkedList->getLength()-1;x++){
		if(0==strcmp(linkedList->getNodeValue(x)->getMovieTitle()->getText(),title->getText())){
			found = x;
		}
	}
	
	return found;
	
}

void Movies::insertionSort(){
	int j;
		for(int i =1 ; i< linkedList->getLength();i++){
			j = i;
				while(j>0 && 0<strcmp(linkedList->getNodeValue(j-1)->getMovieTitle()->getText(),linkedList->getNodeValue(j)->getMovieTitle()->getText()))
					{
						linkedList->swap(j-1,j);
						j--;
					}
	}
}



