import random
import easygui

name = easygui.enterbox("What is your name?")
easygui.msgbox("Ok," + name + "!\nLet's play 21 Game")

comNum = random.randint(1, 21)
userNum1 = random.randint(1, 13)
userNum2 = 0
choice = easygui.buttonbox("Your first card is " + str(userNum1) + ". Do you want more?", choices=['yes', 'no'])
if choice == 'yes':
    userNum2 = random.randint(1, 13)
    easygui.msgbox("Your second card is " + str(userNum2) + ". Check your result")
else :
    easygui.msgbox("Ok, check your result")

answer = str(userNum1 + userNum2)

if userNum1 + userNum2 > 21:
    easygui.msgbox("Your final result is " + answer + ". It is over 21, so you lose. Computer's card was " + str(comNum))
elif userNum1 + userNum2 < comNum :
    easygui.msgbox("Your final result is " + answer + ". Computer's card was " + str(comNum) + ". You lose!")
else :
    easygui.msgbox("Your final result is " + answer + ". Computer's card was " + str(comNum) + ". You win!")

