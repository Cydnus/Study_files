# encoding:UTF-8

# 01
def ex01():
    name = input("이름을 입력하세요 ")
    age = int(input('나이를 입력하세요 '))

    age_100 = 2120-age

    print(name,"씨는 ",age_100,"세에 100살이 됩니다")

#02

def ex02():
    rad = int(input('반지름을 입력하시오 : '))
    print('반지름이 ',rad,'인 원의 넓이 = ' , rad**2 * 3.141592)




#03
def ex03():
    import turtle
    t = turtle.Turtle()
    t.shape('turtle')
    
    side = 100

    for i in range(0,3):
        t.forward(side)
        t.left(120)

#04
'''
    side = 200으로 변경하면됨
'''


#05

def ex05():
    import turtle
    t = turtle.Turtle()
    t.shape('turtle')
    
    side = 100
    angle = 90
    for i in range(0,4):
        t.forward(side*2)
        t.left(angle)

    t.up()
    t.goto(0,side)
    t.down()
    t.forward(side*2)
    t.up()
    t.goto(side,0)
    t.left(angle)
    t.down()
    t.forward(side*2)

    
        
    
ex05()
