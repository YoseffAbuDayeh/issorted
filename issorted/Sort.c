#include <stdio.h>
#include <stdlib.h>
//return of 1 means that it is ordered correctly. return of 2 means it isn't correct.

int correctInt(char** aroar, int size)
{
	size = size - 1; // Subtracting 1 so that the loop doesn't go out of bounds
	for (int i = 0; i < size;i++)
	{
		int num1 = atoi(aroar[i]); // atoi obtains a string and returns the number inside the string.
		int num2 = atoi(aroar[i + 1]);
		if (num1 > num2)
		{
			return i + 2; // If it's not ordered correctly then it will return the index where there was an issue
		}
	}
	return 0;
} 

int correctReal(char** aroar, int size)
{
	size = size - 1;
	for (int i = 0; i < size;i++)
	{
		double num1 = atof(aroar[i]); // atof is the same as atoi but for float values
		double num2 = atof(aroar[i + 1]);
		if (num1 > num2)
		{
			return i + 2;
		}
	}
	return 0;
}

int correctNatural(char** aroar, int size)
{
	size = size - 1;
	for (int i = 0; i < size;i++)
	{
		double num1 = atof(aroar[i]); // If I use atoi then it will truncate the number giving the wrong number
		double num2 = atof(aroar[i + 1]);
		if (ceil(num1) != floor(num1) || ceil(num2) != floor(num2))
		{
			return -1; //This makes sure that the number isn't a float rather an integer.
		}

		if (num1 > num2)
		{
			return i + 2;
		}
	}
	return 0;
}

int correctLines(char** aroar, int size)
{
	size = size - 1;
	for (int i = 0; i < size;i++)
	{
		char *line1 = aroar[i]; // Gets the string from the array
		char *line2 = aroar[i + 1];
		if (strcmp(line1, line2) > 0) // Compares them to see if they are in the correct order.
		{
			return i+2;
		}
	}
	return 0;
}

int correctStrings(char** aroar, int size)
{
	size = size - 1;
	for (int i = 0; i < size;i++)
	{
		char* word1 = aroar[i];
		char* word2 = aroar[i + 1];
		int result = strcmp(word1, word2);
		if (result > 0)
		{
			return i + 2;
		}
	}
	return 0;
}