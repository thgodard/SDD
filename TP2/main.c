/*-----------------------------------------------------*/
/*                    main.c                           */
/*                                                     */
/*         programme principal                         */
/*-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "gestion_pile.h"
#include "gestion_file.h"
#include "annexe.h"

int main()
{

	file_t * file = NULL;
	int codef = 1;
	type_enfile resf, ij = 0;
	file_t * filev = NULL;
/*
	pile_t * pile = NULL;
	int codep = 1;
	type_empile resp, i;

	pile_t * pilev = NULL;
	pilev = init_pile(pile, 7);

	pile = init_pile(pilev, 7);
	i = 0;

	while(codep)
	{
		empiler(pile, &codep, i);
		i ++;
	}
	afficher_pile(pile);
	depiler(pile, &codep, &resp);
	afficher_pile(pile);

	afficher_pile(pilev);
	inverser_pile(pilev);
	afficher_pile(pilev);

	printf("ack(1,4) = %d \n", ackermann(1,4,1000));
	printf("ack(2,4) = %d \n", ackermann(2,4,1000));
	printf("ack(1,5) = %d \n", ackermann(1,5,1000));
	printf("ack(3,3) = %d \n", ackermann(3,3,1000));
*/
	file = init_file(file, 7);
	filev = init_file(filev, 7);


	while(codef && ij<5)
	{
		enfiler(file, &codef, ij);
		ij++;
	}

	afficher_file(file);
	enfiler(file, &codef, 11);
	if(!codef)
	{
		printf("File pleine\n");
	}
	afficher_file(file);

	printf("\n");

	afficher_file(file);
	defiler(file, &codef, &resf);
	afficher_file(file);


//	liberer_pile(pile);
	liberer_file(file);
	liberer_file(filev);
	return 0;
}

