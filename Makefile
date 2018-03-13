#this is a comment

all		:	Movies

Movies	:	Driver.o Movie.o Movies.o Text.o
			g++ -o Movies.exe Driver.o Movie.o Movies.o Text.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
Driver.o	:	Driver.cpp
			g++ -I ./ -c Driver.cpp
				
Movie.o		:	Movie.cpp
			g++ -I ./ -c Movie.cpp
			
Movies.o	:	Movies.cpp
			g++ -I ./ -c Movies.cpp
			
Text.o		:	Text.cpp
			g++ -I ./ -c Text.cpp

clean	:	Movies.exe
			del *.o 
			del Movies.exe