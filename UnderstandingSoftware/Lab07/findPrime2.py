upper = 1000
prime = []

for i in range(2, upper + 1) :
    prime.append(i)

for i in prime :
    for j in range(2, len(prime) + 1) :
        s = i * j
        if s > upper :
            break
        if s in prime :
            prime.remove(s)
            
print(len(prime))
print(prime)