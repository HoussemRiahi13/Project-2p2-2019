#include<gtk/gtk.h>

typedef struct 
{
char nom[20];
char prenom[20];
char cin [20];
char adresse[100];

} compte;

void ajouter_compte(compte c);
void afficher_compte(GtkWidget *liste);
