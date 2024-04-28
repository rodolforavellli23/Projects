# Euler problem number 1

total_sum = 0
for i in range(1, 1000):
    if (i % 3 == 0 or i % 5 == 0):
        total_sum = total_sum + i
print("Euler project's 1st question:\n\'The sum of all integers that are divisible by 3 or by 5 that are greater than 0 and smaller than 1000 is {}\'".format(total_sum))