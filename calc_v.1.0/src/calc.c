#include "calc.h"

GtkWidget *entry = NULL;
GtkWidget *entry2 = NULL;
GtkWidget *window;
GtkWidget *drawing_area;
bool in = false;

char input_buffer[1024] = {0};
char x_input[128] = {0};

elements stack[512] = {0};  // array of structures for lexem
elements *lexem = stack;
elements output[512] = {0};  // array of structures for postfix output
elements *out = output;
elements stack_graph[512] = {0};  // array of structures for lexem
elements *lexem_graph = stack_graph;
double x = 0;

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *builder;

  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "smartcalc.glade", NULL);
  window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
  gtk_builder_connect_signals(builder, NULL);
  entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
  entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "x_value"));

  gtk_widget_show(window);
  g_signal_connect(window, "destroy", G_CALLBACK(on_main_window_destroy), NULL);
  gtk_main();

  g_object_unref(builder);

  return 0;
}

void on_main_window_destroy() { gtk_main_quit(); }

void display(GtkButton *button, gpointer user_data) {
  setlocale(LC_NUMERIC, "C");

  const gchar *text = gtk_button_get_label(button);

  int graph_flag = 0;

  if (strcmp("graph", text) == 0) graph_flag = 1;

  if (strcmp("=", text) == 0 || graph_flag) {
    int error = validation(input_buffer);

    if (in && !error) {
      error = x_validation(x_input);

      // char *prevLocale = setlocale(LC_NUMERIC, NULL);
      // setlocale(LC_NUMERIC, "C");

      if (!error) sscanf(x_input, "%lf", &x);
      // setlocale(LC_NUMERIC, prevLocale);
    }

    if (!error) {
      int count = parser(input_buffer, lexem, x);
      memset(input_buffer, 0, sizeof(input_buffer));
      memset(x_input, 0, sizeof(x_input));
      postfix(lexem, out, &count);  // make postfix notation
      free_lexem(lexem, count);
      double res = 0;
      if (graph_flag) {
        open_new_window(out, count);
        graph_flag = 0;
      } else {
        calculation(out, count, &res);
        free_lexem(out, count);
        char result[128] = {0};
        memset(result, 0, sizeof(result));
        sprintf(result, "%lf", res);
        gtk_entry_set_text(GTK_ENTRY(entry2), x_input);
        gtk_entry_set_text(GTK_ENTRY(entry), result);
        strcpy(input_buffer, result);
        memset(result, 0, sizeof(result));
        x = 0.0;
      }
    } else {
      gtk_entry_set_text(GTK_ENTRY(entry), "ERROR");
      memset(x_input, 0, sizeof(x_input));
      memset(input_buffer, 0, sizeof(input_buffer));
      gtk_entry_set_text(GTK_ENTRY(entry2), x_input);
    }

    in = false;

  } else if (strcmp("CE", text) == 0) {
    memset(input_buffer, 0, sizeof(input_buffer));
    memset(x_input, 0, sizeof(x_input));
    gtk_entry_set_text(GTK_ENTRY(entry), input_buffer);
    gtk_entry_set_text(GTK_ENTRY(entry2), x_input);
    x = 0.0;
    in = false;

  } else if (in) {
    if (strcmp(text, "+/-") == 0) {
      strcat(x_input, "-");
      gtk_entry_set_text(GTK_ENTRY(entry2), x_input);
    } else {
      strcat(x_input, text);
      gtk_entry_set_text(GTK_ENTRY(entry2), x_input);
    }
  } else {
    if (strcmp(text, "+/-") == 0) {
      strcat(input_buffer, "(-");
      gtk_entry_set_text(GTK_ENTRY(entry), input_buffer);
    } else if (strcmp(text, "sin") == 0 || strcmp(text, "cos") == 0 ||
               strcmp(text, "tan") == 0 || strcmp(text, "asin") == 0 ||
               strcmp(text, "acos") == 0 || strcmp(text, "atan") == 0 ||
               strcmp(text, "log") == 0 || strcmp(text, "ln") == 0 ||
               strcmp(text, "sqrt") == 0) {
      strcat(input_buffer, text);
      strcat(input_buffer, "(");
      gtk_entry_set_text(GTK_ENTRY(entry), input_buffer);
      gtk_entry_set_text(GTK_ENTRY(entry), input_buffer);
    } else {
      strcat(input_buffer, text);
      gtk_entry_set_text(GTK_ENTRY(entry), input_buffer);
    }
  }
  (void)user_data;
}

void print_lexem(elements *lexem, int count) {
  printf("%d\n", count);

  for (int i = 0; i < count; i++) {
    printf("stack[%d]:\n", i);
    printf("type: %d\n", lexem->type);
    printf("priority: %d\n", lexem->priority);
    printf("operation: \"%s\"\n", lexem->operation);
    printf("value: %lf\n", lexem->value);
    printf("\n");
    lexem++;
  }
}

int x_validation(char *str) {
  size_t len = 0;
  char buffer[1024] = {0};
  strncpy(buffer, str, sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';
  len = strlen(buffer);
  int error = 0;
  if (len == 0) error++;
  for (size_t i = 0; i < len; i++) {
    if (!isdigit(buffer[i])) {
      if (buffer[i] == '.' || buffer[i] == '-') {
        error = 0;
      } else {
        error = 1;
      }
    }
  }

  return error;
}

void on_entry_focus_in(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
  in = true;
  (void)widget;
  (void)event;
  (void)user_data;
}

void on_entry_focus_out(GtkWidget *widget, GdkEvent *event,
                        gpointer user_data) {
  in = false;
  (void)widget;
  (void)event;
  (void)user_data;
}

void free_lexem(elements *lexem, int count) {
  for (int i = 0; i < count; i++) {
    (lexem + i)->type = 0;
    (lexem + i)->priority = 0;
    memset((lexem + i)->operation, 0, sizeof((lexem + i)->operation));
    (lexem + i)->value = 0;
  }
}
