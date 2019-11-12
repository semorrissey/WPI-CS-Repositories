/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* e = (struct Employee*) malloc( sizeof(struct Employee));
	if(e == NULL)
		return NULL;

	e->birth_year = birth;
	e->start_year = start;
	strcpy(e->name, name);
	return e;
}

/** Prints the information of the given employee object; their birth year, starting year and name
 * @param struct Employee *e, the employee whose information is to be printed to the console
 * @return void
 */
void printEmployee(struct Employee *e) {
	printf("Birth year = %d\n", e->birth_year);
	printf("Starting year = %d\n", e->start_year);
	printf("Name = %s\n", e->name);
}

/**
 * Creates a "first name" and " last name" of 10 random lowercase letters separated by a space, the
 * last of which is terminated by a null-terminator.
 * @return  22 character array as defined by the function description
 */
char* randString(void) {
	char* allocatedString = (char*) malloc(sizeof(char) * 22);
	char* result = allocatedString;
	for (int i = 0; i < 10; i++) { //i is used to repeat 10 times for the "first name"
		//*allocatedString is the pointer to the current index being filled in the string.
		*allocatedString++ = (char)(rand() % 26) + 'a';
	}
	*allocatedString++ = ' '; //add a space
	for (int j = 0; j < 20; j++) { //j is used to repeat 10 times for the "last name"
		//*allocatedString is the pointer to the current index being filled in the string.
		*allocatedString++ = (char)(rand() % 26) + 'a';
	}
	*allocatedString = '\0'; //add a null terminator to the end
	return result;
}

/**
 * Create an integer year between 1940 and 1999
 * @return an integer between 1940 and 1999
 */
int randYear(void) {
	return rand() % 60 + 1940;
}


/**
 * Makes a random employee
 * @return Pointer to employee structure.
 */
struct Employee* makeRandomEmployee(void) {
	int yearOne = randYear();
	int yearTwo = randYear();
	if (yearOne < yearTwo) {
		//checks to see which year is greater yearOne or yearTwo
		// the greater of the two is used for the start year, the least is used for the birth year
		return makeEmployee(yearOne, yearTwo, randString());
	} else {
		return makeEmployee(yearTwo, yearOne, randString());
	}

}

/**
 * Make an array of random employees defined by a given size parameter, count.
 * @param count The number of employees to make
 * @return The pointer to the first element of the array of created random employees
 */
struct Employee** makeRandomEmployees(size_t count) {
	struct Employee** allocatedE = (struct Employee**) malloc(sizeof(struct Employee*) * count);
	struct Employee** result = allocatedE;
	while (count-- > 0) {
		//*out is the current employee being created
		*allocatedE++ = makeRandomEmployee();
	}
	return result;
}

/**
 * Free an array of employees
 * @param e Employee array
 * @param n Length of employee array
 */
void freeEmployees(struct Employee** e, size_t n) {
	for(int i = 0; i < n; i++) {
		//e[i] is the employee to be freed
		free(e[i]);
	}
	free(e);
}

/**
 * Print an employee array
 * @param e Employee array
 * @param n Length of employee array
 */
void printEmployees(struct Employee** e, size_t n) {
	for(int i = 0; i < n; i++) {
		//e[i] is the employee to be printed
		printf("#%d:\n", i + 1);
		printEmployee(e[i]);
	}
}

/**
 * Creates a shallow copy of an employee array. A Shallow copy of an employee array is a new array of employee pointers that
 * uses the same pointers from the original array. There is no structure duplication.
 * @param e Employee array
 * @param number Length of employee array
 * @return shallow copy of employee array
 */
struct Employee** shallowCopy(struct Employee** e, size_t n) {
	struct Employee** allocatedE = (struct Employee**) malloc(sizeof(struct Employee*) * n);
	struct Employee** result = allocatedE;
	while (n-- > 0) {
		// n is the number of employees left to copy,
		// *allocatedE is the current place in the array to copy into
		// *e is the current place in the array to copy from
		*allocatedE++ = *e++;
	}
	return result;
}

/**
 * Copy an employee structure
 * @param e Employee to copy
 * @return A pointer to a duplicate, but different employee from the one passed in.
 */
struct Employee* copyEmployee(struct Employee* e) {
	return makeEmployee(e->birth_year, e->start_year, e->name);
}

/**
 * Creates a deep copy of an employee array.
 * A deep copy of an employee array is a new array of employee pointers to new Employee structures that contain
 * the same values for their birth year, start year and name as the original array.
 * @param e Employee array to copy
 * @param n Length of employee array
 * @return deep copy of employee array
 */
struct Employee** deepCopy(struct Employee** e, size_t n) {
	struct Employee** allocatedE = (struct Employee**) malloc(sizeof(struct Employee*) * n);
	struct Employee** result = allocatedE;
	while (n-- > 0) {
		//n is the number of employees left to copy,
		//*allocatedE is the current place in the array to copy into
		//*e is the current place in the array to make a duplicate of then copy to allocatedE
		*allocatedE++ = copyEmployee(*e++);
	}
	return result;
}
