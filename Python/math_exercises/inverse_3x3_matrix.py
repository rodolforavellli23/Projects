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

np_input_matrix = np.array([first_line, second_line, third_line])
sp_input_matrix = sp.Matrix(np_input_matrix).applyfunc(sp.nsimplify)

# # Test output for the Input matrix
test_prefix = f"{' ':<4}Input = "
str_out_1 = np.array2string(np_input_matrix, prefix=test_prefix)

# # Determinant of the Input matrix
det_input = sp_input_matrix.det()

# # Cofactor matrix

label = f"{' ':<4}Cofactor matrix of the given input matrix: "
cofactor_prefix = f"{" ":<12}"

# | 00 01 02 |
# | 10 11 12 |
# | 20 21 22 |

# -----------------------------------------------------------------
np_a11 = np.array([[np_input_matrix[1][1], np_input_matrix[1][2]], 
                   [np_input_matrix[2][1], np_input_matrix[2][2]]])

det_a11 = sp.Matrix(np_a11).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a12 = np.array([[np_input_matrix[1][0], np_input_matrix[1][2]],
                   [np_input_matrix[2][0], np_input_matrix[2][2]]])

det_a12 = sp.Matrix(np_a12).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a13 = np.array([[np_input_matrix[1][0], np_input_matrix[1][1]], 
                   [np_input_matrix[2][0], np_input_matrix[2][1]]])

det_a13 = sp.Matrix(np_a13).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a21 = np.array([[np_input_matrix[0][1], np_input_matrix[0][2]], 
                   [np_input_matrix[2][1], np_input_matrix[2][2]]])

det_a21 = sp.Matrix(np_a21).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a22 = np.array([[np_input_matrix[0][0], np_input_matrix[0][2]], 
                   [np_input_matrix[2][0], np_input_matrix[2][2]]])

det_a22 = sp.Matrix(np_a22).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a23 = np.array([[np_input_matrix[0][0], np_input_matrix[0][1]], 
                   [np_input_matrix[2][0], np_input_matrix[2][1]]])

det_a23 = sp.Matrix(np_a23).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a31 = np.array([[np_input_matrix[0][1], np_input_matrix[0][2]], 
                   [np_input_matrix[1][1], np_input_matrix[1][2]]])

det_a31 = sp.Matrix(np_a31).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a32 = np.array([[np_input_matrix[0][0], np_input_matrix[0][2]], 
                   [np_input_matrix[1][0], np_input_matrix[1][2]]])

det_a32 = sp.Matrix(np_a32).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
np_a33 = np.array([[np_input_matrix[0][0], np_input_matrix[0][1]],
                   [np_input_matrix[1][0], np_input_matrix[1][1]]])

det_a33 = sp.Matrix(np_a33).applyfunc(sp.nsimplify).det()

# -----------------------------------------------------------------
sp_cofactor_matrix = sp.Matrix([[ det_a11, -det_a12,  det_a13],
                                [-det_a21,  det_a22, -det_a23],
                                [ det_a31, -det_a32,  det_a33]])

cofactor_line_1 = np.array(list(map(parse_and_check_type, sp_cofactor_matrix[0, :])))
cofactor_line_2 = np.array(list(map(parse_and_check_type, sp_cofactor_matrix[1, :])))
cofactor_line_3 = np.array(list(map(parse_and_check_type, sp_cofactor_matrix[2, :])))

np_cofactor_matrix = np.array([cofactor_line_1, cofactor_line_2, cofactor_line_3])

str_out_2 = np.array2string(np_cofactor_matrix, prefix=cofactor_prefix,
                                                formatter={'float_kind': lambda x: f"{x: >6.1f}", # ' >' forces alignment and sign space
                                                           'int_kind': lambda x: f"{x: >4d}"})

# # TODO: Create and print the Transpose matrix of the Cofactor matrix

# Text Output
print(f"\n{test_prefix}{str_out_1}")
print(f"\n{' ':<4}{'':{'-'}<80}\n")
print(f"{' ':<4}Determinant of the input matrix: {det_input}")
print(f"\n{' ':<4}{'':{'-'}<80}\n")
print(f"{label}\n\n{cofactor_prefix}{str_out_2}")
print(f"\n{' ':<4}{'':{'-'}<80}\n")
