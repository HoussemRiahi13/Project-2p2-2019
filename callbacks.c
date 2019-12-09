#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "compte.h"

void
on_ajouter__clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *admin;

admin=lookup_widget(objet_graphique,"admin");
gtk_widget_destroy(admin);
fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();

gtk_widget_show(fenetre_ajout);


}


void
on_modifier__clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affichage;
GtkWidget *admin;

admin=lookup_widget(objet_graphique,"admin");
gtk_widget_destroy(admin);
fenetre_affichage=lookup_widget(objet_graphique,"fenetre_affichage");
fenetre_affichage=create_fenetre_affichage();
gtk_widget_show(fenetre_affichage);
}


void
on_supprimer__clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *fenetre_supprimer;
GtkWidget *admin;

admin=lookup_widget(objet_graphique,"admin");
gtk_widget_destroy(admin);
fenetre_supprimer=lookup_widget(objet_graphique,"fenetre_supprimer");
fenetre_supprimer=create_fenetre_supprimer();
gtk_widget_show(fenetre_supprimer);

}


void
on_afficher__clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *fenetre_affichage;
GtkWidget *admin;
GtkWidget *treeview1;

fenetre_affichage=lookup_widget(objet_graphique,"admin");
gtk_widget_destroy(admin);
fenetre_affichage=lookup_widget(objet_graphique,"fenetre_affichage");
fenetre_affichage=create_fenetre_affichage();
gtk_widget_show(fenetre_affichage);
treeview1=lookup_widget(fenetre_affichage,"treeview1");
afficher_compte(treeview1);
}


void
on_buttonannulerajout_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *admin;

fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");
gtk_widget_destroy(fenetre_ajout);
admin=lookup_widget(objet_graphique,"admin");
admin=create_admin();
gtk_widget_show(admin);
}


void
on_buttonajout_clicked               (GtkWidget       *objet_graphique,
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
on_buttonsupprim_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{compte c ;
GtkWidget *entryCin_s;
GtkWidget *fenetre_supprimer;

fenetre_supprimer=lookup_widget(objet_graphique,"fenetre_supprimer");

entryCin_s=lookup_widget(objet_graphique,"entryCin_s");
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entryCin_s)));
supprimer_compte(c);
}


void
on_button_anullersupprim_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimer;
GtkWidget *admin;

fenetre_supprimer=lookup_widget(objet_graphique,"fenetre_supprimer");
gtk_widget_destroy(fenetre_supprimer);
admin=lookup_widget(objet_graphique,"admin");
admin=create_admin();
gtk_widget_show(admin);

}




void
on_button_annuler_aficher_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *admin;
GtkWidget *fenetre_affichage;
fenetre_affichage=lookup_widget(objet_graphique,"fenetre_affichage");
gtk_widget_destroy(fenetre_affichage);
admin=create_admin();
gtk_widget_show(admin);
}




void
on_button1_modifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{compte c ;
GtkWidget *entry1CINU,*entry2NomU,*entry3PrenomU,*entry4AdresseU;
GtkWidget *fenetre_affichage;
fenetre_affichage=lookup_widget(objet_graphique,"fenetre_affichage");

entry1CINU=lookup_widget(objet_graphique,"entry1CINU");
entry2NomU=lookup_widget(objet_graphique,"entry2NomU");
entry3PrenomU=lookup_widget(objet_graphique,"entry3PrenomU");
entry4AdresseU=lookup_widget(objet_graphique,"entry4AdresseU");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entry1CINU)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(entry2NomU)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entry3PrenomU)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(entry4AdresseU)));


modifier_compte(c,entry1CINU);
}

