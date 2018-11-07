#include <math.h>

const double pi = 3.141;


double umfang_re(double a, double b)
{
	return 2 * (a + b);
}

double flaeche_re(double a, double b)
{
	return a * b;
}

double umfang_de(double a, double b, double c)
{
	return a + b + c;
}

double flaeche_de(double a, double b, double c)
{
	double s;

	s = umfang_de(a, b, c) / 2;

	return sqrt(s*(s-a)*(s-b)*(s-c));
}

double umfang_kr(double a)
{
	return 2 * pi * a;
}

double flaeche_kr(double a)
{
	return pi * (a * a);
}