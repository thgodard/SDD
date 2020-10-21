#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_hachage.h"

int main(){

    tabhachage_t * tab = NULL;
    tab = Init_Tab(29);
    FILE * fich = fopen("phrase.txt", "r");
    Creation_tab(fich, tab);
    Affichage_table(tab);

    /*
    int code = 0;
    char abc[6] = "bonbon";
    table_t ** pos = NULL;
    printf("Mot Recherché : %s\n", abc);
    code = Rech_mot(tab,abc,&pos);
    printf("Booleen indiquant si le mot est trouvé : %d\n",code);
    */

    fclose(fich);
    return 0;
}