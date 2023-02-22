#include "test_util.h"

// functie folosita pentru testarea inserarii
void *test_insert_hashtable(void *arg)
{
	test_hashtable *helper = (test_hashtable *)arg;
	helper->time = clock();

	helper->ht = ht_create(6);

	int instruction, data, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d%d", &instruction, &data);
		ht_put(&helper->ht, data);
	}

	helper->time = clock() - helper->time;
	return NULL;
}

// functie folosita pentru testarea stergerii
void *test_delete_hashtable(void *arg)
{
	test_hashtable *helper = (test_hashtable *)arg;
	helper->time = clock();

	int instruction, data, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d%d", &instruction, &data);
		ht_remove_entry(&helper->ht, data);
	}

	helper->time = clock() - helper->time;
	return NULL;
}

// functie folosita pentru testarea diferitelor operatii,
// dar si pentru run-p1, adica orice tip de fisier de intrare
void *test_random_hashtable(void *arg)
{
	test_hashtable *helper = (test_hashtable *)arg;
	helper->time = clock();
	
	helper->ht = ht_create(6);

	int instruction, data1, data2, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d", &instruction);
		switch (instruction)
		{
		case 0:
			fscanf(helper->in, "%d", &data1);
			ht_put(&helper->ht, data1);
			break;
		case 1:
			fscanf(helper->in, "%d", &data1);
			ht_remove_entry(&helper->ht, data1);
			break;
		case 2:
			fscanf(helper->in, "%d", &data1);
			fprintf(helper->out, "%d\n", ht_has_key(helper->ht, data1));
			break;
		case 3:
			fscanf(helper->in, "%d%d", &data1, &data2);
			ht_replace(&helper->ht, data1, data2);
			break;
		case 4:
			ht_print(helper->ht, helper->out);
			break;
		
		default:
			break;
		}
	}

	ht_free(helper->ht);
	
	helper->time = clock() - helper->time;

	return NULL;
}

// functie folosita pentru testarea inserarii
void *test_insert_avl(void *arg)
{
	test_avl *helper = (test_avl *)arg;
	helper->time = clock();

	int instruction, data, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d%d", &instruction, &data);
		helper->root = insertNode(helper->root, data);
	}

	helper->time = clock() - helper->time;
	return NULL;
}

// functie folosita pentru testarea stergerii
void *test_delete_avl(void *arg)
{
	test_avl *helper = (test_avl *)arg;
	helper->time = clock();

	int instruction, data, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d%d", &instruction, &data);
		helper->root = deleteNode(helper->root, data);
	}

	helper->time = clock() - helper->time;
	return NULL;
}


// functie folosita pentru testarea diferitelor operatii,
// dar si pentru run-p2, adica orice tip de fisier de intrare
void *test_random_avl(void *arg)
{
	test_avl *helper = (test_avl *)arg;
	helper->time = clock();

	int instruction, data1, data2, nr;
	fscanf(helper->in, "%d", &nr);

	for(int i = 0; i < nr; i++) {
		fscanf(helper->in, "%d", &instruction);
		switch (instruction)
		{
		case 0:
			fscanf(helper->in, "%d", &data1);
			helper->root = insertNode(helper->root, data1);
			break;
		case 1:
			fscanf(helper->in, "%d", &data1);
			helper->root = deleteNode(helper->root, data1);
			break;
		case 2:
			fscanf(helper->in, "%d", &data1);
			fprintf(helper->out, "%d\n", hasElem(helper->root, data1));
			break;
		case 3:
			fscanf(helper->in, "%d%d", &data1, &data2);
			helper->root = replaceElem(&helper->root, data1, data2);
			break;
		case 4:
			printElem(helper->root, helper->out);
			break;
		
		default:
			break;
		}
	}

	freeTree(helper->root);
	helper->time = clock() - helper->time;
	return NULL;
}