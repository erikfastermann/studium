#include <stdio.h>
#include <math.h>
#include "mathe.h"

double n;
double ergebnis = 0;
int i;

main()
{
	printf("n eingeben: ");
	scanf("%lf", &n);

	for (i = 1; i <= n; i++)
	{
		ergebnis = ergebnis + (4 / (1 + pow(((i - 0.5) / n), 2)));
	}

	ergebnis = (1/n) * ergebnis;
	printf("Ergebnis: %lf\n", ergebnis);
}
