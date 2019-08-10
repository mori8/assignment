import easygui

num = easygui.buttonbox("choice", choices=['5', '6', '7'])
num = int(num)
guess = easygui.enterbox("choice2", num)