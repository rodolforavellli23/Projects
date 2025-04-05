# Chapter 10 - Recursion; Python Course


# This function calls itself untill it reaches the exit condition
def add_one(num):
    # Exit condition
    if num == 9:
        return num + 1

    total = num + 1
    print(total)

    return add_one(total)

result = add_one(0)

print(result)

