def word_count(filename) :
    f = open(filename)
    counts = {}
    for line in f :
        list = line.split()
        for word in list :
            if word in counts :
                counts[word] += 1
            else :
                counts[word] = 1
    return counts

reply = 'y'

while reply == 'y' :
    filename = input("검색할 파일 이름을 입력하세요: ")
    wc = word_count(filename)

    for word in sorted(wc) :
        if word == "어떻해" :
            word = "어떡해"
        elif word == "됀데" :
            word = "된데"
        elif word == "되" :
            word = "돼"
        print(word, wc[word])

    reply = input("계속하시겠습니까?(y/n)")