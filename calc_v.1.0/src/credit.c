#include "calc.h"

void open_credit_window() {
  GtkBuilder *new_builder;
  GtkWidget *new_window;

  new_builder = gtk_builder_new();
  gtk_builder_add_from_file(new_builder, "smartcalc.glade", NULL);

  new_window = GTK_WIDGET(gtk_builder_get_object(new_builder, "credit_window"));

  CreditData *credit_data = g_slice_new(CreditData);
  credit_data->loan_entry =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "loan_entry"));
  credit_data->period_entry =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "period_entry"));
  credit_data->rate_entry =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "rate_entry"));
  credit_data->radio1 =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "annuity"));
  credit_data->radio2 =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "differential"));
  credit_data->m_label =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "m_label"));
  credit_data->t_label =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "t_label"));
  credit_data->over_label =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "over_label"));
  credit_data->last_label =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "last_label"));

  GtkWidget *calculate_button =
      GTK_WIDGET(gtk_builder_get_object(new_builder, "calculate"));
  g_signal_connect(calculate_button, "clicked",
                   G_CALLBACK(on_process_button_clicked), credit_data);
  g_signal_connect(credit_data->loan_entry, "focus-in-event",
                   G_CALLBACK(set_labels), credit_data);

  gtk_widget_show_all(new_window);

  g_signal_connect(new_window, "destroy", G_CALLBACK(on_credit_window_destroy), credit_data);

}

void on_credit_window_destroy(GtkWidget *widget, gpointer data) {
    CreditData *credit_data = (CreditData *)data;
    g_slice_free(CreditData, credit_data);
    (void)widget;
}

void on_process_button_clicked(GtkWidget *widget, gpointer user_data) {
  double loan = 0;
  double period = 0;
  double rate = 0;

  CreditData *credit_data = (CreditData *)user_data;

  const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(credit_data->loan_entry));
  const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(credit_data->period_entry));
  const gchar *text3 = gtk_entry_get_text(GTK_ENTRY(credit_data->rate_entry));

  sscanf(text1, "%lf", &loan);
  sscanf(text2, "%lf", &period);
  sscanf(text3, "%lf", &rate);

  gboolean r1 =
      gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(credit_data->radio1));
  gboolean r2 =
      gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(credit_data->radio2));

  credit_data->monthly_payment = 0.0;
  credit_data->total = 0.0;
  credit_data->overpayment = 0.0;
  credit_data->monthly_payment_first = 0.0;
  credit_data->monthly_payment_last = 0.0;

  if (r1) {
    annuity_calculation(loan, period, rate, credit_data);
  } else if (r2) {
    differential_calculation(loan, period, rate, credit_data);
  }

  display_result(credit_data, r2);

  (void)widget;
}

void annuity_calculation(double loan, double period, double rate,
                         CreditData *credit_data) {
  double monthly_rate = rate / 12;
  monthly_rate /= 100.;

  double factor = (monthly_rate * pow((1 + monthly_rate), period)) /
                  (pow((1 + monthly_rate), period) - 1);

  credit_data->monthly_payment = loan * factor;
  credit_data->total = credit_data->monthly_payment * period;
  credit_data->overpayment = credit_data->total - loan;
}

void differential_calculation(double loan, double period, double rate,
                              CreditData *credit_data) {
  double x = 0.0;
  double days = 0.0;
  rate = rate / 100.00;
  double fixed = loan / period;

  credit_data->total = loan;

  for (int i = 1; i <= period; i++) {
    if (i % 12 == 2) {
      days = 28;

      if (period > 36 && i % 36 == 2) {
        days = 29;
      }
    } else if (i % 12 == 1 || i % 12 == 3 || i % 12 == 5 || i % 12 == 7 ||
               i % 12 == 8 || i % 12 == 10 || i % 12 == 0) {
      days = 31;
    } else if (i % 12 == 4 || i % 12 == 6 || i % 12 == 9 || i % 12 == 11) {
      days = 30;
    }

    x = loan * rate * days / 365;

    credit_data->total += x;

    if (i == 1) {
      credit_data->monthly_payment_first = fixed + x;
    }

    if (i == period) {
      credit_data->monthly_payment_last = fixed + x;
    }

    loan = loan - fixed;
  }

  credit_data->overpayment = credit_data->total - fixed * period;
}

void display_result(CreditData *credit_data, gboolean r2) {
  char m_str[64];
  char t_str[64];
  char over_str[64];
  char last_str[64];

  memset(m_str, 0, sizeof(m_str));
  memset(t_str, 0, sizeof(t_str));
  memset(over_str, 0, sizeof(over_str));
  memset(last_str, 0, sizeof(last_str));

  gtk_entry_set_text(GTK_ENTRY(credit_data->loan_entry), "");
  gtk_entry_set_text(GTK_ENTRY(credit_data->period_entry), "");
  gtk_entry_set_text(GTK_ENTRY(credit_data->rate_entry), "");

  sprintf(t_str, "Total: %.2lf", credit_data->total);
  gtk_label_set_text(GTK_LABEL(credit_data->t_label), t_str);

  sprintf(over_str, "Overpayment: %.2lf", credit_data->overpayment);
  gtk_label_set_text(GTK_LABEL(credit_data->over_label), over_str);

  if (r2) {
    sprintf(m_str, "The first payment: %.2lf",
            credit_data->monthly_payment_first);
    gtk_label_set_text(GTK_LABEL(credit_data->m_label), m_str);

    sprintf(last_str, "The last payment: %.2lf",
            credit_data->monthly_payment_last);
    gtk_label_set_text(GTK_LABEL(credit_data->last_label), last_str);
  } else {
    sprintf(m_str, "Monthly Payment: %.2lf", credit_data->monthly_payment);
    gtk_label_set_text(GTK_LABEL(credit_data->m_label), m_str);
  }
}

void set_labels(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
  CreditData *credit_data = (CreditData *)user_data;

  gtk_label_set_text(GTK_LABEL(credit_data->m_label), "");
  gtk_label_set_text(GTK_LABEL(credit_data->t_label), "");
  gtk_label_set_text(GTK_LABEL(credit_data->over_label), "");
  gtk_label_set_text(GTK_LABEL(credit_data->last_label), "");

  (void)widget;
  (void)event;
  (void)user_data;
}
