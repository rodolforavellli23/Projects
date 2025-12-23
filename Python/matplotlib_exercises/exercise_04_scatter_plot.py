#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

# - Making A Scatter Plot

# -- Imports
import matplotlib.pyplot as plt
import numpy as np

# -- Sample Data

# --- Class A
x1 = np.array([0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 8]) # Hours Studied
y1 = np.array([55, 60, 65, 62, 68, 70, 75, 78, 82, 85, 87]) # Grades

# --- Class B
x2 = np.array([0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 8]) # Hours Studied
y2 = np.array([50, 58, 65, 70, 72, 78, 83, 88, 92, 95, 97]) # Grades

# -- Building The Scatter Plot

# --- First Plot
plt.scatter(x1, y1, color="green",
                    s=80,
                    label="Class A")

# --- Second Plot
plt.scatter(x2, y2, color="red",
                    s=80,
                    label="Class B")

# --- Costumizing The Scatter Plot
plt.xlabel("Hours Studied")
plt.ylabel("Grades")
plt.title("Test Scores x Hours Studied")
plt.legend()

# -- Output
plt.show()
