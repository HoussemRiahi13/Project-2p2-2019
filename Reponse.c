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

void supprimer_rec(char id[])
{
FILE *f1;
FILE *f2;
char ids[5];
char etat[3];
char rec1[50];

f1=fopen("Rep.txt","r");
f2=fopen("Rep2.txt","a+");
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
remove("Rep.txt");
rename("Rep2.txt","Rep.txt");
}
}
}

void modifier(char id[]){

FILE *f1;
FILE *f2;
char ids[5];
char etat[3];
char rec1[50];



f1=fopen("Rep.txt","r");
f2=fopen("Rep2.txt","a+");
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
remove("Rep.txt");
rename("Rep2.txt","Rep.txt");
}
}
}
