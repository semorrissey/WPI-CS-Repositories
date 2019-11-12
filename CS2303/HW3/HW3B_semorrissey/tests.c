/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Sean Morrissey
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

#define MAX_NAME (99)

bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	printf("\n");

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	printf("\n");

	bool ok3 = testRandString();
	if(ok3){
		puts("randString() passed.");
	}

	printf("\n");

	bool ok4 = testRandYear();
	if(ok4){
		puts("randYear() passed.");
	}

	printf("\n");

	bool ok5 = testMakeRandomEmployee();
	if (ok5) {
		puts("makeRandomEmployee() passed.");
	}

	printf("\n");

	bool ok6 = testMakeRandomEmployees();
	if (ok6) {
		puts("makeRandomEmployees() passed.");
	}

	printf("\n");

	bool ok7 = testPrintEmployees();
	if (ok7) {
		puts("printEmployees() passed.");
	}

	printf("\n");

	bool ok8 = testShallowCopy();
	if(ok8){
		puts("shallowCopy() passed.");
	}

	printf("\n");

	bool ok9 = testFreeEmployees();
	if(ok9){
		puts("freeEmployees() passed.");
	}

	printf("\n");

	bool ok10 = testDeepCopy();
	if(ok10){
		puts("deepCopy() passed.");
	}

	printf("\n");

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known structure and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/** Tests the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}

/** Tests the randString() function by printing out a random string ,that is only printable characters, produced by the function.
 * @return true. The only way to tell if it succeeds is to look at the output for the employee that is made.
 */
bool testRandString(){
	//creates an employee structure to test the function on,
	//creates a start year then calls randYear() until it produces a year greater than the start year
	struct Employee* randomE;
	int startYear = randYear();
	int endYear = randYear();
	char* name = randString();
	while(endYear < startYear){
		endYear = randYear();
	}
	randomE = makeEmployee(startYear, endYear, name);
	printEmployee(randomE);

	return true;
}


/** Tests the randYear() function by printing out a random year between 1940 and 1999.
 * @return result. Returns true only if the year is between 1940 and 1999, can tell if it worked also by looking at output of created employee.
 */
bool testRandYear(){
	int year = randYear();
	bool ok1 = false;
	//tests to see if the function creates a year in a reasonable time frame, thus being 1940-1999
	if(year >= 1940 && year <= 1999){
		printf("%d\n", year);
		ok1 = true;
	}

	//creates an employee structure to test the function on,
	//creates a start year then calls randYear() until it produces a year greater than the start year
	struct Employee* randomE;
	int startYear = randYear();
	int endYear = randYear();
	char* name = randString();
	while(endYear < startYear){
		endYear = randYear();
	}
	randomE = makeEmployee(startYear, endYear, name);
	printEmployee(randomE);


	bool result = ok1;
	return result;
}
/**
 * Tests the function makeRandomEmployee() by creating an employee using the function the outputting it to the console.
 * Also tests the function by having it create an array of 4 random employees.
 * @return true. The only way to tell if it worked is by looking at the output.
 */
bool testMakeRandomEmployee(){
	struct Employee* randEmployee = makeRandomEmployee();
	printEmployee(randEmployee);

	return true;
}

/**
 * Tests the function makeRandomEmployees() by having it create an array of 4 random employees.
 * @return true. The only way to tell if it worked is by looking at the output.
 */
bool testMakeRandomEmployees(){
	size_t count = 4;
	struct Employee** randEmployeeArray = makeRandomEmployees(count);
	for(int i = 0; i<4; i++){
		printEmployee(*(randEmployeeArray + i));
	}
	return true;

}

/**
 * Tests the function printEmployees() by having it print an array of 4 random employees.
 * @return true. The only way to tell if it worked is by looking at the output.
 */
bool testPrintEmployees(){
	size_t count = 4;
	struct Employee** randEmployeeArray = makeRandomEmployees(count);
	printEmployees(randEmployeeArray, count);
	return true;

}
/**
 * Tests the function shallowCopy() by creating an array of 4 random employees and comparing to original to the copy
 * @return true. only returns true if the two arrays are the same.
 */
bool testShallowCopy(){

	size_t count = 4;
	struct Employee** employeeArray = makeRandomEmployees(count);
	struct Employee** employeeArrayCopy = shallowCopy(employeeArray, count);

	for(int i = 0; i<4;i++){
		//compares the employee structures for each index of each array, need to be the samee
		if(!(*(employeeArray+i) == *(employeeArrayCopy+i))){
			return false;
		}
	}
	printf("The original array\n");
	printEmployees(employeeArray, count);
	printf("\nThe copied array\n");
	printEmployees(employeeArrayCopy, count);

	return true;

}

/**
 * Test the function freeEmployees() by creating an array of 4 random employees and calling the function on it
 * @return true. returns true if the function call works without errors
 */
bool testFreeEmployees(){
	size_t count = 4;
	struct Employee** employeeArray = makeRandomEmployees(count);
	freeEmployees(employeeArray, count);
	return true;
}

/**
 * Tests the function deepCopy() by creating an array of 4 random employees and calling the function on it, compares all parts of the employee structure
 * @return true. return true if all parts of the employee structure from the original and copy are the same
 */
bool testDeepCopy(){
	size_t count = 4;
	struct Employee** employeeArray = makeRandomEmployees(count);
	struct Employee** employeeArrayDeep = deepCopy(employeeArray, count);

	//checks to see if all the birth years are the same
	for(int i= 0; i<count;i++){
		if(!(employeeArray[i]->birth_year == employeeArrayDeep[i]->birth_year)){

			return false;
		}
	}

	//checks to see if all the start years are the same
	for(int j= 0; j<count;j++){
		if(!(employeeArray[j]->start_year == employeeArrayDeep[j]->start_year)){

			return false;
		}
	}

	//checks to see if all the names are the same

	//create variables for the names located in the original array and copy
	char* originalName;
	char* copiedName;
	for(int k= 0; k<count;k++){
		//fills respective name strings with the current employee name to be checked
		originalName = employeeArray[k]->name;
		copiedName = employeeArrayDeep[k]->name;
		//first checks if they are the same length
		if(strlen(originalName)!= strlen(copiedName))
			return false;
		//loops through each string comparing them character by character
		for(int l = 0; l<strlen(originalName);l++){
			if(!(*(originalName+l) == *(copiedName+l))){
						return false;
					}
		}
	}

	//prints both arrays to check to see if they are the same
	printf("The original array\n");
	printEmployees(employeeArray, count);
	printf("\nThe deep copied array\n");
	printEmployees(employeeArrayDeep, count);

	return true;
}
