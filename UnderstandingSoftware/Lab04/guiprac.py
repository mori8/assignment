import easygui

selectedLang = easygui.buttonbox("What is your favorite programming language?", choices=["C", "JAVA", "Python"])

easygui.msgbox("You picked " + selectedLang)
