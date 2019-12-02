#include <iostream>
#include <vector>

using namespace std;

double duration(double c, double f, double x)
{
	double t = 0, min = x/2.0;
	for (int i = 0; ; ++i)
	{
		t += c/(f*i+2);
		double r = t + x/(f*i+f+2);
		if (r < min) {
			min = r;
		}
		else 
			return min;
	}
}

int main(int argc, char const *argv[])
{
	int T;
	double C, F, X;
	cin >> T;
	cout.precision(15);
	for (int i = 0; i < T; ++i)
	{
		cin >> C >> F >> X;
		cout << "Case #" << (i+1) << ": " << duration(C, F, X) << endl;
	}
	return 0;
}