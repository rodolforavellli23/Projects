#!/usr/bin/python3

# script to solve simple linear interpolations

"""

slope: m = (y2 - y1)/(x2 - x1)

linear function: (y(x) - y1) = (x - x1)*m

notes: numpy.interp clamps to the boundaries by default (it returns the closest edge value).
       You can change this using the left and right arguments (e.g.: np.interp(5.0, x, y, left=0, right=50)). 

"""

import numpy as np

# Known data points
x_data_Biot = np.array([0.8, 0.9])
y1_data_A1 = np.array([1.2236, 1.2488])
y2_data_lambda1 = np.array([1.4320, 1.5044])

# New point to interpolate to
x_new = 0.82

# Interpolatet value
y_A1_new = np.interp(x_new, x_data_Biot, y1_data_A1)
y_lambda1_new = np.interp(x_new, x_data_Biot, y2_data_lambda1)

# Output
print(f"\n{' ':<4}For Biot = 0.82; the sphere values for A1 and lambda1 are:\n"
      f"\n{' ':<4}A1 = {y_A1_new:.4f}"
      f"\n{' ':<4}lambda1 = {y_lambda1_new:.4f}"
      f"\n")
