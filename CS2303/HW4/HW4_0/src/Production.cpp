/*
 * Production.cpp
 *
 * @author Praise Eteng
 * @author Sean Morrissey
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Production.h"

#define RED_ANSI "\033[1;31m"
#define RESET_ANSI "\033[0m"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int argcount;
char** argval;

/**
 * Move either predators or prey
 * @param g The grid of organisms
 * @param time the current time step
 * @param prey the boolean of whether or not to move the prey or predator
 */
bool Production::move(Grid<Organism>* g, int time, bool prey) {
	bool encounteredALife = false;
	bool encounteredDLife = false;
	for (int i = 0; i < g->width(); i++) {
		for (int j = 0; j < g->height(); j++) {

			//i,j is the x,y coordinate of the current organism

			Organism* o = g->get(i,j);
			if (o != 0) {
				if (o->isPrey()) encounteredALife = true;
				if (!o->isPrey()) encounteredDLife = true;

				if (prey == o->isPrey()) {
					o->move(time);
				}
			}
		}
	}
	return encounteredALife && encounteredDLife;
}

/**
 * Print the organism grid
 * @param grid A grid of organisms
 */
void Production::printOrganismGrid(Grid<Organism>* grid) {
	for (int i = 0; i < grid->width(); i++) {
		for (int j = 0; j < grid->height(); j++) {
			//i,j is the x,y coordinate of the current organism
			if (grid->get(j,i) != 0) {
				if (grid->get(j,i)->isPrey()) {
					cout<<" o";
				} else {
					cout<<" x";
				}
			} else {
				cout<<"  ";
			}

		}
		cout<<endl;
	}
	cout<<endl;
}
Production:: Production(int argc, char** argv){
	argcount = argc;
	argval = argv;
}
bool Production::runProduction() {
	bool result = true;
	int gridSize = 20;
	int doodleBugCount = 5;
	int antCount = 100;
	int timeSteps = 100;
	int pause = 0;

	//parse the arguments
	switch (argcount) {
	case 7:
		pause = atoi(argval[6]);
		/* no break */
	case 6:
		srand(atoi(argval[5]));
		/* no break */
	case 5:
		timeSteps = atoi(argval[4]);
		/* no break */
	case 4:
		antCount = atoi(argval[3]);
		/* no break */
	case 3:
		doodleBugCount = atoi(argval[2]);
		/* no break */
	case 2:
		gridSize = atoi(argval[1]);
		/* no break */
	case 1:
		//No argument case
		break;
	default:
		cerr <<"[Error]: Incorrect usage."<<endl
		<<"         Usage: ./PA5 gridSize #doodlebugs #ants #time_steps seed pause."<<endl
		<<"         All parameters are optional." << endl;
		return false; //EXIT FAILURE
	}



	//Check that the parameters make sense...
	if (gridSize*gridSize < (doodleBugCount + antCount)) {
		cerr <<"[Error]: Invalid arguments"<<endl
				<<"         Too many organisms for the grid!"<<endl;
		return -1; //EXIT FAILURE
	}



	//Make the grid
	Grid<Organism> g(gridSize, gridSize);



	//Fill the grid
	int* indices = (int*) malloc(gridSize*gridSize*sizeof(int)); //serial index array representing every square in the grid
	for (int i = 0; i < gridSize*gridSize; i++)
		indices[i] = i;

	std::random_shuffle(&indices[0], &indices[gridSize*gridSize]); //shuffle the squares

	int j = 0;
	for (int i = 0; i < antCount; i++) {
		int col = indices[j] % gridSize; // get the column from the serialized index
		int row = (indices[j++] - (col)) / gridSize; //get the row from the serialized index

		g.set(col, row, new Ant(col, row, &g)); //place in the new random index order
	}

	for (int i = 0; i < doodleBugCount; i++) {
		int col = indices[j] % gridSize;
		int row = (indices[j++] - (col)) / gridSize;

		g.set(col, row, new Doodlebug(col, row, &g));
	}



	//print the initial board state
	puts("[Intial Board State]");
	printOrganismGrid(&g);



	//Simulation
	int time;
	bool earlyEnd = false;
	for (time = 1; time < timeSteps+1; time++) {

		//time is the current time step

		bool a = move(&g, time, false);
		bool b = move(&g, time, true);
		if (!a || !b) {
			earlyEnd = true;
			break;
		}

		if(pause && !(time % pause)) {
			printf("[Time step %d]\n", time);
			printOrganismGrid(&g);
			puts( "Press Enter to Continue");
			cin.ignore();
		}
	}
	if (!earlyEnd)
		time--; //wind back the clock to be at the last time step



	//Count up the number of ants and doodlebugs
	int ants = 0;
	int doodle = 0;
	for (int i = 0; i < g.width(); i++) {
		for (int j = 0; j < g.height(); j++) {

			//i,j is the x,y coordinate of the current organism

			Organism* o = g.get(i,j);
			if (o != 0) {
				if (o->isPrey()) {
					ants++;
				} else {
					doodle++;
				}
			}
		}
	}


	//print stats
	puts("[STATISTICS]");
	puts( "====================");
	printf(" Simulation ran for %d of %d time steps.\n", time, timeSteps);
	if(earlyEnd)
		puts("   (Simulation ended early due to all of the ants or doodlebugs dying)");
	puts(" (Simulation completed after specified time)");

	printf(" Total simulated ants: %d\n", Ant::deathCount + ants);
	printf(" Total remaining ants: %d\n", ants);
	printf(" Total simulated doodlebugs: %d\n", Doodlebug::deathCount + doodle);
	printf(" Total remaining doodlebugs: %d\n", doodle);
	puts(" Final Board:");

	printOrganismGrid(&g);
	return result;
}

/**
 * Destructor for production object
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

