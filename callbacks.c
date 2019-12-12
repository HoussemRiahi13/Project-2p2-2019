#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Reponse.h"

enum 
{
	ID,
	ETAT,
	REC,
	COLUMNS
};
void afficher_rec(GtkWidget *liste);


void afficher_rec(GtkWidget *liste)
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

void
on_Repondre_clicked                    (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *afficher;
GtkWidget *Reponse;
afficher=lookup_widget(objet_graphique,"afficher");
gtk_widget_destroy(afficher);
Reponse=lookup_widget(objet_graphique,"Reponse");
Reponse=create_Reponse();

gtk_widget_show(Reponse);
}


void
on_liste_clicked                       (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *afficher;
GtkWidget *liste;
GtkWidget *treeview1;
afficher=lookup_widget(objet_graphique,"afficher");
gtk_widget_destroy(afficher);
liste=lookup_widget(objet_graphique,"liste");
liste=create_liste();

gtk_widget_show(liste);
treeview1=lookup_widget(liste,"treeview1");
afficher_rec(treeview1);
}


void
on_retour2_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Reponse, *Afficher;

Reponse=lookup_widget(objet_graphique,"Reponse");

gtk_widget_destroy(Reponse);
Afficher=create_Afficher();
gtk_widget_show(Afficher);
}


void
on_button4_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char id[3],rec[1000];
GtkWidget *input;
GtkWidget *inputs;
input=lookup_widget(objet_graphique,"entry1");
inputs=lookup_widget(objet_graphique,"entry2");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(rec,gtk_entry_get_text(GTK_ENTRY(inputs)));
Reponse(id,rec);
}


void
on_retour_clicked                      (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *liste, *Afficher;

liste=lookup_widget(objet_graphique,"liste");

gtk_widget_destroy(liste);
Afficher=create_Afficher();
gtk_widget_show(Afficher);
}


void
on_modifier2_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Afficher;
GtkWidget *modifier2;
Afficher=lookup_widget(objet_graphique,"Afficher");
gtk_widget_destroy(Afficher);
modifier2=lookup_widget(objet_graphique,"modifier2");
modifier2=create_modifier2();

gtk_widget_show(modifier2);
}


void
on_Supprimer3_clicked                  (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Afficher;
GtkWidget *Supprimer2;
Afficher=lookup_widget(objet_graphique,"Afficher");
gtk_widget_destroy(Afficher);
Supprimer2=lookup_widget(objet_graphique,"Supprimer2");
Supprimer2=create_Supprimer2();

gtk_widget_show(Supprimer2);
}


void
on_envoyer3_clicked                    (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char id[3],rec[1000];
GtkWidget *input;
GtkWidget *inputs;
GtkWidget *sortie;
input=lookup_widget(objet_graphique,"entry3");
inputs=lookup_widget(objet_graphique,"entry4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(rec,gtk_entry_get_text(GTK_ENTRY(inputs)));
modifier(id);
}


void
on_retour4_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifier2, *Afficher;

modifier2=lookup_widget(objet_graphique,"modifier2");

gtk_widget_destroy(modifier2);
Afficher=create_Afficher();
gtk_widget_show(Afficher);
}


void
on_supprime_clicked                    (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char id[3];
GtkWidget *input;
input=lookup_widget(objet_graphique,"entry5");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_rec(id);
}


void
on_retour6_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Supprimer2, *Afficher;

Supprimer2=lookup_widget(objet_graphique,"Supprimer2");

gtk_widget_destroy(Supprimer2);
Afficher=create_Afficher();
gtk_widget_show(Afficher);
}

