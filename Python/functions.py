# Lesson 9 - Python Functions, exercise 1

import getpass
import subprocess

def hello():
    print("\nHello {}!".format(getpass.getuser().capitalize()))

def callUptime(): 
    subprocess.run(["/home/rodolfo/Documentos/GitHub/Projects/Scripts/firstFunction.sh"])
    print("")

hello()

value = input("\nPrint uptime? \'y\' | \'n\': ")

if value != "y" and value != "n":
    print("\nInvalid Input!\n")
elif value == "y":
    callUptime()
elif value == "n":
    print("\nOK\n")

