#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>


typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct list
{
    node* head;
    unsigned int size;
} list;


typedef struct {
	list **buckets; /* Array de liste simplu-inlantuite. */
	/* Nr. total de noduri existente curent in toate bucket-urile. */
	unsigned int size;
	unsigned int hmax; /* Nr. de bucket-uri. */
	/* (Pointer la) Functie pentru a calcula valoarea hash asociata cheilor. */
	unsigned int (*hash_function)(void*);
	/* (Pointer la) Functie pentru a compara doua chei. */
	int (*compare_function)(int, int);
} hashtable;

int compare_function_ints(int a, int b);

unsigned int hash_function_int(void *a);

hashtable * ht_create(unsigned int hmax);

int ht_has_key(hashtable *ht, int key);

void ht_put(hashtable **ht, int key);

int ht_remove_entry(hashtable **ht, int key);

void ht_replace(hashtable **ht, int a, int b);

void *ht_print(hashtable *ht, FILE *out);

hashtable *ht_free(hashtable *ht);

#endif