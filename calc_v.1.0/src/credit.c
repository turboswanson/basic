#include "calc.h"

void open_credit_window() {
  GtkBuilder *new_builder;
  GtkWidget *new_window;
  
  new_builder = gtk_builder_new();
  gtk_builder_add_from_file(new_builder, "smartcalc.glade", NULL);

  new_window = GTK_WIDGET(gtk_builder_get_object(new_builder, "credit_window"));

  CreditData *credit_data = g_slice_new(CreditData);
  credit_data->loan_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "loan_entry"));  
  credit_data->period_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "period_entry"));
  credit_data->rate_entry = GTK_WIDGET(gtk_builder_get_object(new_builder, "rate_entry"));
  credit_data->radio1 = GTK_WIDGET(gtk_builder_get_object(new_builder, "annuity"));
  credit_data->radio2 = GTK_WIDGET(gtk_builder_get_object(new_builder, "differential"));

  GtkWidget *calculate_button = GTK_WIDGET(gtk_builder_get_object(new_builder, "calculate"));
  g_signal_connect(calculate_button, "clicked", G_CALLBACK(on_process_button_clicked), credit_data);

  gtk_widget_show_all(new_window);
  
}

void on_process_button_clicked(GtkWidget *widget, gpointer user_data) {
    double loan = 0;
    double period = 0;
    double rate = 0;

    CreditData *credit_data = (CreditData *)user_data;
   
    const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(credit_data->loan_entry));
    const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(credit_data->period_entry));
    const gchar *text3 = gtk_entry_get_text(GTK_ENTRY(credit_data->rate_entry));

    sscanf(text1,"%lf",&loan);
    sscanf(text2,"%lf",&period);
    sscanf(text3,"%lf",&rate);

    gboolean r1 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(credit_data->radio1));
    gboolean r2 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(credit_data->radio2));

    double monthly_payment = 0.0;
    double total = 0.0;
    double overpayment = 0.0;

    if(r1) {
      annuity_calculation(loan,period,rate,&monthly_payment,&total,&overpayment);
    }else if(r2) {
      differential_calculation(loan,period,rate,&monthly_payment,&total,&overpayment);
    }

    gtk_entry_set_text(GTK_ENTRY(credit_data->loan_entry), "");
    gtk_entry_set_text(GTK_ENTRY(credit_data->period_entry), "");
    gtk_entry_set_text(GTK_ENTRY(credit_data->rate_entry), "");
        
    (void)widget;
}

void annuity_calculation(double loan,double period,double rate,double *monthly_payment,double *total,double *overpayment) {

  double monthly_rate = rate/12;
  monthly_rate /= 100.;

  double factor = (monthly_rate*pow((1+monthly_rate),period)) / (pow((1+monthly_rate),period)-1);

  *monthly_payment = loan*factor;
  *total = monthly_payment*period;
  *overpayment = total - loan;

}

void differential_calculation(loan,period,rate,&monthly_payment,&total,&overpayment) {
  double x = 0.0; 
  double mon = 0.0;
  double z = 0.0;
  double aug = period/12; // 10

  for(int i = 1; i <= period; i++){
    if(i%12 == 1 || i%12 == 3 || i%12 == 5 || i%12 == 7 || i%12 == 8 || i%12 == 10 || i%12 == 0) {
      z = 31;
    }else if(i%12 == 2 || i%12 == 4 || i%12 == 6 || i%12 == 9 || i%12 == 11) {
      z = 30;
    }

    mon = loan/period;
    x = loan * rate * z/365; // 1 - 31 2 - 28 3 - 31 4 - 30 5 - 31 6 - 30 7 - 31 8 - 31 9 - 30 10 - 31 11 - 30 12 - 31 
    loan = loan - x;
  }

}





