# Lesson 17 - Lambda function

squared = lambda num : num * num

sumNum = lambda a , b: a + b

def funcBuilder(x):
    return lambda num: num + x

# ===========================================

value1 = input("\nType number to be squared: ")
# value2 = input("\nType two numbers to be summed: ")

list1 = []

for r in range(2):
    value2 = input("\nType two numbers to be summed: ")
    list1.append(int(value2))

print(f"\n{squared(int(value1))}")

print(f"\n{sumNum(list1[0],list1[1])}")

addTen = funcBuilder(10)
addTwenty = funcBuilder(20)

print(f"\n{addTen(2)}\n\n{addTwenty(2)}\n")