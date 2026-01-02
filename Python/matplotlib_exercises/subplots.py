#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

# A Figure represents the entire canvas of a matplotlib plot
# Ax is the name given to a single subplot whithin a Figure

import matplotlib.pyplot as plt
import numpy as np

# Data

x = np.array(range(1, 6))
y_1 = x*2
y_2 = x**2
y_3 = x**3
y_4 = x**4

# Plotting the graph

figure, axes = plt.subplots(2, 2) # the subplots function takes a row argument and a column argument

# Ax 1
axes[0, 0].plot(x, y_1, color="red")
axes[0, 0].set_title("x*2")

# Ax 2
axes[0, 1].plot(x, y_2, color="blue")
axes[0, 1].set_title("x**2")

# Ax 3
axes[1, 0].plot(x, y_3, color="green")
axes[1, 0].set_title("x**3")

# Ax 4
axes[1, 1].plot(x, y_4, color="orange")
axes[1, 1].set_title("x**4")

# Output
plt.tight_layout()
plt.show()
