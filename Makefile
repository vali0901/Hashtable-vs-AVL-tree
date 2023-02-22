build:	hashtable.o avl.o test.o main_tests.o
	gcc *.o -Wall -g -o main
	gcc -Wall run_p1.c hashtable.o avl.o test.o -o run_p1
	gcc -Wall run_p2.c avl.o hashtable.o test.o -o run_p2

run-best: run-p2

run-p1: hashtable.o avl.o test.o
	./run_p1

run-p2: hashtable.o avl.o test.o
	./run_p2

main: build
	./main

hashtable.o: hashtable.c hashtable.h
	gcc -c hashtable.c

avl.o: avl.c avl.h
	gcc -c avl.c

test.o: test.c test_util.h
	gcc -c test.c

main_tests.o: main_tests.c
	gcc -c main_tests.c

clean:
	rm *.o main run_p1 run_p2