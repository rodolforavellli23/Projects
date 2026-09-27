#!/usr/bin/python3

"""Addtion Function"""
def add(x, y):
    return x + y

"""Subtraction Function"""
def subtract(x, y):
    return x - y

"""Multiplication Function"""
def multiply(x, y):
    return x * y

"""Division Function"""
def divide(x, y):
    if y == 0:
        raise ValueError(f'\n\n{" ":<4}Can\'t divide by zero!\n\n')
    return x / y
