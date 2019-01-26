/*
 * Newton's Interpolation.cpp
 *
 *  Created on: Feb 27, 2015
 *      
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#include<algorithm>
#include<iterator>


double function(double pointsx[], double pointsy[], int k) {
	double value;
	float *dnum = new float[k];

	for (int l = 0; l <= k; l++) {
		dnum[l] = 1;
		for (int j = 0; j <= k; j++) {
			if (l != j)
				dnum[l] *= pointsx[l] - pointsx[j];
		}
		value += pointsy[l] / dnum[l];

	}

	return value;
}

int main() {

	int points = 0;
	double *points_arrayx;
	double *points_arrayy;
	double *polynomial;

	points_arrayx = new double[10];
	points_arrayy = new double[10];

	std::string line;
	std::ifstream myfile;
	myfile.open("src/n.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			points++;
			std::string delimiter = "\t";
			size_t pos = 0;
			pos = line.find(delimiter);
			points_arrayx[points] = atof(line.substr(0, pos).c_str());
			points_arrayy[points] = atof(line.substr(pos).c_str());
		}
	}

	double value;
	double *f = new double[points];
	f[0] = points_arrayy[0];

	for (int kk = 1; kk < points; kk++) {
		value = function(points_arrayx, points_arrayy, kk);
		f[kk] = value;
		//	cout<<f[kk]<<endl;
	}

// Allocation of temp
	double **temp;

	temp = new double*[points];
	for (int l = 0; l < points; l++)
		temp[l] = new double[points];

	for (int l1 = 0; l1 < points; l1++) {
		for (int l2 = 0; l2 < points; l2++) {
			temp[l1][l2] = 0;
		}
	}
	temp[0][0] = f[0];
	temp[1][0] = -1 * points_arrayx[0];
	temp[1][1] = 1;

//Multiplying  of x terms
	if (points > 2) {
		double a[2];
		a[0] = -1 * points_arrayx[1];
		a[1] = 1;
		int p = 1;
		for (int k = 2; k < points; k++) {
			for (int i = 0; i <= p; i++) {
				for (int j = 0; j <= 1; j++) {
					temp[k][i + j] += temp[k - 1][i] * a[j];
				}
			}
			p++;
			a[0] = -1 * points_arrayx[p];
		}
	}

// Making polynomial
	for (int i2 = 1; i2 < points; i2++) {
		for (int j2 = 0; j2 < points; j2++) {
			temp[i2][j2] *= f[i2];
		}
	}

	polynomial = new double[points];
	for (int p1 = 0; p1 < points; p1++)
		polynomial[p1] = 0;

	for (int x = 0; x < points; x++) {
		for (int y = 0; y < points; y++) {
			polynomial[x] += temp[y][x];
		}
	}

	std::cout << "\n\n\nThe Required Polynomial By Newton Interpolation  is : \n\n\n"
			<< std::endl;
	std::cout << "P(X) = ";
	for (int j1 = points - 1; j1 >= 0; j1--) {
		if (polynomial[j1] > 0)
			std::cout << "+" << polynomial[j1] << "X^" << j1;
		else
			std::cout << polynomial[j1] << "X^" << j1;
	}

	return (0);

}

