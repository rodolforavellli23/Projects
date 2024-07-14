# Lesson 18 - Classes in Python

# A class example
class Vehicle:
    # Attributes
    def __init__(self, make, model):
        self.make = make
        self.model = model
    # Methods:      
    # First add the set and get mehods for any attribute given to the class, then follow with any other methods you wish the objects inheriting from this class to have.
    # Make
    def set_make(self, new_make):
        self.make = new_make
    def get_make(self):
        return self.make   
    # Model 
    def set_model(self, new_model):
        self.model = new_model
    def get_model(self):
        return self.model
    # Additional Mehods
    def moves(self):
        print("Moves along...")
