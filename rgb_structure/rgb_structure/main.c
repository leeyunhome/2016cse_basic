
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BMPImage.h"
#include <stdbool.h>
#include <assert.h>

RGB getPixelColor(const RGB* rgb_array, const int res_x, const int res_y, int i, int j)
{
    // repeating boundary
    if (i < 0) i += res_x;
    if (j < 0) j += res_y;

    i = i % res_x;
    j = j % res_y;

    const int ix = i + res_x * j;

    assert(ix >= 0);
    assert(ix < res_x* res_y);

    return rgb_array[ix];
}

int main()
{
    int res_x, res_y;

    //unsigned char* rgb_array = NULL;
    RGB* rgb_array = NULL;

    readBMP24("sample.bmp", &res_x, &res_y, &rgb_array);

    RGB* rgb_temp = (RGB*)malloc(sizeof(RGB) * res_x * res_y);
    
    for (int j = 0; j < res_y; j++)
    {
        for (int i = 0; i < res_x; i++)
        {
            rgb_temp[i + res_x * j] = getPixelColor(rgb_array, res_x, res_y, i + res_x/2, j + res_y/2);
        }
    }
    writeBMP24("output1.bmp", res_x, res_y, rgb_temp);

    free(rgb_array);
    free(rgb_temp);
    return 0;
}
