#ifndef HASH_H
#define HASH_H
#include "listcad.h"	

typedef struct {
	linked_list *l;
} hashTable;

hashTable *new_hashTable();
void lerArq(hashTable **ht);
void addWord(hashTable *ht, char *word);
int hashKey(char *word);
int tamStr(char *word);
void printHash(hashTable *ht);
int countWordHash(hashTable *ht);
void ordenar(hashTable *ht);
void bubble_sort (node *vet, int n);

#endif