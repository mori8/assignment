from tkinter import *
import time

tk = Tk()
canvas = Canvas(tk, width=1000, height=1000)
canvas.pack()
image_list = ['car.gif', 'car.gif']
while True :
    for img in image_list :
        myimage = PhotoImage(file=img)
        canvas.create_image(0, 0, anchor=NW, image=myimage)
        canvas.create_image(200, 200, anchor=NW, image = myimage)
        tk.update()
        time.sleep(3)
