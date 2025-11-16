#!/usr/bin/python3

import numpy as np

A = np.array([[1, 2, 6],
              [1, 2,],
              [2, 4,]])


B = np.array([[7],
              [12],
              [14]])

resAxB = np.matmul(A,B)
#resBxA = np.matmul(B,A)

#print(f"\nA x B = \n{resAxB}\n\nB x A = \n{resBxA}")
