# Lesson 22 - File Operations in Python

file = open("./names.txt") # The 'open()' method will return the contents of a file.

# print(file.read())

# print(file.read(4)) # Should an integer 'n' be passed to the method above, it will return 'n' characters back.

# print(file.readline())
# print(file.readline())

for line in file:
    print(line)


file.close() # For safety reasons, always close a file you may have opened, so as to ensure that any of the changes you might've made will be saved in the file.

try:
    file = open("a.txt")
    print(file.read())
except Exception as e:
    print(f"{e}\n")
finally:
    file.close()

try:
    file = open("names.txt")
    print(file.read())
except Exception as e:
    print(f"{e}\n")
finally:
    file.close()


file = open("names2.txt", "a")
