import math


def heron(a, b, c) :
    s = (a + b + c) / 2
    area = math.sqrt(s*(s-a)*(s-b)*(s-c))
    return area


n1 = float(input("a : "))
n2 = float(input("b : "))
n3 = float(input("c : "))

result = heron(n1, n2, n3)

print(result)