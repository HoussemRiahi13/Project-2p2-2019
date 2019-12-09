#include <stdio.h>
#include<string.h>
#include"compte.h"
#include<gtk/gtk.h>

enum 
{
	NOM,
	PRENOM,
	CIN,
	ADRESSE,
	COLUMNS
};
void ajouter_compte(compte c)
{
FILE *f;
f=fopen("compte.txt","a+");
if 
(f!=NULL)
{
fprintf(f,"%20s%20s%20s%100s \n",c.nom,c.prenom,c.cin,c.adresse);
}
fclose(f);
}
void afficher_compte(GtkWidget *liste)
{
GtkCellRenderer * renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
char adresse[100];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new();					column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new();				column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new();					column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("compte.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("compte.txt","a+");
 while(fscanf(f,"%20s%20s%20s%100s\n",nom, prenom,cin,adresse)!=EOF)
  {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store,      &iter,NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse, -1);
  }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

}





void modifier_compte(compte c ,char cin[20] )
{

FILE *f1;
FILE *f2;

f1=fopen("compte.txt","r");
f2=fopen("compte1.txt","a+");
if
((f2!=NULL) && (f1!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%100s",c.nom,c.prenom,c.cin,c.adresse)!=EOF)
{
if (c.cin != cin )
{
fprintf(f2,"%20s%20s%20s%100s",c.nom,c.prenom,c.cin,c.adresse);
}
else{
	/*supprimer_compte(c, cin[20]  );*/
	ajouter_compte(c);
}
fclose(f1);
fclose(f2);
remove("compte.txt");
rename("compte1.txt","compte.txt");

}

}
}


void supprimer_compte(compte c, char cin[]  )
{
FILE *f1;
FILE *f2;
f1=fopen("compte.txt","r");
f2=fopen("compte1.txt","a+");
if ((f1!=NULL) && (f2!=NULL))
{
while(fscanf(f1,"%20s%20s%20s%100s \n",c.nom,c.prenom,c.cin,c.adresse)!=EOF)
{
if (c.cin != cin )
{
fprintf(f2,"%20s%20s%20s%100s \n",c.nom,c.prenom,c.cin,c.adresse);
}
}
fclose(f1);
fclose(f2);
remove("compte.txt");
rename("compte1.txt","compte.txt");
}
}


		




