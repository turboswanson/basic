#ifndef CALC_H
#define CALC_H

#include <ctype.h>
#include <gtk/gtk.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  GtkWidget *entry;
  GtkWidget *entry2;
  GtkWidget *drawing_area;
} FrontData;

typedef struct {
  int type;
  char operation[5];
  int priority;
  long double value;
} elements;

typedef struct {
  char input_buffer[256];
  char x_input[256];
  elements stack[256];
  elements output[256];
  long double x;
  bool in;
} CalcData;

typedef struct {
  elements *output;
  int count;
} DrawData;

typedef struct {
  CalcData *calc_data;
  FrontData *front_data;
} AppData;

typedef struct {
  GtkWidget *loan_entry;
  GtkWidget *period_entry;
  GtkWidget *rate_entry;
  GtkWidget *radio1;
  GtkWidget *radio2;
  GtkWidget *m_label;
  GtkWidget *t_label;
  GtkWidget *over_label;
  GtkWidget *last_label;
  double monthly_payment;
  double total;
  double overpayment;
  double monthly_payment_first;
  double monthly_payment_last;
} CreditData;

// VALIDATION

int validation(char *str);
int x_validation(char *buffer);

// PARSER

int parser(char *input_buffer, elements *lexem, long double x_value);
int digit_processing(elements *lexem, char *buf, size_t *i);
void unary_processing(elements *lexem, int *count);
void operator_processing(char operator, elements * lexem);
void function_processing(char *buf, elements *lexem, size_t *i);
void brackets_processing(char c, elements *lexem);
void negative_processing(elements **lexem);

// POSTFIX NOTATION

void postfix(elements *input, elements *output, int *count);
void input_to_output(elements *output, elements *input);
void sort_brackets(elements *input, elements **output, elements **tmp_ptr,
                   int *i, int *count_out);

// CALCULATION

void calculation(elements *output, int count, long double *res);
long double execute(long double value1, long double value2, char *operation);
void annuity_calculation(double loan, double period, double rate,
                         CreditData *credit_data);
void differential_calculation(double loan, double period, double rate,
                              CreditData *credit_data);

// FRONTEND

void on_main_window_destroy();
void on_credit_window_destroy(GtkWidget *widget, gpointer data);
void on_graph_window_destroy(GtkWidget *widget, gpointer data);
void on_entry_focus_in(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void on_entry_focus_out(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);
void on_button_clicked(GtkButton *button, gpointer user_data);
void open_new_window(elements *output, int count);
void open_credit_window();
void on_process_button_clicked(GtkWidget *widget, gpointer user_data);
void radio_toggled(GtkRadioButton *b, gpointer user_data);
void open_result_window();
void display_result(CreditData *credit_data, gboolean r2);
void set_labels(GtkWidget *widget, GdkEvent *event, gpointer user_data);

// AUX

void free_lexem(elements *lexem, int count);
void print_lexem(elements *lexem, int count);
void free_calc_data(AppData *app_data);
void free_input(CalcData *calc_data);

#endif