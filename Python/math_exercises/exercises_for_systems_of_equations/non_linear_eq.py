#!/home/rodolfo/Documents/Github/Projects/Python/math_exercises/venv/bin/python3

"""
Solving systems of non-linear equations

Ex:
    x^2 + y = 5
    x^2 + y^2 = 7

Note: For each function to be callable inside another function, they must be defined as lambda type functions.

Personally, I liked sympy more. It suits my usecase better

"""

# ==========================================================================
# Imports
import matplotlib.pyplot as plt
import numpy as np
import sympy as sp
from scipy.optimize import fsolve
from gekko import GEKKO

# ==========================================================================
# Functions
def my_solution(z, func1, func2):
    x = z[0]
    y = z[1]
    F = np.empty(2)
    F[0] = func1(x, y)
    F[1] = func2(x, y)
    return F

func1 = lambda x, y: x**2 + y - 5
func2 = lambda x, y: x**2 + y**2 - 7

# ==========================================================================
# Using fsolve
# Variables

## A figure to be drawn on
fig = plt.figure(1, figsize=(8, 8))

## Step of the meshgrid
delta = 0.025

## XY grid
x, y = np.meshgrid(
        np.arange(-4, 6, delta),
        np.arange(-4, 6, delta)
        )

## Functions
f1 = x**2 + y - 5
f2 = x**2 + y**2 - 7

## Building plot

### First equation
plt.contour(x, y, f1, [0])

### Second equation
plt.contour(x, y, f2, [0])

### Title
plt.title("My Plot")

## Save plot to image
plt.savefig("./graphs/my_plot.jpg", 
            bbox_inches='tight',
            dpi=100
            )

# Using fsolve to find x and y

## Dummy guess value
z_guess = np.array([1, 1])

z = fsolve(my_solution, z_guess, args=(func1, func2))

# Text output
print(f"\n{' ':<4}From fsolve: x = {z[0]:.5f}, y = {z[1]:.5f}")

# ==========================================================================
# Solving using GEKKO

# Set remote as false, so that the local solver will be used to solve the 
# system of equations.
m = GEKKO(remote=False)

# Defines a decision variable that is calculated by the solver
xm, ym = [m.Var(1) for i in range(2)]

# Add a constraint equation built from GEKKO Parameters
m.Equations([xm**2 + ym == 5,
             xm**2 + ym**2 == 7])

# Solves the system of equations
m.solve(disp=False)

# Text output
print(f"{' ':<4}From GEKKO: x = {xm.value[0]:.5f}, y = {ym.value[0]:.5f}")

# ==========================================================================
# Sympy as a tool to solve non-linear equations

# Start sympy, and tell it to use unicode
sp.init_printing(use_unicode=True)

# Make the x & y symbols
x_sp, y_sp = sp.symbols('x, y')

# Make equations to be added
f = sp.Eq(x_sp**2 + y_sp, 5)
g = sp.Eq(x_sp**2 + y_sp**2, 7)

# Solve the system of equations
sp_result = sp.solve([f,g], (x_sp, y_sp))

# Convert each value to its pretty string form upfront
pretty_roots = [
    (sp.pretty(root[0], use_unicode=True), 
     sp.pretty(root[1], use_unicode=True))
    for root in sp_result
]

# Find the maximum character width for the X and Y columns
max_x_len = max(len(x) for x, y in pretty_roots)
max_y_len = max(len(y) for x, y in pretty_roots)

print(f"{' ':<4}All roots from sympy: ", end="")

# Print each root with right-aligned elements inside the parentheses
for index, (x_str, y_str) in enumerate(pretty_roots):
	if index == (len(pretty_roots) - 1): 
		print(f"root {index + 1} = ({x_str:>{max_x_len}}, {y_str:>{max_y_len}}) ", end="")
	else:
		print(f"root {index + 1} = ({x_str:>{max_x_len}}, {y_str:>{max_y_len}}), ", end="")

tmp = [sp.pretty(root) for root in sp_result]
print(f"\n\n{' ':<4}{tmp}\n")
