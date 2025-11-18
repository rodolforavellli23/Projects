#!/usr/bin/python3

import numpy as np
from sympy import Matrix

# --- Matrices ---

A = np.array([[1, 2, 1,  1],
              [1, 2, 2, -1],
              [2, 4, 0,  6]])


#B = np.array([[7],
#              [12],
#              [14]])

# --- Operations ---

rref_A = Matrix(A).rref() # Performs the Reduced Row Echelon From operation on the given matrix

res_A  = np.array(rref_A[0], dtype=float) # Returns the output matrix to the numpy format

print(f"\n{res_A}")
