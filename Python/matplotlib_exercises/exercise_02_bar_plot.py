#!/home/greenshoots/Documentos/GitHub/Projects/Python/matplotlib_exercises/venv/bin/python3

# -- Making bar charts with matplotlib

# -- Imports
import matplotlib.pyplot as plt

# -- Variables
categories = [ "Grain", "Fruits", "Vegetables", "Meat", "Dairy", "Sweets"]
values = [ 4, 3, 2, 5, 3, 1]

# -- Building The Bar Chart

plt.bar(categories, values, color="green")    # Vertical Bar Chart
# plt.barh(categories, values, color="green") # Horizontal Bar Chart

plt.title("Daily Macronutrients") # Chart Title

plt.xlabel("Macronutrients") # X Axis Label
plt.ylabel("Portions") # Y Axis Label

plt.grid(axis="y", linestyle="dashed") # Chart Customization

plt.show() # Display Chart
