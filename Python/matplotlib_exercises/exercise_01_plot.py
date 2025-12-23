#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

import matplotlib.pyplot as plt
import numpy as np

# -- The 'grid()' function helps to make plots easier to read by adding reference lines

# -- Setting the x and y axis

x_axis = np.array(range(1,6))
y_axis = np.array([5 * i for i in range(1,6)])

# -- Terminal text output

print(f"\n{' ':>4}x = {x_axis}\n{' ':>4}y = {y_axis}\n")

# -- Plotting the graph
# The 'axis' parameter chooses from which axis, or both, will the grid line start from

plt.grid(axis="y",
         linestyle="dashed")

plt.plot(x_axis, y_axis)

plt.show()
