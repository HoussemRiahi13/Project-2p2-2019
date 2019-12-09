#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"treeView.h"
#include"crud.h"


void
on_Acceuilgestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
vol v;
gtk_widget_hide (acceuil);
gestion_vol = create_gestion_vol ();
p=lookup_widget(gestion_vol,"treeview1");

i=0;


Voltree(p,"vols.txt");

gtk_widget_show (gestion_vol);

}


void
on_gestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	 gtk_widget_show (acceuil);
        gtk_widget_destroy (gestion_vol);
}


void
on_Ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *cal2;
GtkWidget *comboboxDepart;
GtkWidget *comboboxDestination;
GtkWidget *comboboxCompanie;

GtkWidget *labelid;
GtkWidget *labelsuccess;
GtkWidget *labelComboDepart;
GtkWidget *labelComboDestination;
GtkWidget *labelComboCompanie;
GtkWidget *labelExist;
FILE*f=NULL;
vol v;
int jj1,mm1,aa1,jj2,mm2,aa2,b=1;

labelid=lookup_widget(gestion_vol,"label12");
labelComboDepart=lookup_widget(gestion_vol,"label13");
labelComboDestination=lookup_widget(gestion_vol,"label43");
labelComboCompanie=lookup_widget(gestion_vol,"label46");
labelExist=lookup_widget(gestion_vol,"label11");
labelsuccess=lookup_widget(gestion_vol,"label14");



comboboxDepart=lookup_widget(gestion_vol,"combobox1");
comboboxDestination=lookup_widget(gestion_vol,"combobox4");
comboboxCompanie=lookup_widget(gestion_vol,"combobox6");



cal1=lookup_widget(gestion_vol,"calendar1");
cal2=lookup_widget(gestion_vol,"calendar2");
           gtk_widget_hide (labelsuccess);

strcpy(v.id,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry1"))));

if(strcmp(v.id,"")==0){
                gtk_widget_show (labelid);
b=0;

}else
{
           gtk_widget_hide (labelid);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDepart))==-1){
                gtk_widget_show (labelComboDepart);
b=0;
}
else{

           gtk_widget_hide (labelComboDepart);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxDestination))==-1){
                gtk_widget_show (labelComboDestination);
b=0;
}
else{

           gtk_widget_hide (labelComboDestination);
}


if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboboxCompanie))==-1){
                gtk_widget_show (labelComboCompanie);
b=0;
}
else{

           gtk_widget_hide (labelComboCompanie);
}


if(b==1){

v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton1")));
v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton2")));
strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDepart)));
strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxDestination)));
strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxCompanie)));

gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);
gtk_calendar_get_date (GTK_CALENDAR(cal2),
                       &aa2,
                       &mm2,
   
                    &jj2);




if(exist_vol(v.id)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);

f=fopen("vols.txt","a+");
fprintf(f,"%s %s %s %s %d/%d/%d %d/%d/%d %d %d\n",v.id,v.depart,v.destination,v.companie,jj1,mm1+1,aa1,jj2,mm2+1,aa2,v.nbVols,v.prix);
fclose(f);
                gtk_widget_show (labelsuccess);


//mise a jour du treeView
GtkWidget *p;
p=lookup_widget(gestion_vol,"treeview1");
Voltree(p,"vols.txt");



}

}



}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

 	gchar *id;
        gchar *depart;
        gchar *destination;
        gchar *companie;
        gchar *date_depart;
        gchar *date_retour;
        gint prix;
        gint nbVols;

        gint x1=0,x2=0,x3;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion_vol,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&destination,3,&companie,4,&date_depart,5,&date_retour,6,&nbVols,7,&prix,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry2")),date_depart);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry3")),date_retour);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_vol,"spinbutton3")),nbVols);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_vol,"spinbutton4")),prix);

                if(strcmp(depart,"Tunisie")==0)	x1=0;		
                if(strcmp(depart,"Algerie")==0) x1=1;                
                if(strcmp(depart,"Marroc")==0)  x1=2 ;             

                if(strcmp(destination,"Tunisie")==0) x2=0;                 
                if(strcmp(destination,"Algerie")==0) x2=1;                
                if(strcmp(destination,"Marroc")==0)  x2=2; 

                if(strcmp(destination,"Allmagne")==0) x2=3;                 
                if(strcmp(destination,"Etat-Unis")==0) x2=4;                
                if(strcmp(destination,"Italie")==0)  x2=5;                

                if(strcmp(companie,"Tunisair")==0)  x3=0;              
                if(strcmp(companie,"Nouvelair")==0)       x3=1;        		  



                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox2")),x1);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox5")),x2);
                                 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox7")),x3);





		GtkWidget* msg=lookup_widget(gestion_vol,"label24");
                gtk_label_set_text(GTK_LABEL(msg),id);
		


                gtk_widget_show(lookup_widget(gestion_vol,"button6"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_vol,"label26"); 
        gtk_widget_hide(msg1);//cacher "vol modifié avec succes"


}





}


void
on_Supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_vol,"label25");
        p=lookup_widget(gestion_vol,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_vol(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);}else{
                gtk_widget_show (label);
        }




}


void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
      	vol v;
        strcpy(v.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_vol,"label24"))));
        strcpy(v.depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox2"))));
        strcpy(v.destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox5"))));
        strcpy(v.companie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_vol,"combobox7"))));
        strcpy(v.date_depart,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry2"))));
        strcpy(v.date_retour,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_vol,"entry3"))));
        v.nbVols =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton3")));
        v.prix =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_vol,"spinbutton4")));

        supprimer_vol(v.id);
        ajouter_vol(v);
        Voltree(lookup_widget(gestion_vol,"treeview1"),"vols.txt");
        GtkWidget* msg=lookup_widget(gestion_vol,"label26");
        gtk_widget_show(msg);


}







