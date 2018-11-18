#include <stdio.h>

main()
{
	int feld[5];
	int i, j;
	int feldNeu;
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
	for (i = 0; i < 5; i++)
	{
		printf("%d ", feld[i]);
	}
	printf("\n");

	for (i = 1; i <= 4; i++)
	{
		// innere Schleife stoppt, wenn innerer Rand erreicht 
		// oder Vorgängerelement kleiner als das Aktuelle ist
		for (j = i, anzVgl++; (j >= 1) && (feld[j] < feld[j-1]); j--)
		{
			tmp = feld[j];
			feld[j] = feld[j - 1];
			feld[j - 1] = tmp;
			anzTausch++;
		}
	}

	printf("\nSortierte Folge: ");
	for (i = 0; i < 5; i++)
		printf("%d ", feld[i]);
	printf("Anzahl Verleiche: %d\n", anzVgl);
	printf("Anzahl Tausche: %d\n", anzTausch);
	printf("Gesamtgewicht: %d\n", anzVgl + 3 * anzTausch);
}