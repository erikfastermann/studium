#include <stdio.h>

void einlesen(double preise[5])
{
	FILE* fp;
	fopen_s(&fp, "preise.txt", "r");
	if (fp == NULL)
		printf("Fehler\n");
	else
		fread(preise, sizeof(double), 5, fp);
}

main()
{
	double preise[5];
	char* namen[] = { "Cornetto","Sandwich","Flupper","Polareis", "Solaire" };
	int anzahl[] = { 0,0,0,0,0 };
	einlesen(preise);
	for (int i = 0; i < 5; i++)
		printf("%s: %lf %d\n", namen[i],preise[i], anzahl[i]);
}