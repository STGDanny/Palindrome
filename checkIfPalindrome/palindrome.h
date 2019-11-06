/*
*	FILE			: palindrome.h
*	PROJECT			: checkIfPalindrome
*	PROGRAMMER		: Daniel Pieczewski
*	FIRST VERSION	: 2019-11-06
*	DESCRIPTION		:
*		This is a header file for palindrome.cpp
*/

#pragma once

//Function prototypes
char* reverseString(char[]);
bool checkIfPalindrome(char[], char[]);
void removeNewlines(char[]);
void convertToLowercase(char[]);
bool checkRange(int, int, int, bool);

//Constants
#define MAX_STR_SIZE 20
#define GAP_BETWEEN_CHAR_SETS 32
