import math

print("[Enter length of 3 sides]")
a = float(input("a : "))
b = float(input("b : "))
c = float(input("c : "))
s = (a + b + c) / 2
area = math.sqrt(s * (s - a) * (s - b) * (s - c))
print(area)