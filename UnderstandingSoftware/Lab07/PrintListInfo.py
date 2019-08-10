num = []

while True :
    print("Enter numbers. (To finish press 'Enter' key)")
    n = input()
    if len(n) == 0:
        break
    num.append(float(n))

num.sort()
num_len = len(num)
num_center = int(num_len/2)

print("You entered", num)
print("sum : %.2f" % sum(num))
if num_len % 2 != 0 :
    print("median : %.2f" % num[num_center])
else :
    print("median : %.2f" % ((num[num_center-1] + num[num_center]) / 2))
print("average : %.2f" % (sum(num)/num_len))
