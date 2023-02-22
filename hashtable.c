#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"


list* create_list(void)
{
	list *tmp = malloc(sizeof(list));
	tmp->head = NULL;
	tmp->size = 0;
	return tmp;
}

node* get_nth_node(list* list, int n)
{
	node *ptr = list->head;
	int i = 0;
	while (i < n) {
		ptr = ptr->next;
		i++;
	}
	return ptr;
}

list *add_nth_node(list* list, unsigned int n, int data)
{
	node *new_nod = malloc(sizeof(node));
	new_nod->data = data;
	new_nod->next = NULL;

	if (n == 0) {
		list->head = new_nod;
		list->size += 1;
		return list;
	}

	node *ptr = get_nth_node(list, n - 1);

	ptr->next = new_nod;

	list->size += 1;

	return list;
}

node* remove_nth_node(list* list, unsigned int n)
{
	if (n == 0) {
		node *ptr = list->head;

		list->head = ptr->next;

		ptr->next = NULL;

		list->size -= 1;
		return ptr;
	}

	node *ptr = get_nth_node(list, n - 1);

	node *q = ptr->next;

	ptr->next = ptr->next->next;

	q->next = NULL;

	list->size -= 1;
	return q;
}

list *free_list(list* pp_list)
{
	if(pp_list == NULL)
		return NULL;

	
	node *ptr = pp_list->head;
	int i = 0;
	while(i < pp_list->size) {
		node *q = ptr->next;
		free(ptr);
		ptr = q;
		i++;
	}
	free(pp_list);
	return NULL;
}



int compare_function_ints(int a, int b)
{
	return a - b;
}

unsigned int hash_function_int(void *a)
{
	/*
	 * Credits: https://stackoverflow.com/a/12996028/7883884
	 */
	unsigned int uint_a = *((unsigned int *)a);
	
	uint_a = ((uint_a >> 16u) ^ uint_a) * 0x45d9f3b;
	uint_a = ((uint_a >> 16u) ^ uint_a) * 0x45d9f3b;
	uint_a = (uint_a >> 16u) ^ uint_a;
	return uint_a;
}

hashtable *ht_resize(hashtable *ht, int arg) {
	hashtable *new_ht;
	if (arg > 0) {
		new_ht = ht_create(ht->hmax * 2);
	} else {
		new_ht = ht_create(ht->hmax / 2);
	}

	for(int i = 0; i < ht->hmax; i++) {
		if(ht->buckets[i] == NULL)
			continue;
		
		node *ptr1 = ht->buckets[i]->head;
		node *ptr2 = ptr1;
		while(ptr2) {
			ptr1 = ptr2;
			ht_put(&new_ht, ptr1->data);
			ptr2 = ptr2->next;
			free(ptr1);
		}
		free(ht->buckets[i]);
	}

	free(ht->buckets);
	free(ht);

	return new_ht;
}

hashtable * ht_create(unsigned int hmax)
{
	hashtable *h = malloc(sizeof(hashtable));
	h->size = 0;
	h->hmax = hmax;
	h->hash_function = hash_function_int;
	h->compare_function = compare_function_ints;
	h->buckets = calloc(hmax, sizeof(list));

	return h;
}

int ht_has_key(hashtable *ht, int key)
{
	unsigned int hash = ht->hash_function(&key) % ht->hmax;

	if(ht->buckets[hash] == NULL)
		return 0;

	node *ptr = ht->buckets[hash]->head;
	while(ptr) {
		if(ht->compare_function(key, ptr->data) == 0)
			return 1;
		ptr = ptr->next;
	}

	return 0;
}

int ht_get(hashtable *ht, int key)
{
	unsigned int hash = ht->hash_function(&key) % ht->hmax;
	node *ptr = ht->buckets[hash]->head;
	while(ptr)
	{
		if(ht->compare_function(key, ptr->data) == 0)
			return ptr->data;
		ptr = ptr->next;
	}

	return 0;
}

void ht_put(hashtable **ht, int key)
{
	unsigned int hash = (*ht)->hash_function(&key) % (*ht)->hmax;
	
	if((*ht)->buckets[hash] == NULL)
		(*ht)->buckets[hash] = create_list();

	add_nth_node((*ht)->buckets[hash], (*ht)->buckets[hash]->size, key);
	(*ht)->size++;

	if((float)(*ht)->size / (*ht)->hmax > 0.75) {
		*ht = ht_resize(*ht, 1);
	}

}

int ht_remove_entry(hashtable **ht, int key)
{
	if(ht_has_key(*ht, key) == 0) {
		return 0;
	}

	unsigned int hash = (*ht)->hash_function(&key) % (*ht)->hmax;
	node *ptr = (*ht)->buckets[hash]->head;
	node *rm;
	int i = 0;
	while(ptr) {
		if((*ht)->compare_function(key, ptr->data) == 0) {
			rm = remove_nth_node((*ht)->buckets[hash], i);
			break;
		}
		ptr = ptr->next;
		i++;
	}
	if(rm && ptr) {
		free(rm);
	}

	if((float)(*ht)->size / (*ht)->hmax < 0.15) {
		*ht = ht_resize(*ht, -1);
	}

	return 1;
}

hashtable *ht_free(hashtable *ht)
{
	for(int i = 0; i < ht->hmax; i++) {
		ht->buckets[i] = free_list(ht->buckets[i]);
	}

	free(ht->buckets);
	free(ht);

	return NULL;
}

void ht_replace(hashtable **ht, int a, int b)
{
	if(ht_remove_entry(ht, a)) {
		ht_put(ht, b);
	}
}

void *ht_print(hashtable *ht, FILE *out)
{
	for(int i = 0; i < ht->hmax; i++) {
		if(ht->buckets[i] == NULL)
			continue;
			
		node *ptr1 = ht->buckets[i]->head;
		while(ptr1) {
			fprintf(out, "%d ", ptr1->data);
			ptr1 = ptr1->next;
		}
	}

	fprintf(out, "\n");
}
