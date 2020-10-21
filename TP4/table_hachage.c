/****************************************************************/
/*Maxime AUGIGIE-Theo GODARD                                2020*/
/*--------------------------------------------------------------*/
/*                      table_hachage.c                         */
/*            Traitement de la table de hachage                 */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "table_hachage.h"

unsigned int hash_string (const char * str)
{ 
  unsigned int hash = 5381;             /*  fonction de hachage de D.J. Bernstein*/
  const char *s;
  for (s = str; *s; s++)
 	 hash = ((hash << 5) + hash) + tolower(*s);
  return (hash & 0x7FFFFFFF) %HASH_MAX;
}

/*--------------------------------------------------------*/
/*                      Init_Tab                          */
/*Permet de initialiser la table de hachage donc la taille*/
/* est donnee par HASH_MAX                                */
/*                                                        */                           
/*                      Lexique						      */
/* taille: taille de la table de hachage                  */
/*--------------------------------------------------------*/
tabhachage_t * Init_Tab (int taille){
    int i = 0;
    tabhachage_t * tab = (tabhachage_t *)malloc(sizeof(tabhachage_t));
    tab->taille = HASH_MAX;
    tab->point = calloc(HASH_MAX,sizeof(table_t *));
    for (i=0;i<HASH_MAX;i++){
        tab->point[i] = NULL;
    }
    return tab;
}

/*--------------------------------------------------------*/
/*                      Nouv_mot                          */
/*Permet de creer la cellule contenant un nouveau mot qui */
/*ne se trouve pas encore dans la table                   */
/*                                                        */                           
/*                      Lexique						      */
/* nouvcel:Tete de la nouvelle cellule                    */
/* NouvMot:Nouveau mot a integrer dans la table           */
/*--------------------------------------------------------*/

table_t * Nouv_mot(char * NouvMot){
    table_t * nouv = (table_t *)malloc(sizeof(table_t));
    nouv->mot=malloc(20*sizeof(char));
    strcpy(nouv->mot, NouvMot);
    nouv->compteur = 1;
    nouv->suiv = NULL;
    return nouv;
}

/*--------------------------------------------------------*/
/*                      Adj_mot                           */
/*Permet de faire l'adjonction de la nouvelle cellule     */
/* contenant un nouveau mot                               */
/*                                                        */                           
/*                      Lexique						      */
/* prec:Precedent pour effectuer l'adjonction             */
/* nouv:Tete de la nouvelle cellule a ajouter             */
/*--------------------------------------------------------*/

void Adj_mot(table_t ** prec, table_t * nouv){
    nouv->suiv = *prec;
    *prec = nouv;
}

/*--------------------------------------------------------*/
/*                      Rech_mot                          */
/*Permet de recherche un mot dans la table                */
/*                                                        */                           
/*                      Lexique						      */
/* tab:Pointeur sur la tete de la table                   */
/* mot:mot que l'on recherche                             */
/* position:pointeur qui va pointer sur l'endroit ou se   */
/* trouve le mot ou sur NULL                              */
/*--------------------------------------------------------*/

int Rech_mot(tabhachage_t * tab,char * mot, table_t ** position){
    int trouve = 0;
    int code;
    table_t * cour = NULL;
    code = hash_string(mot);
    cour = tab->point[code];
    while ((cour != NULL) && (strcmp(cour->mot, mot))){
        cour = cour->suiv;
    }
    if (cour != NULL){
        trouve = 1;
    }
    *position = cour;
    return trouve;
}

/*--------------------------------------------------------*/
/*                      Insertion_Table                   */
/*Permet d'inserer dans la table chaque mot contenu dans  */
/* la phrase                                              */
/*                                                        */                           
/*                      Lexique						      */
/* phrase: liste de caractere contenant la phrase etudié  */
/* tab: pointeur sur la tete de la table de hachage       */
/*--------------------------------------------------------*/

void Insertion_Table(char * phrase, tabhachage_t * tab){
    char mot[20];
    int i = 0;
    int j = 0;
    int code;
    table_t * nouvcel;
    table_t * position;
    while (phrase[i] != '.'){
        while((phrase[i] != ' ') && (phrase[i] != '.')){
            mot[j] = tolower(phrase[i]);
            i++;
            j++;
        }
        mot[j] = '\0';
        code = hash_string(mot);
        if (!Rech_mot(tab, mot, &position)){
            nouvcel = Nouv_mot(mot);
            Adj_mot(&tab->point[code],nouvcel);
        }
        else{
            position->compteur++;
        }
        if(phrase[i] == ' '){
            i++;
        }
        j = 0;
    }
}

/*--------------------------------------------------------*/
/*                      Creation_tab                      */
/* Sous programme qui va inserer tout les mots dans la    */
/* table de hachage                                       */
/*                                                        */                           
/*                      Lexique						      */
/* fichier: nom de fichier contenant la phrase            */
/*--------------------------------------------------------*/

void Creation_tab(FILE * fichier, tabhachage_t * tab){
    char * phrase[300];
    while(fgets(phrase,300,fichier)>0){
    Insertion_Table(phrase, tab);
    }
    return tab;
}

/*--------------------------------------------------------*/
/*                      Affichage_table                   */
/*Permet d'afficher la table de hachage                   */
/*                                                        */                           
/*                      Lexique						      */
/* tab: pointeur sur la tete de la table de hachage       */
/*--------------------------------------------------------*/

void Affichage_table(tabhachage_t * tab){
    int i = 0;
    table_t * cour = NULL;
    for(i=0;i<HASH_MAX;i++){
        if (tab->point[i] != NULL){
            printf("Dans la ligne %d de la table on a:\n",i);
            cour = tab->point[i];
            while (cour != NULL){
                printf("%s compté %d fois\n",cour->mot,cour->compteur);
                cour = cour->suiv;
            }
        }
    }
}