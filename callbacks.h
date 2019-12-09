#include <gtk/gtk.h>
typedef struct vol vol;
struct vol{
char id[30];
char depart[30];
char destination[30];
char companie[30];
char date_depart[30];
char date_retour[30];
int nbVols;
int prix;
};
  int i;
  GtkWidget *acceuil;
  GtkWidget *gestion_vol;

void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

