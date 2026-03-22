#!/usr/bin/python3

"""

map(), is a function that applies some other function to a given iterable

"""

store = [("shirt",  20.00),
         ("pants",  25.00),
         ("jacket", 50.00),
         ("socks",  10.00)]

def to_euros(data: list)->list:
    return (data[0], data[1]*0.82)

print(f"\n{' ':<4}EU store = {list(map(to_euros, store))}")

print(f"\n{' ':<4}US store = {store}")
