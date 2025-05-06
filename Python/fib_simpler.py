#!/usr/bin/python3

def fib_generator(n: int) -> int:
    a, b = 0, 1
    for _ in range(int(n)):
        yield a
        a, b = b, a + b

try:
    a: int = input("\n\tHow many elements of the Fibonacci sequence do you wish to print? \n\n\t")
except TypeError:
    print("\n\tOnly positive integers allowed!\n\n")
except Exception as err:
    print(f"\n\tUnexpected {err=}, {type(err)=}")
    raise

print(f"\n\t{list(fib_generator(a))}\n\n")
