from tkinter import *

window = Tk()

l1 = Label(window, text="질문하실 분들은 아래 버튼을 한번만 눌러주세요!", font=("맑은 고딕", 24),)
l2 = Label(window, text="눌러도 해치지 않아요", font=("맑은 고딕", 11))
l1.pack()
l2.pack()

b1 = Button(window, text="교수 호출하기", width=10, bg="blue")
b1.pack()

window.mainloop()