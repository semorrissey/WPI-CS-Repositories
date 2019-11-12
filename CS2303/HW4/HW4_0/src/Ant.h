/**
 * Ant.h
 *
 * @author Praise Eteng
 * @author Sean Morrissey
 */

#ifndef Ant_H
#define Ant_H

#include "Organism.h"
#include "Grid.h"

class Ant : public Organism
{

public:
    static int deathCount;

	Ant(int row, int col, Grid<Organism>* agridptr);

	void move(int time);
	bool isPrey();
	~Ant();

};

#endif
