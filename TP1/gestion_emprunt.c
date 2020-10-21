/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                    gestion_emprunt.c                         */
/*             Traitement de la liste des emprunts              */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "gestion_bib.h"
#include "liste_chainne.h"
#include "gestion_emprunt.h"

/****************************************************************/
/* Creation de la bibliotheque d'emprunt                        */
/* Principe :                                                   */
/* Lecture du fichier d'emprunt et creation par adjonction de la*/
/* bibliotheque d'emprunt                                       */
/*                                                              */
/* Lexique :                                                    */
/* bibli : pointeur sur le debut de la bibliotheque             */
/* ptete : pointeur sur le debut de la bibli d'emprunt          */
/* file : nom du fichier à lire                                 */
/****************************************************************/

void fichier_emprunt(biblio_t ** bibli,emprunt_t ** ptete,const char * file){
    FILE * fichier = NULL;
    int numero=0, date=0, exist;
    fichier = fopen(file,"r");
    emprunt_t ** prec = NULL;
    if (fichier != NULL){
        while(!feof(fichier)){
            if(fscanf(fichier,"%d",&numero)!=0){ //empêche les doublons !
                fscanf(fichier,"%d",&date);
                gestion_emprunt(bibli,numero,1,&exist);
                if (exist == 1){
                    prec = prec_a(ptete,date);
                    adjonction(prec,date,numero);
                }
            }
        }
    fclose(fichier);
    }
}

/****************************************************************/
/* Suppression d'elements dans le bibliotheque d'emprunt        */
/* Principe :                                                   */
/* Recherche du precedent de l'element à supprimer pour ensuite */
/* le supprimer et modifier le booleen dans la bibliotheque     */
/*                                                              */
/* Lexique :                                                    */
/* bibli : pointeur sur le debut de la bibliotheque             */
/* ptete : pointeur sur le debut de la bibli d'emprunt          */
/* file : nom du fichier à lire                                 */
/****************************************************************/

void fichier_suppr(biblio_t ** bibli,emprunt_t ** ptete,const char * file){
    FILE * fichier = NULL;
    int numero=0, date=0, exist;
    fichier = fopen(file,"r");
    emprunt_t ** prec = NULL;
    if (fichier != NULL){
        while(!feof(fichier)){
            if(fscanf(fichier,"%d",&numero)!=0){
                fscanf(fichier,"%d",&date);
                gestion_emprunt(bibli,numero,0,&exist);
                prec = prec_s(ptete,numero);
                suppression(prec);
            }
        }
    fclose(fichier);
    }
}

/****************************************************************/
/* Affichage de la liste d'emprunt                              */
/* Principe :                                                   */
/* Parcours de la liste pour afficher la liste                  */
/*                                                              */
/* Lexique :                                                    */
/* liste : pointeur sur le debut de la bibli d'emprunt          */
/****************************************************************/

void affiche_emprunt(emprunt_t ** liste){
    emprunt_t * cour = *liste;
    printf("\n");
    while(cour != NULL){
        printf("Numero = %d, Date =%d\n",cour->num,cour->dateretour);
        cour = cour->suiv;
    }
    printf("\n");
    
}

/****************************************************************/
/* Affichage de tout les emprunts dont la date de retour est    */
/* inferieur à la date donnee                                   */
/* Principe :                                                   */
/* Parcours de la liste pour afficher les livres respectant la  */
/* la condition                                                 */
/*                                                              */
/* Lexique :                                                    */
/* liste : pointeur sur le debut de la bibli d'emprunt          */
/* flux : flux sur laquelle est afficher les informations       */
/* date : date utilise commme condition de test                 */
/****************************************************************/

void imprime_emprunt(emprunt_t ** liste,FILE * flux,int date){
    emprunt_t * cour = *liste;
    while((cour != NULL)&&(cour->dateretour<date)){
        fprintf(flux,"Numero = %d, Date =%d\n",cour->num,cour->dateretour);
        cour = cour->suiv;
    }
    
}

/****************************************************************/
/* Impression de la liste d'emprunt dans un fichier             */
/* Principe :                                                   */
/* Parcours de la liste pour la copier dans un fichier          */
/*                                                              */
/* Lexique :                                                    */
/* liste : pointeur sur le debut de la bibli d'emprunt          */
/****************************************************************/

void sauvegarde_emprunt(emprunt_t ** liste){
    emprunt_t *cour = *liste;
    FILE * save = NULL;
    save = fopen("save.txt","w");
    if (save != NULL){
        while(cour != NULL){
            fprintf(save,"%d %d\n",cour->num,cour->dateretour);
            cour = cour->suiv;
        }
        fclose(save);
    }
}

/****************************************************************/
/* Liberation de la liste d'emprunt                             */
/* Principe :                                                   */
/* Parcours de la liste et liberation de chaque elements        */
/*                                                              */
/* Lexique :                                                    */
/* liste : pointeur sur le debut de la liste                    */
/****************************************************************/

void liberer_emprunt(emprunt_t ** liste){
    emprunt_t * tmp;
    emprunt_t * cour = *liste;
    while(cour != NULL){
        tmp = cour->suiv;
        free(cour);
        cour = tmp;
    }
}