a = [35, 28, 30, 29, 33, 31, 30]


def search(lst, key) :  # 재귀를 이용한 검색함수 구현
    if not lst :
        return 0
    elif lst[0] == key :
        n = search(lst[1:], key)
        return n + 1
    else :
        n = search(lst[1:], key)
        return n


print(search(a, 30))