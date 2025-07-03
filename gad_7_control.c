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
static GtkLabel *type_of_anxiety_label;

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
    // Update severity display
    gchar *anxiety_text; // declare once
    if (total_score <= 4) {
        anxiety_text = g_strdup_printf("Minimal anxiety");
    } else if (total_score <= 9) {
        anxiety_text = g_strdup_printf("Mild anxiety");
    } else if (total_score <= 14) {
        anxiety_text = g_strdup_printf("Moderate anxiety");
    } else {  // 15-21 (changed from "total_score < 14" which was wrong)
        anxiety_text = g_strdup_printf("Severe anxiety");
    }

    gtk_label_set_text(type_of_anxiety_label, anxiety_text);
    g_free(anxiety_text);
    
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
    type_of_anxiety_label = GTK_LABEL(gtk_builder_get_object(builder, "type_of_anxiety_label"));
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

