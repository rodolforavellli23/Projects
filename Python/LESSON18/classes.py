# Lesson 18 - Classes in Python

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
