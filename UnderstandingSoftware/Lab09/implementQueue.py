choice = 0
queue = []

while choice != 4 :
    print("********** Queue Program **********")
    print("1. Insert item to Queue")
    print("2. Delete item from Queue")
    print("3. Print Queue")
    print("4. Exit")
    print()

    choice = int(input("Enter menu : "))

    if choice == 1 :
        item = input("# Enter item to insert : ")
        queue.append(item)
        print("# '" + str(item) + "' is inserted.")
        print("# State of Queue : " + str(queue))

    elif choice == 2 :
        if len(queue) == 0 :
            print("# Nothing to delete in queue.")
        else :
            print("# First item '" + str(queue[0]) + "' was removed.")
            del queue[0]
            print("# State of Queue : " + str(queue))

    elif choice == 3 :
        if len(queue) == 0:
            print("# Nothing in queue.")

        else :
            print("# State of Queue : " + str(queue))

    if choice != 4 :
        print()