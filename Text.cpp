#include "Text.h"
#include <iomanip>
#include <cstring>

using namespace std;

Text::Text(const char* text)
{	
	//get the length of the string passed to this function
	textLength = strlen(text);
	
	//dynamically allocate a new character array
	char* tempTextArray = new char[(textLength)+1];
	
	//Now put text inside of tempTextArray
	strcpy(tempTextArray, text); 
	
	//put the text sent to this function into the newly created array
	//I can do assignment because it is assigning a pointer (not a cstring)
	this->textArray = tempTextArray;	
}

Text::~Text()
{
	//release the dynamically allocated character array
	delete [] textArray;
}

void Text::editText(const char* newTextArray)
{
	//first delete the array that textArray is currently pointing to (the old string)
	delete [] textArray;
	
	//get the length of the string passed to this function
	textLength = strlen(newTextArray);
	
	//cout << "\n\nThe length of " << newTextArray << " is " << textLength << endl << endl;
	
	//dynamically allocate a new character array
	char* tempTextArray = new char[(textLength)+1];
	
	//Now put the new text passed to this function inside of tempTextArray
	strcpy(tempTextArray, newTextArray); 
	
	//put the text sent to this function into the newly created array
	//I can do assignment because it is assigning a pointer (not a cstring)
	this->textArray = tempTextArray;	
}

void Text::displayText() const
{
	cout << textArray;
}

const char* Text::getText() const
{
	return textArray;
}

int Text::getLength() const
{
	return textLength;
}