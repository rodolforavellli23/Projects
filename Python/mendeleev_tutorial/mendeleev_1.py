#!/home/greenrocket23/Documentos/GitHub/Projects/Python/mendeleev_tutorial/venv/bin/python3

# Learning how to use this Chemistry library for Python

from mendeleev import element

Ag = element("Ag")
H  = element(1)

# The element function can resolve which element's data to call by passing 
# the atomic number of the target element as an argument.

# print(f"\n{' ':<4}Ag is the symbol for the element {Ag.name}\n"
#       f"\n{' ':<4}Its atomic number is {Ag.atomic_number}\n"
#       f"\n{' ':<4}Its atomic weight is {Ag.atomic_weight}\n")

print(f"\n{' ':<4}H is the symbol for the element {H.name}\n"
      f"\n{' ':<4}Its atomic number is {H.atomic_number}\n"
      f"\n{' ':<4}Its atomic weight is {H.atomic_weight}\n")
