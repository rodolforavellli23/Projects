# Lesson 9 - Python Functions

import getpass

def hello():
    print("Hello {}!".format(getpass.getuser().capitalize()))

hello()


