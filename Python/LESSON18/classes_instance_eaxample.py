import io # Pyhton module for stream handling.
import sys # Python built-in functions.
from classes import Vehicle

# An example of a object instance
my_car = Vehicle("Tesla","Model 3")

# -------------------------------------------------------------------------------------

# This creates the variable that will store the output for the method 'moves'
captured_output = io.StringIO()

# This will set the stdout to the previously set variable
sys.stdout = captured_output

# Here will follow the method's output we wish to capture:

# Using a method inherited from the example 'classes.py'
my_car.moves()

# Reseting stdout to it's original config
sys.stdout = sys.__stdout__

# Get the captured output as a 'str' value
var = captured_output.getvalue()

# Close the 'StringIO' object
captured_output.close()

# -------------------------------------------------------------------------------------

print(f"\nMy car's model: {my_car.get_model()}\n\nMy car's maker: {my_car.get_make()}\n\nIt {var.lower()}")