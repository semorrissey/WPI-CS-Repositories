/**
 * Ant.cpp
 *
 * @author Praise Eteng
 * @author Sean Morrissey
 */

#include "Ant.h"

int Ant::deathCount = 0;

/**
 * Ant constructor
 * @param row The row location of this Ant in the grid
 * @param col The column location of this Ant in the grid
 * @param agridptr A pointer to the grid of all Organisms
 * @return Pointer to new Ant
 */
Ant::Ant(int row, int col, Grid<Organism>* agridptr) : Organism(row, col, agridptr)
{

}

/**
 * Attempts to move this Ant to a new grid location
 * If the Ant is alive for at least three time steps, it will attempt to breed
 * @param time The current step count
 */
void Ant::move(int time)
{
    GridCoordinate coord = findNeighbor(Empty);

    // Check if a neighbor has been found, or if this Ant has already moved
    if (coord.x == -1 || moveCount == time)
        return;

    int tempr = r;
    int tempc = c;

    r = coord.x;
    c = coord.y;

    agrid->set(r, c, this); // Move this Ant on the grid
    agrid->set(tempr, tempc, NULL);

    if (breedCount >= 3) // is the ant able to breed
    {
        Ant* newAnt = new Ant(0, 0, agrid);
        newAnt->moveCount = time;
        if (breed(newAnt))
        {
            breedCount = -1; // breedCount will be incremented to zero
        }
    }

    breedCount++;
    stepCount++;
    moveCount = time;

}

/**
 * Check if this Ant is prey
 * @return true
 */
bool Ant::isPrey()
{
	return true;
}

/**
 * Ant destructor
 */
Ant::~Ant()
{
    Ant::deathCount++;
}
