import time

upper = 1000
prime = []

t1 = time.time()

for i in range(2, upper + 1) :
    num = True
    if i == 2 :
        num = True
    else :
        for j in range(2, i) :
            if i % j == 0 :
                num = False
                break
    if num :
        prime.append(i)

t2 = time.time()
print(t2 - t1)
print("# of primes :", len(prime))
print(prime)