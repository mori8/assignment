choice = 0
cup = {'Americano': 0, 'Cafe latte': 0, 'Cafe Mocha': 0}
menu = {'Americano': 1800, 'Cafe latte': 2200, 'Cafe Mocha': 2800}
cash = [5000, 1000, 500, 100]
money = 0


def print_menu() :
    print("=======Sookmyung Cafe=======")
    print("1. Select coffee menu")
    print("2. Check your order")
    print("3. Pay total price")
    print("4. Get change")
    print()


def print_coffeeMenu() :
    print("[Cafe Menu]")
    for item in menu :
        print(" " + str(item) + " " + str(menu[item]) + "won")
    print()


def select_menu() :
    global cup
    while True :
        coffee = input("Select Menu : ")
        if coffee not in cup :
            print("You selected wrong menu..")
        else :
            cups = int(input("How many cups ? "))
            cup[coffee] = cups
            break


def check_order() :
    for item in cup :
        if cup[item] != 0 :
            print(item, "\t", cup[item], "cups")


def calculate_price() :
    global money
    total = cup['Americano'] * menu['Americano'] + cup['Cafe latte'] * menu['Cafe latte'] + cup['Cafe Mocha'] * menu['Cafe Mocha']
    print("TotalPrice :", total)
    while True :
        money = int(input("Pay money : "))
        if money < total :
            print("Too small..")
            print()
        else :
            break


def get_change() :
    price = money
    print("Your change is " + str(price) + " won.")
    print("===========================")
    for i in range(len(cash)) :
        print(str(cash[i]) + " won : " + str(price // cash[i]))
        price = price % cash[i]
    print("\nThank you for using our machine")


print_menu()
while True :
    choose = int(input("choose : "))
    print()
    if choose == 1 :
        print_coffeeMenu()
        print()
        select_menu()
    elif choose == 2 :
        check_order()
    elif choose == 3 :
        calculate_price()
    elif choose == 4 :
        get_change()
        break
    print()