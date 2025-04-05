# Lesson 20 - Object Oriented Python Project
class BankAccountError(Exception):
    pass
class BankAccount:
    def __init__(self, initialAmmount, accName): # Atributes
        self.initialAmmount = initialAmmount
        self.accName = accName
        print(f"\nAccount Name: '{self.accName}'\nInitial Ammount: ${self.initialAmmount:.2f}\n")

    # Methods

    # Getters & Setters Methods

    def set_initialAmmount(self, new_initialAmmount):
        self.initialAmmount = new_initialAmmount
    def get_initialAmmount(self):
        return self.initialAmmount
    
    def set_accName(self, new_accName):
        self.accName = new_accName
    def get_accName(self):
        return self.accName

    # Additional Methods

    def viableTransaction(self, ammount):
        if (self.get_initialAmmount()) > ammount:
            return True
        elif (self.get_initialAmmount()) < ammount:
            return  False
        
    def deposit(self, ammount):
        if ammount >= 0:
            self.set_initialAmmount((self.get_initialAmmount() + ammount))
            print(f"\nDeposit of ${ammount:.2f} completed.")
            print(f"New balance for '{self.get_accName()}': ${self.get_initialAmmount():.2f}\n")
        else:
            print(f"\nInvalid input! Only deposit a positive ammount of cash!\n")
    
    def withdrawal(self, ammount):
        if self.viableTransaction(ammount):
            self.set_initialAmmount((self.get_initialAmmount() - ammount))
            print(f"\nWithdrawal of ${ammount:.2f} completed")
            print(f"New balance for {self.get_accName()}: ${self.get_initialAmmount():.2f}\n")
        else:
            print(f"\nInsufficient funds for this operation (withdrawal of ${ammount:.2f}) in this account!\nRequest Denied!\nUser '{self.get_accName()}' only has ${self.get_initialAmmount():.2f} in this account.\n")
    
    def transfer(self, ammount, acc):        
        try:
            if (self.viableTransaction(ammount)):
                self.set_initialAmmount((self.get_initialAmmount() - ammount))
                acc.set_initialAmmount((acc.get_initialAmmount() + ammount))
                print(f"\nTranfer of ${ammount:.2f} completed")
                print(f"New balance for sender '{self.get_accName()}: ${self.get_initialAmmount():.2f}'")
                print(f"New balance for beneficiary '{acc.get_accName()}': ${acc.get_initialAmmount():.2f}\n")
            else:
                raise BankAccountError(f"\nInsufficient funds for this operation (transfer of ${ammount:.2f}) in this account!\nRequest Denied!\nUser '{self.get_accName()}' only has ${self.get_initialAmmount():.2f} in this account.\n")
        except(Exception) as error:
            print(error)

class InterestRewards(BankAccount):
    def deposit(self, ammount):
        if ammount >= 0:
            self.set_initialAmmount((self.get_initialAmmount() + (ammount * 1.05)))
            print(f"\nDeposit of ${ammount:.2f} plus 5% insterest completed.")
            print(f"New balance for '{self.get_accName()}': ${self.get_initialAmmount():.2f}\n")
        else:
            print(f"\nInvalid input! Only deposit a positive ammount of cash!\n")