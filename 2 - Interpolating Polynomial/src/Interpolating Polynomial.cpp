/*
 * Interpolating Polynomial.cpp
 *
 *  Created on: Feb 27, 2015
 *      
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


//float **x;

int main()

{

	float n, l[2], R, a, x[2][2];

int i, j;

	n = 2;


//	x = (float**) malloc(((n + 1) * 2) * 4);
//
//	l = (float*) malloc(n * 4);


	x[0][0] = 2;
	x[0][1] = 4;

	x[1][0] = 6;
		x[1][1] = 3;

	a = 3.7;


	for (i = 0; i < n; i++)

	{

		l[i] = 1;

		for (j = 0; j < n; j++)

		{

			if (i != j)

				l[i] *= (a - x[j][0]) / (x[i][0] - x[j][0]);

		}

	}

	R = 0;

	for (i = 0; i < n; i++)

	{

		R += l[i] * x[i][1];

	}

	printf("Result=%f", R);


	return (0);

}
