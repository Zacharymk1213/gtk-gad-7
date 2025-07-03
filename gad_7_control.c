#include <gtk/gtk.h>
#include <glib/gstdio.h>

static void
print_hello (GtkWidget   *widget,
             gpointer     data)
{
    g_print ("Hello World\n");
}

static void
quit_cb (GtkWindow *window)
{
    gtk_window_close (window);
}

static void activate (GtkApplication *app,
                      gpointer        user_data)
{
    GtkBuilder *builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "gad_7_main.ui", NULL);


    // connect signal handlers to widgets
    GObject *window = gtk_builder_get_object (builder, "window");
    gtk_window_set_application (GTK_WINDOW (window), app);


    gtk_widget_set_visible (GTK_WIDGET(window), TRUE);

    g_object_unref (builder);
}                      

int
main (int     argc,
      char   *argv[])
{
    #ifdef GTK_SRCDIR
        g_chdir (GTK_SRCDIR)
    #endif
    
    GtkApplication *app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  
    int status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
  
    return status;
  }

      // // Get the label 
    // GObject *label = gtk_builder_get_object (builder, "description_label");
    // // load top
    // GObject *label2 = gtk_builder_get_object (builder, "last_two_weeks_label");
    // GObject *label3 = gtk_builder_get_object (builder, "not_at_all_label");
    // GObject *label4 = gtk_builder_get_object (builder, "several_days_label");
    // GObject *label5 = gtk_builder_get_object (builder, "more_than_half_label");
    // GObject *label6 = gtk_builder_get_object (builder, "nearly_every_day_label");
    // GObject *seperator = gtk_builder_get_object (builder, "seperate_title_and_questions");
    // GObject *seperator2 = gtk_builder_get_object (builder, "two_weeks_separator");
    // GObject *seperator3 = gtk_builder_get_object (builder, "not_at_all_separator");
    // GObject *seperator4 = gtk_builder_get_object (builder, "several_days_separator");
    // GObject *seperator5 = gtk_builder_get_object (builder, "more_than_half_days_separator");
    // // load first question

    // GObject *question1 = gtk_builder_get_object (builder, "first_question_label");
    // GObject *q1radio1 = gtk_builder_get_object (builder, "first_question_0");
    // GObject *q1radio2 = gtk_builder_get_object (builder, "first_question_1");
    // GObject *q1radio3 = gtk_builder_get_object (builder, "first_question_2");
    // GObject *q1radio4 = gtk_builder_get_object (builder, "first_question_3");
    // GObject *q1separator0 = gtk_builder_get_object (builder, "first_question_separator");
    // GObject *q1separator1 = gtk_builder_get_object (builder, "seperator_q_1_0");
    // GObject *q1separator2 = gtk_builder_get_object (builder, "seperator_q_1_1");
    // GObject *q1separator3 = gtk_builder_get_object (builder, "seperator_q_1_2");
    // // load second question

    // GObject *question2 = gtk_builder_get_object (builder, "second_question_label");
    // GObject *q2radio1 = gtk_builder_get_object (builder, "second_question_0");
    // GObject *q2radio2 = gtk_builder_get_object (builder, "second_question_1");
    // GObject *q2radio3 = gtk_builder_get_object (builder, "second_question_2");
    // GObject *q2radio4 = gtk_builder_get_object (builder, "second_question_3");
    // GObject *q2separator0 = gtk_builder_get_object (builder, "second_question_separator");
    // GObject *q2separator1 = gtk_builder_get_object (builder, "seperator_q_2_0");
    // GObject *q2separator2 = gtk_builder_get_object (builder, "seperator_q_2_1");
    // GObject *q2separator3 = gtk_builder_get_object (builder, "seperator_q_2_2");
    // // load third question

    // GObject *question3 = gtk_builder_get_object (builder, "third_question_label");
    // GObject *q3radio1 = gtk_builder_get_object (builder, "third_question_0");
    // GObject *q3radio2 = gtk_builder_get_object (builder, "third_question_1");
    // GObject *q3radio3 = gtk_builder_get_object (builder, "third_question_2");
    // GObject *q3radio4 = gtk_builder_get_object (builder, "third_question_3");
    // GObject *q3separator0 = gtk_builder_get_object (builder, "third_question_separator");
    // GObject *q3separator1 = gtk_builder_get_object (builder, "seperator_q_3_0");
    // GObject *q3separator2 = gtk_builder_get_object (builder, "seperator_q_3_1");
    // GObject *q3separator3 = gtk_builder_get_object (builder, "seperator_q_3_2");
    // // load fourth question
    // GObject *question4 = gtk_builder_get_object (builder, "fourth_question_label");
    // GObject *q4radio1 = gtk_builder_get_object (builder, "fourth_question_0");
    // GObject *q4radio2 = gtk_builder_get_object (builder, "fourth_question_1");
    // GObject *q4radio3 = gtk_builder_get_object (builder, "fourth_question_2");
    // GObject *q4radio4 = gtk_builder_get_object (builder, "fourth_question_3");
    // GObject *q4separator0 = gtk_builder_get_object (builder, "fourth_question_separator");
    // GObject *q4separator1 = gtk_builder_get_object (builder, "seperator_q_4_0");
    // GObject *q4separator2 = gtk_builder_get_object (builder, "seperator_q_4_1");
    // GObject *q4separator3 = gtk_builder_get_object (builder, "seperator_q_4_2");
    // // load fifth question
    // GObject *question5 = gtk_builder_get_object (builder, "fifth_question_label");
    // GObject *q5radio1 = gtk_builder_get_object (builder, "fifth_question_0");
    // GObject *q5radio2 = gtk_builder_get_object (builder, "fifth_question_1");
    // GObject *q5radio3 = gtk_builder_get_object (builder, "fifth_question_2");
    // GObject *q5radio4 = gtk_builder_get_object (builder, "fifth_question_3");
    // GObject *q5separator0 = gtk_builder_get_object (builder, "fifth_question_separator");
    // GObject *q5separator1 = gtk_builder_get_object (builder, "seperator_q_5_0");
    // GObject *q5separator2 = gtk_builder_get_object (builder, "seperator_q_5_1");
    // GObject *q5separator3 = gtk_builder_get_object (builder, "seperator_q_5_2");
    // // load sixth question
    // GObject *question6 = gtk_builder_get_object (builder, "sixth_question_label");
    // GObject *q6radio1 = gtk_builder_get_object (builder, "sixth_question_0");
    // GObject *q6radio2 = gtk_builder_get_object (builder, "sixth_question_1");
    // GObject *q6radio3 = gtk_builder_get_object (builder, "sixth_question_2");
    // GObject *q6radio4 = gtk_builder_get_object (builder, "sixth_question_3");
    // GObject *q6separator0 = gtk_builder_get_object (builder, "sixth_question_separator");
    // GObject *q6separator1 = gtk_builder_get_object (builder, "seperator_q_6_0");
    // GObject *q6separator2 = gtk_builder_get_object (builder, "seperator_q_6_1");
    // GObject *q6separator3 = gtk_builder_get_object (builder, "seperator_q_6_2");

