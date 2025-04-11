#!/usr/bin/python3
# Lesson 9 - Python Functions, Exercise 2

def multiple_inputs(*args):
    print("\n{}".format(args))
    print("\n{}".format(type(args)))

multiple_inputs("Julian",34)
# The line above always returns a tuple

def mult_named_inputs(**kwargs):
    print("\n{}".format(kwargs))
    print("\n{}".format(type(kwargs)))

mult_named_inputs(name = "Julian", age = 34)
# The line above will always return a dict
