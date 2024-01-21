#include "calc.h"

static int check_expression(const char *s1,char *s2){
    int res = 0;

    if(strcmp(s1, s2) == 0){
        res = 1;
    }

    return res;
}


void display(GtkButton *button, gpointer user_data) {
  setlocale(LC_NUMERIC, "C");

  AppData *app_data = (AppData *)user_data;
  CalcData *calc_data = app_data->calc_data;
  FrontData *front_data = app_data->front_data;
 
  elements *lexem = app_data->calc_data->stack;
  elements *out = app_data->calc_data->output;

  const gchar *text = gtk_button_get_label(button);

  int graph_flag = 0;
  
  if (check_expression(text,"graph")) graph_flag = 1;


  if (check_expression(text,"=") || graph_flag) {
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

  } else if (check_expression(text,"CE")) {
    free_input(calc_data);
    gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    app_data->calc_data->x = 0.0;
    app_data->calc_data->in = false;

  } else if (app_data->calc_data->in) {
    if (check_expression(text, "+/-")) {
      strcat(app_data->calc_data->x_input, "-");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    } else {
      strcat(app_data->calc_data->x_input, text);
      gtk_entry_set_text(GTK_ENTRY(front_data->entry2), app_data->calc_data->x_input);
    }
  } else {
    if (check_expression(text, "+/-")) {
      strcat(app_data->calc_data->input_buffer, "(-");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    } else if (check_expression(text, "sin") || check_expression(text, "cos")  ||
               check_expression(text, "tan") || check_expression(text, "asin") ||
               check_expression(text, "acos")|| check_expression(text, "atan") ||
               check_expression(text, "log") || check_expression(text, "ln")   ||
               check_expression(text, "sqrt")) {
      strcat(app_data->calc_data->input_buffer, text);
      strcat(app_data->calc_data->input_buffer, "(");
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), app_data->calc_data->input_buffer);
    } else {
      strcat(app_data->calc_data->input_buffer, text);
      gtk_entry_set_text(GTK_ENTRY(front_data->entry), calc_data->input_buffer);
    }
  }
  
}