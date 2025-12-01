#!/home/greenshoots/Documentos/GitHub/Projects/Python/math_exercises/venv/bin/python3

import mpmath as mp

def fac3(n):
    if n < 0:
        raise ValueError("Triple factorial is not defined for negative numbers")
    if n == 0 or n == 1 or n == 2:
        return mp.mpf(1)

    result = mp.mpf(1)
    i = n
    while i >= 1:
        result *= i
        i -= 3
    return result

mp.dps = 25 # Set precision

fact_test   = mp.factorial(mp.sqrt(5))
double_fact = mp.fac2(6)
triple_fact = fac3(8)

print(f"\n{"√5! =":>8}{float(fact_test):>9.5f}\n")
print(f"{"6!! =":>8}{float(double_fact):>5}\n")
print(f"{"8!!! =":>8}{float(triple_fact):>5}\n")
