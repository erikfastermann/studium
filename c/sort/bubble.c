#include <stdio.h>

main()
{
	int feld[5];
	int i, j, feldNeu;
	int breaker = 0;
	int tmp;

	int anzVgl = 0;
	int anzTausch = 0;

	for (i = 0; i < 5; i++)
	{
		printf("Wert eingeben: ");
		scanf_s("%d", &feldNeu);
		feld[i] = feldNeu;
	}

	printf("Werte: ");
	for (i = 0; i < 5;i++)
	{
		printf("%d ", feld[i]);
	}
	printf("\n");


	for (j = 0; j <= 3; j++)
	{
		for (i = 0; i <= 3; i++)
		{
			anzVgl++;
			if (feld[i+1] < feld[i])
			{
				tmp = feld[i];
				feld[i] = feld[i+1];
				feld[i+1] = tmp;
				breaker = 1;
				anzTausch++;
			}
		}

		if (breaker == 0)
		{
			break;
		}
	}

	printf("\nSortierte Folge: ");
	for (i = 0; i < 5; i++)
		printf("%d ", feld[i]);
	printf("Anzahl Verleiche: %d\n", anzVgl);
	printf("Anzahl Tausche: %d\n", anzTausch);
	printf("Gesamtgewicht: %d\n", anzVgl + 3 * anzTausch);
}