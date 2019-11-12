/*
 * tests.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Sean Morrissey
 */
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strncmp

bool tests(void)
{
	bool results=false;
	puts("During tests");
	bool ok1 = testReadInput();
	if(ok1)puts("Found and read the test file.");
	bool ok2 = testMakeArrays();
	if(ok2)puts("Was able to allocate the arrays ok.");
	bool ok3 = testPlayOne();
	if(ok3)puts("playOne is ok.");
	bool ok4 = testCountNeighbors();
	if(ok4)puts("HowManyNeighbors is ok.");
	bool ok5 = testAnyX();
	if(ok5)puts("anyX is ok.");
	bool ok6 = testSameContent();
	if(ok6)puts("sameContent is ok.");
	bool ok7 = testBlinker();
	if(ok7)puts("blinker is ok.");
	bool ok8 = testGlider();
	if(ok8)puts("glider is ok.");
	puts("end of tests");
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	printf("tests returning %d.\n",results);
	return results;
}
/**
 * testReadInput is function for testing the file input of production.c
 * @return bool results, true/false for whether or not the test passed
 */
bool testReadInput(void)
{
	//the plan is:
	//create a file
	//make sure it can be opened.
	//try a file that should not exist
	//check that we notice it does not exist

	bool results = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	//Here goes: create a file
	FILE* fp;
	fp = fopen("/tmp/LifeInput.txt", "w"); //we write it first for later reading
	if (fp != false)
	{//it opened, yay!
		//file containing a sequence of lines,
		//each consisting of a sequence of 'x' and 'o' characters,
		//indicating the occupied and unoccupied cells
		//of the initial configuration, e.g.
		//oxo
		//xox
		//xox
		//oxo
		int w1 = fprintf(fp, "oxo\n");//returns the number of chars excluding null
		int w2 = fprintf(fp, "xox\n");
		int w3 = fprintf(fp, "xox\n");
		int w4 = fprintf(fp, "oxo\n");
		if ((w1 == w2) && (w2 == w3) && (w3 == w4) && (w4 == 4))
		{
			ok1 = true;
		}
		fclose(fp);
	}
	fp = fopen("/tmp/LifeInput.txt", "r"); //we try to read it
	if (fp != false)
	{//it opened, yay!
		ok2 = true;
		//can we read the correct data?
		char oRow[4]; //test case, we know a string of 3 chars terminated by null

		//printf("First row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))//0 means match
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Second row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Third row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Fourth row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))
		{//got the right data
			ok3 = true;
		}
	}
	results = ok1 && ok2 && ok3;
	return results;
}
/**
 * testMakeArrays tests that the arrays used for performing the Game of Life are created and populated correctly
 * @return bool results, true/false for whether or not the test passed
 */
bool testMakeArrays(void)
{
	bool results = false;
	bool ok1 = false;
	//we need to allocate and populate arrays
	//In this test case we set our arrays to 4 rows x3 columns
	int nRows = 4;
	int nCols = 4;
	char boardBefore[4][4]={
			{'o','x','o','\0'},
			{'x','o','x','\0'},
			{'x','o','x','\0'},
			{'o','x','o','\0'}
	};

	char boardAfter[nRows][nCols];
	//here's the test
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			boardAfter[row][col]=boardBefore[row][col];
		}
	}
	ok1 = true;
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if (boardAfter[row][col]!=boardBefore[row][col])
			{
				ok1=false;
			}
		}
	}

	results = ok1;
	return results;
}
/**
 * testPlayOne tests to see if playOne works as intended
 * @return bool results, true/false for whether or not the test passed
 */
bool testPlayOne(void)
{
	bool results = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	//test 1
	int nRows = 4;
	int nCols = 3;
	char boardBefore[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};


	char boardAfter[nRows][nCols];
	//here's the invocation
	PlayOne(nRows, nCols, (char*)boardBefore, (char*)boardAfter);
	//here's the check
	ok1 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfter[row][col]!=boardBefore[row][col])
			{//error found
				ok1 = false;
			}
		}
	}

	//test 2
	nCols = 8;

	//test case from myTest1.txt
	char boardBeforeTwo[4][8] = {
			{'o','o','o','o','o','o','o','o'},
			{'o','o','o','o','x','o','o','o'},
			{'o','o','o','x','x','o','o','o'},
			{'o','o','o','o','o','o','o','o'}
	};
	char boardAfterCheck[4][8] = {
			{'o','o','o','o','o','o','o','o'},
			{'o','o','o','x','x','o','o','o'},
			{'o','o','o','x','x','o','o','o'},
			{'o','o','o','o','o','o','o','o'}
	};

	char boardAfterTwo[nRows][nCols];

	PlayOne(nRows, nCols, (char*)boardBeforeTwo, (char*)boardAfterTwo);

	ok2 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfterTwo[row][col]!=boardAfterCheck[row][col])
			{//error found
				ok2 = false;
			}
		}
	}

	//test 3

	//test case from myTest2.txt
	char boardBeforeThree[4][8] = {
			{'o','o','o','o','o','o','o','o'},
			{'o','o','o','x','o','x','o','o'},
			{'o','o','o','x','x','x','o','o'},
			{'o','o','o','o','o','o','o','o'}
	};
	char boardAfterCheckTwo[4][8] = {
			{'o','o','o','o','o','o','o','o'},
			{'o','o','o','x','o','x','o','o'},
			{'o','o','o','x','o','x','o','o'},
			{'o','o','o','o','x','o','o','o'}
	};

	char boardAfterThree[nRows][nCols];

	PlayOne(nRows, nCols, (char*)boardBeforeThree, (char*)boardAfterThree);

	ok3 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfterThree[row][col]!=boardAfterCheckTwo[row][col])
			{//error found
				ok3 = false;
			}
		}
	}

	results = ok1 && ok2 && ok3;
	return results;

}
/**
 * testCountNeighbors makes sure HowManyNeighbors works as intended
 * @return bool results, true/false for whether or not the test passed
 */
bool testCountNeighbors(void)
{
	bool results = false;
	bool ok1 =false;
	bool ok2 =false;
	bool ok3 =false;
	bool ok4 =false;

	//create test board
	char testBoard[4][3] ={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};

	//checks the cell at (0,1)
	if(HowManyNeighbors(0,1,4,3,(char*)testBoard) == 2)
		ok1 = true;
	//checks the cell at (0,0)
	if(HowManyNeighbors(0,0,4,3,(char*)testBoard) == 2)
		ok2 = true;
	//checks the cell at (4,3)
	if(HowManyNeighbors(4,3,4,3,(char*)testBoard) == 0)
		ok3 = true;
	//checks the cell at (2,1)
	if(HowManyNeighbors(2,1,4,3,(char*)testBoard) == 5)
		ok4 = true;

	results = ok1 && ok2 && ok3 && ok4;
	return results;
}
/**
 * testAnyX checks to see if anyX works as intended
 * @return bool results, true/false for whether or not the test passed
 */
bool testAnyX(void){
	bool results = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	//creates a test board
	char testBoard[4][3] ={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};

	//checks for an x at (4,3) (the corner)
	if(anyX((char*)testBoard, 4,3))
		ok1 = true;
	//checks for an x at (2,2) (side of the board)
	if(anyX((char*)testBoard, 2,2))
		ok2 = true;
	//checks for an o at (0,0) (corner)
	if(!anyX((char*)testBoard, 0,0))
		ok3 = true;

	results = ok1 && ok2 && ok3;
	return results;
}
/**
 * testSameContent checks to see if sameContent works as intended
 * @return bool results, true/false for whether or not the test passed
 */
bool testSameContent(void){
	bool results = false;
	bool ok1 = false;
	bool ok2 = false;

	//creates 3 boards to check against each other
	char board[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};
	char correctBoard[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};
	char incorrectBoard[4][3]={
			{'o','x','o'},
			{'x','x','x'},
			{'x','x','x'},
			{'o','x','o'}
	};
	//checks to see if the correct board and original are the same
	if(sameContent((char*)board, (char*)correctBoard, 4, 3))
		ok1 = true;
	//checks to see if the original board and incorrect board are the same
	if(!sameContent((char*)board, (char*)incorrectBoard, 4, 3))
		ok2 = true;

	results = ok1 && ok2;
	return results;
}
/**
 * testBlinker makes sure that the entire Game Of Life program works for the non-trivial case, blinker
 * @return bool results, true/false for whether or not the test passed
 */
bool testBlinker(void){
	//if the code in this function runs with the given generations, then the test case passes
	//taken from starter code for testing
	int nRows = 10;
	int nCols = 10;
	int gens = 40;
	char print = 'n';
	char pause = 'n';

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
	FILE* fp = fopen("/home/semorrissey/Downloads/HW2/blinker.txt", "r");
	readFileIntoArray(nRows, nCols, 3, 3, old_p, fp);

	int howManyGens = generate(gens,  nRows,  nCols,  old_p, new_p, other_p, print, pause);
	printf("Ran %d generations\n", howManyGens);
	return true;
}
/**
 * testGlider makes sure that the entire Game Of Life program works for the non-trivial case, glider
 * @return bool results, true/false for whether or not the test passed
 */
bool testGlider(void){
	//if the code in this function runs with the given generations, then the test case passes
	//taken from starter code for testing
	int nRows = 10;
	int nCols = 10;
	int gens = 40;
	char print = 'n';
	char pause = 'n';

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
	FILE* fp = fopen("/home/semorrissey/Downloads/HW2/glider.txt", "r");
	readFileIntoArray(nRows, nCols, 3, 3, old_p, fp);

	int howManyGens = generate(gens,  nRows,  nCols,  old_p, new_p, other_p, print, pause);
	printf("Ran %d generations\n", howManyGens);
	return true;
}
