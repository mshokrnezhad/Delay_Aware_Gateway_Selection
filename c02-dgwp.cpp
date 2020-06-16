// DGWP.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

static double Distnce(int t, int i, double xs[], double ys[])
{
	return sqrt(pow((xs[t] - xs[i]), 2) + pow((ys[t] - ys[i]), 2));
}

int main(int argc, char* argv[])
{
	ofstream cfile;
	ofstream n;
	ofstream rfile;
	rfile.open("r.txt");
	n.open("n.txt");
	cfile.open("c.txt");

	double N_temp = atoi(argv[1]);
	const int N = N_temp;
	double r_temp = atoi(argv[2]);
	const double r = r_temp;

	double xs[N];
	double ys[N];

	ifstream xsfile("xs.txt");
	double a = 0;
	int b = 0;
	while (xsfile >> a)
	{
		xs[b] = a;
		b++;
	}
	ifstream ysfile("ys.txt");
	a = 0;
	b = 0;
	while (ysfile >> a)
	{
		ys[b] = a;
		b++;
	}

	int AdjMat[N][N];

	for (int k1 = 0; k1 < N; k1++)
		for (int k2 = 0; k2 < N; k2++)
			if (Distnce(k1, k2, xs, ys) <= r)
				AdjMat[k1][k2] = 1;
			else
				AdjMat[k1][k2] = 0;

	for (int k1 = 0; k1 < N; k1++)
		for (int k2 = 0; k2 < N; k2++)
			cfile << (k1 + 1) << " " << (k2 + 1) << " " << AdjMat[k1][k2] << endl;


	for (int k1 = 0; k1 < N; k1++)
		n << (k1 + 1) << endl;


	for (int k1 = 0; k1 < N; k1++)
		rfile << (k1 + 1) << endl;

	cfile.close();
	rfile.close();
	n.close();

	return 0;
}