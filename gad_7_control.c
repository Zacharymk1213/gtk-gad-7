#include <gtk/gtk.h>
#include <glib/gstdio.h>


// Global variables to store radio button groups
static GtkCheckButton *q1_buttons[4];
static GtkCheckButton *q2_buttons[4];
static GtkCheckButton *q3_buttons[4];
static GtkCheckButton *q4_buttons[4];
static GtkCheckButton *q5_buttons[4];
static GtkCheckButton *q6_buttons[4];
static GtkCheckButton *q7_buttons[4];

static GtkLabel *score_label;

// Function to calculate and display the total score
static void calculate_score(void) {
    int total_score = 0;
    
    // Check each question group
    GtkCheckButton* question_groups[7][4] = {
        {q1_buttons[0], q1_buttons[1], q1_buttons[2], q1_buttons[3]},
        {q2_buttons[0], q2_buttons[1], q2_buttons[2], q2_buttons[3]},
        {q3_buttons[0], q3_buttons[1], q3_buttons[2], q3_buttons[3]},
        {q4_buttons[0], q4_buttons[1], q4_buttons[2], q4_buttons[3]},
        {q5_buttons[0], q5_buttons[1], q5_buttons[2], q5_buttons[3]},
        {q6_buttons[0], q6_buttons[1], q6_buttons[2], q6_buttons[3]},
        {q7_buttons[0], q7_buttons[1], q7_buttons[2], q7_buttons[3]}
    };
    
    for (int q = 0; q < 7; q++) {
        for (int i = 0; i < 4; i++) {
            if (question_groups[q][i] && gtk_check_button_get_active(question_groups[q][i])) {
                total_score += i; // Value is 0, 1, 2, or 3
                break;
            }
        }
    }
    
    // Update score display
    gchar *score_text = g_strdup_printf("Score: %d", total_score);
    gtk_label_set_text(score_label, score_text);
    g_free(score_text);
    
    g_print("GAD-7 Score: %d\n", total_score);
}
// Callback for radio button changes
static void on_radio_button_toggled(GtkCheckButton *button, gpointer user_data) {
    calculate_score();
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

    // Get radio buttons for each question
    q1_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "first_question_0"));
    q1_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "first_question_1"));
    q1_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "first_question_2"));
    q1_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "first_question_3"));

    q2_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "second_question_0"));
    q2_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "second_question_1"));
    q2_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "second_question_2"));
    q2_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "second_question_3"));

    q3_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "third_question_0"));
    q3_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "third_question_1"));
    q3_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "third_question_2"));
    q3_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "third_question_3"));
    q4_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fourth_question_0"));
    q4_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fourth_question_1"));
    q4_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fourth_question_2"));
    q4_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fourth_question_3"));
    q5_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fifth_question_0"));
    q5_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fifth_question_1"));
    q5_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fifth_question_2"));
    q5_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "fifth_question_3"));
    q6_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "sixth_question_0"));
    q6_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "sixth_question_1"));
    q6_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "sixth_question_2"));
    q6_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "sixth_question_3"));
    q7_buttons[0] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "seventh_question_0"));
    q7_buttons[1] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "seventh_question_1"));
    q7_buttons[2] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "seventh_question_2"));
    q7_buttons[3] = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "seventh_question_3"));

    score_label = GTK_LABEL(gtk_builder_get_object(builder, "sum_label"));
    // Connect signals for all radio buttons
    for (int i = 0; i < 4; i++) {
        g_signal_connect(q1_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q2_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q3_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q4_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q5_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q6_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
        g_signal_connect(q7_buttons[i], "toggled", G_CALLBACK(on_radio_button_toggled), NULL);
    }

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

