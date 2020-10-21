/*-----------------------------------------------------*/
/*                   gestion_pile.h                    */
/*                                                     */
/*   prototypes des fonctions de gestion de la pile    */
/*                                                     */
/*-----------------------------------------------------*/


#ifndef __GESTION_PILE_H__
#define __GESTION_PILE_H__

/*---------------------------*/
/*        Structures         */
/*---------------------------*/
#include "arbre.h"

typedef point_t * type_empile;

typedef struct pile
{
	int taille;
	int sommet;
	type_empile * tab;
} pile_t;

/*---------------------------*/
/*        Prototypes         */
/*---------------------------*/

pile_t * init_pile(pile_t *, int);
int est_vide_pile(pile_t *);
int est_pleine_pile(pile_t *);
void sommet_pile(pile_t *, int *, type_empile *);
void empiler(pile_t *, int *, type_empile);
void depiler(pile_t *, int *, type_empile *);
void liberer_pile(pile_t *);
void afficher_pile(pile_t *);

#endif
