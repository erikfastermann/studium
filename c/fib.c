#include <stdio.h>


int collatz(int n)
{
	if (n == -1)
		return -1;

	if (n == 1)
		return 1;

	if (n % 2 == 0)
		return collatz(n / 2);
	else
		return collatz(n * 3 + 1);
}


int fib(int n)
{
	if ((n == 1) || (n == 2))
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}


void divrest(int n)
{
	int ergeb;
	ergeb = n / 2;

	if (ergeb != 0)
		divrest(ergeb);
	printf("%d", n % 2);
}


main()
{
	int n;
	int ergebnis;

	printf("Zahl eingeben: ");
	scanf_s("%d", &n);

	/*ergebnis = fib(n);
	printf("\nErgebnis Fibo: %d\n", ergebnis);

	ergebnis = collatz(n);
	printf("Ergebnis Collatz: %d\n", ergebnis);*/

	printf("Ergebnis DivRest: ");
	divrest(n);
	putchar('\n');
}