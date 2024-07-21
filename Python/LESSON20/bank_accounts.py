# Lesson 20 - Object Oriented Python Project

class BankAccount:
    def __init__(self, initialAmmount, accName): # Atributes
        self.initialAmmount = initialAmmount
        self.accName = accName
        print(f"\nAccount Name: '{self.accName}'\nInitial Ammount: ${self.initialAmmount:.2f}\n")

    # Methods

    # Getters & Setters Methods

    def set_initialAmmount(self, new_initialAmmount):
        self.initialAmmount = new_initialAmmount
    def get_initialAmount(self):
        return self.initialAmmount
    
    def set_accName(self, new_accName):
        self.accName = new_accName
    def get_accName(self):
        return self.accName

    # Additional Methods

    def deposit(self, ammount):
        self.initialAmmount += ammount
        print(f"\nDeposit of ${ammount:.2f} completed.")
        print(f"New balance for '{self.get_accName()}': ${self.get_initialAmount():.2f}\n")
    
    def withdrawal(self, ammount):
        if (self.get_initialAmount()) < ammount:
            print(f"\nInsufficient funds for this operation (withdrawal of ${ammount:.2f}) in this account!\nRequest Denied!")
            print(f"User '{self.get_accName()}' only has ${self.get_initialAmount():.2f} in this account.\n")
        elif (self.get_initialAmount()) > ammount:
            self.initialAmmount -= ammount
            print(f"\nWithdrawal of ${ammount:.2f} completed")
            print(f"New balance for {self.get_accName()}: ${self.get_initialAmount():.2f}\n")