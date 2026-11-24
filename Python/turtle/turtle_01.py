#!/usr/bin/python3

import turtle 

screen = turtle.Screen()
t = turtle.Turtle()

screen.listen()
screen.onkeypress(lambda: t.forward(10), "Up")
screen.onkeypress(lambda: t.left(15), "Left")
screen.onkeypress(lambda: t.right(15), "Right")
screen.onkeypress(lambda: t.backward(15), "Down")

turtle.mainloop()
