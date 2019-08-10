class Car :
    def __init__(self, speed, color, model):
        self.speed = 0
        self.color = color
        self.model = model

    def drive(self):
        self.speed = 60

    def __str__(self):
        msg = "속도 : " + str(self.speed) + "\n색상 : " + str(self.color)


myCar = Car("red", "BMW")
