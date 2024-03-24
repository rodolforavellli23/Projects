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

# pizza = str("pepperoni")
# print(pizza)
# print(type(pizza))
# print(type(pizza) == str )
# print(isinstance(pizza, str))

# 3) Concatenation
fullname = first.capitalize() + " " + last.capitalize()

# fullname += "!"
# print(fullname)

# 4) Casting a number to a string
decade = str(1980)
# print(type(decade)) 
# print(decade)

# statement = "Music from the " + decade + "'s."
# print(statement)

# 5) Multi-Line Arguments & String Methods

# multiline = ''' 
# Roses are red   

# Violets are blue    

# I'm coding in Python    

# And so are you  
# '''
# print(multiline.title() + "\n" + str(len(multiline)))

# 6) Escape character sequences

sentence = 'I\'m back!\tBack Again!\n\nTell a Friend! \\'
# print(sentence)

# 7) Build a menu

