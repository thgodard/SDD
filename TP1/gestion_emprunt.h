/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                    gestion_emprunt.h                         */
/*             Traitement de la liste des emprunts              */
/****************************************************************/

#ifndef GESTION_EMPRUNT
#define GESTION_EMPRUNT

void fichier_emprunt(biblio_t ** bibli,emprunt_t ** ptete,const char * file);
void fichier_suppr(biblio_t ** bibli,emprunt_t ** ptete,const char * file);
void affiche_emprunt(emprunt_t ** liste);
void imprime_emprunt(emprunt_t ** liste,FILE * flux,int date);
void sauvegarde_emprunt(emprunt_t ** liste);
void liberer_emprunt(emprunt_t ** liste);

#endif