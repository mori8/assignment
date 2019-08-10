balance = 100000
print("You have " + str(balance) + "won")
amount = int(input("Write amount to deposit : "))
if balance >= amount & amount > 0:
    balance -= amount
    print("남은 금액 : " + str(balance))
else :
    print("잔액이 부족합니다.")