#name = input('Enter Person\'s name:')
#CustInput = input('D = Deposit, W = Withdrawal, Q = Quit. Enter D, W, or Q:')
#if CustInput == 'D':
#    deposit = input('Enter amount to deposit:')
#elif CustInput == 'W':
#    withdrawal = input('Enter amount to withdraw:')
#elif CustInput == 'Q':
#    print('Have a great life')
#else:
#    print('Please enter a capital D, W, or Q')
#balance = 0
class SavingsAccount:
    def __init__(self):
        self.name = ''
        self.balance = 0
        
    def getBalance(self):
        return self.balance

    def setBalance(self, newBalance):
        self.balance = newBalance
        
    def getName(self):
        return self.name

    def setName(self, newName):
        self.name = newName

    
    def makeDeposit(self):
        deposit = input('Enter amount to deposit:')
        self.balance = self.balance + int(deposit)
        
        
    def makeWithdrawal(self):
        withdrawal = input('Enter amount to withdraw:')
        if self.balance - int(withdrawal) > 0:
            self.balance = self.balance - int(withdrawal)
        elif self.balance - int(withdrawal) < 0:
            print('Insufficient funds, transaction denied.')

def main():
    myAccount = SavingsAccount()
    myAccount.setName(input('What is your name?'))
    myAccount.setBalance(0)
    CustInput = ''

    while (CustInput != 'Q'):
        print('D = Deposit, W = Withdrawal, Q = Quit.')
        CustInput = input('Enter D, W, or Q:')
        if CustInput == 'D':
             myAccount.makeDeposit()
             print('Balance: $' + str(myAccount.getBalance() ) )
        elif CustInput == 'W':
             myAccount.makeWithdrawal()
             print('Balance: $' + str(myAccount.getBalance() ) )
        elif CustInput == 'Q':
             print('End of transactions. Have a good day ' + myAccount.getName() + '.' )
        else:
             print('Please enter a capital D, W, or Q')

main()
