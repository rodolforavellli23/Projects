#!/usr/bin/python3

# Default Arguments Exercise

# # Function Declaration

# Note that for this function, the 'discount' and 'tax' parameters must be
# in the decimal form of percentages, like: 5% -> 0.05

def net_print(listed_price, discount=0, tax=0.04):
    return listed_price * (1 - discount) * (1 + tax)

# # Preparing The Total

total = net_print(500, 0, 0.05)

# # Text Output

print(f"\n\n{' ':<4}My total = {total}\n")
