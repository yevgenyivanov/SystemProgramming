
all: connections

connections: main.o my_mat.o
	gcc main.o my_mat.o -o connections

main.o: main.c my_mat.h
	gcc -c main.c -o main.o

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c -o my_mat.o

	