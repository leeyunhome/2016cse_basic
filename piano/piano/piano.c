// piano.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define NUM_KEYS 4

char key_list[] = { 'a', 's', 'd', 'f' };
float frequency_list[] = { 261.626 ,293.665,329.628, 349.228 };

float getFrequencyFromKey(char key)
{
	for (int n = 0; n < NUM_KEYS; n++)
	{
		if (key_list[n] == key)
		{
			return frequency_list[n];
		}
	}

	return 0.0f;
}

void playSound(void)
{
	char ch = getch();

	Beep(getFrequencyFromKey(ch), 500);

}
int main()
{
	while (1)
	{
		playSound();

	}

	return 0;
}
