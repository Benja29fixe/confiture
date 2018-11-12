all: main

main: main.o fonctions.o
	gcc  main.o fonctions.o -o main

main.o: main.c
	gcc -c main.c -o main.o

fonctions_liste.o: fonctions.c fonctions.h
	gcc -c fonctions.c -o fonctions.o

clean:
	rm -r *.o main


