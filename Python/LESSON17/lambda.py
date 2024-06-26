# Lesson 17 - Lambda function

squared = lambda num : num * num

sumNum = lambda a , b: a + b

def funcBuilder(x):
    return lambda num: num + x

# ===========================================

value1 = input("\nType number to be squared: ")

list1 = []

for r in range(2):
    
    if(r == 0):
        value2 = input("\nType two numbers to be summed: ")
    elif(r == 1):
        value2 = input("\nType the second number: ")
    
    list1.append(int(value2)) # Using the 'append()' method is the correct way to add elements to a list object

print(f"\n{squared(int(value1))}")

print(f"\n{sumNum(list1[0],list1[1])}")

addTen = funcBuilder(10)
addTwenty = funcBuilder(20)

print(f"\n{addTen(2)}\n\n{addTwenty(2)}\n")