// MonteCarloSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

double getRandomNumber(const double min, const double max);
bool isInsideCircle(const double x, const double y);
int main()
{
	FILE* of = fopen("circle.txt", "w");

	srand((unsigned int)time(NULL));

	int num_square = 0;
	int num_circle = 0;

	int test_itr = 0;
	for (int j = 0, test_itr = 1; j < 20; j++, test_itr *=2)
	{
		for (int i = 0; i < test_itr; ++i)
		{
			const double x = getRandomNumber(0, 1);
			const double y = getRandomNumber(0, 1);

			num_square++;

			if (isInsideCircle(x, y) == true)
			{
				num_circle++;

				/*printf("%f, %f\n", x, y);
				fprintf(of, "%f, %f\n", x, y);*/
			}
		}

		const double pi_est = 4.0 * (double)num_circle / (double)num_square;

		printf("%d %f\n", test_itr, pi_est);
	}


	fclose(of);

	return 0;
}

double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min) * temp;

	return temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	const double f = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) - r * r;
	
	if (f > 0.0) return false;
	else return true;
}