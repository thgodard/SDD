/* ----------------------------------------------------------------------------*/
/*                                  arbre.c                                    */
/*                                                                             */
/*        Implémentation des fonctions de gestion de l'arbre                   */
/*                                                                             */
/* ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "gestion_pile.h"
#include "gestion_file.h"

/* ----------------------------------------------------------------------------*/
/*     Récupération de la chaîne de caractères pour créer l'arbre              */
/*                                                                             */
/*  Entrée : fichier : pointeur sur le fichier qui contient la chaîne          */
/*           chaine : pointeur sur la chaîne récupérée                         */
/*                                                                             */
/*  Sortie : la taille de la chaîne récupérée                                  */
/* ----------------------------------------------------------------------------*/

int recup_chaine(FILE * fichier, char * chaine)
{
	int taille = 0;
	char val;
	
	while(!feof(fichier))
	{
		taille ++;
		val = fgetc(fichier);
		chaine[taille] = val;
	}

	return taille - 1;
}

/* ----------------------------------------------------------------------------*/
/*              Affichage de la chaîne de caractères récupérée                 */
/*                                                                             */
/*  Entrée : chaine : pointeur sur la chaîne de caractères à afficher          */
/*           taille : taille de la chaîne à afficher                           */
/*                                                                             */
/*  Sortie : affichage de la chaîne de caractères sur la sortie standard       */
/* ----------------------------------------------------------------------------*/

void afficher_chaine(char * chaine, int taille)
{
	int i;

	for(i = 0; i<taille; i++)
	{
		printf("%c", chaine[i]);
	}

	printf("\n");

}

/* ----------------------------------------------------------------------------*/
/*            Création d'un point de l'arbre                                   */
/*                                                                             */
/*  Entrée : valeur : la valeur affectée au point créé                         */
/*                                                                             */
/*  Sortie : un pointeur sur le point créé                                     */
/* ----------------------------------------------------------------------------*/

point_t * creer_point(char valeur)
{
	point_t * point = (point_t *)malloc(sizeof(point_t));
	point->val = valeur;
	point->lh = NULL;
	point->lv = NULL;
	return point;
}

/* ----------------------------------------------------------------------------*/
/*               Création de l'arbre                                           */
/*                                                                             */
/*  Entrée : expression : chaîne de caractères qui contient l'expression       */
/*           algébrique de l'arbre                                             */
/*           taille : la taille de la chaîne contenant l'expression algébrique */
/*  Sortie : un pointeur sur la racine de l'arbre                              */
/* ----------------------------------------------------------------------------*/

point_t * creer_arbre(char * expression, int taille)
{
	pile_t * pile = init_pile(pile, 30);
	point_t * tete = NULL;
	point_t ** prec = &tete;
	point_t * cour = tete;

	point_t * nv_point = NULL;
	int ok, i;
	int nouv_expr = 1;
	
	for(i=0;i<taille;i++)
	{
		switch(expression[i])
		{
			case '*' :
				prec = &cour->lv;
				break;

			case '+' :
				depiler(pile, &ok, &cour);
				nouv_expr = 1;
				prec = &cour->lh;
				break;

			case '(' :
				nouv_expr = 1;
				break;

			case ')' :
				depiler(pile, &ok, &cour);
				break;

			default : 
				nv_point = creer_point(expression[i]);
				*prec = nv_point;
				cour = nv_point;

				if(nouv_expr)
				{
					empiler(pile, &ok, cour);
					nouv_expr = 0;
				}
				break;
		}
	}

	liberer_pile(pile);

	return tete;
}

/* ----------------------------------------------------------------------------*/
/*                Affichage du parcours postfixé de l'arbre                    */
/*                                                                             */
/*  Entrée : tete : pointeur sur la racine de l'arbre duquel on affiche le     */
/*           parcours postfixé                                                 */
/*                                                                             */
/*  Sortie : affichage du parcours postfixé sur la sortie standard             */
/* ----------------------------------------------------------------------------*/

void afficher_parcours_postfixe(point_t * tete)
{
	point_t * cour = tete;
	pile_t * pilex = init_pile(pilex, 30);
	int ok = 0;

	while(cour != NULL)
	{
		empiler(pilex, &ok, cour);
		cour = cour->lv;

		while((cour==NULL) && !(est_vide_pile(pilex)))
		{
			depiler(pilex, &ok, &cour);
			printf("%c ", cour->val);
			cour = cour->lh;
		}
	}
	printf("\n");
	liberer_pile(pilex);
}

/* ----------------------------------------------------------------------------*/
/*     Insertion d'un point dans un arbre connaissant la valeur du pere        */
/*                                                                             */
/*  Entrée : tete: pointeur de l'arbre                                         */
/*          val_rech: valeur du point que l'on recherche (pere)                */
/*          val_inser: valeur que l'on veut inserer                            */
/*  Sortie : insertion du point par effet de bord                              */
/* ----------------------------------------------------------------------------*/

void insertionArbre(point_t * tete, char val_rech, char val_inser){
    point_t * pere = recherchepere(tete, val_rech);
    if(pere != NULL){
    	insertionfils(&(pere->lv), val_inser);     
    }
}

/* ----------------------------------------------------------------------------*/
/*     Recherche du père d'un point de l'arbre, connaissant sa valeur          */
/*                                                                             */
/*  Entrée : tete: pointeur de l'arbre                                         */
/*           val : valeur du point dont on recherche le père                   */
/*                                                                             */
/*  Sortie : un pointeur sur le point père trouvé                              */
/* ----------------------------------------------------------------------------*/

point_t * recherchepere(point_t * tete, char val){
    pile_t * file = init_file(file, 30);
    point_t * cour = tete;
    int code;
    while((cour != NULL) && (cour->val != val)){
        enfiler(file, &code, cour);
        cour = cour->lh;
        while(cour == NULL && !est_vide_file(file)){
            defiler(file, &code, &cour);
            cour = cour->lv;
        }
    }
    liberer_file(file);
    return cour;
}

/* ----------------------------------------------------------------------------*/
/*     Insertion d'un point dans la liste des fils                             */
/*                                                                             */
/*  Entrée : tete: pointeur de l'arbre                                         */
/*           val : valeur du point que l'on veut insérer                       */
/*                                                                             */
/*  Sortie : insertion d'un point par effet de bord                            */
/* ----------------------------------------------------------------------------*/

void insertionfils(point_t ** tete, char val){
    point_t * nouv_fils = creer_point(val);
    point_t * cour = *tete;
    point_t ** prec = tete;
    if (nouv_fils != NULL)
    {
        while ((cour != NULL) && (val > cour->val))
        {
            prec = &(cour->lh);
            cour = cour->lh;
        }
        nouv_fils->lh = cour;
        *prec = nouv_fils;
    }
}
