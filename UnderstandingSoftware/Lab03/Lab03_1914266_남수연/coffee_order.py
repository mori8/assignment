print("[Coffee Menu]")
print("1. Americano : 1500")
print("2. Cafe Mocha : 2500")
print("3. Green tea latte : 3000")

ame = int(input("Number of americano : "))
camo = int(input("Number of cafe mocha : "))
green = int(input("Numner of green tea latte : "))

Total = 1500 * ame + 2500 * camo + 3000 * green
print("\nTotal :", Total)