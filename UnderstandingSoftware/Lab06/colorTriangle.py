import turtle

t= turtle.Pen()
t.color("yellow")
t.pencolor(0, 0, 1)
t.begin_fill()
t.setheading(60)
for i in range(3) :
    t.forward(100)
    t.right(120)
t.end_fill()

t.up()
t.forward(150)
t.down()
for i in range(3) :
    t.forward(100)
    t.right(120)