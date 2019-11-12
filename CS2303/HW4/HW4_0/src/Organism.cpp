/**
 * Organism.cpp
 *
 * @author Praise Eteng
 * @author Sean Morissey
 */

#include "Organism.h"
/**
 * Creates a new Organism
 * NOTE: Organism is abstract and cannot be directly instantiated
 * @param xcoord The column location of this Organism in the grid
 * @param ycoord The row location of this Organism in the grid
 * @param gridpointer A pointer to the grid of all Organisms
 * @return Pointer to new Organism
 */
Organism::Organism(int row, int col, Grid<Organism>* agridptr)
{
	stepCount = 0;
	breedCount = 0;
    moveCount = -1;
	r = row;
	c = col;
	agrid = agridptr;
}

/**
 * Find the neighbor organism base on given organisms
 *
 * @param type Type of adjacent space to look for
 * @return the coordinate to a random found cell or (-1, -1) if no cell found
 */
GridCoordinate Organism::findNeighbor(NeighborType type) {

	struct GridCoordinate g[4];
	int g_idx = 0;

	for (int i = r-1; i <= r+1; i++) {
		for (int j = c-1; j <= c+1; j++) {

			//i,j is the x,y coordinate of the current organism

			//check valid coords and if not the cell itself and not diagonals
			if (i >= 0 && j >= 0 && i < agrid->width() && j < agrid->height() && !((r == i)&&(c == j)) && (r == i || c == j)) {

				Organism* org = agrid->get(i,j);
				//Check candidacy for a matching neighbor
				if ((type==Empty && org == 0) || (org != 0 && ((org->isPrey() && type==Ant) || (!org->isPrey() && type==Doodlebug)))) {

					struct GridCoordinate coord;
					coord.x = i;
					coord.y = j;
					g[g_idx++]=coord;
				}
			}
		}
	}
	if (g_idx == 0) {
		struct GridCoordinate fakeCoord;
		fakeCoord.x = -1;
		fakeCoord.y = -1;
		return fakeCoord;
	}
	return g[rand()%(g_idx)];
}

/**
 * Attempts to breed this Organism
 * @param org The newly bred Organism
 * @return true if this Organism has successfully bred, false otherwise
 */
bool Organism::breed(Organism* org)
{
    GridCoordinate coord = findNeighbor(Empty);

    if (coord.x == -1)
    {
        delete org;
        return false;
    }

    org->r = coord.x;
    org->c = coord.y;
    agrid->set(org->r, org->c, org);

    return true;
}

Organism::~Organism() {
	//stub
}

