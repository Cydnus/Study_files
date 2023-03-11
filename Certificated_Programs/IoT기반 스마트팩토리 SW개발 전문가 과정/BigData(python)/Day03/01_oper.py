# 01
def ex01():
    print(2+17)
    print(2-17)

    print(2*17)

    print(17**2)
    print(10*2**17)

    print(2**2**3)

    print(17/5)
    print(17//5)


#02
def ex02():

    p = int(input('피제수를 입력하시오 : '))
    q = int(input('제수를 입력하시오 : '))
    print("나눗셈의 몫 = ",p//q)
    print("나눗셈의 나머지", p%q)


#03
def ex03():
    sec =1000
    min = sec//60
    remainder = sec%60
    print(min,"분", remainder,'초')


#04

def ex04():
    x=y=100
    print(x)
    print(y)


#05
def ex05():
    x = 1000
    print('초기값 x = ',x)
    x+=2
    print('x +=2 후의 x = ',x)
    x-=2
    print('x -=2 후의  x = ',x)
    

#06
def ex06():
    x = int(input("첫 번째 수: "))
    y = int(input("두 번째 수: "))
    z = int(input("세 번째 수: "))

    avg = (x+y+z)/3
    print('평균 = ', avg)

ex06()
