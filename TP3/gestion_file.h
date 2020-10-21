/*-----------------------------------------------------*/
/*                   gestion_file.h                    */
/*                                                     */
/*   prototypes des fonctions de gestion de la file    */
/*                                                     */
/*-----------------------------------------------------*/

#ifndef __GESTION_FILE_H__
#define __GESTION_FILE_H__

/*---------------------------*/
/*        Structures         */
/*---------------------------*/
#include "arbre.h"

typedef point_t * type_enfile;

typedef struct file
{
	int taille;
	int nb_elem;
	int tete;
	int queue;
	type_enfile * tab;
} file_t;

/*---------------------------*/
/*        Prototypes         */
/*---------------------------*/

file_t * init_file(file_t *, int);
int est_vide_file(file_t *);
int est_pleine_file(file_t *);
void tete_file(file_t *, int *, type_enfile *);
void enfiler(file_t *, int *, type_enfile);
void defiler(file_t *, int *, type_enfile *);
void liberer_file(file_t *);
void afficher_file(file_t *);


#endif
