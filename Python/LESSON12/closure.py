# Chapter 12 - Closures

# It is when a given nested function has access to the environment variable values from it's parent function.

import getpass

def parent_func(person):

    try:
        coins = int(input("\nHow many coins does {} have? ".format(person)))
    except ValueError:
        print("\nInput not recognized! Only input integers!\n")

    def nested_func():
        nonlocal coins
        nonlocal person
        coins -= 1

        if coins > 1:
            print("\n{} now has {} coins\n".format(person, coins))
        elif coins >= 0:
            print("\n{} now has 1 coin\n".format(person))
        else:
            print("\n{} is now {} coins in debt\n".format(person, coins))

    nested_func()

value = getpass.getuser().capitalize()

parent_func(value)