import easygui

subjects = ["Understanding Computer Science", "English reading", "Writing"]
reply = easygui.choicebox("Which subject do you want to take?", choices=subjects)
easygui.msgbox(reply + " is chosen")
