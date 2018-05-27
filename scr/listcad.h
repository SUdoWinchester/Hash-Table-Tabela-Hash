#ifndef LISTCAD_H
#define LISTCAD_H

typedef struct Node {
	char *str;
	int count;
	struct Node *next;
} node;

typedef struct {
	node *first;
	int count;
	int max;
} linked_list;

linked_list *new_linked_list(int size);
node *create_node(char *str);

void insert_first(linked_list *l, char *str);
void insertat(linked_list *l, char *str, int posicao);
void insert_last(linked_list *l, char *str);

void print(linked_list *l);
int is_empty(linked_list *l);
int is_full(linked_list *l);
int verificaPalavra(linked_list *l, char *word);
int countWordList(linked_list *l);
int countNode(linked_list *l);

void remove_first(linked_list *l);
void removeat(linked_list *l, int x);
void remove_last(linked_list *l);

void destroy_linked_list(linked_list **l);


#endif