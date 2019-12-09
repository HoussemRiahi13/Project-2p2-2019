#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Reponse.h"


void Reponse(char id[],char rec[])
{

FILE *f1;

f1=fopen("Rep.txt","a+");
fprintf(f1,"%s %s\n",id,rec);
fclose(f1);

}


