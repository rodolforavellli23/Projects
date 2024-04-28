# Lesson 8 - Loops

# While loops

# var = 0
# while var <= 10:
#     print("var is equal to {}".format(var))
#     var+=1

# For loops

names = ["Dave","Sarah","John"]
actions = ["eats","codes","sleeps"]
count = 0

print("")

for name in names:
    print("User number {}, name: {}".format(str(count + 1), name))
    print("")
    count+=1

# for action in actions:
#     for name in names:
#         if name == "Dave" and action == "eats":
#             print("{} {}".format(name, action))
#             print("")
#         elif name == "Sarah" and action == "codes":
#             print("{} {}".format(name, action))
#             print("")
#         elif name == "John" and action == "sleeps":
#             print("{} {}".format(name, action))
#             print("")

for n in range(0,3):
    print("{} {}".format(names[n], actions[n]))
    print("")

# for x in "OHIO":
#     print(x)

# for n in range(4):
#     print(n)

# for n in range(2,4):
#     print(n)

# for n in range(0,100,20):
#     print(n)
# else:
#     print("Done!")