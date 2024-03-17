# Data types lesson from Dave Gray

import math

# String data type

# 1) Literal Assigment

first = "rodolfo"
last = "ravelli"

# print(type(first))
# print(type(first) == str )
# print(isinstance(first, str))

# 2) Constructor Function

pizza = str("pepperoni")
# print(pizza)
# print(type(pizza))
# print(type(pizza) == str )
# print(isinstance(pizza, str))

# 3) Concatenation
fullname = first.capitalize() + " " + last.capitalize()
# print(fullname)

# fullname += "!"
# print(fullname)

# 4) Casting a number to a string
decade = str(1980)
print(type(decade)) 
print(decade)