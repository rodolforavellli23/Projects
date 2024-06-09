# Lesson 13 - F Strings

import getpass

value = input("\nHow many coins does {} have? ".format(getpass.getuser().capitalize()))

player = { 'name': getpass.getuser().capitalize(), 'coins': value} # This is a dictionary

message = "\n{name} has {coins} coins left.".format(**player) # this value inside the parentheses calls the dictionary

print(message)

##########################################
# Block 2 - f string formatting

message2 = f"\n{player['name']} has {player['coins']} coins left."

print(message2)

num = float(player['coins'])

print(f"\n2.5 times {num} is roughly equal to {2.5 * num:.2f}\n")