/*-----------------------------------------------------*/
/*                    gestion_pile.c                   */
/*                                                     */
/*  impl�mentation des fonction de gestion de la pil  */
/*                                                     */
/*-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_pile.h"

/*-----------------------------------------------------*/
/* init_pile      Initialisation d'une nouvelle pile   */
/*                                                     */
/* en entr�e : un pointeur sur la pile � intialiser  */
/*             en entier pour la taille de la pile    */
/* en sortie : un pointeur sur la pile initialis�e   */
/*                                                   */
/*----------------------------------------------------*/

pile_t * init_pile(pile_t * pile, int taille)
{
	pile = (pile_t *)malloc(sizeof(pile_t));

	if(pile)
	{
		pile->taille = taille;
		pile->sommet = -1;
		pile->tab = (type_empile *)malloc(taille*sizeof(type_empile));
	}

	return pile;
}

/*------------------------------------------------------*/
/* est_vide_pile  Un bool�en qui indique si une pile   */
/*                est vide                             */
/* en entr�e : un pointeur sur la pile � v�rifier    */
/*                                                     */
/* en sortie : un entier qui sert de bool�en (1/0)    */
/*                                                     */
/*-----------------------------------------------------*/

int est_vide_pile(pile_t * pile)
{
	return (pile->sommet == -1);
}

/*------------------------------------------------------*/
/* est_pleine_pile  Un bool�en qui indique si une pile */
/*                est pleine                            */
/* en entr�e : un pointeur sur la pile � v�rifier    */
/*                                                     */
/* en sortie : un entier qui sert de bool�en (1/0)    */
/*                                                     */
/*-----------------------------------------------------*/

int est_pleine_pile(pile_t * pile)
{
	return (pile->taille - 1 == pile->sommet);
}

/*-----------------------------------------------------*/
/* sommet_pile  Renvoie la valeur du sommet d'une pile */
/*                                                     */
/* en entr�e : un pointeur sur la pile                */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'ex�cution s'est bien d�roul�e, un pointeur */
/*    sur la variable r�sultat                        */
/*-----------------------------------------------------*/

void sommet_pile(pile_t * pile, int * code, type_empile * res)
{
	*code = 0;
	if (!est_vide_pile(pile))
	{
		*res = pile->tab[pile->sommet];
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* empiler   Empile une valeur au sommet de la pile    */
/*                                                     */
/* en entr�e : un pointeur sur la pile                */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'ex�cution s'est bien d�roul�e, une variable */
/*    contenant la valeur � empiler                   */
/*-----------------------------------------------------*/

void empiler(pile_t * pile, int * code, type_empile val)
{
	*code = 0;
	if(!est_pleine_pile(pile))
	{
		pile->sommet ++;
		pile->tab[pile->sommet] = val;
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* depiler    D�pile la valeur de sommet d'une pile   */
/*                                                     */
/* en entr�e : un pointeur sur la pile                */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'ex�cution s'est bien d�roul�e, un pointeur */
/*    sur la variable r�sultat                        */
/*-----------------------------------------------------*/

void depiler(pile_t * pile, int * code, type_empile * res)
{
	*code = 0;
	if(!est_vide_pile(pile))
	{
		*res = pile->tab[pile->sommet];
		pile->sommet --;
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* liberer_pile  Lib�re la m�moire allou�e � la pile*/
/*                                                     */
/* en entr�e : un pointeur sur la pile � lib�rer     */
/*                                                     */
/* en sortie : rien                                    */
/*                                                     */
/*-----------------------------------------------------*/

void liberer_pile(pile_t * pile)
{
	free(pile->tab);
	free(pile);
}

/*-----------------------------------------------------*/
/* afficher_pile    Affiche la pile sur la sortie      */
/*                  standard                           */
/* en entr�e : un pointeur sur la pile � afficher    */
/*                                                     */
/* en sortie : rien                                    */
/*                                                     */
/*-----------------------------------------------------*/

void afficher_pile(pile_t * pile)
{
	int i;

	printf("Contenu de la pile (sommet en premier) : [");
	for(i = pile->sommet; i>=0; i--)
	{
		printf(" %d ", pile->tab[i]);
	}
	printf("] \n");
}
