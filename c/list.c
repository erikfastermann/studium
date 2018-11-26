#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct list
{
	int key;
	char info[10];
	struct list* next;
};

struct list* head = NULL;


void append(int myKey, char info[10])
{
	// Zeiger neues Element
	struct list* ptr;
	// Zeiger Durchlauf Liste
	struct list* tail;

	// Speicher alloc im Heap
	ptr = (struct list*)malloc(sizeof(struct list));

	ptr->key = myKey;
	strcpy_s(ptr->info, 10, info);

	// aktuell ist letztes Element
	ptr->next = NULL;

	// neuer listenanker
	tail = head;

	if (head == NULL)
	{
		// Liste leer -> erstes Elem ist letztes Elem
		head = ptr;
	}
	else
	{
		// suche nach letztem Elem
		while (tail->next != NULL)
			tail = tail->next;

		// Listenende
		tail->next = ptr;
	}
}


void insert(int myKey, char info[10])
{
	struct list* ptr;

	// Speicher alloc im Heap
	ptr = (struct list*)malloc(sizeof(struct list));

	ptr->key = myKey;
	strcpy_s(ptr->info, 10, info);

	// in die liste
	ptr->next = head;

	// neuer listenanker
	head = ptr;
}


void del(int myKey)
{
	struct list* ptr;
	struct list* prevPtr;

	if (head == NULL)
	{
		printf("\n List empty. \n");
		return;
	}
	
	// wenn erstes Listenelem
	if (head->key == myKey)
	{
		printf("\nDeleted entry with key: %d\n", myKey);
		head = head->next;
		return;
	}

	// Key suchen
	ptr = head->next;
	prevPtr = head;

	// bis Listenende oder Key gefunden
	while ((ptr->next != NULL) && (ptr->key != myKey))
	{
		prevPtr = ptr;
		ptr = ptr->next;
	}

	// Warum Schleife verlassen?
	if (ptr->key == myKey)
	{
		// gesuchtes Element gefunden
		prevPtr->next = ptr->next;
		printf("Element %d wurde gelöscht\n", myKey);
	}
	else
	{
		printf("Element %d nicht gefunden!\n", myKey);
	}
}


void showlist()
{
	// Hilfszeiger zum auflisten
	struct list* ptr;

	// Pointer auf Listenanfang
	ptr = head;

	if (ptr == NULL)
	{
		printf("\nEmpty list.\n");
		return;
	}
	else
	{
		while (ptr != NULL)
		{
			printf("\nKey: %d\n", ptr->key);
			printf("Info: %s\n", ptr->info);

			ptr = ptr->next;
		}
	}
}


main()
{
	char auswahl;
	int key = 1;
	char info[10];
	int delKey;

	do
	{
		printf("-----------------------");
		printf("\n>>> Lists <<<\n");
		printf("append		- a\n");
		printf("insert		- i\n");
		printf("delete		- d\n");
		printf("show list	- l\n");
		printf("exit		- e\n");
		printf("-----------------------\n");
		printf(">>> ");
		auswahl = getchar();

		switch (auswahl)
		{
		case 'a':
		{
			printf("\nAdd: ");
			scanf_s("%s", info, 10);
			putchar('\n');
			append(key++, info);
			break;
		}

		case 'i': 
		{
			printf("\nInfo: ");
			scanf_s("%s", info, 10);
			putchar('\n');
			insert(key++, info);
			break;
		}

		case 'd':
		{
			printf("\nDelete: ");
			scanf_s("%d", &delKey);
			putchar('\n');
			del(delKey);
			break;
		}

		case 'l': 
		{
			printf("\n---");
			showlist();
			printf("---\n\n");
			break;
		}

		case 'e': 
			break;
		default: printf("Nope.\n");
		}

		//Tastaturpuffer leeren
		getchar();

	} while (auswahl != 'x');
}