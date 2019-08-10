city = ["Seoul", "Busan", "Suwon", "Chicago", "Tokyo"]
a = "Hello"
b = "World"
print(a + "\n" + b)
#print(a + \n + b) 안돼
print(a, end = " cc ");print(b) #end option
print("Hello\tWorld") #줄바꿈은 안해줌 그냥 4칸 스페이스

sen = "Python is easier than C"
sen2 = "Python is easier than %s"
sen3 = "C"
print(sen2 % sen3) #Python is easier than C
sen3 = "Java"
print(sen2 % sen3) #Python is easier than Java

sen2 = "Python is %d times easier than %s"
sen3 = "C"
sen4 = 5
print(sen2 %(sen4, sen3))

sen4 = 5.5
sen2 = "Python is %1f times easier than %s"
print(sen2 %(sen4, sen3))


sentence = "Have a nice day"
spl = sentence.split(' ')
print(spl)
spl = sentence.split('a') #['H', 've', 'nice d', 'y']
print(spl)