/****************************************************************/
/*Maxime AUGIGIE-Theo GODARD                                2020*/
/*--------------------------------------------------------------*/
/*                      table_hachage.h                         */
/*            Traitement de la table de hachage                 */
/****************************************************************/

#ifndef __TABLE_HACHAGE_H__
#define __TABLE_HACHAGE_H__

#define HASH_MAX 29

typedef struct table
{
	char * mot;
	int compteur;
	struct table * suiv;
} table_t;

typedef struct tabhachage
{
	int taille;
	table_t ** point;
} tabhachage_t;


unsigned int hash_string (const char *str);
tabhachage_t * Init_Tab (int taille);
table_t * Nouv_mot(char * NouvMot);
void Adj_mot(table_t ** prec, table_t * nouv);
int Rech_mot(tabhachage_t * tab,char * mot, table_t ** position);
void Insertion_Table(char * phrase, tabhachage_t * tab);
void Creation_tab(FILE * fichier, tabhachage_t * tab);
void Affichage_table(tabhachage_t * tab);

#endif