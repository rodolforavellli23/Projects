# Derangement function - Returns how many permutations of a number of 'n' things
# there are where none of these things are in their original position.

# import math

# def factorial(var):
#     if int(var) == 0 or int(var) == 1:
#         return 1
#     elif int(var) >= 2:
#         return int(var) * factorial( int(var) - 1 )
#     else:
#         return '\nInput not recognized!\n'


# def derangement(var1):
#     a = factorial(var1)
#     b = a / (math.e)

#     if abs(b - (math.floor(b))) < 0.5:
#         c = (math.floor(b))
#     else:
#         c = (math.ceil(b))
    
#     return c

def derangement(var1):
    if int(var1) == 0:
        return 1
    elif int(var1) == 1:
        return 0
    elif int(var1) >= 2:
        return (( int(var1) - 1 ) * ((derangement( int(var1) - 1 )) +
                                     (derangement( int(var1) - 2 ))))

print(f"{derangement(3)}")
print(f"{derangement(4)}")
print(f"{derangement(5)}")
print(f"{derangement(6)}")