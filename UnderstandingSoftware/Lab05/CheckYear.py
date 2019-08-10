
select = 0

while select != 3 :

    print("=====Checking Year Program=====")
    print("      1. Check Leap Year       ")
    print("      2. Check Total Day       ")
    print("      3.      Exit             ")
    print("===============================")

    select = int(input("Select : "))
    if select == 1 :
        year = int(input("Enter year to check : "))
        if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0) :
            print(year, "is leap year.")
        else :
            print(year, "is not leap year.")

    elif select == 2 :
        print("Enter month and date.")
        month = int(input("Month : "))
        date = int(input("Date : "))

        day = 0

        for i in range(month) :
            if i in [1, 3, 5, 7, 8, 10] :
                day += 31
            elif i == 0 :
                day += 0
            elif i == 2 :
                day += 28
            else :
                day += 30

        day += date
        print("2019." + str(month) + "." + str(date), "is", str(day) + "th day in 2019.")

    elif select == 3 :
        print("Thanks for using program.")

    else :
        print("You entered wrong number.")
    print()