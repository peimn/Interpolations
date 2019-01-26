/*
 * Lagrange interpolation.cpp
 *
 *  Created on: Feb 27, 2015
 *      
 */




#include<iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <assert.h>
#define MaxN 90
using namespace std;
int main()
{
 float arr_x[MaxN+1], arr_y[MaxN+1], numerator, denominator, x, y=0;
 int i, j, n=0;

 string line;
 	ifstream myfile;
 	myfile.open("src/n.txt");
 	if (myfile.is_open()) {
 		while (getline(myfile, line)) {
 			n++;
 			std::string delimiter = "\t";
 			size_t pos = 0;
 			pos = line.find(delimiter);
 			arr_x[n] = atof(line.substr(0, pos).c_str());
 			arr_y[n] = atof(line.substr(pos).c_str());
 		}
 	}
 cout<<"Enter the value of x: ";
 cin>>x;

 for (i=0; i<=n; i++)
 {
  numerator=1;
  denominator=1;
  for (j=0; j<=n; j++)
   if(j!=i)
   {
    numerator *= x-arr_x[j];
    denominator *= arr_x[i]-arr_x[j];
   }
  y+=(numerator/denominator)*arr_y[i];
 }
 cout<<x<<", "<<y;
return (0);
}
