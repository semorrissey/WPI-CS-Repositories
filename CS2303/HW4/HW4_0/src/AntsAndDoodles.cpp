//============================================================================
// Name        : Ants.cpp
// Author      : Therese building on Ciaraldi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Production.h"

class Production;


int main(int argc, char* argv[])
{//gridSize #doodlebugs #ants #time_steps seed pause
	std::cout << "!!!Hello the classmates, it's time for fun with C++!!!" << std::endl;
	if(argc > 7){
		puts("Usage: Too many arguments were passed through to the command Line!");
		puts("./PA5 gridSize #doodlebugs #ants #time_steps seed pause");
		return 1;

	}
	Production ps = Production(argc, argv);
	bool ok = ps.runProduction();
	if(ok)
	{
		puts("Production worked.");
	}
	else
	{
		puts("Production did not work.");
	}
	ps.~Production(); //done with production


	return 0;
}
