# Lesson 17 - Higher Order Functions

numbers = [1,1,2,3,5,8,13]

squared = map((lambda num : num * num), numbers) 

# 'map()' is a higher order function that returns the output of another function that is passed
#  as a parameter within itself over a second parameter that can be iterated over 
#  (ex: lists[], tuples() and dictionaries{}).

repeated = lambda lst : list(dict.fromkeys(lst))

# This lambda function will take the keys from an iterable 
# and remove all repeated items. This works by taking a list
# turning it into a dictionary object(That mantains insertion order)
# and casts it back into a list again. 

# -------------------------------------------------------------------

print(f"\nThe square of the list {numbers} is {list(squared)}")

odd_nums = filter((lambda num : num % 2 != 0), numbers)

repeated_nums = repeated(list(odd_nums))

print(f"\nThe odd numbers in the list {numbers} are {repeated_nums}\n")