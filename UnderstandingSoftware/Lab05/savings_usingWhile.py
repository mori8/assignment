balance = 0
month = 1

while month < 36 :
    balance += 50000
    print("%2d month, current %d won" % (month, balance))
    month += 2

print("total balance :", balance)