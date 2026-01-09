#!/usr/bin/python3

# Generator functions in python

# This function behaves like an iterator
def count_to_n(n: int):
    numbers = []
    count = 1
    while count < (n + 1):
        numbers.append(count)
        count+=1
    return numbers

# This function behaves like a generator
def yield_to_n(n: int) -> str:
    count = 1
    while count <= n:
        if count == n:
            yield f"{count}\n"
            count+=1
        else:
            yield f"{count}, "
            count+=1

# pretty printer for the iterator function
def print_list(list):
    for i in range(len(list)):
        if i == (len(list) - 1):
            print(f"{list[i]}\n", end="")
        else:
            print(f"{list[i]}, ", end="")

num = int(input(f"\n{' ':<4}What is the number for this count? "))

print(f"\n{' ':<4}", end="")
print_list(count_to_n(num))

print(f"\n{' ':<4}{''.join(yield_to_n(num))}") # This is the usual way to consume a generator object
