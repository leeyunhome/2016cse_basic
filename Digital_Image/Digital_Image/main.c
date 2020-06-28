
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BMPImage.h"

bool isInsideCircle(const double x, const double y);

int main()
{
    int res_x, res_y;

    unsigned char* rgb_array = 0;

    readBMP24("hodu.bmp", &res_x, &res_y, &rgb_array);

    printf("%d %d\n", res_x, res_y);

    for (int j = res_y-1; j >= 0; j--)
    {
        for (int i = 0; i < res_x; i++)
        {
            unsigned char r, g, b;
            const int ix = i + j * res_x;
            r = rgb_array[ix * 3 + 0];
            g = rgb_array[ix * 3 + 1];
            b = rgb_array[ix * 3 + 2];

            //if (r == 255 && g == 255 && b == 255)
            //{
            //    //printf(" ");
            //    rgb_array[ix * 3 + 0] = 0;
            //    rgb_array[ix * 3 + 1] = 0;
            //    rgb_array[ix * 3 + 2] = 0;
            //}
            //else
            //{
            //    //printf("A");
            //}

            const float gray = (r + g + b) / 3;
            if (!isInsideCircle(i, j))
            {
                rgb_array[ix * 3 + 0] = gray;
                rgb_array[ix * 3 + 1] = gray;
                rgb_array[ix * 3 + 2] = gray;
            }
        }
        printf("\n");
    }

    writeBMP24("hodu_update.bmp", res_x, res_y, rgb_array);

    return 0;
}
bool isInsideCircle(const double x, const double y)
{
    const double x_c = 150;
    const double y_c = 150;
    const double r = 100;
    const double f = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) - r * r;

    if (f > 0.0) return false;
    else return true;
}