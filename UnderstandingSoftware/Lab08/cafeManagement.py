reviews = {}
menu = 0
while True :
    print("\n1. Show all reviews")
    print("2. Add cafe review")
    print("3. Delete cafe review")
    print("4. Search cafe")
    print("5. Exit")

    menu = int(input("menu : "))

    if menu == 1 :
        print("Store Grade")
        for store in reviews :
            print(store, "\t", reviews[store])

    elif menu == 2 :
        store = input("Add store : ")
        grade = float(input("Grade (1..5) : "))
        while (grade < 1) or (grade > 5) :
            print("Wrong")
            grade = int(input("Grade (1..5) : "))
        reviews[store] = grade

    elif menu == 3 :
        store = input("Delete store : ")
        if store in reviews :
            del reviews[store]
        else :
            print(store, "is not found")

    elif menu == 4 :
        store = input("Search store : ")
        if store in reviews :
            print(store, "\t", reviews[store])

    elif menu == 5 :
        break
