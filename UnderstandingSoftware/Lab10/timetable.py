

class Lecture :
    def __init__(self, name, professor, limit, place):
        self.name = name
        self.professor = professor
        self.limit = limit
        self.place = place

    def changeLimitOfStudent(self, newLimit):
        self.limit = newLimit

    def changePlace(self, newPlace):
        self.place = newPlace

    def printInfo(self):
        print("Professor :", self.professor)
        print("Limit of student :", self.limit)
        print("Place :", self.place)


lec = {}

while True :
    print()
    print("******************************\n"
          "          Time table\n"
          "******************************")
    print("1. Open new class")
    print("2. Change limit of students")
    print("3. Change classroom")
    print("4. Print lecture Info")
    print("5. Exit")
    print("******************************")

    menu = int(input("Choose >> "))

    if menu == 1 :
        name = input("Lecture name : ")
        professor = input("Professor : ")
        limit = input("Limit of student : ")
        place = input("Place : ")

        lec[name] = Lecture(name, professor, limit, place)

    elif menu == 2 :
        changeLec = input("Enter lecture name : ")
        newLimit = int(input("Enter new limit of students : "))

        lec[changeLec].changeLimitOfStudent(newLimit)

    elif menu == 3 :
        changeLec = input("Enter lecture name : ")
        newPlace = input("Enter new classroom : ")

        lec[changeLec].changePlace(newPlace)

    elif menu == 4 :
        lecture = input("Enter lecture name : ")
        lec[lecture].printInfo()

    elif menu == 5 :
        break