sarah = [55, 63, 77, 81]
john = [65, 61, 67, 72]
alice = [97, 95, 92, 88]
scores = [sarah, john, alice]

for student in scores :
    for score in student :
        print(score, end=' ')
    print()

words = ['apple', 'carrot', 'banana', 'daisy']

print(words.sort())
print(words.sort(reverse=True)) #아니면 sort 후 reverse