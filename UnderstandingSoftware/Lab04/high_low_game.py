import random

answer = random.randint(1, 100)
prediction = 0
times = 6

while prediction != answer and times > 0:
    prediction = int(input("Enter your prediction number : "))

    if prediction < answer:
        print("Lower than answer.")
    elif prediction > answer:
        print("Higher than answer.")
    else:
        break

    times -= 1
    print("You only have ", times, "times Left\n")

if prediction == answer:
    print("Answer!")
else :
    print("No more chance. Answer is", answer)
