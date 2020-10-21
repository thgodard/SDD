/*-----------------------------------------------------*/
/*                    gestion_file.c                   */
/*                                                     */
/*  implémentation des fonction de gestion de la file  */
/*                                                     */
/*-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "gestion_file.h"

/*-----------------------------------------------------*/
/* init_file      Initialisation d'une nouvelle file   */
/*                                                     */
/* en entrée : un pointeur sur la file à intialiser    */
/*             en entier pour la taille de la file     */
/* en sortie : un pointeur sur la file initialisée     */
/*                                                     */
/*-----------------------------------------------------*/

file_t * init_file(file_t * file, int taille)
{
	file = (file_t *)malloc(sizeof(file_t));

	if(file)
	{
		file->taille = taille;
		file->nb_elem = 0;
		file->tete = 0;
		file->queue = 0;
		file->tab = (type_enfile *)malloc(taille * sizeof(type_enfile));
	}

	return file;
}

/*-----------------------------------------------------*/
/* est_vide_file  Un booléen qui indique si une file   */
/*                est vide                             */
/* en entrée : un pointeur sur la file à vérifier      */
/*                                                     */
/* en sortie : un entier qui sert de booléen (1/0)     */
/*                                                     */
/*-----------------------------------------------------*/

int est_vide_file(file_t * file)
{
	return (file->nb_elem == 0);
}

/*-----------------------------------------------------*/
/* est_pleine_file  Un booléen qui indique si une file */
/*                est pleine                           */
/* en entrée : un pointeur sur la file à vérifier      */
/*                                                     */
/* en sortie : un entier qui sert de booléen (1/0)     */
/*                                                     */
/*-----------------------------------------------------*/

int est_pleine_file(file_t * file)
{
	return (file->nb_elem == file->taille);
}

/*-----------------------------------------------------*/
/* tete_file  Renvoie la valeur de tête d'une file     */
/*                                                     */
/* en entrée : un pointeur sur la file                 */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'exécution s'est bien déroulée, un pointeur    */
/*    sur la variable résultat                         */
/*-----------------------------------------------------*/

void tete_file(file_t * file, int * code, type_enfile * res)
{
	*code = 0;

	if(!est_vide_file(file))
	{
		*res = file->tab[file->tete];
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* enfiler   Enfile une valeur en fin de file          */
/*                                                     */
/* en entrée : un pointeur sur la file                 */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'exécution s'est bien déroulée, une variable   */
/*    contenant la valeur à enfiler                    */
/*-----------------------------------------------------*/

void enfiler(file_t * file, int * code, type_enfile val)
{
	*code = 0;

	if(!est_pleine_file(file))
	{
		file->nb_elem ++;
		file->tab[file->queue] = val;
		file->queue = (file->queue + 1) % file->taille;
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* defiler    Défile la valeur de tête d'une file      */
/*                                                     */
/* en entrée : un pointeur sur la file                 */
/*                                                     */
/* en sortie : un pointeur sur un entier qui indique   */
/*  si l'exécution s'est bien déroulée, un pointeur    */
/*    sur la variable résultat                         */
/*-----------------------------------------------------*/

void defiler(file_t * file, int * code, type_enfile * res)
{
	*code = 0;

	if(!est_vide_file(file))
	{
		*res = file->tab[file->tete];
		file->nb_elem --;
		file->tete = (file->tete + 1) % file->taille;
		*code = 1;
	}
}

/*-----------------------------------------------------*/
/* liberer_file  Libère la mémoire allouée à la file   */
/*                                                     */
/* en entrée : un pointeur sur la file à libérer       */
/*                                                     */
/* en sortie : rien                                    */
/*                                                     */
/*-----------------------------------------------------*/


void liberer_file(file_t * file)
{
	free(file->tab);
	free(file);
}

/*-----------------------------------------------------*/
/* afficher_file    Affiche la file sur la sortie      */
/*                  standard                           */
/* en entrée : un pointeur sur la file à afficher      */
/*                                                     */
/* en sortie : rien                                    */
/*                                                     */
/*-----------------------------------------------------*/

void afficher_file(file_t * file)
{
	int i = file->tete;

	printf("Contenu de la file (tête en premier) : [");

	do
	{
		printf(" %d ", file->tab[i]);
		i = (i+1)%file->taille;
	}
	while(i != file->queue);

	printf("]\n");
}

