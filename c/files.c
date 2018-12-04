#include <stdio.h>

struct person {
	char name[20];
	int alter;
	int mat;
};


void reader(char file1, struct person student, FILE *fp)
{
	if (fopen_s(&fp, file1, "rb") != 0)
	{
		printf("Fehler!");
		return -1;
	}

	while (!feof(fp))
	{
		if (fscanf_s(fp, "%s\n", &student.name) == EOF)
			break;
		printf("\n%s", student.name);

		if (fscanf_s(fp, "%d\n", &student.alter) == EOF)
			break;
		printf("\n%s", student.alter);

		if (fscanf_s(fp, "%d\n\n", &student.mat) == EOF)
			break;
		printf("\n%d", student.mat);
	}

	fclose(fp);
}

void writer(char file1, struct person student, FILE *fp)
{
	if (fopen_s(&fp, "file1", "wb") != 0)
	{
		printf("Fehler!");
		return -1;
	}

	printf("Name: ");
	scanf_s("%s", &student.name, 20);

	printf("\nAlter: ");
	scanf_s("%d", &student.alter);

	printf("\nMat.-Nummer: ");
	scanf_s("%d", &student.mat);

	fprintf(fp, "%s\n", student.name);
	fprintf(fp, "%d\n", student.alter);
	fprintf(fp, "%d\n\n", student.mat);

	fclose(fp);
}

main()
{
	char sel;
	char file1 = "file1.txt";
	struct person student;
	FILE *fp;

	printf("Menu\n");
	printf("write - w\n");
	printf("read - r\n");
	printf(">>> ");
	sel = getchar();

	switch (sel)
	{
	case 'w': 
	{
		writer(file1, student, fp);
		break;
	}

	case 'r' :
	{
		reader(file1, student, fp);
		break;
	}

	default: break;
	}
}