#!/usr/bin/env python
# coding: utf-8

# In[1]:


import turtle as t
from tkinter import messagebox


# In[2]:


WIDTH = 3
HEIGHT = 3


# In[3]:


t.setup(600, 600)
t.bgcolor("black")
t.color("white")
t.hideturtle()
t.speed(10)
t.width(10)
t.up()


# In[4]:



for i in range(WIDTH) :
  t.up()
  t.goto(-300, i*200-300)
  t.down()
  t.forward(600)     
t.left(90)
  
for i in range(1, HEIGHT) :
  t.up()
  t.goto(i*200-300, -300)
  t.down()
  t.forward(600)
      
t.pencolor("green")
t.up()


# In[5]:


def draw_x(x, y) :
    t.up()
    t.goto(x + 50, y - 200)
    t.down()
    t.write("X", font = ('Arial', 100, 'normal'))


# In[6]:


def draw_o(x, y) :
    t.up()
    t.goto(x + 50, y - 200)
    t.down()
    t.write("O", font = ('Arial', 100, 'normal'))


# In[7]:


def draw(board) :
    x = -300
    y = 300
    for piece in board :
        if piece == "X" :
            draw_x(x, y)
        elif piece == "O" :
            draw_o(x, y)
            
        x += 200
        if x >= 300 :
            x = -300
            y -= 200 


# In[8]:


board = ["", "", "", "", "", "", "", "", ""]
nextTurn = "O"


# 모양 잡아주기

# In[9]:


def shape3_3(board):
    temp = []
    for i in range(0,HEIGHT):
        t1 = list()
        for j in range(0, WIDTH):
            t1.append(board[i*3+j])
        temp.append(t1)
    return temp
            


# 가로줄 확인

# In[10]:


def checkLeft(board, x, y, check ):
    '''왼쪽 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x-1,y,check)
    return 0

def checkRight(board, x, y, check ):
    '''오른쪽 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x+1,y,check)
    return 0


# 세로줄 확인

# In[11]:


def checkUp(board, x, y, check ):
    '''위쪽 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x,y-1,check)
    return 0

def checkDown(board, x, y, check ):
    '''아래쪽 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x,y+1,check)
    return 0


# 대각선 ↖↘

# In[12]:


def checkLeftUp(board, x, y, check ):
    '''대각선 왼쪽 위 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x-1,y-1,check)
    return 0

def checkRightDown(board, x, y, check ):
    '''대각선 오른쪽 아래 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x+1,y+1,check)
    return 0


# 대각선 ↗ ↙

# In[13]:


def checkRightUp(board, x, y, check ):
    '''대각선 오른쪽 위 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x+1,y-1,check)
    return 0

def checkLeftDown(board, x, y, check ):
    '''대각선 왼쪽 아래 같은지 확인'''
    if ( x < 0 or x >= WIDTH ) or ( y < 0 or y >= HEIGHT  ) :
        return 0
    if board[y][x] == check :
        return 1 + checkLeft(board,x-1,y+1,check)
    return 0

    


# 확인  
# 빈칸여부 -> 게임 무승부  
# 각 방향 더해서 2(width-1, height-1 (WIDTH + HEIGHT)/2 -1)  ( 클릭된 부분 제외)이면 한 줄 가득 찼다고 판단  
# 게임이 종료가 아니라면 None 반환

# In[14]:


def GameCheck(board, cell, ch):
    end_check = True
    for i in board :
        if i == '':
            end_check = False
            break
            
    shape = shape3_3(board)
    x =cell%3
    y = cell//3 
    
    if checkLeft(shape, x-1, y, ch) + checkRight(shape, x+1, y, ch) == WIDTH-1:
        return shape[y][x]
    elif checkUp(shape, x, y-1, ch) + checkDown(shape, x, y+1, ch) == HEIGHT-1:
        return shape[y][x]
    elif checkLeftUp(shape, x-1, y-1, ch) + checkRightDown(shape, x+1, y+1, ch) == (WIDTH + HEIGHT)/2 -1:
        return shape[y][x]
    elif checkRightUp(shape, x+1, y-1, ch) + checkLeftDown(shape, x-1, y+1, ch) == (WIDTH + HEIGHT)/2 -1:
        return shape[y][x]
    elif end_check :
        return 'end'
    return None


# 기존 clicked부분 에 덮어쓰여지는것을 방지  
# 클릭 이후 게임 종료 여부 확인

# In[15]:


def clicked(x, y) :
    global nextTurn, board
    print(x, "", y)
    column = (x + 300) // 200
    row = -(y - 300) // 200
    cell = column + row * 3
    cell = int(cell)
    print(row, "", column)
    if board[cell] =="":
        board[cell] = nextTurn
        
        if nextTurn == "X" : nextTurn = "O"
        else : nextTurn = "X"
        draw(board)
        ch = GameCheck(board, cell, board[cell])
        if ch == None:
            return
        elif ch == board[cell]:
            messagebox.showinfo('','%s 승리' %board[cell])
            t.bye()
        elif ch == 'end':
            messagebox.showinfo('','게임이 종료되었습니다.')
            t.bye()
        


# In[16]:



draw(board)
t.onscreenclick(clicked)
t.mainloop()


# In[ ]:




