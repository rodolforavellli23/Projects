#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

# The array2string function handles the multi-line indentation automatically!

import numpy as np

matrix = np.array([[10, 40, 70],
                   [20, 50, 80],
                   [30, 60, 80]])

prefix = "    matrix = "

formatted_matrix = np.array2string(matrix, prefix=prefix)

print(f"\n{prefix}{formatted_matrix}")
