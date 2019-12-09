#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


enum 
{
	ID,
	ETAT,
	REC,
	COLUMNS
};
void afficher(GtkWidget *liste);


void afficher(GtkWidget *liste)
{
GtkCellRenderer * renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char etat[1];
char id[2];
char rec[100];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new();					column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new();				column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("reclamation.txt","a+");
 while(fscanf(f,"%3s%3s%50s\n",id,etat,rec)!=EOF)
  {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store,      &iter,ID,id,ETAT,etat,REC,rec, -1);
  }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

}

void afficher_rep(GtkWidget *liste);

void afficher_rep(GtkWidget *liste)
{
GtkCellRenderer * renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[3];
char rec[50];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new();					column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);



	renderer=gtk_cell_renderer_text_new();				column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("Rep.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("Rep.txt","a+");
 while(fscanf(f,"%3s%50s\n",id,rec)!=EOF)
  {
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store,      &iter,ID,id,REC,rec, -1);
  }
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

}




void
on_ajouter_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *principale;
GtkWidget *ajouter;
principale=lookup_widget(objet_graphique,"principale");
gtk_widget_destroy(principale);
ajouter=lookup_widget(objet_graphique,"ajouter");
ajouter=create_ajouter();

gtk_widget_show(ajouter);
}


void
on_afficher_clicked                    (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *principale;
GtkWidget *liste;
GtkWidget *treeview1;
principale=lookup_widget(objet_graphique,"principale");
gtk_widget_destroy(principale);
liste=lookup_widget(objet_graphique,"liste");
liste=create_liste();

gtk_widget_show(liste);
treeview1=lookup_widget(liste,"treeview1");
afficher(treeview1);


}


void
on_envoyer_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char id[3],rec[1000];
GtkWidget *input;
GtkWidget *inputs;
GtkWidget *sortie;
input=lookup_widget(objet_graphique,"entry1");
inputs=lookup_widget(objet_graphique,"entry2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(rec,gtk_entry_get_text(GTK_ENTRY(inputs)));
reclamation(rec,id);
gtk_label_set_text(GTK_LABEL(sortie),"Reclamations envoyer");
}


void
on_retour1_clicked                      (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouter, *principale;

ajouter=lookup_widget(objet_graphique,"ajouter");

gtk_widget_destroy(ajouter);
principale=create_principale();
gtk_widget_show(principale);
}


void
on_retour2_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *liste, *principale;

liste=lookup_widget(objet_graphique,"liste");

gtk_widget_destroy(liste);
principale=create_principale();
gtk_widget_show(principale);
}


void
on_Afficher_Repondus_clicked                 (GtkWidget		*objet_graphique,
                                              gpointer          user_data)
{
GtkWidget *principale;
GtkWidget *Reclamation_Repondus;
GtkWidget *treeview2;
principale=lookup_widget(objet_graphique,"principale");
gtk_widget_destroy(principale);
Reclamation_Repondus=create_Reclamation_Repondus();

gtk_widget_show(Reclamation_Repondus);
treeview2=lookup_widget(Reclamation_Repondus,"treeview2");
afficher_rep(treeview2);

}


void
on_retour3_clicked                      (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Afficher_Repondus, *principale;

Afficher_Repondus=lookup_widget(objet_graphique,"Afficher_Repondus");

gtk_widget_destroy(Afficher_Repondus);
principale=create_principale();
gtk_widget_show(principale);
}
