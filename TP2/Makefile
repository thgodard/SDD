prog: gestion_pile.o gestion_file.o annexe.o main.o
	gcc -o prog gestion_pile.o gestion_file.o annexe.o main.o -g
	@echo "Lancer le programme avec  ./prog"

gestion_pile.o: gestion_pile.c gestion_pile.h
	gcc -o gestion_pile.o -c gestion_pile.c -Wall -Wextra -g

gestion_file.o: gestion_file.c gestion_file.h
	gcc -o gestion_file.o -c gestion_file.c -Wall -Wextra -g

annexe.o: annexe.c annexe.h
	gcc -o annexe.o -c annexe.c -Wall -Wextra -g

main.o: main.c gestion_pile.h gestion_file.h annexe.h
	gcc -o main.o -c main.c -Wall -Wextra -g

clean:
	rm -f *.o
