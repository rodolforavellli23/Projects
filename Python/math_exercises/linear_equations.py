#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# Solving a system of linear equations with Cramer's method

# Imports
import numpy as np

# Functions

# Pretty printer for the coeficient matrix being used
def printer(matrix, indent):
    for i, line in enumerate(matrix):
        if(i == 0):
            yield f"{line}\n"
        else:
            yield f"{" ":<{indent}}{line}\n"

# Cramer's method for solving linear equations
def cramer(matrix, constants):
    # Determinant of the original matrix
    D = np.linalg.det(matrix)

    # Substituting the constants array into the original matrix
    mat1 = np.array([  constants  , matrix[:, 1],  matrix[:, 2]])
    mat2 = np.array([ matrix[:, 0],  constants  ,  matrix[:, 2]])
    mat3 = np.array([ matrix[:, 0], matrix[:, 1],   constants  ])

    # Calculating the determinants of the modified matrices
    D1 = np.linalg.det(mat1)
    D2 = np.linalg.det(mat2)
    D3 = np.linalg.det(mat3)

    # Calculating the value of the variables x, y & z
    x = D1/D
    y = D2/D
    z = D3/D

    # Printing out the values for the variables x, y & z
    print(f"\n{' ':<4}X = {x:.3f}\n{' ':<4}Y = {y:.3f}\n{' ':<4}Z = {z:.3f}\n")

# Variables

# System Of Equations
# 10*x + 40*y + 70*z = 300
# 20*x + 50*y + 80*z = 360
# 30*x + 60*y + 80*z = 390

# Note: Cramer's method only works on square matrices

# Matrix with the coefficients of the linear equations above
matrix = np.array([[10, 40, 70],
                   [20, 50, 80],
                   [30, 60, 80]])

# Array with the constants
constants = np.array([300, 360, 390])

# Indentation parameter for the printer function
indent = 13

# Text Output
print(f"\n{' ':<4}matrix = {''.join(printer(matrix, indent))}")
print(f"{' ':<4}constants = {constants}")
print(f"\n{' ':<4}{type(matrix)}\n{' ':<4}{type(constants)}")
cramer(matrix, constants)
