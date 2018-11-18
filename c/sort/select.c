#include <stdio.h>

main()
{
	int feld[5];
	int i, j, feldNeu;
	int minIndex;
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
	for (j = 0; j < 5; j++)
	{
		printf("%d ", feld[j]);
	}
	printf("\n");

	for (i = 0; i <= 3; i++)
	{
		minIndex = i;

		for (j = i + 1; j <= 4; j++)
		{
			anzVgl++;
			if (feld[j] < feld[minIndex])
			{
				minIndex = j;
			}
		}

		anzVgl++;
		if (minIndex != i)
		{
			anzTausch++;
			tmp = feld[i];
			feld[i] = feld[minIndex];
			feld[minIndex] = tmp;
		}
	}

	printf("\nSortierte Folge: ");
	for (i = 0; i < 5; i++)
		printf("%d ", feld[i]);
	printf("Anzahl Verleiche: %d\n", anzVgl);
	printf("Anzahl Tausche: %d\n", anzTausch);
	printf("Gesamtgewicht: %d\n", anzVgl + 3 * anzTausch);
}