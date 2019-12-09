#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "compte.h"


void
on_button_ajouter_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *agent;
GtkWidget *fenetre_ajout;
agent=lookup_widget(objet_graphique,"agent");
gtk_widget_destroy(agent);
fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();

gtk_widget_show(fenetre_ajout);
}


void
on_button_afficher_clicked             (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *agent;
GtkWidget *treeview1;

agent=lookup_widget(objet_graphique,"agent");
gtk_widget_destroy(agent);
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_compte(treeview1);
}


void
on_buttonAjouter_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
compte c ;
GtkWidget *entryNom,*entryPrenom,*entryCin,*entryAdresse;
GtkWidget *fenetre_ajout;
fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");

entryNom=lookup_widget(objet_graphique,"entryNom");
entryPrenom=lookup_widget(objet_graphique,"entryPrenom");
entryCin=lookup_widget(objet_graphique,"entryCin");
entryAdresse=lookup_widget(objet_graphique,"entryAdresse");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entryCin)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(entryAdresse)));


ajouter_compte(c);
}


void
on_buttonanulleajouter_clicked         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *agent;

fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
agent=lookup_widget(objet_graphique,"agent");
agent=create_agent();
gtk_widget_show(agent);
}


void
on_buttonanulleafficher_clicked       (GtkWidget     *objet_graphique,
                                          gpointer         user_data)
{GtkWidget *fenetre_afficher;
GtkWidget *agent;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
agent=lookup_widget(objet_graphique,"agent");
agent=create_agent();
gtk_widget_show(agent);
}
      

