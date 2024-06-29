# Lesson 17 - Using the 'reduce' method

from functools import reduce

numbers = [1,2,3,4,5,1]

total = reduce((lambda acc, curr : acc + curr), numbers, 10)

print(f"\nTotal: {total}\n\nAlso Total, but from sum(): {sum(numbers)}\n")