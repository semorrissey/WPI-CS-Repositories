/*
 * mystring.c
 *
 *  Created on: Jan 24, 2019
 *      Author: Sean Morrissey
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = mystrlen2(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		mystrcpy(newstr, s);
	}
	return newstr;
}
/**
 * Duplicates a character string of up to size size in characters into a freshly-allocated block of memory
 * @param str the string to duplicate
 * @return Pointer to the new string.
 * 		   NULL if unable to allocate memory, errno holds the error code
 */
char* mystrndup(const char *str, size_t size){

	size_t length = mystrlen2(str)-size;
	char* newstr = (char*) malloc(length+1);
	if(newstr){
		mystrcpy(newstr, str);
	}
	return newstr;

}
/**
 * Copies a given string char by char into a string destination
 * @param char* dest the string of which src will be copied into
 * @param char* src the string to be copied
 * @return the copied string
 */
char* mystrcpy(char* dest, char* src) {
	char* temp = dest;

	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return temp;
}

/*
 * Copies the first n characters from the source to the destination string
 * @param char* dest pointer to the destination array where the content will be copied
 * @param char* src the string to be copied
 * @param size_t n the maximum amount of characters to be copied
 * @return the destination is returned
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char* temp = dest;
	for(int i = 0; i<n; i++){
		*dest++ = *src++;
	}

	return temp;
}
/**
 * Combines the first n of src to the dest with a null-terminating character.
 * If the length of src is less than n, then only the content up to the null terminating character is copied.
 * @param char* dest pointer to the destination character array, should be big enough to hold the concatenated string and null terminating character
 * @param char* src string to be appended
 * @param size_t n  maximum number of characters to be appended
 * @return the destination is returned
 */
char* mystrncat(char* dest, char* src, size_t n) {
	  char *temp = dest;
	    while (*dest)
	        dest++;
	    while (n--)
	        if (!(*dest++ = *src++))
	            return temp;
	    *dest = 0;
	    return temp;
}
/**
 * Combines the string pointed by src to the end of the string pointed by dest
 * @param char* dest pointer to the destination character array, should be big enough to hold concatenated string
 * @param char* src the string to be appended
 * @return the destination is returned
 */
char* mystrcat(char *dest, const char *src){
	char* temp = dest;
	while(*dest)
		dest++;
	while(*dest++ == *src++);
	return temp;
}

