![image](https://github.com/user-attachments/assets/ea6b696b-33bd-419f-883c-ba0d418637a6)

Gtk Gad 7 is an application that allows you to self-score the GAD-7.

Compile it using:
```
gcc $( pkg-config --cflags gtk4 ) -o gad_7 gad_7_control.c $( pkg-config --libs gtk4 )

```
