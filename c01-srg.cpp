// Smart Meter Random Generator.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "iostream"
#include "fstream"

using namespace std;


int main(int argc, char* argv[])
{
	int n = 0;
	int seed = 0;
	int R = 0;
	int max_dis = 0;

	int cln = atoi(argv[1]);
	int cls = atoi(argv[2]);
	int clr = atoi(argv[3]);
	int clmd = atoi(argv[4]);

	n = cln;
	seed = cls;
	R = clr;
	max_dis = clmd;

	srand(seed);
	ofstream matlab_file;
	ofstream xs_file;
	ofstream ys_file;
	ofstream n_file;
	xs_file.open("xs.txt");
	ys_file.open("ys.txt");
	n_file.open("N.txt");
	float x[n + 1];
	float y[n + 1];
	int flag = 0;
	x[0] = rand() % R;
	y[0] = rand() % R;

	for (int i = 1; i <= n; i++)
	{
		x[i] = 0;
		y[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		while (flag == 0)
		{
			x[i] = rand() % R;
			y[i] = rand() % R;
			for (int j = 0; j < i; j++)
			{
				if ((abs(x[i] - x[j]) <= max_dis) && (abs(y[i] - y[j]) <= max_dis))
					flag = 1;
			}
			for (int j = 0; j < i; j++)
			{
				if (x[i] - x[j] == 0 && y[i] - y[j] == 0)
					flag = 0;
			}
		}
		flag = 0;
	}

	for (int i = 1; i <= n; i++)
		xs_file << x[i] << endl;

	for (int i = 1; i <= n; i++)
		ys_file << y[i] << endl;

	n_file << n;

	xs_file.close();
	ys_file.close();
	n_file.close();

	return 0;
}