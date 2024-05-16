# Factorial fucntion in python

def factorial(var):
    if int(var) == 0 or int(var) == 1:
        return 1
    elif int(var) >= 2:
        return int(var) * factorial( int(var) - 1 )
    else:
        return '\nInput not recognized!\n'

try:
    var = input("\nType number to factorialize: ")
    print('\nResult: {}\n'.format(factorial(var)))
except:
    if not type(var) is int:
        raise TypeError("\nError: Only input integers!")
