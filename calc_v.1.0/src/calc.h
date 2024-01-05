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
  int type;
  char operation[5];
  int priority;
  double value;
} elements;

typedef struct {
  elements *output;
  int count;
} DrawData;

// void on_entry_activate(GtkEntry *entry, gpointer user_data);
void on_main_window_destroy();
int parser(char *input_buffer, elements *lexem, double x_value);
int validation(char *str);
int x_validation(char *buffer);
void free_lexem(elements *lexem, int count);
void on_entry_focus_in(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void on_entry_focus_out(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);
int digit_processing(elements *lexem, char *buf, size_t *i);
void unary_processing(elements *lexem, int *count);
void operator_processing(char operator, elements * lexem);
void function_processing(char *buf, elements *lexem, size_t *i);
void brackets_processing(char c, elements *lexem);
void negative_processing(elements **lexem);
void postfix(elements *input, elements *output, int *count);
void input_to_output(elements *output, elements *input);
void sort_brackets(elements *input, elements **output, elements **tmp_ptr,
                   int *i, int *count_out);
void calculation(elements *output, int count, double *res);
double execute(double value1, double value2, char *operation);
void print_lexem(elements *lexem, int count);
void on_button_clicked(GtkButton *button, gpointer user_data);
void open_new_window(elements *output, int count);

#endif