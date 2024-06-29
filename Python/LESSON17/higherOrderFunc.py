# Lesson 17 - Higher Order Functions

numbers = [1,1,2,3,5,8,13]

squared = map((lambda num : num * num), numbers) 

# 'map()' is a higher order function that returns the output of another function that is passed
#  as a parameter within itself over a second parameter that can be iterated over 
#  (ex: lists[], tuples() and dictionaries{}).

print(f"\nThe square of the list {numbers} is {list(squared)}")

# -------------------------------------------------------------------

odd_nums = filter((lambda num : num % 2 != 0), numbers)

# This lambda func returns the bool 'True' every time it detects an odd number,
# as it checks if the remainder of it's division by 2 is different from '0'.

print(f"\nThe odd numbers in the list {numbers} are {list(odd_nums)}\n")