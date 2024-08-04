# Lesson 22 - File Operations in Python

import os

file = open("./names.txt") # The 'open()' method will return the contents of a file.

print(file.read())

# print(file.read(4)) # Should an integer 'n' be passed to the method above, it will return 'n' characters back.

# print(file.readline())
# print(file.readline())

# for line in file:
#     print(line)

file.close()
# For safety reasons, always close a file you may have opened,
# so as to ensure that any of the changes you might've made will be saved in the file.

print("") # Spacing printed content

try:
    file = open("a.txt")
    print(file.read())
except Exception as e:
    print(f"{e}")
finally:
    file.close()

print("") # Spacing printed content

# try:
#     file = open("names.txt")
#     print(file.read())
# except Exception as e:
#     print(f"{e}")
# finally:
#     file.close()

# file = open("names.txt", "a")
# file.write("Neil")
# file.close()

file = open("names.txt", "r")
print(file.read())
file.close()

print("") # Spacing printed content

file = open("context.txt", "w")
file.write("Mathew\nJohn\nLuke\nMarcus\nMary")
file.close()

file = open("context.txt")
print(file.read())
file.close()

print("") # Spacing printed content

file = open("name_list.txt", "x")
file.close()

file = open("name_list.txt", "w")
file.write("Names List")
file.close()

file = open("name_list.txt")
print(file.read())
file.close()

print("") # Spacing printed content

if (os.path.exists("./more_names.txt")):
    try:
        os.remove("./more_names.txt")
    except Exception as e:
        print(f"\n{e}\n")
        
with open("names.txt") as f:
    contents = f.read()
    f.close()

with open("name_list.txt", "w") as f:
    f.write(contents)
    f.close()

file = open("name_list.txt")
print(file.read())
file.close()