#!/usr/bin/python3

import numpy as np

A = np.array([[2, 5, 6]])

B = np.array([[3], 
              [4], 
              [-5]])

resAxB = np.matmul(A, B)
resBxA = np.matmul(B, A)

print(f"A x B = \n\n{resAxB}\n\nB x A = \n\n{resBxA}")
