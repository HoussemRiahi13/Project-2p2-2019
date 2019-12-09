#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"


void reclamation(char rec[],char id[]){

FILE *f;
char etat[4];
strcpy(etat,"0");
f=fopen("reclamation.txt","a+");
fprintf(f,"%s\t%s\t%s\n",id,etat,rec);
fclose(f);

}


