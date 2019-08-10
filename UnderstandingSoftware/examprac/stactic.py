score = [65, 80, 75, 90, 72, 77, 68, 83, 88, 79, 85, 77, 90, 65]
ave = 78.143
sum1 = 0
sum2 = 0
sum3 = 0

for i in score :
    #1
    sum1 += pow(i - ave, 2)
    #2
    sum2 += i ** 2
    var2 = (sum2 - 14 * (ave ** 2)) / 13
    #3
    sum3 += i
    var3 = (sum2 - sum3 ** 2 / 14) / 13


var1 = sum1 / 13

print("%.3f" % var1)
print("%.3f" % var2)
print("%.3f" % var3)
