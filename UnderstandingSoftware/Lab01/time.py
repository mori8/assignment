sec = int(input("초를 입력해 주세요 :"))
minute = sec // 60
second = sec % 60
hour = minute // 60
minute = minute % hour



print(sec, "초는", hour, "시간", minute, "분", second, "초 입니다.")