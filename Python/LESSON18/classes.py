# Lesson 18 - Classes in Python

import io # Pyhton module for stream handling.
import sys # Python built-in functions.

# A class example
class Vehicle:
    # Attributes
    def __init__(self, make, model):
        self.make = make
        self.model = model
    # Methods:
    #  
    # First add the set and set mehods for any attribute given to the class, then follow with any other methods you wish the objects inheriting from this class to have.

    def set_make(self):
        self.make = self
    def get_make(self):
        return self.make
    
    def set_model(self):
        self.model = self
    def get_model(self):
        return self.model

    def moves(self):
        print("Moves along...")

# An example of a object instance
my_car = Vehicle("Tesla","Model 3")

# -------------------------------------------------------------------------------------

# This creates the variable that will store the output for the method 'moves'
captured_output = io.StringIO()

# This will set the stdout to the previously set variable
sys.stdout = captured_output

# Using a method inherited from the example class
my_car.moves()

# Reseting stdout to it's original config
sys.stdout = sys.__stdout__

# Get the captured output as a 'str' value
var = captured_output.getvalue()

# Close the 'StringIO' object
captured_output.close()

# -------------------------------------------------------------------------------------

print(f"\nMy car's model: {my_car.get_model()}\n\nMy car's maker: {my_car.get_make()}\n\nIt {var.lower()}")
