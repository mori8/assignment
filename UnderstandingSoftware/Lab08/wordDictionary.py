choice = 0
words = {}
score = []

while choice != 7 :
    print("**********************************************")
    print("*            Sookmyung Dictionary            *")
    print("**********************************************")
    print("              1. Save words                   ")
    print("              2. Delete words                 ")
    print("              3. Print all words              ")
    print("              4. Search word                  ")
    print("              5. Word Test                    ")
    print("              6. Show Test Score              ")
    print("              7. Exit                         ")
    print("==============================================")
    choice = int(input("Select >>"))

    if choice == 1 :
        print("Enter word to save. Press 'Enter' to finish")
        print()
        while True :
            word = input("Word : ")
            if word == "" :
                break
            elif word in words :
                print("Already Exist")
                break
            mean = input("Mean : ")
            words[word] = mean
            print()

    elif choice == 2 :
        print("Enter word to deleted")
        print()
        word = input("Word : ")
        if word not in words :
            print("No such words")
        else :
            del words[word]
            print("Deletion is completed")

    elif choice == 3 :
        for word in words :
            print(word, "\t", words[word], "\n")

    elif choice == 4 :
        print("Enter word to search")
        print()
        word = input("word : ")
        print()
        print(word, "\t", words[word])

    elif choice == 5 :
        count = 0
        if len(words) == 0 :
            print("Test can't be started, because of no words")
        else :
            for word in words.keys() :
                print(word, ": ", end=' ')
                mean = input()
                if mean == words[word] :
                    print("Correct!")
                    count += 1
                else :
                    print("Wrong..")
            print("You got", str(count), "answers.")
            score.append(count)

    elif choice == 6 :
        score.sort(reverse=True)
        print("     ScoreBoard     ")
        print("====================")
        rank = 1
        for i in range(len(score)):
            if (i + 1 < len(score) and score[i] == score[i + 1]):
                print(str(rank) + " rank       " + str(score[i]) + "answer")
            else:
                print(str(rank) + " rank       " + str(score[i]) + "answer")
                rank += 1

    elif choice == 7 :
        print("Thanks for using dictionary")




