#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"
void ajouter(char login[],char password[],int role)
{
FILE *f;
f=fopen("Users.txt","a");
if (f==NULL)
{ printf("error");}
printf("donner votre login");
scanf("%s",login);
printf("donner votre password");
scanf("%s",password);
printf("donner votre role");
scanf("%d",&role);
fprintf(f,"%s %s %d \n",login,password,role);
fclose(f);
}

void affiche()
{ static int counter =0;
int r;
FILE *f=fopen("Users.txt","r");
char login[100] ,password[100];
while(!feof(f))
{ fscanf(f,"%s %s %d",login,password,&r);
  fprintf(stdout ,"%s %s %d" ,login,password,r);
  counter++;
}
fclose(f);
}

int verifier (char username[], char password[])
{
FILE* f;
char User[50];
char Passwd[50];
int r;
f=fopen("Users.txt","r");

if(f!=NULL)
{
while (fscanf(f,"%s %s %d",User,Passwd,&r)!=EOF)
   {
     if(strcmp(username,User)==0 && strcmp(password,Passwd)==0)
      {
       fclose(f);
       return (r);
      }
   }
}

fclose(f);
return -1;
}


