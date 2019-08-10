import easygui

L = ["Korean dish", "Western dish", "Chinese's style", "Japanese", "Exit"]
easygui.msgbox("Welcome to buy lunch ticket!\n(Lunch : 11:00 - 15 : 00)")

choice = ""
pay = 0

while choice != "Exit" :
    choice = easygui.buttonbox("Choose lunch menu to buy", choices=L)
    if choice == "Korean dish" :
        answer = easygui.enterbox("Korean dish is 2500 won.\nHow many tickets do you want to buy?")
        pay += int(answer) * 2500
    elif choice == "Western dish" :
        answer = easygui.enterbox("Western dish is 3000 won.\nHow many tickets do you want to buy?")
        pay += int(answer) * 3000
    elif choice == "Chinese's style" :
        answer = easygui.enterbox("Chinese's style is 2000 won.\nHow many tickets do you want to buy?")
        pay += int(answer) * 2000
    elif choice == "Japanese" :
        answer = easygui.enterbox("Japanese is 3500 won.\nHow many tickets do you want to buy?")
        pay += int(answer) * 3500
    elif choice == "Exit" :
        easygui.msgbox("Total amount to pay : " + str(pay) +"\nThanks for using!")