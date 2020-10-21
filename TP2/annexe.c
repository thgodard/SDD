/*-----------------------------------------------------*/
/*                    annexe.c                         */
/*                                                     */
/*   implémentation de la fonction inversion           */
/*    et de la fonction d'Ackermann                    */
/*-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "gestion_file.h"
#include "gestion_pile.h"

/*-----------------------------------------------------*/
/* inverser_pile   Inverse une pile sans en           */
/*                    créer une nouvelle               */
/* en entrée : un pointeur sur la pile à inverser      */
/*                                                     */
/* en sortie : rien, la modification est faite par     */
/*             effet de bord                           */
/*-----------------------------------------------------*/


void inverser_pile(pile_t * pile)
{
	file_t * file = NULL;
	int codep = 1, codef = 1;
	type_empile resp;
	type_enfile resf;

	file = init_file(file, pile->taille);

	if(pile)
	{
		while(!est_vide_pile(pile))
		{
			depiler(pile, &codep, &resp);
			if(codep)
			{
				resf = resp;
				enfiler(file, &codef, resf);
			}
		}

		while(!est_vide_file(file))
		{
			defiler(file, &codef, &resf);
			if(codef)
			{
				resp = resf;
				empiler(pile, &codep, resp);
			}
		}
	}

	liberer_file(file);
}

/*-----------------------------------------------------*/
/* ackermann   Version récursive de la fonction        */
/*                    d'Ackermann                      */
/* en entrée : deux entiers et la taille de la pile    */
/*                 utilisée                            */
/* en sortie : la valeur de la fonction                */
/*                                                     */
/*-----------------------------------------------------*/

int ackermann(int m, int n, int taille_pile)
{
	pile_t * pile = NULL;
	int ml = m, nl = n;
	int codep = 1;
	int fin = 0;
	int taille_ok = 1;

	pile = init_pile(pile, taille_pile);

	while(!fin && taille_ok)
	{
		if(ml == 0)
		{
			nl ++;

			if(!est_vide_pile(pile))
			{
				depiler(pile, &codep, &ml);
				ml --;
			}
			else
			{
				fin = 1;
			}
		}
		else
		{
			if(nl == 0)
			{
				ml --;
				nl = 1;
			}
			else
			{
				empiler(pile, &taille_ok, ml);
				nl --;
			}
		}
	}

	if(!taille_ok)
	{
		fprintf(stderr, "Taille de pile insuffisante. \n");
	}

	return nl;
}
