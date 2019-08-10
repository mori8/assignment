import easygui
import turtle


shape = easygui.buttonbox("Select shape", choices=['circle', 'triangle'])

if shape == 'triangle' :
    triNum = int(easygui.enterbox("Enter number of triangle to draw"))
else :
    cirNum = int(easygui.enterbox("Enter number of circle to draw"))

t = turtle.Pen()
turtle.setup(width=550, height=400)
t.up()
t.backward(180)
t.down()

if shape == 'triangle' :
    if triNum >= 1 :
        for i in range(3) :
            t.forward(30)
            t.left(120)
        t.up()
        t.forward(60)
        t.down()

    if triNum >= 2 :
        for i in range(triNum - 1) :
            for j in range(3) :
                t.forward(30)
                t.left(120)
            t.up()
            t.forward(30)
            t.down()
            if i % 2 != 0 :
                t.up()
                t.forward(30)
                t.down()

elif shape == 'circle':
    for i in range(cirNum) :
        t.circle(20)
        t.up()
        t.forward(40)
        t.down()
        if i % 2 != 0 :
            t.up()
            t.forward(40)
            t.down()