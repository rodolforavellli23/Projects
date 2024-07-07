# Lesson 18 - Class inheritance in Python

from classes import Vehicle

class Airplane(Vehicle):
    def __init__(self, make, model):
        super().__init__(make, model)
    
    def moves(self):
        return "It flies on..."

my_airplane = Airplane("Airbus","A308")

print(f"\nMy airplane's maker: {my_airplane.get_make()}\nMy airplane's model: {my_airplane.get_model()}\n{my_airplane.moves()}\n")