#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "gestion_pile.h"


int main()
{
	char * exp_alg;
	int t;
	point_t * racine;
	FILE * fich = fopen("testerino.txt", "r");
	t = recup_chaine(fich, exp_alg);
	afficher_chaine(exp_alg, t);

	racine = creer_arbre(exp_alg, t);
	afficher_parcours_postfixe(racine);
	insertionArbre(racine, 'h', 'j');
	afficher_parcours_postfixe(racine);
	insertionArbre(racine, 'a', 't');
	afficher_parcours_postfixe(racine);

	return 0;
}