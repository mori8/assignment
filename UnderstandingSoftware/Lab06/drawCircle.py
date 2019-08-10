import turtle

edges = 100
length = 400 / edges
angle = 360 / edges

t = turtle.Pen()
t.pencolor("blue")
t.width(5)
t.speed(5)

for i in range(edges) :
    t.forward(length)
    t.right(angle)