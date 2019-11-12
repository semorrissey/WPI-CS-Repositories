/**
 * Doodlebug.h
 *
 * @author Praise Eteng
 * @author Sean Morrissey
 */

#ifndef Doodlebug_H
#define Doodlebug_H

#include "Organism.h"
#include "Grid.h"

class Doodlebug : public Organism
{

private:
    int lastAte;

public:
    static int deathCount;

    Doodlebug(int row, int col, Grid<Organism>* agridptr);

    void move(int time);
    bool isPrey();
    int getLastMeal();
    ~Doodlebug();

};

#endif
