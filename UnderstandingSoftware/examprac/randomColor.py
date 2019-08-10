import random
import turtle

length = random.randint(10, 110)
angle = random.randint(30, 180)

t = turtle.Pen()
turtle.setup(width = 500, height = 500)
t.pencolor(random.random(), random.random(), random.random())
t.width(3)
t.speed(5)
for i in range(200) :
    t.pencolor(random.random(), random.random(), random.random())
    length = random.randint(10, 110)
    angle = random.randint(30, 180)
    t.forward(length)
    t.right(angle)