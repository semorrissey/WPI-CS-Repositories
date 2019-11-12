/**
 * Organism.h
 *
 * @author Praise Eteng
 */

#ifndef Organism_H
#define Organism_H

#include "Grid.h"

class Organism
{

protected:
	int stepCount;
	int breedCount;
	int moveCount;
	int r;
	int c;

	bool breed(Organism* org);

	Grid<Organism>* agrid;

public:
	Organism(int row, int col, Grid<Organism>* agridptr);

	enum NeighborType {Empty, Doodlebug, Ant};
	GridCoordinate findNeighbor(NeighborType type);

	virtual void move(int time) = 0;
	virtual bool isPrey() = 0;
	virtual ~Organism() = 0;

};

#endif
