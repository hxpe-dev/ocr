#include <gtk/gtk.h>

// Called when the button is clicked
static void on_click(GtkButton *button, gpointer user_data) {
  (void)button;
  GtkLabel *label = GTK_LABEL(user_data);
  gtk_label_set_text(label, "Button clicked!");
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  // Main window
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "OCR Word Search Solver");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // Vertical container
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_set_border_width(GTK_CONTAINER(box), 20);
  gtk_container_add(GTK_CONTAINER(window), box);

  // Label and button
  GtkWidget *label = gtk_label_new("Hello GTK!");
  GtkWidget *button = gtk_button_new_with_label("Click me");
  g_signal_connect(button, "clicked", G_CALLBACK(on_click), label);

  gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}
