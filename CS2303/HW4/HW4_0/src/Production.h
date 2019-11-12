/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include "Grid.h"
#include "Organism.h"
class Production {

public:
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();
	void createGrid();
	bool move(Grid<Organism>* g, int time, bool prey);
	void printOrganismGrid(Grid<Organism>* grid);
};

#endif /* PRODUCTION_H_ */
