// piano.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define NUM_NOTES 8

//char key_list[] = { 'a', 's', 'd', 'f' };
//float frequency_list[] = { 261.626 ,293.665,329.628, 349.228 };

//char key_table[NUM_NOTES];
//float freq_table[NUM_NOTES];

char* key_table = NULL;
float* freq_table = NULL;

int num_keys = 0;

void initialize();
void finalize();
int  findFrequency(const char note);

float getFrequencyFromKey(char key)
{
	for (int n = 0; n < NUM_NOTES; n++)
	{
		if (key_table[n] == key)
		{
			return freq_table[n];
		}
	}

	return 0.0f;
}
void playSound(void)
{
	char ch = getch();

	Beep(getFrequencyFromKey(ch), 500);

}

//int* my_array = 0;

int main()
{
	/*const int num_data = 12;

	my_array = (int*)malloc(sizeof(int) * num_data);

	for (int i = 0; i < num_data; i++)
	{
		my_array[i] = i;
	}

	for (int i = 0; i < num_data; i++)
	{
		printf("%d\n", my_array[i]);
	}*/
	initialize();

	while (true) // while(1) without stdbool.h
	{
		const char c = (char)getch();	// input one character

		if (c == 'x') break;

		Beep(findFrequency(c), 500);
	}

	finalize();
	/*
	FILE* input_file = fopen("key_mapping.txt", "r");

	if (!input_file)
	{
		printf("File was not found.");
		exit(1);
	}

	int num_keys;
	fscanf(input_file, "%d\n", &num_keys);	// don't forget \n

	printf("%d\n", num_keys);

	key_table = (char*)malloc(num_keys);
	freq_table = (float*)malloc(sizeof(float)*num_keys);

	for (int i = 0; i < num_keys; i++)
	{
		char key;
		float freq;
		fscanf(input_file, "%c %f\n", &key, &freq);	// don't forget \n

		printf("%c %f\n", key, freq);
		key_table[i] = key;
		freq_table[i] = freq;
	}

	while (1)
	{
		playSound();

	}

	fclose(input_file);
	free(key_table);
	free(freq_table);
	*/

	return 0;
}

void initialize()
{
	FILE* input_file = fopen("key_mapping.txt", "r");

	if (!input_file)
	{
		printf("File was not found.");
		exit(1);
	}

	fscanf(input_file, "%d\n", &num_keys);	// don't forget \n

	printf("aa : %d\n", num_keys);

	// dynamically allocate memory for arrays
	key_table = (char*)malloc(num_keys);
	freq_table = (float*)malloc(sizeof(float) * num_keys);

	for (int i = 0; i < num_keys; i++)
	{
		// temporary variable to store data from a file
		char key;
		float freq;

		// read key and freq data from file
		fscanf(input_file, "%c %f\n", &key, &freq);	// don't forget \n

		// copy temporary variables to arrays
		key_table[i] = key;
		freq_table[i] = freq;

		// print key and freq to confirm data read from a file
		printf("%c %f\n", key, freq);
	}

	// don't forget to cloase files after reading file operations
	fclose(input_file);
}

void finalize()
{
	// if valid memory was allocated to this pointer
	if (key_table != NULL)
	{
		// return memory to OS
		free(key_table);

		// tag this pointer variable is NOT pointing available memory
		key_table = NULL;
	}

	// if valid memory was allocated to this pointer
	if (freq_table != NULL)
	{
		// return memory to OS
		free(freq_table);

		// tag this pointer variable is NOT pointing available memory
		freq_table = NULL;
	}
}

int  findFrequency(const char note)
{
	for (int i = 0; i < num_keys; i++)
	{
		if ((char)key_table[i] == note)
		{
			return (int)freq_table[i];
		}
	}

	return 0;
}