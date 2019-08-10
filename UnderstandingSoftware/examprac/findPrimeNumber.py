import time

upper = 1000


def prime1() :  # 2부터 i-1로 나누어 떨어지지 않는 수를 소수로 탐색
    global upper
    t1 = time.time()
    num = []
    for i in range(2, upper + 1) :
        prime = True
        if i == 2 :
            prime = True
        else :
            for j in range(2, i) :
                if i % j == 0 :
                    prime = False
                    break
        if prime :
            num.append(i)
    t2 = time.time()
    print("elapsed time =", t2 - t1)
    print("# of primes =", len(num))
    print(num)


def prime2() :  # 리스트에서 소수의 배수를 제거하는 방법으로 탐색
    global upper
    t1 = time.time()
    num = []
    for i in range(2, upper + 1) :
        num.append(i)
    for i in num :
        for j in range(2, upper + 1) :
            s = i * j
            if s > upper :
                break
            if s in num :
                num.remove(s)
    t2 = time.time()
    print("elapsed time =", t2 - t1)
    print("# of primes =", len(num))
    print(num)


prime1()
prime2()