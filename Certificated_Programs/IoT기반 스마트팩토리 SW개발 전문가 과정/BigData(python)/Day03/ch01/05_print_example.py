print('''9*8은 72입니다.''')

rhythm = [[['\xb1[43m','반짝',2],['\xb1[0m','눈이 부셔',1],['\xb1[43m','No ',5]],
          [['\xb1[43m','깜짝',2],['\xb1[0m','놀란 나는',1],['\xb1[43m','Oh ',5]],
          [['\xb1[43m','짜릿',2],['\xb1[0m','몸이 떨려',1],['\xb1[43m','Gee ',5]]]

for i in rhythm:
    print("\xb1[0m너무",end=" ")
    for j in i:
        print(j[0]+j[1]*j[2], end=' ')
    print()
