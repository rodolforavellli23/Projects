#!/usr/bin/python3

# Fibonacci generator
def fib(n: int) -> list[int]:
    try:
        sequence = [0]
        if int(n) < 0:
            raise Exception("\n\tOnly input positive integer numbers!\n")
        if int(n) > 1:
            sequence.append(1)
        if int(n) > 2:
            for num in range(2,int(n)):
                sequence.append(int(sequence[num - 1]) + int(sequence[num - 2]))
        return sequence
    except ValueError:
        print(f"\n\tOnly input positive integer numbers!\n\n")
    except Exception as e:
        print(f"\n\tError: {e}\n\n")

# User input
a = input("\n\tHow many elements of the Fibonacci sequence do you wish to print? \n\n\t")

# Try to create the array to be printed
try:
    arr = fib(int(a))
except ValueError:
    print(f"\n\tOnly input positive integer numbers!\n\n")
except Exception as e:
    print(f"\n\tError: {e}\n\n")

# Array Logic
index_width = len(str(a))

last_value = arr[int(a) - 1]
str_of_lv = str(last_value)
num_width = len(str_of_lv)

print(f"")

for element in range(0,len(arr)):
    print(f"\tElement {element:<{index_width}}{': '}{arr[element]:>{num_width}}")

#for element in range(0,len(arr)):
#    if element == 0:
#        print(f"\t{arr[element]} , ", end="")
#    if element == (len(arr) - 1):
#        print(f"{arr[element]}", end="")
#    else:
#        print(f"{arr[element]} , ", end="")

print("\n")

# END
