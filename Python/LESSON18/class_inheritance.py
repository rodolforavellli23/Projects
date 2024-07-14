# Lesson 18 - Class inheritance in Python

from classes import Vehicle

class Airplane(Vehicle):
    def __init__(self, make, model, faa_id):
        super().__init__(make, model)
        self.faa_id = faa_id
    
    def set_faa_id(self, new_value):
        self.faa_id = new_value
    def get_faa_id(self):
        return self.faa_id    

    def moves(self):
        return "It flies on..."

my_airplane = Airplane("Airbus","A308","N-12345")

my_airplane.set_faa_id("N-22222")

print(f"\nMy airplane's maker: {my_airplane.get_make()}\n\nMy airplane's model: {my_airplane.get_model()}\n\nMy FAA ID: {my_airplane.get_faa_id()}\n\n{my_airplane.moves()}\n")