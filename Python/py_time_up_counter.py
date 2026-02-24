#!/usr/bin/python3

# Counting Exercise

import time

# The flush optional command forces print to flush the buffer to the console.
# Whithout which, the interpreter will wait until the function finishes in order to
# print the result.

def count(start=0, end=1):
    for i, x in enumerate(range(start, end+1)):
        if i == len(range(start, end)):
            print(f"{x}", end="", flush=True)
        else:
            print(f"{x}, ", end="", flush=True)
            time.sleep(1)

print(f"\n\n{' ':<4}My count: ", end="")
count(1, 6)
print(f" seconds waited\n")
