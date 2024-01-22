#include "calc.h"

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *builder;
  GtkWidget *window;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "smartcalc.glade", NULL);
  
  AppData *app_data = g_slice_new(AppData);
  app_data->calc_data = g_slice_new(CalcData);
  app_data->front_data = g_slice_new(FrontData);
   
  free_calc_data(app_data);
 
  gtk_builder_connect_signals(builder, app_data);

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  gtk_builder_connect_signals(builder, NULL);
  app_data->front_data->entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
  app_data->front_data->entry2  = GTK_WIDGET(gtk_builder_get_object(builder, "x_value"));

  gtk_widget_show(window);
  g_signal_connect(window, "destroy", G_CALLBACK(on_main_window_destroy), NULL);
  gtk_main();

  g_object_unref(builder);
  g_slice_free(CalcData, app_data->calc_data);
  g_slice_free(FrontData, app_data->front_data);
  g_slice_free(AppData, app_data);

  return 0;
}

void on_main_window_destroy() { gtk_main_quit(); }



