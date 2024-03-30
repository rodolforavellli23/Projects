import math

# Data types lesson from Dave Gray

# String data type

# 1) Literal Assigment

# first = "rodolfo"
# last = "ravelli"

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
# fullname = first.capitalize() + " " + last.capitalize()

# fullname += "!"
# print(fullname)

# 4) Casting a number to a string
# decade = str(1980)
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

# sentence = 'I\'m back!\tBack Again!\n\nTell a Friend! \\'
# print(sentence)

# 7) Build a menu

# title = " menu ".upper()
# print('')
# print(title.center(22, "="))
# print("Coffee".ljust(16,".") + "$ 1.00".rjust(4))
# print("Muffin".ljust(16,".") + "$ 1.00".rjust(4))
# print("Cheesecake".ljust(16,".") + "$ 1.00".rjust(4))
# print('')

# 8) String Index Values

# print("")
# print(first[0:2].upper())
# print(first[0:].upper())
# print("")

# 9) Mthods that ruturn boolean data

# print(first.startswith("r"))
# print(first.endswith("l"))

# 10) Boolean data type

# mybool = True
# x = bool(False)
# print(type(x))
# print(isinstance(mybool, bool))

# 11) Numeric Types

#   11.a) Integers('int')

#         price = 100
#         best_price = int(80)
#         print(type(best_price))
#         print(isinstance(price, int))

#   11.b) Floating Point numbers('float')    

