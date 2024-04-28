# Chapter 5 - User input

# Rock, Paper & Scissors game

import numpy as np

repeat = True

while repeat == True:

    randint = np.random.randint(1,3)

    print('')
    value = input('Enter...\n\nNumber key 1 for Rock, 2 for Paper and 3 for Scissors: ')

    if value != "1" and value != "2" and value != "3":
        print("\nInvalid input! Exiting game!\n")
        break

    print('')
    print("Computer's choice: {}".format(randint))
    print('')
    
    playerChoice = int(value)

    if playerChoice == randint:
        print('Tie!')
    elif playerChoice == 1 and randint == 2:
        print('Rock loses to paper! Computer wins!')
    elif playerChoice == 1 and randint == 3:
        print('Rock defeats Scissors! Player wins!')
    elif playerChoice == 2 and randint == 3:
        print('Paper loses to Scissors! Computer wins!')
    elif playerChoice == 2 and randint == 1:
        print('Paper defeats Rock! Player wins!')
    elif playerChoice == 3 and randint == 1:
        print('Scissors loses to Rock! Computer wins!')
    elif playerChoice == 3 and randint == 2:
        print('Scissors defeat Paper! Player wins!')
    else:
        print('Invalid input!') 

    print('')
    
    playRepeat = input("Play Again? 1 to continue, 0 to exit: ")

    if playRepeat == "0": 
        print("")
        break
    elif playRepeat == "1":
        print("")
        continue
    elif playRepeat != "1" and playRepeat != "0":
        print("\nInvalid input! Exiting game!\n")
        break


