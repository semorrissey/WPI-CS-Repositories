/**
 * Doodlebug.cpp
 *
 * @author Praise Eteng
 * @Author Sean Morrissey
 */

#include "Doodlebug.h"

int Doodlebug::deathCount = 0;

/**
 * Doodlebug Constructor
 * @param row The row location of this Doodlebug in the grid
 * @param col The column location of this Doodlebug in the grid
 * @param agridptr A pointer to the grid of all Organisms
 * @return Pointer to new Doodlebug
 */
Doodlebug::Doodlebug(int row, int col, Grid<Organism>* agridptr) : Organism(row, col, agridptr)
{
	lastAte=0;
}

/**
 * Attempts to move a Doodlebug
 * If Doodlebug survives for at least 8 timesteps, it will attempt to breed
 * @param time The current timestep
 */
void Doodlebug::move(int time)
{
    GridCoordinate coord = findNeighbor(Ant);

    if (coord.x == -1) // prioritize ant cells over Empty cells
    {
        coord = findNeighbor(Empty);
        // // Check if a neighbor has been found, or if this Doodlebug has already moved
        if (coord.x == -1 || moveCount == time)
            return;
    } else {
        delete agrid->get(coord.x, coord.y); // "eat" the Ant
        lastAte = -1; // will be incremented to 0
    }

    lastAte++;

    int tempr = r;
    int tempc = c;

    r = coord.x;
    c = coord.y;

    agrid->set(r, c, this); // move Doodlebug on grid
    agrid->set(tempr, tempc, NULL);

    if (lastAte >= 3) // starvation logic
    {
        agrid->set(r, c, NULL);
        delete this; // seppuku
        return;
    }

    if (breedCount >= 8) // attempt to breed
    {
        Doodlebug* newBug = new Doodlebug(0, 0, agrid);
        newBug->moveCount = time;
        if (breed(newBug))
        {
            breedCount = -1; // will be deincremented to 0
        }
    }

    breedCount++;
    stepCount++;
    moveCount = time;
}

/**
 * Check if this Doodlebug is prey
 * @return false
 */
bool Doodlebug::isPrey()
{
    return false;
}

/**
 * Gets the last time this Doodlebug ate
 * @return last timestep this Doodlebug ate
 */
int Doodlebug::getLastMeal()
{
    return lastAte;
}

/**
 * Doodlebug destructor
 */
Doodlebug::~Doodlebug()
{
    Doodlebug::deathCount++;
}
