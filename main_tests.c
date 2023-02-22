#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "hashtable.h"
#include "avl.h"
#include "test_util.h"

// input tests
static char in[18][32] = {
	"./in/test1.in", "./in/test2.in", "./in/test3.in", "./in/test4.in", "./in/test5.in", "./in/test6.in",
	"./in/test7.in", "./in/test8.in", "./in/test9.in", "./in/test10.in", "./in/test11.in","./in/test12.in",
	"./in/test13.in", "./in/test14.in", "./in/test15.in","./in/test16.in", "./in/test17.in", "./in/test18.in"
						};

// output files
static char out[18][32] = {
	"./out/test13.out", "./out/test14.out", "./out/test15.out","./out/test16.out", "./out/test17.out", "./out/test18.out"
						};

// unde se retin valorile obtinute la rularea testelor
static clock_t insert_hashtable[6][10], insert_avl[6][10], delete_hashtable[6][10], delete_avl[6][10], random_hashtable[6][10], random_avl[6][10];

// rularea unui test dat ca parametru pentru hashtable (creeaza un thread)
void run_test_hash(void *test(void *), char *in_path, char *out_path, test_hashtable *result) {
	result->in = fopen(in_path, "r");
	
	if(out_path)
		result->out = fopen(out_path, "w");

	pthread_t thread;

	pthread_create(&thread, NULL, test, result);
	pthread_join(thread, NULL);

	fclose(result->in);

	if(out_path)
		fclose(result->out);
}

// rularea unui test dat ca parametru pentru AVL (creeaza un thread)
void run_test_avl(void *(*test)(void *), char *in_path, char *out_path, test_avl *result) {
	result->in = fopen(in_path, "r");
	
	if(out_path)
		result->out = fopen(out_path, "w");

	pthread_t thread;

	pthread_create(&thread, NULL, test, result);
	pthread_join(thread, NULL);

	fclose(result->in);
	
	if(out_path)
		fclose(result->out);
}

// rularea tuturor testelor
void run_all_tests() {

	// test hashtable
	
	for(int i = 0; i < 6; i++) {
		test_hashtable result;

		// run insert and delete 10 times

		for(int j = 0; j < 10; j++) {
			run_test_hash(test_insert_hashtable, in[i], NULL, &result);
			
			insert_hashtable[i][j] = result.time;

			run_test_hash(test_delete_hashtable, in[i + 6], NULL, &result);

			delete_hashtable[i][j] = result.time;
			
			result.ht = ht_free(result.ht);
		}

		// run random 10 times

		for(int j = 0; j < 10; j++) {
			run_test_hash(test_random_hashtable, in[i + 12], out[i], &result);
			
			random_hashtable[i][j] = result.time;
		}
	}

	// tests avl
   
    for(int i = 0; i < 6; i++) {
		test_avl result;

        // run insert and delete 10 times

        for(int j = 0; j < 10; j++) {
			result.root = NULL;

            run_test_avl(test_insert_avl, in[i], NULL, &result);

            insert_avl[i][j] = result.time;
			
            run_test_avl(test_delete_avl, in[i + 6], NULL, &result);

            delete_avl[i][j] = result.time;
            
			freeTree(result.root);
        }

        // run random 10 times

        for(int j = 0; j < 10; j++) {
			result.root = NULL;

            run_test_avl(test_random_avl, in[i + 12], out[i], &result);
            
            random_avl[i][j] = result.time;
        }
    }
}

// afisarea rezultatelor, facandu-se media aritmetica
void get_results()
{

	for(int i = 0; i < 6; i++) {
		clock_t avg_inserth = 0, avg_inserta = 0;
		clock_t avg_deleteh = 0, avg_deletea = 0;
		clock_t avg_randomh = 0, avg_randoma = 0;

		for(int j = 0; j < 10; j++)
		{
			avg_inserth += insert_hashtable[i][j];
			avg_inserta += insert_avl[i][j];

			avg_deleteh += delete_hashtable[i][j];
			avg_deletea += delete_avl[i][j];

			avg_randomh += random_hashtable[i][j];
			avg_randoma += random_avl[i][j];
		}

		int nr_in;
		switch (i)
		{
		case 0:
			nr_in = 100;
			break;
		case 1:
			nr_in = 250;
			break;
		case 2:
			nr_in = 500;
			break;
		case 3:
			nr_in = 1000;
			break;
		case 4:
			nr_in = 2500;
			break;
		case 5:
			nr_in = 5000;
			break;
		
		default:
			break;
		}

		printf("HASHTABLE vs AVL (%d)\n", nr_in);
		printf("insert: %lu vs %lu\n", avg_inserth / 10, avg_inserta / 10);
		printf("delete:: %lu vs %lu\n", avg_deleteh / 10, avg_deletea / 10);
		printf("random: %lu vs %lu\n\n", avg_randomh / 10, avg_randoma / 10);
	}
}

int main() {

	run_all_tests();

	get_results();

	return 0;
}