import numpy as np

# Define the polynomial coefficients in descending order of exponentials
coefficients = [24, 8, -975, 0, 8750, 0, -109375]

# Find the roots of the polynomial
roots = np.roots(coefficients)
# Create an array with the roots of the polynomial
real_roots = [r.real for r in roots if np.isreal(r)]

for nums in real_roots:
    if(np.sign(nums) == -1):
        print(f"\t{float(nums)}")
    elif(np.sign(nums) == 1):
        print(f"\t+{float(nums)}")

print(f"\n\tx1 = {float(real_roots[0]):.5f} , x2 = {float(real_roots[1]):.5f}\n")
