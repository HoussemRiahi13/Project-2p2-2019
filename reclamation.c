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


void supprimer_rec(char id[])
{
FILE *f1;
FILE *f2;
char ids[5];
char etat[3];
char rec1[50];

f1=fopen("reclamation.txt","r");
f2=fopen("reclamation2.txt","a+");
if 
((f2!=NULL)&&(f1!=NULL))
{
while (fscanf(f1,"%3s%3s%50s",ids,etat,rec1)!=EOF)
{
if (id != ids)
{
fprintf(f2,"%3s%3s%50s",ids,etat,rec1);
}
fclose(f1);
fclose(f2);
remove("reclamation.txt");
rename("reclamation2.txt","reclamation.txt");
}
}
}

void modifier(char id[]){

FILE *f1;
FILE *f2;
char ids[5];
char etat[3];
char rec1[50];



f1=fopen("reclamation.txt","r");
f2=fopen("reclamation2.txt","a+");
if 
((f2!=NULL)&&(f1!=NULL))
{
while (fscanf(f1,"%3s%3s%50s",ids,etat,rec1)!=EOF)
{
if (id != ids)
{
fprintf(f2,"%3s%3s%50s",ids,etat,rec1);
}
else{
	supprimer_rec(id);
	reclamation(id,rec1);
}
fclose(f1);
fclose(f2);
remove("reclamation.txt");
rename("reclamation2.txt","reclamation.txt");
}
}
}
