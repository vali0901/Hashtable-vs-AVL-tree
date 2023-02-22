#include <stdio.h>
#include <stdlib.h>

#include "test_util.h"
#include "hashtable.h"

// avl

int main() {
    char filein[32] = "./test.in";
    char fileout[32] = "./test.out";

    test_avl helper;
    helper.root = NULL;
    helper.in = fopen(filein, "r");
    helper.out = fopen(fileout, "w");
    
    test_random_avl(&helper);

    fclose(helper.in);
    fclose(helper.out);
}