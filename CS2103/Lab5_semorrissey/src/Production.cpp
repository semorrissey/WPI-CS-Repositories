/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"

int timestepsLeft=100;

/**
 * Production::Production(int argc, char* argv[]) is the general constructor for the production code.
 * Initializes the amount of steps left for the current game
 */
Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	int timestepsLeft = 100; //initialize available timesteps
}
/**
 * bool Production::runProduction() is the function for performing individual steps for all instantiated objects on the grid
 * @return bool result, returns true for if the steps succeeded
 */
bool Production::runProduction()
{
	bool result = true;
	while(timestepsLeft-- > 0)
	{
		//dbs.step;
		//ants.step;
	}
	return result;
}
/**
 * Production::~Production is the destructor for an instantiated Production object, removes the production instance from memory
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

