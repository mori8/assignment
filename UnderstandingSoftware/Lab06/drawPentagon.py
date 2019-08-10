import turtle

t = turtle.Pen()
t.pencolor("pink")
t.width(7)

speed_value = [1, 3, 6, 10, 0]
for i in speed_value :
     t.speed(i)
     t.forward(150)
     t.right(72)

t.pencolor("red")
speed_value = ['slowest', 'slow', 'normal', 'fast', 'fastest']
for i in speed_value:
    t.speed(i)
    t.forward(150)
    t.right(72)
