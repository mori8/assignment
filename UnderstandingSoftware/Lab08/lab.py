nl = []

def getListElements() :
    global nl
    while True :
        d = input("adf")
        if d != "" :
            nl.append(int(d))
        else :
            if len(nl) == 0 :
                print("blank")
                break
            else :
                break

def search() :
    global nl
    findnum = int(input("number :"))
    index = 0
    while index < len(nl) :
        if findnum == nl[index] :
            print(str(index+1) + "에 존재함")
            break
        else :
            index += 1

    if index == len(nl) :
        print("없음")


getListElements()
if len(nl) != 0 :
    search()