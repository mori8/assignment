import turtle

t = turtle.Pen()
t.shape("turtle")
t.color("red")
t.width(3)

t.left(54)

for i in range(6) :
    t.left(36)
    t.forward(30)

for i in range(6) :
    t.left(12)
    t.forward(25)

t.left(25)

for i in range(7) :
    t.left(12)
    t.forward(25)

for i in range(5) :
    t.left(36)
    t.forward(30)