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

  return 0;
}

void on_main_window_destroy() { gtk_main_quit(); }

void display(GtkButton *button, gpointer user_data) {
  setlocale(LC_NUMERIC, "C");

  AppData *app_data = (AppData *)user_data;
  CalcData *calc_data = app_data->calc_data;
  FrontData *front_data = app_data->front_data;
 
  elements *lexem = app_data->calc_data->stack;
  elements *out = app_data->calc_data->output;

  const gchar *text = gtk_button_get_label(button);

  int graph_flag = 0;

  if (strcmp("graph", text) == 0) graph_flag = 1;

  if (strcmp("=", text) == 0 || graph_flag) {
    int error = validation(app_data->calc_data->input_buffer);

    if (!error) {
      error = x_validation(app_data->calc_data->x_input);
      if (!error) sscanf(app_data->calc_data->x_input, "%Lf", &app_data->calc_data->x);
     
    }

    if (!error) {
      int count = parser(app_data->calc_data->input_buffer,lexem, app_data->calc_data->x);
      free_input(calc_data);
      postfix(lexem, out, &count); 
      free_lexem(lexem, count);
      long double res = 0;
      if (graph_flag) {
        open_new_window(out, count);
        graph_flag = 0;
      } else {
        calculation(out, count, &res);
        free_lexem(out, count);
        char result[256] = {0};
        memset(result, 0, sizeof(result));
        sprintf(result, "%.10Lg", res);
        gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
        gtk_entry_set_text(GTK_ENTRY(front_data->entry), result);
        strcpy(app_data->calc_data->input_buffer, result);
        memset(result, 0, sizeof(result));
        app_data->calc_data->x = 0.0;
      }
    } else {
      free_input(calc_data);
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), "ERROR");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    }

    app_data->calc_data->in = false;

  } else if (strcmp("CE", text) == 0) {
    free_input(calc_data);
    gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    app_data->calc_data->x = 0.0;
    app_data->calc_data->in = false;

  } else if (app_data->calc_data->in) {
    if (strcmp(text, "+/-") == 0) {
      strcat(app_data->calc_data->x_input, "-");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    } else {
      strcat(app_data->calc_data->x_input, text);
      gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    }
  } else {
    if (strcmp(text, "+/-") == 0) {
      strcat(app_data->calc_data->input_buffer, "(-");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    } else if (strcmp(text, "sin") == 0 || strcmp(text, "cos") == 0 ||
               strcmp(text, "tan") == 0 || strcmp(text, "asin") == 0 ||
               strcmp(text, "acos") == 0 || strcmp(text, "atan") == 0 ||
               strcmp(text, "log") == 0 || strcmp(text, "ln") == 0 ||
               strcmp(text, "sqrt") == 0) {
      strcat(app_data->calc_data->input_buffer, text);
      strcat(app_data->calc_data->input_buffer, "(");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    } else {
      strcat(app_data->calc_data->input_buffer, text);
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), calc_data->input_buffer);
    }
  }
  (void)user_data;
}


void on_entry_focus_in(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
  AppData *app_data = (AppData *)user_data;
  app_data->calc_data->in = true;
  (void)widget;
  (void)event;
  (void)user_data;

}

void on_entry_focus_out(GtkWidget *widget, GdkEvent *event,
                        gpointer user_data) {
  AppData *app_data = (AppData *)user_data;
  app_data->calc_data->in = false;
  (void)widget;
  (void)event;
  (void)user_data;
}
