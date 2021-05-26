#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>
#include <fstream>

using namespace std;
 
vector<double>x;
vector<double>y;

double lagranzh(vector<double>x, vector<double>y, double t) {
	double z = 0;


	int j = 0;
	while (j < y.size()) {
		double p1 = 1;
		double p2 = 1;

		int i = 0;
		while (i < x.size()) {

			if (i == j) {
				p1 = 1 * p1;
				p2 = 1 * p2;
			}
			else {
				p1 = p1 * (t - x[i]);
				p2 = p2 * (x[j] - x[i]);
			}
			i++;
		}
		z += y[j] * p1 / p2;
		j++;
	}

	return z;
}


int main() {
	string s;

	int c = 0;
	ifstream ins("xy.txt");

	vector<double>xnew, ynew;

	string xx, yy;

	if (ins.is_open())
	{
		while (getline(ins, s)) {
			ins >> xx >> yy;
			x.push_back(stod(xx));
			y.push_back(stod(yy));
		}
	}

	for (double i = 0.0; i < 50; i+=0.5)
	{
		xnew.push_back(i);
 	}


	for (int i = 0; i < xnew.size(); i++)
	{
 
		ynew.push_back(lagranzh(x, y, xnew[i]));
 
	}


	for (int i = 0; i < xnew.size(); i++)
	{
		cout << ynew[i] << endl;
	}

	return 0;
};