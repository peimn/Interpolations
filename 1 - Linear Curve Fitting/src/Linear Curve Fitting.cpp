
/*
 * Linear Curve Fitting.cpp
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

using namespace std;

int main() {
	string line;
	int n = 0, i;
	double x[20], y[20], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
	double a, b;
	ifstream myfile;
	myfile.open("src/regdat.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			n++;
			string delimiter = "\t";
			size_t pos = 0;
			pos = line.find(delimiter);
			x[n] = atof(line.substr(0, pos).c_str());
			y[n] = atof(line.substr(pos).c_str());
		}
	}
	for (i = 0; i <= n - 1; i++) {
		sumx = sumx + x[i];
		sumx2 = sumx2 + x[i] * x[i];
		sumy = sumy + y[i];
		sumxy = sumxy + x[i] * y[i];

	}
	a = ((sumx2 * sumy - sumx * sumxy)  / (n * sumx2 - sumx * sumx) );
	b = ((n * sumxy - sumx * sumy)  / (n * sumx2 - sumx * sumx) );
	printf("\n\nThe line is Y=%3.3f +%3.3f X", a, b);
	return (0);
}
