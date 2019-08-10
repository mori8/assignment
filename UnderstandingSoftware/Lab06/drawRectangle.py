import turtle

turtle.setup(width = 600, height = 600)

t = turtle.Pen()
t.pencolor("blue")
t.width(10)

for i in range(4) :
    t.forward(200)
    t.right(90)