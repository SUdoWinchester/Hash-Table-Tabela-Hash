#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#include "listcad.h"

#define TAM 127
#define TAMWORD 47

void lerArq(hashTable **ht) {
	FILE *arq;
	char word[TAMWORD], ch, *wordS;
	int i, tamWord;

	wordS = malloc(sizeof(char));

	arq = fopen("txt.txt", "r");

	if(arq == NULL)
		printf("Nao foi possivel abrir o arquivo...\n");
	else {
		ch=fgetc(arq);
		while(ch != EOF) {
			i = 0;
			while(!ispunct(ch) && !isspace(ch) && !iscntrl(ch) && ch != EOF) {
				word[i] = tolower(ch);
				ch=fgetc(arq);
				i++;
			}

			if(i != 0) {
			
				word[i] = '\0';

				tamWord = tamStr(word);
				wordS = (char *) realloc(wordS, tamWord*sizeof(char));
				for(int j = 0; j < tamWord; j++)
					wordS[j] = word[j];

				addWord(*ht, wordS);
				wordS = NULL;
			}

			ch=fgetc(arq);
			if(ch == ' ')
				ch=fgetc(arq);
		}
	}

	fclose(arq);
}

hashTable *new_hashTable() {
	hashTable *ht = (hashTable*) malloc(TAM * sizeof(hashTable));

	for(int i = 0; i < TAM; i++) {
		ht[i].l = new_linked_list(-1);
		ht[i].l->first = NULL;
	}

	return ht;
}

void addWord(hashTable *ht, char *word) {
	int key = hashKey(word);

	if(ht[key].l->first == NULL) {
		insert_first(ht[key].l, word);
		return ;
	} else {
		if(verificaPalavra(ht[key].l, word) == 0) {
			insert_first(ht[key].l, word);
		}
	}
}

int hashKey(char *word) {
	int key = 0;

	for (int i = 0; word[i] != '\0'; i++) {
		key += word[i];
	}

	return key % TAM;
}

int tamStr(char *word) {
	int tam = 0;
	for(int i = 0; word[i] != '\0'; i++, tam++);
	return tam + 1;
}

void printHash(hashTable *ht) {
	for(int i = 0; i < TAM; i++) {	
		if(ht[i].l->first != NULL) {
			print(ht[i].l);
		}
	}
	printf("\n\nNumero de palavras: %d\n", countWordHash(ht));
}

int countWordHash(hashTable *ht) {
	int count = 0;
	for(int i = 0; i < TAM; i++) {	
		if(ht[i].l->first != NULL) {
			count += countWordList(ht[i].l);
		}
	}

	return count;
}

void ordenar(hashTable *ht) {
	int count = 0;

	for(int i = 0; i < TAM; i++) {
		if(ht[i].l->first != NULL) {
			count += countNode(ht[i].l);
		}
	}

	node *ord = (node*) malloc(count * sizeof(node));

	node *aux;
	int i = 0;
	int j = 0;
	while(i < count) {
		while(j < TAM) {
			aux = ht[j].l->first;
			while(aux != NULL) {
				ord[i].str = aux->str;
				ord[i].count = aux->count;
				ord[i].next = NULL;
				i++;
				aux = aux->next;
			}
			j++;
		}
	}

	bubble_sort(ord, count);

	for(i = 0; i < count; i++) {
		printf("%d\t%s\n", ord[i].count, ord[i].str);
	}

	ord = NULL;
	free(ord);
}

void bubble_sort(node *vet, int n) {
    char *str;
    int count;
    for (int k = 1; k < n; k++) {
        for (int j = 0; j < n - 1; j++) {
            if (vet[j].count < vet[j+1].count) {
                str = vet[j].str;
                count = vet[j].count;

                vet[j].str = vet[j+1].str;
                vet[j].count = vet[j+1].count;

                vet[j+1].str = str;
                vet[j+1].count = count;
            }
        }
    }
}