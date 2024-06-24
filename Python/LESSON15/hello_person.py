# LESSON 15 - Python Command Line Arguments

import argparse

parser = argparse.ArgumentParser(description="Provides a personal greeting.") # Creates the parser

parser.add_argument(
    "-n", "--name", metavar="name", nargs='+',
    required="True", help="The name of the person to be greeted"
) # Adds the argument

args = parser.parse_args() # Parses arguments

for arg in vars(args):
    list_as_string = " ".join(map(str,(getattr(args,arg))))

# The above loop will parse through the Namespace object created by the 'parse_args()' function, then it will join
# into the 'list_as_string' variable the arguments stored in 'vars(args)' that have been retrieved by the 'getattr(*obj, *str)' 
# function. Each atribute will be iteratively cast into a 'str'.

print(f"Hello {list_as_string}!")