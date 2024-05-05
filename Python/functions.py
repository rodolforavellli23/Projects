# Lesson 9 - Python Functions, exercise 1

import getpass
import subprocess

def hello():
    print("\nHello {}!".format(getpass.getuser().capitalize()))

def callUptime(): 
#    value = subprocess.run(["/home/rodolfo/Documentos/GitHub/Projects/Scripts/firstFunction.sh"], capture_output=True, text=True)
#    print('stdout: ', value.stdout)
#    print('stderr: ', value.stderr)
    value = subprocess.run(["/home/rodolfo/Documentos/Projetos/Projects/Scripts/firstFunction.sh"], capture_output=True, text=True)
    print('\nstdout: \n', value.stdout)
    print('\nstderr: \n', value.stderr)   

hello()

value = input("\nPrint uptime? \'y\' | \'n\': ")

if value != "y" and value != "n":
    print("\nInvalid Input!\n")
elif value == "y":
    callUptime()
elif value == "n":
    print("\nOK\n")

