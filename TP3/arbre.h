/* ----------------------------------------------------------------------------*/
/*                                  arbre.h                                    */
/*                                                                             */
/*        Déclaration des prototypes de fonction et des structures             */
/*                         de gestion de l'arbre                               */
/* ----------------------------------------------------------------------------*/

#ifndef __ARBRE_H__
#define __ARBRE_H__
#include <stdio.h>

/*--------------------------------------*/
/*            STRUCTURES                */
/*--------------------------------------*/

struct point
{
	char val;
	struct point * lh;
	struct point * lv;
};
typedef struct point  point_t;

/*--------------------------------------*/
/*            PROTOTYPES                */
/*--------------------------------------*/

point_t * creer_point(char);
int recup_chaine(FILE *, char *);
void afficher_chaine(char *, int);
point_t * creer_arbre(char *, int);
void afficher_parcours_postfixe(point_t *);
void insertionArbre(point_t *, char , char );
point_t * recherchepere(point_t *, char );
void insertionfils(point_t **, char );

#endif
