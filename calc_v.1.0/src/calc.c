#include "calc.h"

GtkWidget *entry = NULL;
GtkWidget *entry2 = NULL;
GtkWidget *window;
GtkWidget *drawing_area;

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *builder;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "smartcalc.glade", NULL);

  CalcData *calc_data = g_slice_new(CalcData);
  memset(calc_data->input_buffer,0,sizeof(calc_data->input_buffer));
  memset(calc_data->x_input,0,sizeof(calc_data->x_input));

  calc_data->in = false;

  for(int i = 0; i < 256 ; i++){
    calc_data->stack[i].type = 0;
    calc_data->output[i].type = 0;
    calc_data->stack[i].priority = 0;
    calc_data->output[i].priority = 0;
    calc_data->stack[i].operation[0] = 0;
    calc_data->stack[i].operation[1] = 0;
    calc_data->stack[i].operation[2] = 0;
    calc_data->stack[i].operation[3] = 0;
    calc_data->stack[i].operation[4] = 0;
    calc_data->output[i].operation[0] = 0;
    calc_data->output[i].operation[1] = 0;
    calc_data->output[i].operation[2] = 0;
    calc_data->output[i].operation[3] = 0;
    calc_data->output[i].operation[4] = 0;
    calc_data->stack[i].value = 0;
    calc_data->output[i].value = 0;
  }

  gtk_builder_connect_signals(builder, calc_data);

  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  gtk_builder_connect_signals(builder, NULL);
  entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
  entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "x_value"));

  gtk_widget_show(window);
  g_signal_connect(window, "destroy", G_CALLBACK(on_main_window_destroy), NULL);
  gtk_main();

  g_object_unref(builder);
  g_slice_free(CalcData, calc_data);

  return 0;
}

void on_main_window_destroy() { gtk_main_quit(); }

void display(GtkButton *button, gpointer user_data) {
  setlocale(LC_NUMERIC, "C");

  CalcData *calc_data = (CalcData *)user_data;
  elements *lexem = calc_data->stack;
  elements *out = calc_data->output;

  const gchar *text = gtk_button_get_label(button);

  int graph_flag = 0;

  if (strcmp("graph", text) == 0) graph_flag = 1;

  if (strcmp("=", text) == 0 || graph_flag) {
    int error = validation(calc_data->input_buffer);

    if (!error) {
      error = x_validation(calc_data->x_input);
      if (!error) sscanf(calc_data->x_input, "%Lf", &calc_data->x);
     
    }

    if (!error) {
      int count = parser(calc_data->input_buffer,lexem, calc_data->x);
      memset(calc_data->input_buffer, 0, sizeof(calc_data->input_buffer));
      memset(calc_data->x_input, 0, sizeof(calc_data->x_input));
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
        gtk_entry_set_text(GTK_ENTRY(entry2), calc_data->x_input);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
        strcpy(calc_data->input_buffer, result);
        memset(result, 0, sizeof(result));
        calc_data->x = 0.0;
      }
    } else {
      gtk_entry_set_text(GTK_ENTRY(entry), "ERROR");
      memset(calc_data->x_input, 0, sizeof(calc_data->x_input));
      memset(calc_data->input_buffer, 0, sizeof(calc_data->input_buffer));
      gtk_entry_set_text(GTK_ENTRY(entry2), calc_data->x_input);
    }

    calc_data->in = false;

  } else if (strcmp("CE", text) == 0) {
    memset(calc_data->input_buffer, 0, sizeof(calc_data->input_buffer));
    memset(calc_data->x_input, 0, sizeof(calc_data->x_input));
    gtk_entry_set_text(GTK_ENTRY(entry), calc_data->input_buffer);
    gtk_entry_set_text(GTK_ENTRY(entry2), calc_data->x_input);
    calc_data->x = 0.0;
    calc_data->in = false;

  } else if (calc_data->in) {
    if (strcmp(text, "+/-") == 0) {
      strcat(calc_data->x_input, "-");
      gtk_entry_set_text(GTK_ENTRY(entry2), calc_data->x_input);
    } else {
      strcat(calc_data->x_input, text);
      gtk_entry_set_text(GTK_ENTRY(entry2), calc_data->x_input);
    }
  } else {
    if (strcmp(text, "+/-") == 0) {
      strcat(calc_data->input_buffer, "(-");
      gtk_entry_set_text(GTK_ENTRY(entry), calc_data->input_buffer);
    } else if (strcmp(text, "sin") == 0 || strcmp(text, "cos") == 0 ||
               strcmp(text, "tan") == 0 || strcmp(text, "asin") == 0 ||
               strcmp(text, "acos") == 0 || strcmp(text, "atan") == 0 ||
               strcmp(text, "log") == 0 || strcmp(text, "ln") == 0 ||
               strcmp(text, "sqrt") == 0) {
      strcat(calc_data->input_buffer, text);
      strcat(calc_data->input_buffer, "(");
      gtk_entry_set_text(GTK_ENTRY(entry), calc_data->input_buffer);
      gtk_entry_set_text(GTK_ENTRY(entry), calc_data->input_buffer);
    } else {
      strcat(calc_data->input_buffer, text);
      gtk_entry_set_text(GTK_ENTRY(entry), calc_data->input_buffer);
    }
  }
  (void)user_data;
}


void on_entry_focus_in(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
  CalcData *calc_data = (CalcData *)user_data;
  calc_data->in = true;
  (void)widget;
  (void)event;
  (void)user_data;

}

void on_entry_focus_out(GtkWidget *widget, GdkEvent *event,
                        gpointer user_data) {
  CalcData *calc_data = (CalcData *)user_data;
  calc_data->in = false;
  (void)widget;
  (void)event;
  (void)user_data;
}


