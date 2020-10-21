prog: table_hachage.o main.o
	gcc -o prog table_hachage.o main.o -g
	@echo "Lancer le programme avec  ./prog"

table_hachage.o: table_hachage.c table_hachage.h
	gcc -o table_hachage.o -c table_hachage.c -Wall -Wextra -g

main.o: main.c table_hachage.h
	gcc -o main.o -c main.c -Wall -Wextra -g

clean:
	rm -f *.o
