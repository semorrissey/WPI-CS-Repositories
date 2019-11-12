/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Sean Morrissey
 */

#include "Ant.h"
/**
 * Ant::Ant() is the general constructor in the case that nothing is passed in when the ant object is created
 */
Ant::Ant()
//:Organism(true)
{

}
/**
 * Ant::Ant(int r, int c) is the constructor in the case that a row and col is passed in,
 * this means the ant will be placed on the grid at the cell located in (r,c)
 */
Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
}
/**
 * bool Ant::move() is a function that returns a boolean value for whether or not the ant has completed a valid move
 * @return bool status, returns true if a move is able to be made, false otherwise
 */

bool Ant::move()
{
	bool status = true;
	return status;
}
/**
 * bool Ant::breed() is a function for the status of breeding for this ant object instance
 * @return bool status, returns true for when breeding occurs from the function call, false otherwise
 */
bool Ant::breed()
{
	bool status = true;
	return status;
}
/**
 * Ant::~Ant() is a destructor for the ant object, it removes the current ant instance from memory
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

