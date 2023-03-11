#01

def lab01():
    x = -1
    y = 3
    print('다항식의 계산 결과 : ',(-y)**3+2*x**2*y)

#02
def lab02():
    fd = int(input('화씨온도 : '))

    print('섭씨온도 : ', (fd-32)*5/9)


#03

def lab03():
    x1 = int(input('x1 : '))
    y1 = int(input('y1 : '))
    x2 = int(input('x2 : '))
    y2 = int(input('y2 : '))

    print("두 점 사이의 거리 = ",((x2-x1)**2 + (y2-y1)**2)**(1/2))

#04
def lab04():
    import turtle
    t = turtle.Turtle()

    t.shape('turtle')

    t.left(45)
    t.forward(141.4)
    
    t2 = turtle.Turtle()

    t2.shape('turtle')

    t2.forward(100)
    
    t3 = turtle.Turtle()

    t3.shape('turtle')
    t3.up()
    t3.left(90)
    t3.goto(100,0)
    t3.down()
    
    t3.forward(100)

#05
def lab05():
    import time
    total_sec = time.time()
    total_min = total_sec//60
    cur_min = int(total_min % 60)
    total_hour = total_min //60
    cur_hour = int(total_hour %24)
    cur_hour += 9

    print('현재 한국 시간 : ', cur_hour,'시', cur_min,'분')

#06
def lab06():
    in_money = int(input("투입한 돈 : "))
    price = int(input("물건 가격 : "))
    charge = in_money-price
    coin500 = int(charge // 500)
    coin100 = int(charge%500/100)
    print('거스름돈 : ', charge)
    print('500원 동전의 수 : ', coin500)
    print('100원 동전의 수 : ', coin100)

    
    

lab06()
