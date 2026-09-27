# Lesson 19 - Exceptions and error handling

# Defining a custom error

class CustomError(Exception):
    pass

# Variables

x = 2

# 'try... except' block

try:
    # print(f"\n{x}")
    # if type(x) is not str:
    #     raise TypeError("\nNot a string variable!\n")
    # raise Exception("\nCustom exception raised!\n")
    raise CustomError("\nCustom exception raised! Again!\n")
except(NameError):
    print("\nA NameError exception was raised!\nThe varaible has not been previouly defined in the program!\n")
except(ZeroDivisionError):
    print("\nError! Division by zero is an undefined operation!\n")
except(Exception) as error:
    print(error)
else:
    print("\nNo errors raised\n")
finally:
    print("Leaving program\n")
