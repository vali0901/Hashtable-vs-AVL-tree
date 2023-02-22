#ifndef __TEST_INSERT_DELETE_H__
#define __TEST_INSERT_DELETE_H__

#include <stdio.h>
#include <time.h>

#include "hashtable.h"
#include "avl.h"

typedef struct test_hashtable  {
	FILE *in;
	FILE *out;
	hashtable *ht;
	clock_t time;
} test_hashtable;

typedef struct test_avl  {
	FILE *in;
	FILE *out;
	struct Node *root;
	clock_t time;
} test_avl;



void *test_insert_hashtable(void *arg);

void *test_delete_hashtable(void *arg);

void *test_random_hashtable(void *arg);

void *test_insert_avl(void *arg);

void *test_delete_avl(void *arg);

void *test_random_avl(void *arg);

#endif