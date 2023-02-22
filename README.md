# Hash-table vs AVL tree

This is a comparison study between the two data structures used for storing integers (sets).
I've compared the performance depending on three main operations: insertion, deletion and a
set of random operations (insertion, deletion, replacing an element and printing
all elements).

Input tests are generated using the python script and there are 6 tests for each main operation,
each test increasing in size.

The study is presented in the pdf file, containing theoretical comments about these data structures,
and also the interpretation of the results, with a conclusion.

### Input format
* 0 a -> insert element a in the set
* 1 a -> deletes element a from the set
* 2 a -> checks if a exists in the set (print 0 / 1)
* 3 a b -> replace a with b if a exists in the set
* 4 -> prints all the elements in the set

### Makefile rules
* build -> builds all the objects reuired
* main -> runs all the tests and prints at stdout the results (executable from main_tests file)
* run-p1 -> reads from test.in, prints to test.out, testing hashtable implementation
* run-p2 -> reads from test.in, prints to test.out, testing avl tree implementation
* clean -> removes all the object and executable files

### Weaknesses
The input tests contain random generated operations and numbers, so those tests might not be
comparable to real life usages of these data structures.

The time measured for each operation also contains the time used by reading from file operations
which is not constant. In order to soften this problem, i am considering for the comparison the
average time taken by ten executions for each input test.
