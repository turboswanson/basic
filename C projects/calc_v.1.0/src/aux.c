#include "calc.h"

void print_lexem(elements *lexem, int count) {
  printf("%d\n", count);

  for (int i = 0; i < count; i++) {
    printf("stack[%d]:\n", i);
    printf("type: %d\n", lexem->type);
    printf("priority: %d\n", lexem->priority);
    printf("operation: \"%s\"\n", lexem->operation);
    printf("value: %Lf\n", lexem->value);
    printf("\n");
    lexem++;
  }
}

void free_lexem(elements *lexem, int count) {
  for (int i = 0; i < count; i++) {
    (lexem + i)->type = 0;
    (lexem + i)->priority = 0;
    memset((lexem + i)->operation, 0, sizeof((lexem + i)->operation));
    (lexem + i)->value = 0;
  }
}

void free_calc_data(AppData *app_data) {
  for (int i = 0; i < 256; i++) {
    app_data->calc_data->stack[i].type = 0;
    app_data->calc_data->output[i].type = 0;
    app_data->calc_data->stack[i].priority = 0;
    app_data->calc_data->output[i].priority = 0;
    app_data->calc_data->stack[i].operation[0] = 0;
    app_data->calc_data->stack[i].operation[1] = 0;
    app_data->calc_data->stack[i].operation[2] = 0;
    app_data->calc_data->stack[i].operation[3] = 0;
    app_data->calc_data->stack[i].operation[4] = 0;
    app_data->calc_data->output[i].operation[0] = 0;
    app_data->calc_data->output[i].operation[1] = 0;
    app_data->calc_data->output[i].operation[2] = 0;
    app_data->calc_data->output[i].operation[3] = 0;
    app_data->calc_data->output[i].operation[4] = 0;
    app_data->calc_data->stack[i].value = 0;
    app_data->calc_data->output[i].value = 0;
  }

  memset(app_data->calc_data->input_buffer, 0,
         sizeof(app_data->calc_data->input_buffer));
  memset(app_data->calc_data->x_input, 0, sizeof(app_data->calc_data->x_input));

  app_data->calc_data->in = false;
}

void free_input(CalcData *calc_data) {
  memset(calc_data->input_buffer, 0, sizeof(calc_data->input_buffer));
  memset(calc_data->x_input, 0, sizeof(calc_data->x_input));
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