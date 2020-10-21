/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                      gestion_bib.h                           */
/*            Traitement de la liste bibliotheque               */
/****************************************************************/

#ifndef GESTION_LIB
#define GESTION_LIB

#define taille_max 40
typedef struct liste_livre
{
    int num;
    char titre[taille_max];
    int emprunt;
    struct liste_livre * suiv;
}livre_t;

typedef struct liste_biblio
{
    char categorie[3];
    struct liste_livre * pointeur;
    struct liste_biblio * suiv;
}biblio_t;

void creer_liste(int taille,livre_t ** prec,FILE * fichier);
void lecture_fichier(const char * file, biblio_t ** res);
void gestion_emprunt(biblio_t ** bibli,int numero,int empr,int *exist);
void affiche_cat(livre_t ** liste);
void affiche_bibli(biblio_t ** bibli);
void lire(char *chaine, int taille, FILE * fichier);
void liberer_bib(biblio_t ** bibli);


#endif