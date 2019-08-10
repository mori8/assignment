def searchn(lst, key) :
    if not lst :
        return 0
    elif lst[0] == key :
        n = searchn(lst[1:], key)
        return n+1
    else :
        n = searchn(lst[1:], key)
        return n


print(searchn([1,4,6,8,4,5,1,5,4], 4))