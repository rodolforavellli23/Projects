# Lesson 20 - Object Oriented Python Project

from bank_accounts import *

Dave = BankAccount(1000, "Dave")
Sarah = BankAccount(2000, "Sarah")

Dave.deposit(700)
Sarah.deposit(400)

Dave.withdrawal(100)
Sarah.withdrawal(100)

Dave.withdrawal(10000)

Dave.transfer(500, Sarah)
Dave.transfer(5000, Sarah)

Sarah_savings = InterestRewards(Sarah.get_initialAmmount(), "Sarah")
Sarah_savings.deposit(500)