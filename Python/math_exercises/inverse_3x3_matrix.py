#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# Python program to take a 3x3 matrix and return its inverse matrix

import numpy as np
import sympy as sp

# Functions
def parse_and_check_type(s):
    try:
        # Convert to float first
        num = float(s)
        # Check if the float value is numerically an integer
        if num.is_integer():
            # If it is, cast it to an int and return as 'int'
            return int(num)
        else:
            return num
    except ValueError:
        return "not a number", None

# User Input
print(f"\n{' ':<4}Find the inverse matrix (work in progress):\n"
      f"\n{' ':<4}Please note that the values of each line must be separated by a ', ' separator."
      f"\n{' ':<4}Also, each line must only take 3 elements.\n")
a = input(f"{' ':<4}Please input the first line of the 3x3 matrix  : ")
b = input(f"{' ':<4}Please input the second line of the 3x3 matrix : ")
c = input(f"{' ':<4}Please input the third line of the 3x3 matrix  : ")

# Processing User Input
first_line = np.array(list(map(parse_and_check_type, (a.split(", ")))))
second_line = np.array(list(map(parse_and_check_type, (b.split(", ")))))
third_line = np.array(list(map(parse_and_check_type, (c.split(", ")))))

input_matrix = np.array([first_line, second_line, third_line])

# # Test output for the input matrix
test_prefix = f"{' ':<4}Input = "
str_out = np.array2string(input_matrix, prefix=test_prefix)

# # Determinant of the input matrix
sp_input_matrix = sp.Matrix(input_matrix).applyfunc(sp.nsimplify)
det_input = sp_input_matrix.det()

# Text Output
print(f"\n{test_prefix}{str_out}")
print(f"\n{' ':<4}{'':{'-'}<80}\n")
print(f"{' ':<4}Determinant of the input matrix: {det_input}")
print(f"\n{' ':<4}{'':{'-'}<80}\n")
