// Week9Digital_Image.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BMPImage.h"

//int x = 3;
//
//void updateX(int *input)
//{
//	*input = 10;
//}

int main()
{
	int res_x, res_y;

	unsigned char* rgb_array = 0;
	readBMP24("A+.bmp", &res_x, &res_y, &rgb_array);

	printf("%d %d\n", res_x, res_y);

	for (int j = res_y -1; j >= 0 ; j--)
	{
		for (int i = 0; i < res_x; i++)
		{
			unsigned char r, g, b;
			const int ix = i + res_x * j;
			r = rgb_array[ix * 3 + 0];
			g = rgb_array[ix * 3 + 1];
			b = rgb_array[ix * 3 + 2];

			if (r == 255 && g == 255 && b == 255)
			{
				printf(" ");
				rgb_array[ix * 3 + 0] = 100;
				rgb_array[ix * 3 + 1] = 232;
				rgb_array[ix * 3 + 2] = 123;
			}
			else
				printf("A");

			//const float red = rgb_array[ix * 3 + 0];
			//const float green = rgb_array[ix * 3 + 1];
			//const float blue = rgb_array[ix * 3 + 2];

			//const float gray = (red + green + blue) / 3;

			//rgb_array[ix * 3 + 0] = gray;
			//rgb_array[ix * 3 + 1] = gray;
			//rgb_array[ix * 3 + 2] = gray;
		}
		printf("\n");
	}

	writeBMP24("A+_update.bmp", res_x, res_y, rgb_array);


	//printf("%d\n", x);

	//updateX(&x);

	//printf("%d\n", x);

	//int num_size = 10;
	//float a[10][20];
	//float* b = (float*)malloc(sizeof(float) * num_size);
	///*a[0] = 1;
	//b[0] = 1;*/

	//for (int i = 0; i < num_size; i++)
	//{
	//	a[i] = i;
	//	b[i] = i;
	//}

	//free(b);
}
