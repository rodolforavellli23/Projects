# Lesson 14 - Python modules

import math # This is a Python module, which are similar to small libraries that are built in to the Python3 binary
import random as rdm

pi = math.pi
count = 0

print(f"\nPi is aproximately equal to {float(pi):.4f}\n")

for item in dir(rdm):
    print("{}. {}".format(count,item))
    count+=1

print("")