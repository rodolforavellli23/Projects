#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

# Creating a pie chart

import matplotlib.pyplot as plt
import numpy as np

categories = [ "Freshmen", "Sophomores", "Juniors", "Seniors"]
values = np.array([ 300, 250, 275, 225])
colors = [ "coral", "yellowgreen", "lightblue", "khaki"]

plt.pie(values, labels=categories,
                autopct="%.1f%%",
                colors=colors,
                explode=[ 0, 0, 0, 0.1],
                shadow=True,
                startangle=348)

plt.title("Percentage Of Students")

plt.show()
