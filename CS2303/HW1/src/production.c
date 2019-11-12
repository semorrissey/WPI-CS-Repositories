/*
 * production.c
 *
 *  Created on: Nov 3, 2018
 *      Author: Sean Morrissey
 *      @author Student's name goes here
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include <math.h>

/** Your production code goes in this function.
 *
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return true if Program was able to print a calendar.
 *         false if User entered bad input.
 */

bool production(int argc, char* argv[])
{
	bool results = false;
	bool done = false;
	//get the year, Usage as needed.
	int year = -1;
	puts("CALENDAR");
	if(argc<2)
	{
		puts("Enter a year");
		scanf("%d",&year);
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	else
	{
		char* ptr=0;
		long year_l = strtol(argv[1],&ptr,10);
		year = (int)year_l;
		if(year<1752)
		{
			printf("Usage: Year should be greater than 1751, received %d.\n",year);
			done = true;
		}
	}
	if(!done)
	{
		const char *months[] = {"January", "February", "March", "April", "May","June", "July",\
				"August", "September", "October", "November", "December"};
		int monthsSize[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int leapYear = is_leap_year(year);

		//print calendar; begins with a for loop for printing every month 1 at a time
		for(int currentMonth = 0; currentMonth<12; currentMonth++){
			//checks if Feb is a leap year for the current year, changes if necessary
			if(currentMonth == 1 && leapYear == 1)
				monthsSize[1] = 29;
			//print the month name
			printf("%s\n", months[currentMonth]);
			//print the days of the week text
			puts("Sun  Mon  Tue  Wed  Thu  Fri  Sat");
			//print the weeks

			int firstDay = calculate_day_of_week(1,currentMonth, year);
			int day = firstDay;

			//prints the necessary spaces so that the first day appears in the correct place in the console
			for(int j = 0; j<firstDay; j++){
				printf("     ");
			}

			// prints every single day relative to the placement of the first day,
			//h being the day 1-31 of the days in the month
			for(int h = 1; h<= monthsSize[currentMonth]; h++){
				//checks to see if the current day, 0 to 6, is a Saturday (6) and if it is not the last day of the month
				if(day% 7 == 6 && h != monthsSize[currentMonth]){
					//print a newline to start the next week, reset the day to Sunday (0)
					printf("%3d\n",h);
					day = 0;
				}else{
					//checks if the current day is the last day of the month, if so ignore adding a newline,
					//if not then place the day number normally
					if(h == monthsSize[currentMonth])
						printf("%3d", h);
					else
						printf("%3d  ", h);
					day++;
				}
			}
			printf("\n");
		}
	}
	if(!done)
	{
		results=true;
	}
	return results;
}

/** Calculates how many days are in a given month for a given year.
 * @param year The year we are checking.
 * @param month The month we are checking. Range 0 through 11, where January = 0.
 * @return Day of the week. Range 0 through 6, where Sunday = 0.
 *         -1 if invalid input (e.g., year < 1752, month out of range).
 */
int calculate_days_in_month(int year, int month)
{
	//checks if a proper year and month was entered
	if(year < 1752 || !(month >= 0) || !(month <= 11))
		return -1;
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	//checks if its a leap year; if its not, return the proper number of days
	if(is_leap_year(year) && month == 1)
		return 29;
	return months[month];
}
/** Test if a given year is a leap year or not.
 * @param year The year we are testing
 * @return 1 if it is a valid leap year.
 *         0 if a valid year, but not a leap year.
 *        -1 if not a valid year (i.e. before the calendar rule changed in 1752).
 */

int is_leap_year(int year)
{
	//checks if the year is correct, accounts for the case that the year is 1752
	if(year <= 1752){
		if(year == 1752)
			return 1;
		return -1;
	}
	//
	else if ((year % 4 ==0 && year % 100 !=0) || year % 400 == 0){
		return 1;
	}
	else{
		return 0;
	}

}
/** Determines what day of the week a particular date falls on.
 * @param day Day of the month, counting from 1.
 * @param month Range 0 through 11, where January = 0.
 * @param year The year.
 * @return -1 for invalid input (e.g., year < 1752, month out of range,
 *            day < 1 or > appropriate for that month & year
 *         0 through 6, where Sunday = 0.
 *
 */
int calculate_day_of_week(int day, //first day of month is 1
		int month, //uses 0 for January
		int year)
{//invalid input gets a -1 answer
	//initial to check to see if given parameters are valid
	if(!(day>=1) || !(day<=31) || !(month>=0) || !(month <=11)|| year < 1752)
		return -1;

	//initialize the day, year, front of year, back of year and month variables for formula
	int d;
	int y;
	int c;
	int m;
	int w;

	//front
	c = year / 100;
	//back
	y = year % 100;

	//handles if the year is something like two thousand and the month is jan or feb
	//by subtracting 1 from the front of the year and setting the back to 99
	if(month == 0 || month == 1){
		if(y == 0){
			y=99;
			c--;
		}
		else
			y--;
	}

	d = day;

	//an array that handles the month shift for making march first and feb last
	int shiftedM[12] = {11,12,1,2,3,4,5,6,7,8,9,10};
	m = shiftedM[month];

	//computation of the formula
	w  =((int) (d+floor(2.6*m -0.2)+ y + floor(y/4) + floor(c/4)-2*c)%7);

	//handles if result is off (negative)
	if(w < 0)
		return w+7;
	else
		return w;
}

