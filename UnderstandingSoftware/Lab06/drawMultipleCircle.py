import turtle

t = turtle.Pen()
t.color("blue")
t.pencolor("blue")
t.begin_fill()
t.left(90)
t.forward(100)
t.left(90)
t.circle(100, 90)
t.left(90)
t.forward(100)
t.end_fill()
t.right(90)

t.color("red")
t.pencolor("red")
t.right(90)
t.begin_fill()
t.forward(100)
t.left(90)
t.circle(100, 90)
t.left(90)
t.forward(100)
t.end_fill()

t.color("green")
t.pencolor("green")
t.right(90)
t.begin_fill()
t.forward(100)
t.left(90)
t.circle(100, 90)
t.left(90)
t.forward(100)
t.end_fill()

t.color("yellow")
t.pencolor("yellow")
t.begin_fill()
t.forward(100)
t.left(90)
t.circle(100, 90)
t.left(90)
t.forward(100)
t.end_fill()

t.up()
t.forward(100)
t.down()
t.left(90)
t.pencolor("white")
t.width(5)
t.circle(50)
t.left(90)
t.up()
t.forward(100)
t.right(90)
t.down()
t.circle(50)