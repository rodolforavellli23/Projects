# Lesson 17 - Higher Order Functions

numbers = [1,1,2,3,5,8,13]

squared = map((lambda num : num * num), numbers) 

# 'map()' is a higher order function that returns the output of another function that is passed
#  as a parameter within itself over a second parameter that can be iterated over (ex: lists[], tuples() and dictionaries{})

print(f"\nThe square of the list {numbers} is {list(squared)}\n")