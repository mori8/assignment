from turtle import *


class my_turtle(Turtle) :
    def set_turtle(self, color):
        self.color(color)
        self.shape('turtle')


t1 = my_turtle()
t2 = my_turtle()
t3 = my_turtle()
t4 = my_turtle()

t1.set_turtle('Red')
t2.set_turtle('Blue')
t3.set_turtle('Green')
t4.set_turtle('Black')

t2.left(90)
t3.left(180)
t4.right(90)

angle = 75

t1.speed(0)
t2.speed(0)
t3.speed(0)
t4.speed(0)

for x in range(100):
    t1.forward(x)
    t2.forward(x)
    t3.forward(x)
    t4.forward(x)

    t1.left(angle)
    t2.left(angle)
    t3.left(angle)
    t4.left(angle)