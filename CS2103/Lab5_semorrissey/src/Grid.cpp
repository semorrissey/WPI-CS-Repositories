/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;

/**
 * Grid::Grid is the general constructor for the Grid object, calls the constructor again with a default value
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}
/**
 * Grid::Grid(int nSquaresOnASide) is the general constructor if an integer for grid size is passed through.
 * It initializes and allocates an array of cells of size nSquaresOnASide
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
}
/**
 * bool Grid::setCellOccupannt(int r, int c, occupationStatus g) is the function for set the occupant object of a cell
 * @return bool , return true or false depending on whether the function succeeded on placing the object into the cell
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}
/**
 * occupationStatus Grid::getCellOccupant(int r, int c) is the function for retrieving the occupant type placed in a given cell (r,c)
 * @param int r, the row of the location to be viewed
 * @param int c, the column of the location to be viewed
 * @return occupationStatus, the object type that is in the location (r,c). Can be an Ant, Doodlebug or empty.
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}
/**
 * Grid::~Grid() is the destructor for an instance of a Grid object, removes the Grid instance from memory
 */
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

