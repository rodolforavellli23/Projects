#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# Matrix multiplication on Python

# Imported libraries
import numpy as np
import sympy as sp

# Variable declaration

prefix_1 = f"{' ':<4}Matrix A = "
prefix_2 = f"{' ':<4}Matrix A^-1 = " 
prefix_3 = f"{' ':<4}A*A^-1 = I; I = "

np_matrix_A = np.array([[1, 2, 3],
                        [0, 1, 4],
                        [5, 6, 0]])

# Calculating the Inverse matrix

sp_matrix_A = sp.Matrix(np_matrix_A)

sp_matrix_A_inver = sp.Matrix.inv(sp_matrix_A) 

np_matrix_A_inver = np.array(sp_matrix_A_inver).astype(np.int64)

# Calculating the Identity matrix
# Have to use sympy here for exact results

sp_matrix_I = sp_matrix_A * sp_matrix_A_inver
np_matrix_I = np.array(sp_matrix_I).astype(np.int64)

# String formatting
str_1 = np.array2string(np_matrix_A, prefix=prefix_1)
str_2 = np.array2string(np_matrix_A_inver, prefix=prefix_2, formatter={'int': lambda x: f"{x:3d}"})
str_3 = np.array2string(np_matrix_I, prefix=prefix_3, formatter={'int': lambda x: f"{x:1d}"})

# Text output
print(f"\n{prefix_1}{str_1}\n")
print(f"{prefix_2}{str_2}\n")
print(f"{prefix_3}{str_3}\n")
