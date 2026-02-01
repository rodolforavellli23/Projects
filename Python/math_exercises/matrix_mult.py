#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# Matrix multiplication on Python

# Imported libraries
import numpy as np

# Variable declaration
prefix_1 = f"{' ':<4}Matrix A = "
prefix_2 = f"{' ':<4}Matrix A^-1 = " 
prefix_3 = f"{' ':<4}A*A^-1 = I; I = "

matrix_A = np.array([[1, 2, 3],
                     [0, 1, 4],
                     [5, 6, 0]])

matrix_A_inver = np.array([[-24,  18,  5],
                           [ 20, -15, -4],
                           [ -5,   4,  1]])

# Matrix multiplication
matrix_I = np.matmul(matrix_A, matrix_A_inver)

# String formatting
str_1 = np.array2string(matrix_A, prefix=prefix_1)
str_2 = np.array2string(matrix_A_inver, prefix=prefix_2)
str_3 = np.array2string(matrix_I, prefix=prefix_3)

# Text output
print(f"\n{prefix_1}{str_1}\n")
print(f"{prefix_2}{str_2}\n")
print(f"{prefix_3}{str_3}\n")

