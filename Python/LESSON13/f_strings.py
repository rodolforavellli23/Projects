# Lesson 13 - F Strings

import getpass

value = input("\nHow many coins does {} have? ".format(getpass.getuser().capitalize()))

player = { 'name': getpass.getuser().capitalize(), 'coins': value} # This is a dictionary

message = "\n{name} has {coins} coins left\n".format(**player) # this value inside the parentheses calls the dictionary

print(message)