#include <iomanip>
#include <iostream>

using namespace std;

static double f(long double x, long double y)
{
	return  y * y + cos(x + 1.23 * y);
};

static double gradX(long double x, long double y)
{
	return -sin(x + 1.23 * y);
};

static double gradY(long double x, long double y)
{
	return  2 * y - 1.23 * sin(x + 1.23 * y);
};

static double norm(long double x, long double y)
{
	return sqrt((-sin(x + 1.23 * y)) * (-sin(x + 1.23 * y)) + (2 * y - 1.23 * sin(x + 1.23 * y)) * (2 * y - 1.23 * sin(x + 1.23 * y)));
};


static void output(long double x, long double y)
{
	cout << setw(4) << fixed << setprecision(5) << x;
	cout << setw(14) << fixed << setprecision(5) << y;
	cout << setw(14) << fixed << setprecision(5) << f(x, y) << endl;
};

void main()
{
	long double x0 = -0.4;
	long double y0 = 1.9;
	long double h = 0.002;
	long double M = 6;

	long double x = x0;
	long double y = y0;

	output(x, y);

	for (int k = 0; k < 4; ++k)
	{
		long double gradx = gradX(x, y);
		long double grady = gradY(x, y);
		long double Norm = norm(x, y);

		x = x - h * gradx / Norm;
		y = y - h * grady / Norm;

		output(x, y);
	};

	cin >> x;
};