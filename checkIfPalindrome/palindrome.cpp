/*
*	FILE			: palindrome.cpp
*	PROJECT			: checkIfPalindrome
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2019-11-06
*	DESCRIPTION		:
*		The function(s) in this file take a string as input from the user
*		and determines whether or not it is a palindrome.
*/

#include <stdio.h>
#include <string.h>
#include "palindrome.h"



int main() {
	char originalString[MAX_STR_SIZE] = { 0 };
	char str[MAX_STR_SIZE] = { 0 };

	//Loop program infinitely
	while (true) {
		//Take user input and store it in str
		printf("\nEnter a string and I will check if it's a palindrome: ");
		fgets(str, MAX_STR_SIZE, stdin);

		//Remove all newlines from string
		removeNewlines(str);

		//Save the inputed string in a different variable so we can do calculations
		strcpy_s(originalString, str);

		//Change entire string to lowercase letters
		convertToLowercase(originalString);

		//Call checkIfPalindrome to determine result
		//If checkIfPalindrome returns true:
		if (checkIfPalindrome(originalString, reverseString(originalString))) {
			printf("\n%s is a palindrome\n", str);
		}
		//If checkIfPalindrome returns anything but true (false):
		else {
			printf("\n%s is not a palindrome\n", str);
		}
	}
	return 0;
}



/*
*	FUNCTION		: reverseString
*	DESCRIPTION		:
*		This function takes an array of char (string) and reverses the elements
*		one by one.
*	PARAMETERS		:
*		char[]		: An array (string) to reverse
*	RETURNS			:
*		char*		: Returns a pointer to a new static string == reversed str[]
*/
char* reverseString(char str[]) {
	//Set to static so it persists after the function has ended
	static char reversedString[MAX_STR_SIZE] = { 0 };

	//For every element in the array starting from the end
	//excluding the last element which is a null termination
	for (int i = (strlen(str) - 1), j = 0; i >= 0; i--, j++) {
		//Set the first element of the reversed string to the last element or str
		//effectively reversing the string
		reversedString[j] = str[i];
	}
	//Return a pointer to the reversed string
	return reversedString;
}



/*
*	FUNCTION		: checkIfPalindrome
*	DESCRIPTION		:
*		This function takes two arrays and uses strcmp to determine
*		if the strings are equal
*	PARAMETERS		:
*		char[]		: One array to compare
*		char[]		: Another array to compare
*	RETURNS			:
*		bool		: true if strcmp == 0, false otherwise
*/
bool checkIfPalindrome(char str[], char revStr[]) {
	//If the strings are equal, strcmp will return 0
	return (strcmp(str, revStr) == 0);
}



/*
*	FUNCTION		: checkRange
*	DESCRIPTION		:
*		This function takes two arrays and uses strcmp to determine
*		if the strings are equal
*	PARAMETERS		:
*		int check	: Value to check
*		int min		: Minimum of range (inclusive)
*		int	max		: Maximum of range (inclusive)
*		bool inc	: Whether or not you want to comparison to be inclusive
*					  True for inclusive, false for exclusive
*	RETURNS			:
*		bool		: true if in range, false otherwise
*/
bool checkRange(int check, int min, int max, bool inclusive) {
	//If inclusive
	if (inclusive) {
		//Return the boolean result of range calculation (inclusive)
		return (check >= min && check <= max);
	}
	//If exclusive
	else {
		//Return the boolean result of range calculation (exclusive)
		return (check > min&& check < max);
	}
}