# Lesson 9 - Python Functions

import getpass
import subprocess

def hello():
    print("\nHello {}!".format(getpass.getuser().capitalize()))

def callUptime():
    try:
        subprocess.run(["/home/rodolfo/Documentos/GitHub/Projects/Scripts/firstFunction.sh"], check=True)
    except subprocess.CalledProcessError as e:
        subprocess.run(["/home/rodolfo/Documentos/Projetos/Projects/Scripts/firstFunction.sh"])

hello()

value = input("\nPrint uptime? \'y\' \| \'n\': ")

if value != "y" and value != "n":
    print("\nInvalid Input!\n")
elif value == "y":
    callUptime()
elif value == "n":
    print("\nOK\n")