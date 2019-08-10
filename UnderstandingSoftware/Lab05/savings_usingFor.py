balance = 0

for month in range(1, 36, 2) :
    balance += 50000
    print("%2d month, current %d won" % (month, balance))

print("total balance : %d" % balance)