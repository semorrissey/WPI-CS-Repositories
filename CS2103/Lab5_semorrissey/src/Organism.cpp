/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"
bool amAnt = false;
/**
 * Organism::Organism() is the general constructor for the Organism object
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}
/**
 * Organism::Organism() is the general constructor for if it was called with a boolean, b.
 * @param bool b, True or False for if the organism instantiated will be an Ant
 */
Organism::Organism(bool b) {
	amAnt = b;

}
/**
 * bool Organism::isPrey() is the function that determines if the object is prey. If it is an Ant, then it is prey.
 * @return bool amAnt, If the Organism is an Ant, then it is prey. If not, then it is not.
 */
bool Organism::isPrey()
{
	return amAnt;
}
/**
 * void Organism::setAmAnt(bool b) is the function for manually setting the organism instance to be an Ant
 * @param bool b, the boolean that determines if the organism instance is an Ant or not.
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}
/**
 * Organism::~Organism() is the destructor for an Organism instance, removes the organism instance from memory
 */
Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

