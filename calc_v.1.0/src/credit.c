#include "calc.h"

void open_credit_window() {
  GtkBuilder *new_builder;
  GtkWidget *new_window;
 
  new_builder = gtk_builder_new();
  gtk_builder_add_from_file(new_builder, "smartcalc.glade", NULL);

  new_window = GTK_WIDGET(gtk_builder_get_object(new_builder, "credit_window"));

  CreditData *credit_data = g_slice_new(CreditData);
  credit_data->loan_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "loan_entry"));  
  credit_data->period_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "period_entry"));
  credit_data->rate_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "rate_entry"));

  GtkWidget *calculate_button = GTK_WIDGET(gtk_builder_get_object(new_builder, "calculate"));
  
  g_signal_connect(calculate_button, "clicked", G_CALLBACK(on_process_button_clicked), credit_data);

  
  gtk_widget_show_all(new_window);
  
}





void on_process_button_clicked(GtkWidget *widget, gpointer user_data) {
    CreditData *credit_data = (CreditData *)user_data;
   
    const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(credit_data->loan_entry));
    const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(credit_data->period_entry));
    const gchar *text3 = gtk_entry_get_text(GTK_ENTRY(credit_data->rate_entry));

    credit_data_processing(text1,text2,text3);

    gtk_entry_set_text(GTK_ENTRY(credit_data->loan_entry), "");
    gtk_entry_set_text(GTK_ENTRY(credit_data->period_entry), "");
    gtk_entry_set_text(GTK_ENTRY(credit_data->rate_entry), "");
        
    (void)widget;
}

void credit_data_processing(const gchar *text1,const gchar *text2,const gchar *text3){
    double loan = 0;
    double period = 0;
    double rate = 0;

    sscanf(text1,"%lf",&loan);
    sscanf(text2,"%lf",&period);
    sscanf(text3,"%lf",&rate);


}

