/*
*	FILE			: standardize.cpp
*	PROJECT			: checkIfPalindrome
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2019-11-06
*	DESCRIPTION		:
*		The function(s) in this file take a string as input from the user
*		and standardize it for use in palindrome.cpp
*/

#include <stdio.h>
#include <string.h>
#include "palindrome.h"



/*
*	FUNCTION		: removeNewlines
*	DESCRIPTION		:
*		This function takes an array and looks for a '\n'
*		if it finds one it will change it to a null termination
*	PARAMETERS		:
*		char[]		: An array to remove '\n' from
*	RETURNS			:
*		void		: void
*/
void removeNewlines(char str[]) {
	//For every element in the string...
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
		}
	}
}



/*
*	FUNCTION		: convertToLowercase
*	DESCRIPTION		:
*		This function takes an array and looks for uppercase letters
*		if it finds one it will change it to it's lowercase equivalent.
*		This is done to make strcmp and checkIfPalindrome work correctly
*	PARAMETERS		:
*		char[]		: An array to remove uppercase letters from
*	RETURNS			:
*		void		: void
*/
void convertToLowercase(char str[]) {
	//For every element in the string...
	for (unsigned int i = 0; i < strlen(str); i++) {
		//If the letter is an uppercase letter:
		if (checkRange(str[i], 'A', 'Z', true)) {
			//Change the value to lowercase by jumping between char sets
			str[i] += GAP_BETWEEN_CHAR_SETS;
		}
	}
}