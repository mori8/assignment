name = input("Write a name of the account owner : ")
balance = 100000
amount = int(input("Enter amount for withdrawal : "))
balance -= amount
print("Balance of", name, "'s account :", balance)