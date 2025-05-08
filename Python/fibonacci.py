#!/usr/bin/python3

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

a = input("\n\tHow many elements of the Fibonacci sequence do you wish to print? \n\n\t")

print(f"\n\t{fib(int(a))}\n")
