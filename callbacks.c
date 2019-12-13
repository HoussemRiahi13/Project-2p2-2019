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

	CITY,
	PRIX,
	MOY,
	CODE,
	COLUMNS
};






void affichercon(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char city[30];
	char prix[1];
	char moy[30];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" city",renderer,"text",CITY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" moy",renderer,"text",MOY,NULL);
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
		while(fscanf(f,"%s %s %s %s \n",city,prix,moy,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,CITY,city,PRIX,prix,MOY,moy,CODE,code,-1);
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

	char city[30];
	char prix[5];
	char moy[30];
	char code[5];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix",renderer,"text",PRIX,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" moy",renderer,"text",MOY,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" code",renderer,"text",CODE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("excursion.txt","r");

if(f==NULL)
{

	return;
}
else
{f=fopen("excursion.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",city,prix,moy,code)!=EOF)
	{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,CITY,city,PRIX,prix,MOY,moy,CODE,code,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{int m,a,x,j;
char moy[30] , city[30] , prix[5],code[10],z[5];
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry6");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f;
FILE *F;
f=fopen("junk1.txt","a"); 
F=fopen("excursion.txt","r");
fscanf(F,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);
if(x!=code)
{fprintf(f,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);}
fclose(f);
fclose(F);
f=fopen("excursion.txt","w");
F=fopen("junk1.txt","r");
fscanf(F,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);
{fprintf(f,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);}



}


void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window2;
int m,a,x,j;
char moy[30] , city[30] , prix[5],code[10],z[5];
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry6");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f;
FILE *F;
f=fopen("junk1.txt","a"); 
F=fopen("excursion.txt","r");
fscanf(F,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);
if(x!=code)
{fprintf(f,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);}
fclose(f);
fclose(F);
f=fopen("excursion.txt","w");
F=fopen("junk1.txt","r");
fscanf(f,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);
while(f!=EOF)
{fprintf(F,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);}



window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
window2=lookup_widget(objet_graphique,"window2");
window2=create_window2();
gtk_widget_show(window2);


}


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
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
on_reserver_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window3;


window1=lookup_widget(objet_graphique,"window1");
gtk_widget_destroy(window1);
window3=lookup_widget(objet_graphique,"window3");
window3=create_window3();
gtk_widget_show(window3);

}


void
on_ajouter1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char moy[20],city[20],prix[20],code[5],z[5];
int *j,*m,*a;
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry1");
strcpy(city,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry2");
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input6;
input6=lookup_widget(objet_graphique,"spinbutton1");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
GtkWidget *input7;
input7=lookup_widget(objet_graphique,"spinbutton2");
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
GtkWidget *input8;
input8=lookup_widget(objet_graphique,"spinbutton3");
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry3");
strcpy(moy,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input4;
input4=lookup_widget(objet_graphique,"entry4");
strcpy(z,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input5;
input5=lookup_widget(objet_graphique,"entry5");
strcpy(code,gtk_entry_get_text(GTK_ENTRY(input5)));
FILE *f;
f=fopen("excursion.txt","a"); 
fprintf(f,"%s %s %s %s %s %d/%d/%d\n",moy,city,prix,z,code,j,m,a);
fclose(f);

GtkWidget *window1, *window2;
window2=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(window2);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_retour_ajouter_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1, *window2;
window2=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(window2);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_annuler_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1, *window3;
window3=lookup_widget(objet_graphique,"window3");

gtk_widget_destroy(window3);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);

}


void
on_reserver1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char nom[20],prenom[20],cin[20];
GtkWidget *input1;
input1=lookup_widget(objet_graphique,"entry1");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
GtkWidget *input2;
input2=lookup_widget(objet_graphique,"entry2");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3;
input3=lookup_widget(objet_graphique,"entry3");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
FILE *f;
f=fopen("reservation.txt","a"); 
fprintf(f,"%s %s %s \n",nom,prenom,cin);
fclose(f);

GtkWidget *window1, *window3;
window3=lookup_widget(objet_graphique,"window3");

gtk_widget_destroy(window3);
window1=lookup_widget(objet_graphique,"window1");
window1=create_window1();
gtk_widget_show(window1);


}

