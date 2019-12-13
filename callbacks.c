#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
void affichervoiture(GtkWidget *liste);
void afficher(GtkWidget *liste);


enum
{
	MODELE,
	CITY,
	PRIX, 
	CODE,
	COLUMNS
};






void affichervoiture(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char modele[30];
	char city[30];
	char prix[5];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" modele",renderer,"text",MODELE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" city",renderer,"text",CITY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" code",renderer,"text",CODE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("derniere_consultation.txt","r");

if(f==NULL)
{

	return;
}
else
{f=fopen("derniere_consultation.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",modele,city,prix,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,MODELE,modele,CITY,city,PRIX,prix,CODE,code,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char modele[30];
	char city[30];
	char prix[5];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" modele",renderer,"text",MODELE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" city",renderer,"text",CITY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" code",renderer,"text",CODE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("voiture.txt","r");

if(f==NULL)
{

	return;
}
else
{f=fopen("voiture.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",modele,city,prix,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,MODELE,modele,CITY,city,PRIX,prix,CODE,code,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void
on_retour_clicked                      (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window6, *window1;
window1=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(window1);
window6=lookup_widget(objet_graphique,"window6");
window6=create_window6();
gtk_widget_show(window6);


}


void
on_ajouter_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window2;

window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
window2=lookup_widget(objet_graphique,"window2");
window2=create_window2();
gtk_widget_show(window2);


}


void
on_rechercher_clicked                  (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window4;

window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
window4=lookup_widget(objet_graphique,"window4");
window4=create_window4();
gtk_widget_show(window4);


}


void
on_consulter_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window3;
GtkWidget *treeview1;

window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
window3=lookup_widget(objet_graphique,"window3");
window3=create_window3();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher(treeview1);

}


void
on_ajouter2_clicked                    (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{char modele[20],city[20],prix[20];
int x;
x=((rand()%100)+1);
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry1");
strcpy(modele,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry2");
strcpy(city,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry3");
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input3)));
FILE *f;
f=fopen("voiture.txt","a"); 
fprintf(f,"%s	   %s 	    %s	 	%d \n",modele,prix,city,x);
fclose(f);

GtkWidget *window2, *window1;
window2=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(window2);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);
}



void
on_retour1_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window2, *window1;
window2=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(window2);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_retour3_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window3, *window1;
window3=lookup_widget(objet_graphique,"window3");

gtk_widget_destroy(window3);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_retour4_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window4, *window1;
window4=lookup_widget(objet_graphique,"window4");

gtk_widget_destroy(window4);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_rechercher4_clicked                 (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{

}


void
on_retour5_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5, *window1;
window5=lookup_widget(objet_graphique,"window5");

gtk_widget_destroy(window5);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_reserver5_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window5, *window6;
window5=lookup_widget(objet_graphique,"window5");

gtk_widget_destroy(window5);
window6=lookup_widget(objet_graphique,"window6");
window6=create_window6();
gtk_widget_show(window6);


}


void
on_supprimer5_clicked                  (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{int y,x,et,z;
char modele[30], nom[20] , city[30] , prix[5];
GtkWidget *window5;
GtkWidget *window1;
GtkWidget *input1;
x=lookup_widget(objet_graphique,"entry7");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f;
FILE *F;
f=fopen("junk.txt","a"); 
F=fopen("voiture.txt","r");
fscanf(F,"%s %s %s %d\n",modele,prix,city,z);
if((int)(x) != z)
{fprintf(f,"%s %s %s %d\n",modele,prix,city,y);}
fclose(f);
fclose(F);
f=fopen("voiture.txt","w");
F=fopen("junk.txt","r");
fscanf(f,"%s %s %s %d\n",nom,prix,city,y);
while(f!=EOF)
{fprintf(F,"%s %s %s %d\n",nom,prix,city,y);}

window5=lookup_widget(objet_graphique,"window5");
gtk_widget_destroy(window5);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);


}


void
on_modifier5_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{int y,x,et,z;
char modele[30] ,nom[20], city[30] , prix[5];
GtkWidget *window5;
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *input1;
x=lookup_widget(objet_graphique,"entry7");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f;
FILE *F;
f=fopen("junk.txt","a"); 
F=fopen("voiture.txt","r");
fscanf(F,"%s %s %s %d\n",modele,prix,city,z);
if((int)(x) != z)
{fprintf(f,"%s %s %s %d\n",modele,prix,city,y);}
fclose(f);
fclose(F);
f=fopen("voiture.txt","w");
F=fopen("junk.txt","r");
fscanf(f,"%s %s %s %d\n",nom,prix,city,y);
while(f!=EOF)
{fprintf(F,"%s %s %s %d\n",nom,prix,city,y);}

window5=lookup_widget(objet_graphique,"window5");
gtk_widget_destroy(window5);
window1=lookup_widget(objet_graphique,"window1");
window2=create_window2();
gtk_widget_show(window2);


}


void
on_retour6_clicked                     (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window6, *window5;
window6=lookup_widget(objet_graphique,"window6");

gtk_widget_destroy(window6);
window5=lookup_widget(objet_graphique,"window5");
window5=create_window5();
gtk_widget_show(window5);

}


void
on_reserver6_clicked                   (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
char nom[20],prenom[20],cin[20];
int j1,m1,a1,j2,m2,a2;
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry10");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry9");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry8");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input4;
input4=lookup_widget(objet_graphique,"spinbutton4");
j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
GtkWidget *input5;
input5=lookup_widget(objet_graphique,"spinbutton5");
m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
GtkWidget *input6;
input6=lookup_widget(objet_graphique,"spinbutton6");
a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
GtkWidget *input7;
input7=lookup_widget(objet_graphique,"spinbutton1");
j2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
GtkWidget *input8;
input8=lookup_widget(objet_graphique,"spinbutton2");
m2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
GtkWidget *input9;
input9=lookup_widget(objet_graphique,"spinbutton3");
a2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
FILE *f;
f=fopen("reservation.txt","a"); 
fprintf(f,"%s %s   %s : %d / %d / %d until %d / %d / %d \n",nom,prenom,cin,j1,m1,a1,j2,m2,a2);
fclose(f);
}



