def prime1() :
    primes = []
    upper = 1000
    for i in range(2, upper + 1) :
        prime = True
        if i == 2 :
            prime = True
        else :
            for j in range(2, i) :
                if i % j == 0:
                    prime = False
                    break
        if prime :
            primes.append(i)


def prime2() :
    primes = []
    upper = 1000
    for i in range(2, upper + 1) :
        primes.append(i)
    for i in primes :
        for j in range(2, upper + 1) :
            s = i * j
            if s > upper :
                break
            else :
                if s in primes :
                    primes.remove(s)
                    
