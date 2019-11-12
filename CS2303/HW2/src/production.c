/*
 * production.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Sean Morrissey
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>
#include <string.h>

bool production(int argc, char* argv[])
{
	bool results = false;
	bool ok2; //for opening file
	bool done = false;
	int nRows=-1;
	int nCols = -1;
	int gens = 0; //number of generations to play
	int howManyLinesInFile = 0;
	int maximumWidth = 0;
	char filename[100];
	for(int i= 0; i<100; i++)
	{
		filename[i]='\0';
	}
	char print = 'n';
	char pause = 'n';
	//etc.
	//get the NR NC gens input [print] [pause], Usage as needed.
	if(argc<5)//not all mandatory args provided
	{
		usage();
		done=true;
	}
	else if (argc >= 7)
	{
		pause = argv[6][0];
	}
	if (!done && (argc >= 6))
	{
		print = argv[5][0];
	}

	if(!done)//must be greater than or equal to 5, so get the mandatory vals
	{

		char* ptr=0;
		long nr_l = strtol(argv[1],&ptr,10);//get the NR
		nRows = (int)nr_l;
		if(nRows<1)
		{
			printf("Usage: Rows should be greater than 0, received %d.\n",nRows);
			done = true;
		}

		//stuff missing here
		long nc_l = strtol(argv[2],&ptr,10);
		nCols = (int)nc_l;
		if(nCols<1){
			printf("Usage: Columns should be greater than 0, received %d.\n", nCols);
			done = true;
		}
		long gens_l = strtol(argv[3],&ptr,10);
		gens =(int)gens_l;
		if(gens<1){
			printf("Usage: Generations should be greater than 0, received %d", gens);
		}
		strcpy(filename, argv[4]);
		//now we have the command line
		//Let's read the input file
		FILE* fp = fopen(filename, "r"); //we try to read it
		if (fp != false)
		{//it opened, yay!
			printf("Opened %s.\n",filename);
			ok2 = true;
			//can we read the data?
			char oRow[100];
			//Let's find out how many lines there are, and
			//find out the maximum width
			bool doneReadingFile = false;
			while(!doneReadingFile)
			{
				oRow[0]='\0';
				fscanf(fp, "%s", oRow);
				if(strlen(oRow)!=0)//there was something there
				{
					howManyLinesInFile++;
					if(strlen(oRow)>maximumWidth){
						maximumWidth= strlen(oRow);
					}
					puts(oRow);
				}
				else
				{
					doneReadingFile = true;
					fclose(fp);
				}
			}
			printf("found %d lines, longest is %d characters.\n", howManyLinesInFile, maximumWidth);
		}//can read filename
		else
		{
			puts("Cannot find that file,");
			done = true;
		}
		if(!done)//if its not done, populate the arrays, read the file and begin generating
		{
			char A[nRows][nCols];
			char B[nRows][nCols];
			char C[nRows][nCols];
			char* old_p=&A[0][0];
			char* new_p=&B[0][0];
			char* other_p=&C[0][0];

			for(int row = 0; row< nRows; row++)
			{
				for(int col = 0; col<nCols; col++)
				{
					//initialize elements of A, B and C
					A[row][col] = "o";
					B[row][col] = "o";
					C[row][col] = "o";

				}
			}
			FILE* fp = fopen(filename, "r");//we read it before, we expect we can read it again
			readFileIntoArray(nRows, nCols, howManyLinesInFile,  maximumWidth, old_p, fp);

			printThis(nRows,nCols, old_p);

			int howManyGens = generate(gens,  nRows,  nCols,  old_p, new_p, other_p, print, pause);
			printf("Ran %d generations\n", howManyGens);
		}

	}//not done
	results = !done;
	return results;

}
/**
 * PlayOne carries out one generation
 * @param unsigned int nr, the number of rows in the petri dish
 * @param unsigned int nc, the number of columns in the petri dish
 * @param char* Old, the location of the upper left of starting petri dish
 * @param char* New, the location of the upper left of the ending petri dish
 * @return There is none, because results are in New array
 */
void PlayOne (unsigned int nr, unsigned int nc, char* Old, char* New)
{
	int nRows = nr;
	int nCols = nc;
	//loop over all locations in the new dish
	//figure out whether occupied or not
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			//There are three rules,
			// use occupied in old
			//use neighbors in old
			bool occupied = true;
			occupied = 	(getLetter(row,col,nCols, Old)=='x');

			if(occupied
					&&((HowManyNeighbors(row, col, nRows, nCols, Old)<2)
							|| (HowManyNeighbors(row, col, nRows, nCols, Old)>3)))
			{//Death rule
				*(New + (row * nCols) + col)='o';
			}
			else if(occupied)
			{//Survival rule
				*(New + (row * nCols) + col)='x';
			}
			else if(HowManyNeighbors(row, col, nRows, nCols, Old)==3)
			{//Birth rule
				*(New + (row * nCols) + col)='x';

			}
			else
			{
				*(New + (row * nCols) + col)='o';
			}
		}
	}
}
/**
 * Usage notifies the user of them of the correct command line input for the Game Of Life Program to work
 * @return print statement with correct format
 */
void usage(void)
{
	puts("Usage: HW2 NR NC gens input [print] [pause]");
}
/**
 * getLetter gets the specific letter at given row/column of the old array in a generation
 * @param int row, the row of the letter
 * @param int col, the column of the letter
 * @param int nCols, the amount of Columns in the array
 * @param char* Old, the array for the generation
 * @return char result, the letter at the given row/column of the old array
 */
char getLetter(int row, int col, int nCols, char* Old)
{
	return *(Old+ (row*nCols)+col);
}
/**
 * HowManyNeighbors is a helper function for calculating the number of neighbors for each cell
 * @param int row, the row of the cell
 * @param int col, the column of the cell
 * @param int nRows, the number of rows in the array
 * @param int nCols, the number of columns in the array
 * @param char* Old, the array for the function to search through
 * @return int result, the amount of neighbors for the given cell
 */
int HowManyNeighbors(int row, int col, int nRows, int nCols, char* Old)
{
	int howManyN = 0;
	//there could be as many as 8 neighbors
	//cells on an edge or corner have fewer neighbors
	//we will search for neighbors clockwise from NorthWest
	if (row>0)
	{
		if(col>0)
		{
			if(getLetter(row-1, col-1,nCols, Old)=='x')//NW
			{
				howManyN++;
			}
		}
		if(getLetter(row-1, col,nCols, Old)=='x')//N
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row-1, col+1,nCols, Old)=='x')//NE
			{
				howManyN++;
			}
		}
	}//can look north
	if(col>0)
	{
		if(getLetter(row, col-1,nCols, Old)=='x')//W
		{
			howManyN++;
		}
	}
	if(col<(nCols-1))
	{
		if(getLetter(row, col+1,nCols, Old)=='x')//E
		{
			howManyN++;
		}
	}
	if(row<nRows-1)
	{
		if(col>0)
		{
			if(getLetter(row+1, col-1,nCols, Old)=='x')//SW
			{
				howManyN++;
			}
		}
		if(getLetter(row+1, col,nCols, Old)=='x')//S
		{
			howManyN++;
		}
		if(col<(nCols-1))
		{
			if(getLetter(row+1, col+1,nCols, Old)=='x')//SE
			{
				howManyN++;
			}
		}
	}//can look south

	return howManyN;
}
/**
 * readFileIntoArray transfers the Game Of Life state from a given file into an array using pointers
 * @param int nRows, the number of rows for the given array
 * @param int nCols, the number of colunms for the given array
 * @param int howManyLinesInFile, the number of lines from the Game State file
 * @param int maximumWidth, the finite number of width for the game
 * @param char* ar_p, the array to be filled
 * @param FILE* fp, the file to be read
 * @return There is nothing to return, the function is void
 */
void readFileIntoArray(int nRows, int nCols, int howManyLinesInFile, int maximumWidth, char* ar_p, FILE* fp)
{	//loop over array
	//files each index of the array with an o
	for(int row = 0; row< nRows; row++)
	{
		for(int col = 0; col<nCols; col++)
		{
			*(ar_p+(row*nCols)+col) = 'o';

		}
	}
    //loops through file 'array'
	//when an x is found in the line of the file, it fills the corresponding spot in the array with an x
	for(int frow=0; frow< howManyLinesInFile; frow++)
	{
		char fromFile[maximumWidth];

		for(int i = 0; i<maximumWidth; i++)
		{
			fromFile[i]='o';
		}
		fscanf(fp, "%s", fromFile);
		for(int fcol=0; fcol<maximumWidth; fcol++)
		{
			if(fromFile[fcol]=='x')
			{
				int targetRow = frow+(nRows-howManyLinesInFile)/2;
				int targetCol = fcol+(nCols-maximumWidth)/2;
				*(ar_p+(targetRow*nCols)+targetCol) = 'x';
			}
		}
	}
}
/**
 * generate is the function that process a generation(s) under the rules of the game of life
 * @param int gens, the amount of generations to run
 * @param int nRows, the amount of rows in the array
 * @param int nCols, the amount of columns in the array
 * @param char* old_p, the array of the previous generation
 * @param char* new_p, the array of the next/current generation
 * @param char* other_p, the place holder array to swap pointers
 * @param char print, y/n for whether or not the generations should be printed
 * @param char pause, y/n for whether or not the program should pause between generations
 * @return int g, the amount of successful generations
 */
int generate(int gens,  int nRows,  int nCols,  char* old_p, char* new_p, char* other_p, char print, char pause)
{
	int g = 0;
	bool allOrganismsDead = false;
	bool patternRepeated = false;
	bool done = false;
	bool firstTime = true;
	//processes generations until gensDone is equal to gens or done is true
	for(int gensDone = 0; !done && (gensDone<gens); gensDone++)
	{
		if(!anyX(old_p, nRows, nCols))
		{//all organisms are dead
			allOrganismsDead =  true;
			done = true;
			puts("All organisms dead.");
			printThis(nRows, nCols, old_p);
		}
		PlayOne(nRows, nCols, old_p, new_p);
		g++;
		if(sameContent(other_p, new_p, nRows, nCols))//checks if the pattern is repeated
		{
			patternRepeated = true;
			done = true;
			puts("Pattern repeated in one generation.");
			printThis(nRows, nCols, old_p);
		}
		if(firstTime)//checks to see if this the first time the generation ran
		{
			firstTime = false;
		}
		else
		{
			if(sameContent(other_p, new_p, nRows, nCols))
			{
				patternRepeated = true;
				puts("Pattern repeated after two generations.");
				printThis(nRows, nCols, other_p);
				done= true;

			}
		}
		if(!done)//handles the "in between" of generations
		{
			if(print=='y')//if the command line mentions to print generations, do it
			{
				puts("New generation");
				printThis(nRows, nCols, new_p);
			}
			if(pause=='y')//if the command line mentions to pause between generations, do it
			{
				puts("Paused waiting for input.");
				getc(stdin);//just waits for user input
			}
			//musical chairs for the pointers, sets the old pointer to what new was, the new pointer to what it will be (other),
			//and other to the old pointer
			char* old = old_p;
			old_p = new_p;
			new_p = other_p;
			other_p = old;
		}


	}//end of generations

	return g;
}
/**
 * anyX checks whether the given array contains an x or not
 * @param char* arr, the array to be checked
 * @param int nRows, the number of rows in the array
 * @param int nCols, the number of Columns in the array
 * @return bool any, true/false if an x is present
 */
bool anyX(char* arr, int nRows, int nCols)
{
	bool any = false;
	//loops through given array, searches for a present x
	for(int row=0; !any && (row<nRows); row++)
	{
		for(int col=0; !any && (col< nCols); col++)
		{
			if(*(arr+ (row * nCols) +col) == 'x')//checks to see if the current index of arr is an x
			{
				any=true;
			}
		}
	}
	return any;
}
/**
 * sameContent is a helper function that checks to see if the contents of each given array is the same
 * @param char* one_p, the first array for comparison
 * @param char* another_p, the second array for comparison
 * @param int nRows, the number of rows for the two arrays (assuming they are the same)
 * @param int nCols, the number of columns for the two arrays (assuming they are the same)
 * @return bool same, true/false if the content of both arrays are the same
 */
bool sameContent(char* one_p, char* another_p, int nRows, int nCols)
{
	bool same = true; //for all the comparisons that have been made so far

	//loops through given arrays
	//compares one_p to another_p at each iteration, if it is not same is set to false
	//and is returned once the loop finishes
	for(int row=0; same && (row<nRows); row++)
	{
		for(int col=0; same && (col< nCols); col++)
		{
			if(*(one_p+(row*nCols)+col)!= *(another_p+(row*nCols)+col))//checks to see if the current index of one is the same as another
			{
				same=false;
			}
		}
	}
	return same;

}
/**
 * printThis prints out the given array
 * @param int nRows, the number of rows for the given array
 * @param int nCols, the number of columns for the given array
 * @param char* old_p, the array to be printed
 * @return There is nothing to be returned, the function is of type void
 */
void printThis(int nRows, int nCols, char* old_p)
{
	//loops through array
	//prints every index of the array
	for(int row=0;row<nRows;row++)
	{
		for(int col=0;col<nCols;col++)
		{
			printf("%c", *(old_p + (row * nCols) +col));
		}
		printf("\n");
	}
}
