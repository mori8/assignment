name = input("Write your name : ")
call = int(input("call(sec) : "))
data = int(input("data(MB) : "))
rate = 12100 + (1.98 * call) + (5 * data)
print(name + ", You have to pay", rate, "Won")