print("1. F-C conversion")
print("2. C-F conversion")
print("3. Exit")

menu = 0 #입력받는 변수의 형태에 따라 초기화 방법도 달라짐

while menu != 3 :
    menu = int(input("Select Menu : "))
    if menu == 1 :
        fahr = float(input("Enter fahr : "))
        cel = 5/9 * (fahr - 32)
        print("Celsius : %.1f\n" % cel)
    elif menu == 2 :
        cel = float(input("Enter celsius : "))
        fahr = 9/5 * cel + 32
        print("Fahr : %.1f\n" % fahr)
    elif menu == 3 :
        print("**Program Exit**")
    else :
        print("You entered wrong menu.")