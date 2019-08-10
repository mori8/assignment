score = int(input("Enter your exam score : "))

if (score < 0) or (score > 100) :
    print("You entered wrong score.")
elif score >= 90 :
    print("A")
elif score >= 80 :
    print("B")
elif score >= 70 :
    print("C")
else :
    print("F")

#첫번째 이프에서 반대되는 모든 경우에서 첫번째 엘이프에 해당하는 경우에 첫번째 엘이프가 돌아감
#첫번째 이프가 만족하면 그 밑에 있는 모든 엘이프와 엘스는 실행되지 않음
#이프와 모든 엘이프에 만족하지 않을 시에 엘스 속 문장이 실행됨
