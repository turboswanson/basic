#include "calc.h"

void loan_entry_activate_callback(GtkEntry *entry, gpointer user_data) {
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Entered text: %s\n", text);
    (void)user_data;
}

void period_entry_activate_callback(GtkEntry *entry, gpointer user_data) {
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Entered text: %s\n", text);
    (void)user_data;
}

void rate_entry_activate_callback(GtkEntry *entry, gpointer user_data) {
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Entered text: %s\n", text);
    (void)user_data;
}

void open_credit_window() {
  GtkBuilder *new_builder;
  GtkWidget *new_window;
  
  new_builder = gtk_builder_new();
  gtk_builder_add_from_file(new_builder, "smartcalc.glade", NULL);

  new_window = GTK_WIDGET(gtk_builder_get_object(new_builder, "credit_window"));

  GtkWidget *loan_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "loan_entry"));
  GtkWidget *period_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "period_entry"));
  GtkWidget *rate_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "rate_entry"));

  g_signal_connect(loan_entry, "activate", G_CALLBACK(loan_entry_activate_callback), NULL);
  g_signal_connect(period_entry, "activate", G_CALLBACK(period_entry_activate_callback), NULL);
  g_signal_connect(rate_entry, "activate", G_CALLBACK(rate_entry_activate_callback), NULL);

  gtk_widget_show_all(new_window);
  
 
}