/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/
#include <stdlib.h>
// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
char* randString(void);
int randYear(void);
struct Employee* makeRandomEmployee(void);
struct Employee** makeRandomEmployees(size_t count);
void freeEmployees(struct Employee** e, size_t number);
void printEmployees(struct Employee** e, size_t number);
struct Employee** shallowCopy(struct Employee** e, size_t number);
struct Employee* copyEmployee(struct Employee* e);
struct Employee** deepCopy(struct Employee** e, size_t number);
