#!/usr/bin/python3

# Consider the system of linear equations below:

#  x +  y +  z =  6
#  0 + 2y + 5z = -4
# 2x + 5y + -z = 27

# Which is the same as:

# | 1  1  1 |   | x |   |  6 | 
# | 0  2  5 | @ | y | = | -4 | 
# | 2  5 -1 |   | z |   | 27 |

#      A          X       B 

# Therefore:

# A @ X = B; X = B / A; X = A^-1 @ B

import numpy as np

A = np.matrix([[1,  1,  1],
               [0,  2,  5],
               [2,  5, -1]])

B = np.matrix([[ 6],
               [-4],
               [27]])

inver_A = np.linalg.inv(A)

X = inver_A @ B

print(f"\n x = {X[0]}, y = {X[1]}, z = {[2]}\n{X}\n\n")
