#!/usr/bin/python3

# testing the *args keyword

def summation(*args):
    result = 0
    for arg in args:
        if not isinstance(arg, (int, float)):
            print("\n\tERROR: may only sum numbers! Do not input chars or strings!")
            return
        result += arg
    print(f"\n\tSummation: {result}\n")

# Convert the input string into a list of numbers
try:
    # Prompt the user for input
    input_str= input("\n\tWhich numbers to sum? (Separate with spaces): ")
    arguments = [float(i) if '.' in i else int(i) for i in input_str.split()]
    summation(*arguments)
except ValueError:
    print("\n\tERROR: Invalid input! Please enter only numbers separated by spaces.")
