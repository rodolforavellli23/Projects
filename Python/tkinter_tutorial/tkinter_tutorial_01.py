#!/home/greenshoots/Documentos/GitHub/Projects/Python/tkinter_tutorial/venv/bin/python3

# First tkinter lesson

from tkinter import *
# import the library

window = Tk()
# Create the window object

window.geometry("480x470")
# Set windows width x height

window.title("Hello World!")
# Window title

icon = PhotoImage(file='./src/apu.png') 
# This will create an icon object that can be displayed on the taskbar

window.iconphoto(True, icon)
# Display the window icon on the taskbar as the icon for the open window

window.config(background="#38312b")
# Set the background to this color I picked

window.mainloop()
# Create the window main loop, it will stay open until the user closes the program
