i = 2
j = 1

while i < 10 :
    print("==%d단==" %i)
    while j < 10 :
        print("%d x %d = %d" % (i, j, i*j))
        j += 1
    print()
    j = 1
    i += 1