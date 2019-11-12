/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>

/**
 * Tests2::Tests2() is the general constructor for the Test object, it begins by initializing a grid.
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}
/**
 * bool Tests2::doTests() is a function for performing the test functions defined in this source code file.
 * @return bool results, returns true for all the test functions passing, will return false for one failing
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10;
	return results;
}
/**
 * bool Tests2::gridTest() is a function for testing a Grid object.
 * It checks to see if the cells are empty when initialized and if an ant organism is placed correctly into a cell
 * @return bool result, returns true if all cases passes. If not, it returns false.
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}
/**
 * bool Tests2::makeAntsTest() is a test function that checks to see if the ant object is functioning correctly. It checks to see
 * If an ant is able to be placed onto a cell on the grid, in both using the constructor and the grid's native function of placing objects.
 * Also checks to see if other organism objects are not able to be placed on top of it.
 * @return bool result, returns true if all cases pass, false if any of them fail.
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}
/**
 * bool Tests2::antMoveTest() is a test function for seeing if the Ant object's move function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::antsMoveTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = false;
	std::cout << "Running the move ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(1,2);
	bool ok3 = false;
	bool couldMove = a1->move();
	//tests to see if the ant was able to move whatsoever
	if(couldMove)
		std::cout << "Ant was able to move"<< std::endl;
	//tests to see if there is even the possibility for the ant to move to any position up, down, left, or right
	else if(myGrid_p->getCellOccupant(1, 1)!= empty && myGrid_p->getCellOccupant(1, 3)!= empty
			&& myGrid_p->getCellOccupant(0, 2)!= empty && myGrid_p->getCellOccupant(2, 2)!= empty)
	{
		if(!ok3){
			std::cout << "Ant cannot move" << std::endl;
			ok2 = true;
		}
	}

	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2 && ok3;
	return result;
}
/**
 * bool Tests2::antBreedTest() is a test function for seeing if the Ant object's breed function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::antsBreedTest()
{
	// possible test cases include: checking to see if breeding works for every adjacent square,
	//if it is able to choose an open space at random, if it does not replace  filled cells when breeding, checking if the cool down works
	//This test case will rely on the amount of open cells there are in a given grid and being able to check the status for breeding.
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}
/**
 * bool Tests2::antDieTest() is a test function for seeing if the Ant object's destructor function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::antsDieTest()
{
	//possible test cases for include: when the ant is near 1 or more doodlebugs that could eat it, a different test case for amount of
	//doodlebugs or different positions.
	//testing to see if the destructor works on its own and not in the case that an ant is eaten by a doodlebug
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}
/**
 * bool Tests2::makeDoodlesTest() is a test function for seeing if the Doodlebug object is initialized correctly
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::makeDoodlesTest()
{
	//possible test cases include: creating doodlebugs ontop of other organisms, placing it in an open space or in corners, and
	//making the doodlebug in an arbitrary location
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}
/**
 * bool Tests2::doodleMoveTest() is a test function for seeing if the Doodlebug object's move function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::doodleMoveTest()
{
	//possible test cases include: normal movement (no ants near it), an ant in any possible movement locations (up, down, left, right),
	// and moving while a doodlebug is near by
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}
/**
 * bool Tests2::doodleBreedTest() is a test function for seeing if the Doodlebug object's breed function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::doodleBreedTest()
{
	//posible test cases include : testing that it is able to breed in eight turns, making sure that starvation has priority over breeding,
	//checking to see if it does not breed when there is no room for it, and testing that the cool down for breeding works.
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}
/**
 * bool Tests2::doodleEatTest() is a test function for seeing if the Doodlebug object's eat function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::doodleEatTest()
{
	//possible test cases include: testing starvation by making sure the doodlebug dies in three turns using an empty grid, testing that it can eat an ant regardless of location
	//(up, down, left, right)
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
/**
 * bool Tests2::doodleDieTest() is a test function for seeing if the Doodlebug object's destructor function works as intended
 * @return bool result, returns true if all cases pass, returns false if any of them fail
 */
bool Tests2::doodleDietest()
{
	//possible test cases: testing again that starvation works, making sure the doodlebug is removed from the grid regardless of location
	//can test various locations on a grid with various amounts of doodlebugs to see if they end up being removed as anticipated (in three time steps)
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}
/**
 * Tests2::~Tests2() is the destructor for an instance of the Tests2 object, removes the object from memory
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

