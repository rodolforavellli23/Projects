#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Data

df = pd.read_csv("./sources/data_02.csv")

type_count = df["Type1"].value_counts(ascending=True)

# Plotting the graph

plt.figure(figsize=(10, 6)) # parameters for 'figure()' are width & height
plt.barh(type_count.index, type_count.values, color="#fc8c03",
                                              edgecolor="black")
plt.title("N° Of Pokemon By Primary Type")
plt.xlabel("Count")
plt.ylabel("Type")
plt.tight_layout()
plt.show()
