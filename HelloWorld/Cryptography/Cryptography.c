// Cryptography.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#define MAX_STR 255

int main()
{
	char input_string[MAX_STR];

	scanf("%s", input_string);
	
	for (int i = 0; i < MAX_STR; i++)
	{
		char c = input_string[i];

		if (c == '\0') break;

		int ascii = (int)c;	// casting char to int
		int ascii_en = ascii - 3; // Caesar cipher

		if (ascii_en < 65) ascii_en += 26;

		char c_en = (char)ascii_en;

		printf("%c ", c_en);
	}

	return 0;
}

