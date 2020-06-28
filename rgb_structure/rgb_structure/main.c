
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BMPImage.h"
#include <stdbool.h>
#include <assert.h>
 
int main()
{
    int res_x, res_y;

    //unsigned char* rgb_array = NULL;
    RGB* rgb_array = NULL;

    readBMP24("sample.bmp", &res_x, &res_y, &rgb_array);

    writeBMP24("output.bmp", res_x, res_y, rgb_array);

    return 0;
}
