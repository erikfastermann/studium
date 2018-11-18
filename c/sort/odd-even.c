#include <stdio.h>
// für Zufall
#include <stdlib.h>
#include <time.h>

void printer(int * feld, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 5 == 0)
		{
			putchar('\n');
		}
		printf("%10d", feld[i]);
	}
	putchar('\n');
}

void sort(int * feld, int n)
{
	for (int i = 0; i < (n / 2 + 1); i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			for (int x = j; x < (n - 1); x += 2)
			{
				if (feld[x] > feld[x + 1])
				{
					int tmp = feld[x];
					feld[x] = feld[x + 1];
					feld[x + 1] = tmp;
				}
			}
		}
	}
}

main()
{
	int n; //Anzahl Feldelemente

	int * feld; //dynamisches Feld mit Zeiger

	//Eingabe n
	printf("Eingabe n: ");
	scanf_s("%d", &n);

	//Feld anlegen
	feld = (int*)malloc(n*sizeof(int));

	//init Zufallsgen
	srand((unsigned)time(0));

	//für jedes Feldelem eine Zufallszahl
	for (int i = 0; i < n; i++)
	{
		feld[i] = rand();
	}

	printer(feld, n);
	sort(feld, n);
	printer(feld, n);
	putchar('\n');
}

