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

print(f"\n2.5 times {num} is equal to {2.5 * num:.1f}\n")

for nums in range(1,11):
    print(f"2.5 times {float(nums):.1f} is equal to {2.5 * nums:.1f}")

print("\n")

for nums in range(1,11):
    print(f"2.5 divided by {float(nums):.1f} is equal to {2.5 / nums}")