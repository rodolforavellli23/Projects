# Factorial fucntion in python

def factorial(var):
    if int(var) == 0 or int(var) == 1:
        return 1
    elif int(var) >= 2:
        return int(var) * factorial( int(var) - 1 )
    else:
        return '\nInput not recognized!\n'


again = True
while(again):
    var = input("\nType number to factorialize: ")
    print('\nResult: {}'.format(factorial(var)))
    again = input("\nGo again? \'1\' if yes or \'0\' if no: ")
    if again == "1":
        continue
    elif again == "0":
        print("\nExiting\n")
        break
    elif again != "1" or again != "0":
        print("\nInvalid input! Exiting!\n")
        break

