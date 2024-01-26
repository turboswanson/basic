#include "calc.h"

void open_new_window(elements *output, int count) {
  GtkBuilder *new_builder;
  GtkWidget *new_window;
  GtkWidget *drawing_area;

  DrawData *draw_data = g_slice_new(DrawData);
  draw_data->output = output;
  draw_data->count = count;

  new_builder = gtk_builder_new();
  gtk_builder_add_from_file(new_builder, "smartcalc.glade", NULL);

  new_window =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "drawing_window"));
  drawing_area =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "drawing_area"));
  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw),
                   draw_data);

  gtk_widget_show_all(new_window);
  g_signal_connect(new_window, "destroy", G_CALLBACK(on_graph_window_destroy), draw_data);

}

void on_graph_window_destroy(GtkWidget *widget, gpointer data) {
    DrawData *draw_data = (DrawData *)data;
    g_slice_free(DrawData, draw_data);
    (void)widget;
}


void on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  DrawData *draw_data = (DrawData *)user_data;
  elements *output = draw_data->output;
  int count = draw_data->count;

  double width = (double)gtk_widget_get_allocated_width(widget);
  double height = (double)gtk_widget_get_allocated_height(widget);
  cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);  // RGB values for white
  cairo_paint(cr);

  cairo_translate(cr, width / 2.0,
                  height / 2.0);  // Move the origin to the center

  // Draw X and Y axes
  cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
  cairo_set_line_width(cr, 1.0);

  // X-axis
  cairo_move_to(cr, -width / 2.0, 0);
  cairo_line_to(cr, width / 2.0, 0);
  cairo_stroke(cr);

  // Y-axis
  cairo_move_to(cr, 0, -height / 2.0);
  cairo_line_to(cr, 0, height / 2.0);
  cairo_stroke(cr);

  // X-axis label
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_move_to(cr, width / 2.0 - 20, -10);
  cairo_show_text(cr, "X");

  // // Y-axis label
  cairo_move_to(cr, 10, -height / 2.0 + 20);
  cairo_show_text(cr, "Y");

  cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  // RGB values for red

  // Draw X-axis values
  for (double i = (-width / 2.); i < width / 2.; i += 50) {
    cairo_move_to(cr, i, -5);
    cairo_line_to(cr, i, 5);
    cairo_stroke(cr);

    cairo_move_to(cr, i - 5, 20);
    char label[16];
    if (i == 0.0)
      sprintf(label, "0");
    else
      sprintf(label, "%.2lf", i / 100);
    cairo_show_text(cr, label);
  }

  // Draw Y-axis values
  for (double i = (-height / 2); i < height / 2; i += 50) {
    cairo_move_to(cr, -5, i);
    cairo_line_to(cr, 5, i);
    cairo_stroke(cr);

    cairo_move_to(cr, -40, i + 5);
    if (i == 0) continue;
    char label[16];
    sprintf(label, "%.2lf", -i / 100);
    cairo_show_text(cr, label);
  }

  // // Draw the graph
  cairo_set_line_width(cr, 1.0);

  int flag = 0;

  for (double x = -width; x < width; x += 0.1) {
    long double y = 0;

    for (int i = 0; i < count; i++) {
      if ((output + i)->operation[0] == 'x') {
        (output + i)->value = x;
      }
    }
    calculation(output, count, &y);

    if (!isnan(y)) {
      if (!flag) {
        cairo_move_to(cr, x * 100, -y * 100);
        flag = 1;
      }
      cairo_line_to(cr, x * 100, -y * 100);
    }
  }

  cairo_stroke(cr);

  flag = 0;
}
