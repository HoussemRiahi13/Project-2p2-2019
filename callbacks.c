#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include <string.h>


void on_buttonLogin_clicked (GtkWidget  *objet_graphique,gpointer user_data)
{
GtkWidget *Window1;
GtkWidget *Window2;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output1;

char username[50];
char password[50];
int  r=0;
char erreure[50];

Window1=lookup_widget(objet_graphique,"windowAuth");
input1=lookup_widget(objet_graphique,"entryUsername");
input2=lookup_widget(objet_graphique,"entryPassword");
output1= lookup_widget(objet_graphique, "labelErreure");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
r=verifier(username,password);

  if(r==-1)
    {
        strcpy(erreure,"id et/ou mot de passe incorret !");
        GdkColor color;
	gdk_color_parse ("red", &color);
	gtk_widget_modify_fg (output1, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL (output1), erreure);
    }

  else if(r==1)
    {
        Window2=create_windowBienvenueadmin();	
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
  else if(r==2)
    {
        Window2=create_windowBienvenueagent();	
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
  else 
    {
        Window2=create_windowBienvenueclient();	
        gtk_widget_hide(Window1);		
	gtk_widget_show (Window2); 
    }
}

void on_buttonRetour_clicked  (GtkWidget  *objet_graphique,gpointer user_data)
{
GtkWidget *Window1;
GtkWidget *Window2;
Window1=lookup_widget(objet_graphique,"windowBienvenueadmin");
Window2=create_windowAuth();
gtk_widget_hide(Window1);		
gtk_widget_show (Window2); 
}





