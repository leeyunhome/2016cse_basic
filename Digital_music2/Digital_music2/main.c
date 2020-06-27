
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#pragma comment (lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>

#define NUM_MAX_NOTES 1000

char notes[NUM_MAX_NOTES];
int length[NUM_MAX_NOTES];

void playSound(char note);
void record();
void replay();

int main()
{
    // prepare for recording
    for (int n = 0; n < NUM_MAX_NOTES; n++) notes[n] = '\0'; // initialize notes array
    for (int n = 0; n < NUM_MAX_NOTES; n++) length[n] = 0; // initialize lengths (of corresponding notes) array

    printf("Start recording\n");

    record();

    printf("End recording\n\n");

    printf("Start replaying\n");

    replay();

    printf("End replaying\n");
}

void playSound(char note)
{
    switch (note)
    {
    case 'a':
        printf("C-25 ");
        PlaySound(TEXT("sound_files/25.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;
    case 's':
        printf("D-27 ");
        PlaySound(TEXT("sound_files/27.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;
    case 'd':
        printf("E-29 ");
        PlaySound(TEXT("sound_files/29.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'f':
        printf("F-30 ");
        PlaySound(TEXT("sound_files/30.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'g':
        printf("G-32 ");
        PlaySound(TEXT("sound_files/32.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'h':
        printf("A-34 ");
        PlaySound(TEXT("sound_files/34.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'j':
        printf("B-36 ");
        PlaySound(TEXT("sound_files/36.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'k':
        printf("C-37 ");
        PlaySound(TEXT("sound_files/37.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'w':
        printf("C#-26 ");
        PlaySound(TEXT("sound_files/26.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'e':
        printf("D#-28 ");
        PlaySound(TEXT("sound_files/28.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;
    
    case 't':
        printf("F#-31 ");
        PlaySound(TEXT("sound_files/31.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'y':
        printf("G#-33 ");
        PlaySound(TEXT("sound_files/33.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    case 'u':
        printf("A#-35 ");
        PlaySound(TEXT("sound_files/35.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        break;

    }
}

void record()
{
    int current_ix = 0; // array index to save (store) pressed key
    int time_temp = (int)timeGetTime();

    while (true) // while (1)
    {
        char input_character;
        input_character = (char)getch();

        int current_time = (int)timeGetTime();
        int elapsed_time = current_time - time_temp; // milli seconds

        notes[current_ix] = input_character; // sotre input character (note)

        if (current_ix > 0)
        {
            length[current_ix - 1] = elapsed_time;  // store length of the note
            printf("%dms ", elapsed_time); // ms = milli second
        }

        current_ix++;

        time_temp = current_time;

        if (input_character == 13)
        {
            printf("\n");
            return; // stop recording when Enter was pressed
        }

        playSound(input_character);
    }
}

void replay()
{
    // play notes stored in notes[] array
    // stop playing when recorded note is NULL character \0.
    // Sleep during the recorded time!
    for (int i = 0; i < NUM_MAX_NOTES; ++i)
    {
        if (notes[i] == '\0') break;
        playSound(notes[i]);
        Sleep(length[i]);
    }
    
}