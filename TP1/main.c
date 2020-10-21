/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                          main.c                              */
/*                      Gestion du menu                         */
/*                    Programme principal                       */
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_bib.h"
#include "liste_chainne.h"
#include "gestion_emprunt.h"

int main(int argc, char *argv[]){
    biblio_t * bibli = NULL;
    emprunt_t * list_emprunt=NULL;

    if (argc == 2){
    lecture_fichier(argv[1],&bibli); 
    printf("Affichage de la bibliotheque :");
    affiche_bibli(&bibli);


    fichier_emprunt(&bibli,&list_emprunt,"emprunt.txt");
    printf("Affichage de la bibliotheque apres lecture liste emprunt :");
    affiche_bibli(&bibli);
    printf("Affichage de la liste des emprunts :");
    affiche_emprunt(&list_emprunt);
    sauvegarde_emprunt(&list_emprunt);
    printf("Affichage des emprunts apres une date donnee :\n");
    imprime_emprunt(&list_emprunt,stdout,19961103);
    printf("\n");

    fichier_suppr(&bibli,&list_emprunt,"rendu.txt");
    printf("Affichage de la bibliotheque apres lecture liste suppr :");
    affiche_bibli(&bibli);
    printf("Affichage de la liste des emprunts :");
    affiche_emprunt(&list_emprunt);
    sauvegarde_emprunt(&list_emprunt);

    liberer_bib(&bibli);
    liberer_emprunt(&list_emprunt);

    }
    
    return 0;
}

