def bmi(height_weight_list) :
    bmi_list = []
    for h, w in height_weight_list :
        bmi = w / (h / 100 * h / 100)   #외워
        bmi_list.append(bmi)
    return bmi_list


students = [[160, 52], [162, 65], [170, 65]]
result = bmi(students)

for i in range(len(result)) :
    print(result[i])
