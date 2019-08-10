import easygui

lang = easygui.buttonbox("What is your favorite programming language?", choices = ['C', 'Java', 'Python'])
easygui.msgbox("You picked " + lang)