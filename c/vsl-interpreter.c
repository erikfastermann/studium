#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>	 	// wird z.B. zum Test auf whitespaces ben�tigt

FILE	*fp;			// Zeiger auf Eingabedatei
int	buf = 0;			// Ergebnispuffer
int expression(void);	// Prototyp, wegen zykl. Rekursion n�tig



//Hilfsfunktionen:
//Dient zur Fehleranzeige, es kann eine beliebige Nachricht �bergeben werden

void error(char* str)
{
	printf("\n*** Fehler: %s\n", str);
	exit(1);
}


//Liest das n�chste Zeichen, �bergeht dabei alle whitespaces
int next(void)
{
	int ch;
	do						// f�hre Leseschleife aus
	{
		if (buf)			// wenn Zeichen im Puffer steht
		{
			ch = buf;		// kopiere in Hilfsvariable
			buf = 0;		// setze Puffer auf 0
		}
		else
		{
			ch = getc(fp);		// lies n�chstes Zeichen aus Datei
			if (ch == EOF)		// wenn Dateiende
				error("Dateiende erreicht");	// Fehlermeldung
			putchar(ch);		// gib Zeichen auf Monitor aus
		}
	} while (isspace(ch));		// solange Trennzeichen gelesen werden
	return ch;
}






//Testet, ob das n�chste Zeichen einem erwarteten Zeichen entspricht
//R�ckgabewert 1 bei �bereinstimmung, sonst 0

int nextis(char chgiven)
{
	char ch = next();
	if (ch != chgiven)
		buf = ch;		// Zwischenpuffern, wenn keine �bereinstimmung
	return (ch == chgiven);
}

//Implementierung der Syntaxregeln :
//F�r Ziffer wird keine eigene Funktion ben�tigt, es kann isdigit(char); benutzt werden
//X bekommt einen korrekten Wert, entweder eine Ziffer oder das Ergebnis eines Ausdrucks, im Fehlerfall bricht das Programm mit exit(1) aus der Funktion error(char*) ab.

int factor(void)
{
	int x;
	char ch = next();				// n�chstes Zeichen holen
	if (isdigit(ch))				// ist es eine Ziffer ?
	{
		x = ch - '0';				// ASCII-Wandlung
	}
	else
	{
		if (ch == '(')				// dann muss es ein Ausdruck sein
		{
			x = expression();		// Ausdruck rekursiv auswerten
			if (!nextis(')'))			// jetzt muss ) stehen
				error("')' expected");
		}
		else
			error("Digit or '(' expected");
	}
	return x;
}



//Auswertung eines Begriffes, dieser kann aus mehreren Faktoren bestehen
int term(void)
{
	int x;
	x = factor();				// rekursiv Faktor berechnen

	while (nextis('*'))			// es kommt ein weiterer Faktor
		x *= factor();			// mit bisherigem Faktor multiplizieren
	return x;
}


//Auswertung eines Ausdrucks :

int expression(void)
{
	int x = term();					// Ausdruck beginnt mit Begriff
	for (;;)						// Endlosschleife
	{
		if (nextis('+'))				// es folgt ein weiterer Begriff
			x += term();			// neuen Begriff addieren
		else
			if (nextis('-'))
				x -= term();		// neuen Begriff subtrahieren
			else
				break;			// sonst verlassen
	}

	return x;
}









main()
{
	char filename[51];				// Puffer f�r Dateinamen			
	int x;

	printf("VSL - Interpreter Version 0.0\n\n");
	printf("Name der Eingabedatei: ");
	scanf_s("%50s", filename, 50);

	fopen_s(&fp, filename, "r");			// Datei zum Lesen �ffnen

	if (fp == NULL)						// Fehler beim �ffnen
		error("Datei nicht gefunden");
	printf("Datei %s wird gelesen\n", filename);

	if (!nextis('{'))					// Programm muss mit { beginnen
		error("'{' expected");			// gleich Abbruch
	x = expression();					// jetzt muss Ausdruck folgen

	printf("\n\nBerechneter Wert: %d\n", x);	// Ausgabe des Ergebnis

	if (!nextis('}'))					// Programmende mit }
		error("'}' expected");
	return 0;
}
