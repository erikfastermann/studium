#include <stdio.h>
#include <stdlib.h>

#define X 40
#define Y 40


void initFeld(char feld[X][Y])
{
	int i, j;

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
			feld[i][j] = ' ';
	}
}


void showFeld(char feld[X][Y])
{
	int i, j;

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
			printf("%c ", feld[i][j]);
		putchar('\n');
	}
}


int feldNachbarn(char feld[X][Y], int x, int y)
{
	int nachbarn = 0;

	if ((x == 0) || (y == 0) || (x == X) || (y == Y))
		return -1;

	else
	{
		if (feld[x - 1][y - 1] == '*')
			nachbarn++;
		if (feld[x][y - 1] == '*')
			nachbarn++;
		if (feld[x + 1][y - 1] == '*')
			nachbarn++;
		if (feld[x - 1][y] == '*')
			nachbarn++;
		if (feld[x + 1][y] == '*')
			nachbarn++;
		if (feld[x - 1][y + 1] == '*')
			nachbarn++;
		if (feld[x][y + 1] == '*')
			nachbarn++;
		if (feld[x + 1][y + 1] == '*')
			nachbarn++;
	}

	return nachbarn;
}


void copyFeldFunc(char feld[X][Y], char copyFeld[X][Y])
{
	int i, j;

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
			copyFeld[i][j] = feld[i][j];
	}
}


void leben(char feld[X][Y], char copyFeld[X][Y])
{
	int i, j;
	int nachbarn;

	for (i = 1; i < X - 1; i++)
	{
		for (j = 1; j < Y - 1; j++)
		{
			nachbarn = feldNachbarn(feld, i, j);
			if ((nachbarn == -1) || (nachbarn == 2))
				copyFeld[i][j] = copyFeld[i][j];
			else if ((nachbarn < 2) || (nachbarn > 3))
				copyFeld[i][j] = ' ';
			else if (nachbarn == 3)
				copyFeld[i][j] = '*';
		}
	}
}


void sel(char feld[X][Y])
{
	char auswahl;
	printf("Menu:\n");
	printf("Segler - s\n");
	printf("Pi - p\n");
	printf("Kroete - k\n");
	auswahl = getchar();

	switch (auswahl)
	{
	case 's':
		feld[1][2] = '*';
		feld[2][3] = '*';
		feld[3][1] = '*';
		feld[3][2] = '*';
		feld[3][3] = '*';
		break;

	case 'p':
		feld[20][20] = '*';
		feld[19][20] = '*';
		feld[18][20] = '*';
		feld[18][21] = '*';
		feld[18][22] = '*';
		feld[20][23] = '*';
		feld[19][23] = '*';
		feld[18][23] = '*';
		break;

	case 'k':
		feld[18][20] = '*';
		feld[18][21] = '*';
		feld[18][22] = '*';
		feld[19][19] = '*';
		feld[19][20] = '*';
		feld[19][21] = '*';
		break;

	default:
		printf("Your life is a failure!\n");
		exit(-1);
	}
	
}


main()
{
	char feld[X][Y];
	char copyFeld[X][Y];

	initFeld(feld);
	initFeld(copyFeld);
	sel(feld);
	showFeld(feld);
	copyFeldFunc(feld, copyFeld);

	while (1)
	{
		system("cls");
		showFeld(feld);
		leben(feld, copyFeld);
		copyFeldFunc(copyFeld, feld);
	}
}