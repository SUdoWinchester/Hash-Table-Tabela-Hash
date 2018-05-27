#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void main() {
	hashTable *ht = new_hashTable();
	lerArq(&ht);

	printf("Tabela Hash:\n");
	printHash(ht);

	printf("\n\n\nOrdenado:\n");
	ordenar(ht);
	
	getch();
}