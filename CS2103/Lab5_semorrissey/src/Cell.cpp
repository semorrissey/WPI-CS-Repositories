/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Sean Morrissey
 */

#include "Cell.h"

occupationStatus guest  = empty;
/**
 * Cell:Cell() is the general constructor for the cell object
 */
Cell::Cell() {

	guest = empty;
}
/**
 * bool Cell::setOccupant(occupationStatus g) checks to see if guest currently holds or will hold an Organism. Only one object can be held in a cell
 * @param occupationStatus g, this is the object type to be placed in the cell
 * @return bool result, this is a boolean for if the cell was able to be filled with the object type g
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
	if(guest==empty)
	{
		guest = g;
	}
	else
	{
		result = false;
	}
	return result;
}
/**
 * Cell::getOccupant() returns the current occupant type of the cell, if there is nothing in it, it will return 'empty'
 * @return occupationStatus guest, the object type in the current cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}
/**
 * Cell::~Cell() is the destructor for the cell object, removes the cell from memory when it does not need to be used again
 */
Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

