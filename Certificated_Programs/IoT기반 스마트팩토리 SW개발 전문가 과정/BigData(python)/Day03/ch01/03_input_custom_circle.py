import turtle

rad = int(input('원의 반지름을 입력하시오 : '))
color = input('원의 색깔을 입력하시오 : ')

t = turtle.Turtle()
t.shape('
        turtle')

t.up()
t.goto(0,-rad)
t.down()

t.begin_fill()
t.color(color)

t.circle(rad)
t.fillcolor(color)
t.end_fill()
