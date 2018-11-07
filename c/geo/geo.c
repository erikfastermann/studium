#include <stdio.h>
#include <stdlib.h>
#include "func.h"

main()
{
	double a;
	double b;
	double c;
	char auswahl;

	do
	{
		system("cls");
		printf("Eyyyyy\n");
		printf("Rechteck: r\n");
		printf("Dreieck: d\n");
		printf("Kreis: k\n");
		printf("Exit: e\n");
		printf("> ");
		auswahl = getchar();

		switch (auswahl)
		{
			case 'r':
			{
				printf("Kanten a b eingeben: ");
				scanf_s("%lf %lf", &a, &b);

				printf("\nUmfang Rechteck: %lf\n", umfang_re(a, b));
				printf("Flaeche Rechteck: %lf\n", flaeche_re(a, b));
				break;
			}

			case 'd': 
			{
				printf("Kanten a b c eingeben: ");
				scanf_s("%lf %lf %lf", &a, &b, &c);

				printf("\nUmfang Dreieck: %lf\n", umfang_de(a, b, c));
				printf("Flaeche Dreieck: %lf\n", flaeche_de(a, b, c));
				break;
			}

			case 'k': 
			{
				printf("Radius eingeben: ");
				scanf_s("%lf", &a);

				printf("\nUmfang Kreis: %lf\n", umfang_kr(a));
				printf("Flaeche Kreis: %lf\n", flaeche_kr(a));

				break;
			}

			case 'e': break;
			default: printf("You have autism. Please try again.");
		}

		// Tastaturpuffer leeren
		getchar();
		printf("\n");

		if (auswahl != 'e')
			system("pause");

	} while (auswahl != 'e');
	
}

