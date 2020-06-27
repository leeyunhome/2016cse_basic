// piano.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define NUM_NOTES 8

//char key_list[] = { 'a', 's', 'd', 'f' };
//float frequency_list[] = { 261.626 ,293.665,329.628, 349.228 };

//char key_table[NUM_NOTES];
//float freq_table[NUM_NOTES];

char* key_table;
float* freq_table;

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

int* my_array = 0;

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

	return 0;
}
