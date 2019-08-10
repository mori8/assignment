def binary(stack, n) :
    if n == 1 :
        stack.append(1)
        return stack
    else :
        remainder = n % 2
        quotient = n // 2
        stack.append(remainder)
        return binary(stack, quotient)

stack = []
bin = reversed(binary(stack, 120))

for i in bin :
    print(i, end='')

