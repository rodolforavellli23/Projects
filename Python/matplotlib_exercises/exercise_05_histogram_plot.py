#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

# -- Learning how to make a histogram

import matplotlib.pyplot as plt
import numpy as np

# -- Making a dataset of scores
scores = np.random.normal(loc=80, scale=10, size=100)
scores_clip = np.clip(scores, 0, 100) # By clipping we can ensure the score array will not contain values below 0 or above 100

# -- Plotting the histogram

# --- Note_01: The 'bins' optional argument refers to how many ranges will the histogram be split on

plt.hist(scores_clip, bins=10,
                      color="forestgreen",
                      edgecolor="black")
plt.title("Exam Scores")
plt.xlabel("Scores")
plt.ylabel("N° Of Students")
plt.grid(axis="y", linestyle="dashed")
plt.show()

# print(f"\n{scores.round(decimals=2)}\n\n{type(scores)}\n")
