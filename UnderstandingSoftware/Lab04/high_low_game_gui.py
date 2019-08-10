import random
import easygui
answer = random.randint(1, 100)
prediction = 0
times = easygui.buttonbox("Choose times for challenge : ", choices=['5', '6', '7'])
times = int(times)

while prediction != answer and times > 0:
    prediction = easygui.enterbox("Enter your prediction number : ")
    prediction = int(prediction)
    if prediction < answer :
        easygui.msgbox("Lower")
    elif prediction > answer:
        easygui.msgbox("Higher")
    else :
        break

    --times
    print("You only have", times, "times Left\n")

if prediction == answer :
    easygui.msgbox("Answer!")
else :
    easygui.msgbox("No more chance. Answer is", answer)