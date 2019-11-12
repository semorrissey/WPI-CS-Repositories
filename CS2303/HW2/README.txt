CS2303 HW2
Starter code and test cases provided by Professors Ciaraldi and Smith

HW2 is an implementation of Conway's Game Of Life

An explination of the game can be found at : https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

The game of life is instantiated using an 'old', 'new', and 'other' array to display the game board for every generation.
Methods, readFileIntoArray and production, transfer the content from the input file to these arrays to begin the game.
playOne and generate handle the bulk of the game by processing generations according to the game's rules.
Helper functions including anyX, sameContent, HowManyNeighbors, and printThis work in conjunction with 
playOne and generate to make the game function.


The program should be invoked and ran from the command line using the following:
	./HW2 NR NC gens inputfile [print] [pause]

NR and NC are integers that represent the rows and columns of the Game Of Life Board
gens is an integer that represents the generations to be ran
inputfile should be a file path to a text file consisting of a grid of x's and o's and should be located alongside the excecutable
[print] is a character 'y' or 'n' for whether or not the program prints out every generation to the console
[pause] is a character 'y' or 'n' for whether or not the program pauses between every generation; the program is continued with a key press