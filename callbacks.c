#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

void affichercon(GtkWidget *liste);
void afficher(GtkWidget *liste);


enum
{
	HOTEL,
	CITY,
	ETOILE,
	PRIX, 
	CODE,
	COLUMNS
};






void affichercon(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char hotel[30];
	char city[30];
	char etoile[1];
	char prix[5];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" hotel",renderer,"text",HOTEL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" city",renderer,"text",CITY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" etoile",renderer,"text",ETOILE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" code",renderer,"text",CODE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("derniere_consultation.txt","r");

if(f==NULL)
{

	return;
}
else
{f=fopen("derniere_consultation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",hotel,city,etoile,prix,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,HOTEL,hotel,CITY,city,ETOILE,etoile,PRIX,prix,CODE,code,-1);
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

	char hotel[30];
	char city[30];
	char etoile[1];
	char prix[5];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" hotel",renderer,"text",HOTEL,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" city",renderer,"text",CITY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" etoile",renderer,"text",ETOILE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" code",renderer,"text",CODE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("hotel.txt","r");

if(f==NULL)
{

	return;
}
else
{f=fopen("hotel.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",hotel,city,etoile,prix,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,HOTEL,hotel,CITY,city,ETOILE,etoile,PRIX,prix,CODE,code,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero;
GtkWidget *window1;

zero=lookup_widget(objet_graphique,"zero");
gtk_widget_destroy(zero);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_consulter_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero;
GtkWidget *window2;
GtkWidget *treeview1;

zero=lookup_widget(objet_graphique,"zero");
gtk_widget_destroy(zero);
window2=lookup_widget(objet_graphique,"window2");
window2=create_window2();
gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeview1");

afficher(treeview1);


}


void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero;
GtkWidget *window3;

zero=lookup_widget(objet_graphique,"zero");
gtk_widget_destroy(zero);
window3=lookup_widget(objet_graphique,"window3");
window3=create_window3();
gtk_widget_show(window3);

}


void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero;
GtkWidget *window4;

zero=lookup_widget(objet_graphique,"zero");
gtk_widget_destroy(zero);
window4=create_window4();
gtk_widget_show(window4);


}


void
on_ajouter1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char nom[20],city[20],prix[20];
int et,x;
x=((rand()%100)+1);
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry1");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry2");
strcpy(city,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *etoile;
etoile=lookup_widget(objet_graphique,"spinbutton1");
et=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(etoile));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry4");
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input3)));
FILE *f;
f=fopen("hotel.txt","a"); 
fprintf(f,"%s %s %d %s %d\n",nom,city,et,prix,x);
fclose(f);

GtkWidget *zero, *window1;
window1=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(window1);
zero=create_zero();
gtk_widget_show(zero);
}


void
on_retour1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero, *window1;
window1=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(window1);
zero=create_zero();
gtk_widget_show(zero);

}


void
on_retour2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero, *window2;
window2=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(window2);
zero=create_zero();
gtk_widget_show(zero);

}


void
on_Retour3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero, *window3;
window3=lookup_widget(objet_graphique,"window3");

gtk_widget_destroy(window3);
zero=create_zero();
gtk_widget_show(zero);

}


void
on_rechercher3_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{int et,e,y;
char nom[30],n[30] , city[30] , c[30], prix[5],p[30];
GtkWidget *window3;
GtkWidget *window4;
GtkWidget *treeview1;
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry4");
strcpy(n,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry5");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry6");
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input4;
input4=lookup_widget(objet_graphique,"spinbutton2");
e=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));



FILE *f;
FILE *F;
f=fopen("derniere_consultation.txt","a"); 
F=fopen("hotel.txt","r");
fscanf(F,"%s %s %d %s %d\n",nom,city,et,prix,y);
while(F !=EOF)
{
if(n==nom || c==city || p==prix || e==et)
{fprintf(f,"%s %s %d %s %d\n",nom,city,et,prix,y);}}
fclose(f);
fclose(F);


window3=lookup_widget(objet_graphique,"window3");
gtk_widget_destroy(window3);
window4=create_window4();
gtk_widget_show(window4);
treeview1=lookup_widget(window4,"treeview1");

affichercon(treeview1);

}


void
on_reserver4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window4;
GtkWidget *window5;

window4=lookup_widget(objet_graphique,"window4");
gtk_widget_destroy(window4);
window5=create_window5();
gtk_widget_show(window5);

}


void
on_suprimer4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{int y,x,et,z;
char nom[30] , city[30] , prix[5];
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"window4");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f;
FILE *F;
f=fopen("junk1.txt","a"); 
F=fopen("hotel.txt","r");
z=fscanf(f,"%d");
fscanf(F,"%s %s %d %s %d\n",nom,city,et,prix,y);
if(x!=z)
{fprintf(f,"%s %s %d %s %d\n",nom,city,et,prix,y);}
fclose(f);
fclose(F);
f=fopen("hotel.txt","w");
F=fopen("junk1.txt","r");
fscanf(f,"%s %s %d %s %d\n",nom,city,et,prix,y);
while(f!=EOF)
{fprintf(F,"%s %s %d %s %d\n",nom,city,et,prix,y);}
GtkWidget *window4;
GtkWidget *zero;

window4=lookup_widget(objet_graphique,"window4");
gtk_widget_destroy(window4);
zero=create_zero();
gtk_widget_show(zero);
}


void
on_modifier4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{int y,x,et,z;
char nom[30] , city[30] , prix[5];
GtkWidget *window4;
GtkWidget *window1;
GtkWidget *input1;
x=lookup_widget(objet_graphique,"entry7");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f;
FILE *F;
f=fopen("junk.txt","a"); 
F=fopen("hotel.txt","r");
z=fscanf(f,"%d");
fscanf(F,"%s %s %d %s %d\n",nom,city,et,prix,y);
if(x!=z)
{fprintf(f,"%s %s %d %s %d\n",nom,city,et,prix,y);}
fclose(f);
fclose(F);
f=fopen("hotel.txt","w");
F=fopen("junk.txt","r");
fscanf(f,"%s %s %d %s %d\n",nom,city,et,prix,y);
while(f!=EOF)
{fprintf(F,"%s %s %d %s %d\n",nom,city,et,prix,y);}

window4=lookup_widget(objet_graphique,"window4");
gtk_widget_destroy(window4);
window1=create_window1();
gtk_widget_show(window1);


}


void
on_retour4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero, *window4;
window4=lookup_widget(objet_graphique,"window4");

gtk_widget_destroy(window4);
zero=create_zero();
gtk_widget_show(zero);

}


void
on_Annuler5_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *zero, *window5;
window5=lookup_widget(objet_graphique,"window5");

gtk_widget_destroy(window5);
zero=create_zero();
gtk_widget_show(zero);
}


void
on_reserver5_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char nom[20],prenom[20],cin[20];
int j1,m1,a1,j2,m2,a2;
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry8");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry9");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry10");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input4;
input4=lookup_widget(objet_graphique,"spinbutton3");
j1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
GtkWidget *input5;
input5=lookup_widget(objet_graphique,"spinbutton4");
m1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
GtkWidget *input6;
input6=lookup_widget(objet_graphique,"spinbutton5");
a1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
GtkWidget *input7;
input7=lookup_widget(objet_graphique,"spinbutton6");
j2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
GtkWidget *input8;
input8=lookup_widget(objet_graphique,"spinbutton7");
m2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
GtkWidget *input9;
input9=lookup_widget(objet_graphique,"spinbutton8");
a2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
FILE *f;
f=fopen("reservation.txt","a"); 
fprintf(f,"%s %s   %s : %d / %d / %d until %d / %d / %d \n",nom,prenom,cin,j1,m1,a1,j2,m2,a2);
fclose(f);
}

