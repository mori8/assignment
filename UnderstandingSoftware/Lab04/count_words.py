import easygui

sentence = easygui.enterbox("Write a sentence.")
easygui.msgbox("You wrote \"" + sentence + "\"")
answer = easygui.choicebox("Choose your word to study.", choices=sentence.split())

easygui.msgbox("Today's word :\n" + answer)