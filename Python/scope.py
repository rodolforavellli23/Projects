# Chapter 11 - Scope

name = "rodolfo"

def greet(var):
    print("\nHello {}!".format(var.capitalize()))
    color = input("\nFavorite Color?: ")
    print("\n{}'s favorite color is {}\n".format(name.capitalize(), color))

greet(name)
