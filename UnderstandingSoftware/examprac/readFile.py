def read_file() :
    f = open("hungry.txt")
    while True :
        line = f.readline()
        if len(line) == 0 :
            break
        line = line.strip()
        mymemo.append(line)
    f.close()


def write_file() :
    f = open("hungry.txt", 'w')
    for item in mymemo :
        msg = item + '\n'
        f.write(msg)
    f.close()


mymemo = []

read_file()
for item in mymemo :
    msg = item
    print(msg)


mymemo = []

while True :
    print("Write an item to buy. blank to exit : ")
    item = input()
    if len(item) == 0 :
        break
    mymemo.append(item)

write_file()
print(len(mymemo), "items ar written into file.")