scores = []
choice = 0

while choice != 4 :
    print("\n1. Show ranking & average of scores")
    print("2. Add scores")
    print("3. Delete a score")
    print("4. Exit\n")
    choice = int(input("choice : "))

    if choice == 1 :
        print("\nScore board\n")
        if len(scores) == 0 :
            print("No score")
        else :
            rank = 1
            scores.sort(reverse=True)
            total = 0
            for score in scores :
                total += score
                print(rank, "\t", score)
                ++rank
            print("\nScore average : ", total/len(scores))
    elif choice == 2 :
        while True :
            print("Enter score (0..100) (otherwise exit)")
            score = int(input("score : "))
            if (score < 0) or (score > 100) :
                break
            else :
                scores.append(score)
    elif choice == 3 :
        score = int(input("Enter a score to delete : "))
        if score in scores :
            scores.remove(score)
        else :
            print("No such score")
    else :
        break