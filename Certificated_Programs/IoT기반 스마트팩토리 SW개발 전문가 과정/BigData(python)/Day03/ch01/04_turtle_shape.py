import turtle

colors = ['red','cyan','blue','green','yellow','orange','magenta']

t = turtle.Turtle()

turtle.bgcolor('black')
t.speed(8)
t.width(3)
length = 10

'''
while length < 500 :
    t.forward(length)
    t.pencolor(colors[length%7])
    t.right(89)
    length += 5
'''
    
while length < 10000 :
    t.forward(length)
    t.pencolor(colors[length%7])
    t.right(55)
    length += 1
