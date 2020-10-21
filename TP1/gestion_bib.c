/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                      gestion_bib.c                           */
/*            Traitement de la liste bibliotheque               */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_bib.h"

/****************************************************************/
/* Creation de la sous-liste chainee de la bibliotheque         */
/* Principe :                                                   */
/* allocation et remplissage de l'élément avec les valeurs lues */
/*                                                              */
/* Lexique :                                                    */
/* taille : nombre de cellule de la sous_liste                  */
/* prec : position de la premiere allocation                    */
/* fichier : nom du fichier à lire                              */
/****************************************************************/

void creer_liste(int taille,livre_t ** prec,FILE * fichier){
    livre_t * cour = NULL;
    int i = 0;

    for (i=0;i<taille;i++){
        cour = (livre_t *)malloc(sizeof(livre_t));
        fscanf(fichier,"%d",&cour->num);
        lire(cour->titre,taille_max,fichier);
        cour->emprunt = 0;
        cour->suiv = NULL;
        *prec = cour;
        prec = &cour->suiv;
    }
}

/****************************************************************/
/* Creation de la liste chainee de la bibliotheque              */
/* Principe :                                                   */
/* allocation et remplissage de l'élément avec les valeurs lues */
/*                                                              */
/* Lexique :                                                    */
/* file : nom de fichier a lire                                 */
/* res : pointeur sur le début de la liste chainee              */
/****************************************************************/

void lecture_fichier(const char * file, biblio_t ** res){
    biblio_t * cour = NULL;
    biblio_t ** prec = NULL;
    livre_t ** liste = NULL;
    prec = res;
    int taille = 0;
    FILE * fichier = NULL;
    fichier = fopen(file,"r");
    if (fichier != NULL){
        while(!feof(fichier)){
            cour=(biblio_t *)malloc(sizeof(biblio_t));
            cour->pointeur=NULL;
            cour->suiv=NULL;
            if(fscanf(fichier,"%s",cour->categorie)>0){ //empêche les doublons !!!
                fscanf(fichier,"%d",&taille);
                liste = &cour->pointeur;
                creer_liste(taille,liste,fichier);
                *prec = cour;
                prec = &cour->suiv;
            }
       }
    fclose(fichier);
    }

}

/****************************************************************/
/* Gestion du booleen disant si le livre est emprunte ou pas    */
/* Principe :                                                   */
/* Parcours de la bibliotheque jusqu'à trouver le livre emprunte*/
/*                                                              */
/* Lexique :                                                    */
/* bibli : pointeur sur le debut de la bibliotheque             */
/* numero : numero du livre recherche                           */
/* empr : booleen indiquant sur le livre est emprunte           */
/* exist : booleen indiquant si le livre exist ou si il est deja*/
/* empreinte                                                    */
/****************************************************************/

void gestion_emprunt(biblio_t ** bibli,int numero,int empr,int *exist){
    biblio_t * cour = NULL;
    livre_t * cour2 = NULL;
    cour = *bibli;
    int ok = 0;
    while ((cour != NULL)&&(ok != 1)){
        if (cour != NULL){
            cour2 = cour->pointeur;
            while ((cour2 != NULL)&&(cour2->num != numero)){
                cour2 = cour2->suiv;
            }
            if(empr == 1){
                if ((cour2 != NULL) && (cour2->emprunt != 1)){
                    cour2->emprunt = empr;
                    ok = 1;
                    *exist = 1;
                }
                else{
                    *exist = 0;
                }
            }
            else{
                if(cour2 != NULL){
                    cour2->emprunt =empr;
                    ok = 1;
                }
            }
        }
        cour = cour->suiv;
    }
}

/****************************************************************/
/* Affichage de la sous-liste chainee                           */
/* Principe :                                                   */
/* Parcours de la liste et affichage des elements               */
/*                                                              */
/* Lexique :                                                    */
/* liste : pointeur sur le debut de la sous-liste               */
/****************************************************************/

void affiche_cat(livre_t ** liste){
    livre_t * cour = *liste;
    while(cour != NULL){
        printf("Numero = %d, Titre =%s, Emprunt=%d\n",cour->num,cour->titre,cour->emprunt);
        cour = cour->suiv;
    }

}

/****************************************************************/
/* Affichage de la liste bibliotheque                           */
/* Principe :                                                   */
/* Parcours de la liste et affichage des categories             */
/*                                                              */
/* Lexique :                                                    */
/* bibli : pointeur sur le debut de la bibliotheque             */
/****************************************************************/

void affiche_bibli(biblio_t ** bibli){
    biblio_t * cour = *bibli;
    printf("\n");
    while(cour != NULL){
        printf("Cat = %s\n",cour->categorie);
        affiche_cat(&cour->pointeur);
        cour = cour->suiv;
    }
    printf("\n");
    
}

/****************************************************************/
/* Suppression du \0 du fgets                                   */
/* Principe :                                                   */
/* determination de la taille de l'element lu et remplacement du*/
/* dernier caractere                                            */
/*                                                              */
/* Lexique :                                                    */
/* chaine : chaine de caractere lu                              */
/* taille : taille de la chaine de caractere lu                 */
/* fichier : nom de fichier devant etre lu                      */
/****************************************************************/

void lire(char *chaine, int taille, FILE * fichier){
    char *posentrer = NULL;
    if (fgets(chaine,taille,fichier) != NULL){
        posentrer = strchr(chaine,'\n');
        if (posentrer != NULL){
            *posentrer = '\0';
        }
    }
}

/****************************************************************/
/* Liberation de la bibliotheque                                */
/* Principe :                                                   */
/* Parcours de la bibliotheque et liberation de chaque elements */
/*                                                              */
/* Lexique :                                                    */
/* bibli : pointeur sur le debut de la bibliotheque             */
/****************************************************************/

void liberer_bib(biblio_t ** bibli){
    biblio_t * tmp1;
    biblio_t * cour = *bibli;
    livre_t * cour2 = NULL;
    livre_t * tmp2;
    while(cour != NULL){
        tmp1 = cour->suiv;
        cour2 = cour->pointeur;
        while(cour2 != NULL){
            tmp2 = cour2->suiv;
            free(cour2);
            cour2 = tmp2;
        }
        free(cour);
        cour = tmp1;
    }
}