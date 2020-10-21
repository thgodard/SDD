/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                      liste_chainne.c                         */
/*          Fonction pour la liste chainee des emprunts         */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste_chainne.h"

/* & = adresse , * = contenu */

/****************************************************************/
/* Recherche du precedent pour effectuer une adjonction         */
/* Principe :                                                   */
/* Parcours de la liste jusqu'a atteindre une date superieur à  */
/* celle donne en entree                                        */
/*                                                              */
/* Lexique :                                                    */
/* ptete : pointeur sur le debut de la liste                    */
/* date : date servant de condition d'arret de parcours         */
/****************************************************************/

emprunt_t ** prec_a(emprunt_t ** ptete, int date){
    emprunt_t * cour = NULL;
    emprunt_t ** prec = NULL;
    cour = *ptete;
    prec = ptete;
    while ((cour != NULL) && (date > cour->dateretour)){
        prec = &cour->suiv;
        cour = cour->suiv;
    }
    return prec;
}

/****************************************************************/
/* Recherche du precedent pour effectuer une suppression        */
/* Principe :                                                   */
/* Parcours de la liste jusqu'à atteindre un le numero du livre */
/* recherche                                                    */
/*                                                              */
/* Lexique :                                                    */
/* ptete : pointeur sur le debut de la liste                    */
/* numero : numero du livre à supprimer de la liste d'emprunt   */
/****************************************************************/

emprunt_t ** prec_s(emprunt_t ** ptete, int numero){
    emprunt_t * cour = NULL;
    emprunt_t ** prec = NULL;
    cour = *ptete;
    prec = ptete;
    while ((cour != NULL) && (numero != cour->num)){
        prec = &cour->suiv;
        cour = cour->suiv;
    }
    return prec;
}

/****************************************************************/
/* Adjonction                                                   */
/* Principe :                                                   */
/* Allocation, remplissage et adjonction dans la liste          */
/*                                                              */
/* Lexique :                                                    */
/* prec : pointeur servant à l'adjontion de la cellule          */
/* date : date de retour du livre                               */
/* numero : numero du livre emprunte                            */
/****************************************************************/

void adjonction(emprunt_t ** prec, int date, int numero){
    emprunt_t * nouv = (emprunt_t *)malloc(sizeof(emprunt_t));
    nouv->num = numero;
    nouv->dateretour = date;
    nouv->suiv = *prec;
    *prec = nouv;
}

/****************************************************************/
/* Suppresion                                                   */
/* Principe :                                                   */
/* Modification du suiv de la cellule precedent la cellule à    */
/* supprimer                                                    */
/*                                                              */
/* Lexique :                                                    */
/* prec : pointeur servant à la suppresion de la cellule        */
/****************************************************************/

void suppression(emprunt_t ** prec){
    emprunt_t * temp = *prec;
    *prec=temp->suiv;
    free(temp);
}


