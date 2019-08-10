stack = []

num = int(input("Enter 10-base number : "))

remainder = num % 2
quotient = num // 2

while quotient > 1 :
    stack.append(remainder)
    print("Stack : ", stack)
    remainder = quotient % 2
    quotient = quotient // 2

if quotient == 1 :
    stack.append(remainder)
    stack.append(1)

print("Stack : ", stack)
print("10-base number :", num)
print("2-base number :", end=" ")
while stack != [] :
    c = stack.pop()
    print(c, end='')
