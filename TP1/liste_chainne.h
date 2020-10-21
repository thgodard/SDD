/****************************************************************/
/*Nicolas Ambal-Theo GODARD                                 2020*/
/*--------------------------------------------------------------*/
/*                      liste_chainne.h                         */
/*          Fonction pour la liste chainee des emprunts         */
/****************************************************************/

#ifndef LISTE_CHAINNE
#define LISTE_CHAINNE

typedef struct liste_emprunt{
    int num;
    int dateretour;
    struct liste_emprunt * suiv;
} emprunt_t;

emprunt_t ** prec_a(emprunt_t ** ptete, int date);
emprunt_t ** prec_s(emprunt_t ** ptete, int numero);
void adjonction(emprunt_t ** prec, int date, int numero);
void suppression(emprunt_t ** prec);


#endif