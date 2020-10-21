executable : gestion_bib.o gestion_emprunt.o liste_chainne.o main.o
	gcc -o executable gestion_bib.o gestion_emprunt.o liste_chainne.o main.o -g
	@echo "Lancer le programme avec  ./executable"

gestion_bib.o: gestion_bib.c gestion_bib.h
	gcc -o gestion_bib.o -c gestion_bib.c -Wall -Wextra -g

gestion_emprunt.o: gestion_emprunt.c gestion_emprunt.h liste_chainne.h gestion_bib.o
	gcc -o gestion_emprunt.o -c gestion_emprunt.c -Wall -Wextra -g

liste_chainne.o: liste_chainne.c liste_chainne.h
	gcc -o liste_chainne.o -c liste_chainne.c -Wall -Wextra -g

main.o : main.c gestion_bib.h liste_chainne.h gestion_emprunt.h
	gcc -o main.o -c main.c -Wall -Wextra -g

clean : 
	rm -rf *.o 



	
