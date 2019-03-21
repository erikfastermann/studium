#include <stdio.h>

void main() {
	int ctr = 0;
	int zahl;
	printf("Zahl eingeben: ");
	scanf_s("%d", &zahl);
	for (int i = 2; i < zahl; i++) {
		if (zahl % i == 0) {
			ctr++;
			printf("%d\n", i);
		}
	}
	if (ctr) {
		printf("Anzahl der Teiler: %d\n", ctr);
	}
	else {
		printf("Primzahl!\n");
	}
}