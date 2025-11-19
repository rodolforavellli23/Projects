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

# Performs the Reduced Row Echelon Form operation on the given matrix
rref_A = Matrix(A).rref() 

# Returns the output matrix to the numpy array format, with each element 
# being recast as a floating point number.
res_A  = np.array(rref_A[0], dtype=float) 

print(f"\n{res_A}")
