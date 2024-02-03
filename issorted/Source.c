#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"


int main(int argc, char* argv[])
{
	int sortOrNot = 9;
	char** aroar = NULL; //Declares a 2D array/pointer so that later it can be cleared
	char input[100]; // Declares which will contain the input inserted by the user
	int counter = 0; // Counts how many words/lines/numbers the User inputs
	if (argc == 1)
	{
		while (scanf("%s", input) != EOF) // Grabs input until the user typed the End Of File character.
		{ //It needs 3 control Z to quit which I think is fine since the demo also needed 3 control Zs
			counter++; //Add 1 to the size of the input
			aroar = realloc(aroar, counter * sizeof(char*)); //Resizes the array so that it we can add 1 Input
			if (aroar == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE; // If there isn't enough memory then it will say so and stop.
			}

			aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char)); // Gets some memory to add the string form user
			if (aroar[counter - 1] == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}
			strcpy(aroar[counter - 1], input);
			// Saves the string from the user to the array of strings so we can later use it. 
		}
		int result = correctStrings(aroar, counter); //Calls the method from the sort.c file
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else
		{
			printf("element %d (%s) not sorted\n", result, aroar[1]);
			sortOrNot = 0;
		}
		//Prints an output message similar to the one in the demo.
		for (int i = 0; i < counter; i++) {
			free(aroar[i]); //Frees the strings inside the array
		}
		free(aroar); // Frees the array itself
		if (sortOrNot == 1)
		{
			return 101;
		}
		else if (sortOrNot == 0)
		{
			return 100;
		}
	}
	if (strcmp(argv[1], "-i") == 0)
	{
		while (scanf("%s", input) != EOF)
		{ 
			counter++;
			aroar = realloc(aroar, counter * sizeof(char*));
			if (aroar == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}

			aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
			if (aroar[counter - 1] == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}
			strcpy(aroar[counter - 1], input);

		}
		int result = correctInt(aroar, counter); 
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else
		{
			printf("element %d (%s) not sorted\n", result, aroar[1]);
			sortOrNot = 0;
		} // Using 1 instead of result since when the pointer 'advances' then it's new default is to when it 'advances'
	}
	else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
	{
		printf("issorted 1.0.0 (c) 2023, Yoseff Abu Dayeh\n==========================================\n");
		printf("usage: issorted [(-(n|i|r|s|l|h))|--help] [filename]\n\n\t-n\tsort natural numbers\n\t-i\tsort integers numbers\n\t-r\tsort real numbers\n\t-s\tsort strings(default)\n\t-l\tsort lines\n\t-h\tdisplay help\n\n\t--help display help\n\n\tfilename\toptional stream source (default is stdin)\n");
		return EXIT_SUCCESS;
	}
	else if (strcmp(argv[1], "-r") == 0)
	{
		while (scanf("%s", input) != EOF)
		{
			counter++;
			aroar = realloc(aroar, counter * sizeof(char*));
			if (aroar == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}

			aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
			if (aroar[counter - 1] == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}
			strcpy(aroar[counter - 1], input);

		}
		int result = correctReal(aroar, counter);
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else
		{
			printf("element %d (%s) not sorted\n", result, aroar[1]);
			sortOrNot = 0;
		}
	}
	else if (strcmp(argv[1], "-n") == 0)
	{
		while (scanf("%s", input) != EOF)
		{
			counter++;
			aroar = realloc(aroar, counter * sizeof(char*));
			if (aroar == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}

			aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
			if (aroar[counter - 1] == NULL) {
				printf("Error: memory allocation failed.\n");
				return EXIT_FAILURE;
			}
			strcpy(aroar[counter - 1], input);

		}
		int result = correctNatural(aroar, counter);
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else if (result == -1)
		{
			printf("Error: file does not contain natural numbers\n");
			sortOrNot = EXIT_FAILURE;
		} //unlike the other modes this one can get a number that is not expected. if it gets that then it will print so
		else 
		{
			printf("element %d (%s) not sorted\n", result,aroar[1]);
			sortOrNot = 0;
		}
	}
	else if (strcmp(argv[1], "-l") == 0) 
	{
		char letter;
		int i =0;
		while ((letter = getchar()) != EOF)
		{// Gets one character at a time. Finishes when the user inputs one control Z
			if (letter == '\n')
			{ // Once it finds a newline characters it ads the input string to the array.
				input[i] = '\0'; // adds the end of line character to the end of the line.
				counter++;
				aroar = realloc(aroar, counter * sizeof(char*));
				if (aroar == NULL) {
					printf("Error: memory allocation failed.\n");
					return EXIT_FAILURE;
				}

				aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
				if (aroar[counter - 1] == NULL) {
					printf("Error: memory allocation failed.\n");
					return EXIT_FAILURE;
				}
				strcpy(aroar[counter - 1], input);
				for (int x = 0;x <= i;x++ )
				{
					input[x] = '\0'; //Empties the string so we can use it again.
				}
				i = 0;// Sets the index to 0 so we start counting from 0 and not 1.
			}
			else
			{ // If the string doesn't have a newline characters it concatenates it to the string and increases I symbolizing the character in the string
				input[i] = letter;
				i++;
			}
		}
		int result = correctLines(aroar, counter);
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else
		{
			printf("element %d (%s) not sorted\n", result, aroar[1]);
			sortOrNot = 0;
		}
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
	while (scanf("%s", input) != EOF)
	{
		counter++;
		aroar = realloc(aroar, counter * sizeof(char*));
		if (aroar == NULL) {
			printf("Error: memory allocation failed.\n");
			return EXIT_FAILURE;
		}

		aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
		if (aroar[counter - 1] == NULL) {
			printf("Error: memory allocation failed.\n");
			return EXIT_FAILURE;
		}
		strcpy(aroar[counter - 1], input);

	}
	int result = correctStrings(aroar, counter);
	if (result == 0)
	{
		printf("sorted\n");
		sortOrNot = 1;
	}
	else
	{
		printf("element %d (%s) not sorted\n", result, aroar[1]);
		sortOrNot = 0;
	}
	}
	else
	{
		if (argv[1][0] == '-')
		{
			printf("ERROR: invalid switch."); // Makes sure that the user isn't here because they misspelled something
			return EXIT_FAILURE;
		}
		char letter;
		int i = 0;
		FILE* stream = fopen(argv[1], "rb"); // Opens the file.
		if (stream == NULL)
		{
			printf("Error, file not found\n");
			return EXIT_FAILURE; // If it can't find it then it says that it's not found
		}
		while ((letter = fgetc(stream)) != EOF)
		{ // Starts reading from the file.
			if (letter == '\n')
			{// Same logic as before with the line
				input[i] = '\0';
				counter++;
				aroar = realloc(aroar, counter * sizeof(char*));
				if (aroar == NULL) {
					printf("Error: memory allocation failed.\n");
					return 1;
				}

				aroar[counter - 1] = malloc((strlen(input) + 1) * sizeof(char));
				if (aroar[counter - 1] == NULL) {
					printf("Error: memory allocation failed.\n");
					return 1;
				}
				strcpy(aroar[counter - 1], input);
				for (int x = 0;x <= i;x++)
				{
					input[x] = '\0';
				}
				i = 0;
			}
			else
			{
				input[i] = letter;
				i++;
			}
		}
		int result = correctStrings(aroar, counter);
		if (result == 0)
		{
			printf("sorted\n");
			sortOrNot = 1;
		}
		else
		{
			printf("element %d (%s) not sorted\n", result, aroar[1]);
			sortOrNot = 0;
		}
	}
	for (int i = 0; i < counter; i++) 
	{
		free(aroar[i]);
	} //Frees the strings inside the array
	free(aroar); // Frees the array itself.
	if (sortOrNot == 1)
	{
		return 101;
	}
	else if (sortOrNot == 0)
	{
		return 100;
	}
}
