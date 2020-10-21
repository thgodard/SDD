prog: gestion_pile.o gestion_file.o arbre.o main.o
	gcc -o prog gestion_pile.o gestion_file.o arbre.o main.o -g
	@echo "Lancer le programme avec  ./prog"

gestion_pile.o: gestion_pile.c gestion_pile.h arbre.h
	gcc -o gestion_pile.o -c gestion_pile.c -Wall -Wextra -g

gestion_file.o: gestion_file.c gestion_file.h arbre.h
	gcc -o gestion_file.o -c gestion_file.c -Wall -Wextra -g

arbre.o: arbre.c arbre.h gestion_pile.h gestion_file.h
	gcc -o arbre.o -c arbre.c -Wall -Wextra -g

main.o: main.c gestion_pile.h gestion_file.h arbre.h 
	gcc -o main.o -c main.c -Wall -Wextra -g

clean:
	rm -f *.o
