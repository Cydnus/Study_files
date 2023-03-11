#!/usr/bin/env python
# coding: utf-8

# In[121]:


import turtle 
import math 


# In[122]:


t = turtle.Turtle()
turtle.ht()
t.shape('turtle')
screen = turtle.Screen()
turtle.setup(width = 800, height = 450)
t.speed(8)


# In[123]:


vx = 0
vy = 0
v = (vx + vy)/2
x = -380
y = -200


# In[124]:


t.up()
t.goto(x,y)
t.down()


# In[125]:


velocity = 50
angle = t.heading()


# In[126]:


spaceCheck = False


# In[127]:


def up():
    global angle,t
    angle += 5
    if angle > 90 :
        angle = 90
    t.setheading(angle)

def down():
    global angle,t
    angle -=5
    if angle < 0 :
        angle = 0
    t.setheading(angle)
        
        
def space():
    global vx,vy, spaceCheck, angle, v
    if not spaceCheck :
        spaceCheck = True
        before_vy = vy
        vx = velocity * math.cos(angle*3.14/180.0)
        vy = velocity * math.sin(angle*3.14/180.0)
        temp_y = velocity * math.sin(angle*3.14/180.0)
        while abs(vy-10) < temp_y :
            draw()
        else :
            spaceCheck = False


# In[128]:


def draw():
    global vx,vy,x,y,t,angle,v,velocity
    
    vx = vx
    vy = vy - 10    
    v = (x**2 + vy**2)**0.5
    print(vx,vy,v)
    
    x = x +vx
    y = y+ vy 
    if y <= -200 :
        y = -200
    
    angle = math.asin(vy/velocity)
    
    t.setheading((360+angle)%360)
    
    t.goto(x,y)


# In[129]:



screen.onkeypress(up, "Up")
screen.onkeypress(down, "Down")

screen.onkeypress(space, "space")

screen.listen() # 프로그램 활성화


# In[130]:



turtle.mainloop()

