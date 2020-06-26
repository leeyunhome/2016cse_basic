// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        printf("Arg %d = %s\n", i, argv[i]);
    }

    return 0;
}
