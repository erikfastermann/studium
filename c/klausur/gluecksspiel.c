#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0

int EingabeWert(int spieler) {
	int swert = -1;
	while (1) {
		printf("Spieler %d Wert zwischen 0 und 100 eingeben: ", spieler);
		scanf_s("%d", &swert);
		if ((swert < 0) || (swert > 100)) {
			printf("Ungueltige Eingabe\n");
		}
		else {
			return swert;
		}
	}
}

int ErmittleSieger(int wert, int spieler1, int spieler2) {
	spieler1 -= wert;
	spieler2 -= wert;

	if (spieler1 < 0) {
		spieler1 *= -1;
	}
	if (spieler2 < 0) {
		spieler2 *= -1;
	}

	if (spieler1 < spieler2) {
		return 1;
	}
	else if (spieler1 > spieler2) {
		return 2;
	}
	else if (spieler1 == spieler2) {
		return 0;
	}
	return -1;
}

void main() {
	char erneut;
	int wert, spieler1, spieler2;

	printf("*** Willkommen zum Gluecksspiel ***\n");

	srand((unsigned)time(0));

	while (1) {
		erneut = 'x';

		wert = rand() % (MAX);
		printf("Wert = %d\n\n", wert);

		spieler1 = EingabeWert(1);
		spieler2 = EingabeWert(2);

		switch (ErmittleSieger(wert, spieler1, spieler2)) {
		case 1: {
			printf("*** Spieler 1 hat gewonnen ***\n");
			break;
		}
		case 2: {
			printf("*** Spieler 2 hat gewonnen ***\n");
			break;
		}
		case 0: {
			printf("*** Unentschieden ***\n");
			break;
		}
		}

		while (erneut != 'j') {
			getchar();
			printf("Noch eine Runde ? - j/n: ");
			erneut = getchar();
			if (erneut == 'n')
				exit(0);
		}
	}
}