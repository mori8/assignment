choice = 0
words = []

while choice != 4 :
    print("**********************************************")
    print("*            Sookmyung Dictionary            *")
    print("**********************************************")
    print("              1. Save words                   ")
    print("              2. Delete words                 ")
    print("              3. Print all words              ")
    print("              4. Exit                         ")
    print("==============================================")
    choice = int(input("Select >>"))

    if choice == 4 :
        break
    elif choice == 1 :
        print("Enter word to save. Press 'Enter' to finish")
        print()
        while True :
            word = input("Word : ")
            if len(word) == 0:
                break
            if word in words :
                print("Already Exist")
            else :
                words.append(word)
    elif choice == 2 :
        print("Enter word to delete")
        print()
        while True :
            word = input("Word : ")
            if word not in words :
                print("No Exist")
            else :
                words.remove(word)
                print("Deletion complete")
                break
    elif choice == 3 :
        for i in words :
            print(i)
    else :
        print("You entered wrong menu.")
