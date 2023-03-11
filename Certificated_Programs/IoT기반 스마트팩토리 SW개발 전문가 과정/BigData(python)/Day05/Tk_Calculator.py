#!/usr/bin/env python
# coding: utf-8

# ##### 외부 모듈(라이브러리) 추가

# In[1]:


from tkinter import *
from PIL import Image, ImageTk
import os


# ##### 창 불러오기

# In[2]:


window = Tk()
window.title("Calculator Made By Sangho Cho")


# ##### 기본 이벤트 처리 함수 설정
# ###### 숫자 입력

# In[3]:


def input_Num(event):
    global text_low
    text_low['text'] +=str(event)


# ###### 연산자 입력

# In[4]:


def input_oper(oper):
    global text_low, text_high
    temp = text_high['text'].strip()
    
    if temp == '' and text_low['text'].strip() =='':
        return
    elif temp == '' :
        if oper == '+'or oper == '-'or oper =='×'or oper == '÷' or oper == '%' :
            txtl = text_low['text'].strip()
            text_high['text'] += str(float(txtl))+" "+oper
            text_low['text'] =""
            return
        elif oper == '=': 
            txtl = text_low['text'].strip()
            text_high['text'] += str(float(txtl))
            text_low['text'] =""
            return
            
    elif temp[len(temp)-1] != '+' and temp[len(temp)-1] != '-' and temp[len(temp)-1] !='×'and temp[len(temp)-1] != '÷' and temp[len(temp)-1] != '%' :
        text_high['text'] =""
        return
        
    if oper == '+'or oper == '-'or oper =='×'or oper == '÷'  or oper == '%' :
        txth = text_high['text'].strip()
        txtl = text_low['text'].strip()
        txth = txth.replace('×','*')
        txth = txth.replace('÷','/')
        calTxt = str(txth+  str(float(txtl)))       
        retstr = str(eval(calTxt))
        retstr += " " + str(oper)
        print(retstr)

        text_low['text'] =""
        text_high['text'] = retstr
    elif oper == 'ce':
        text_low['text'] =""
        text_high['text'] = ""
    elif oper == 'c':
        text_low['text'] =""
    elif oper == '◁' and  text_low['text'] !="":
        text_low['text'] = text_low['text'][0:-1]
    elif oper == '±' and (text_low['text'] !="" or text_low['text'] !="0") :
        text_low['text'] = str(float(text_low['text'])*(-1))
    elif oper == '=' and text_low['text'] !="" :
        txth = text_high['text'].strip()
        txtl = text_low['text'].strip()
        txth = txth.replace('×','*')
        txth = txth.replace('÷','/')        
        calTxt = str(txth+  str(float(txtl)))
        retstr = str(eval(calTxt))

        retstr += " "
        print(retstr)

        text_low['text'] =""
        text_high['text'] = retstr
    
    elif oper == 'º'and not('.' in text_low['text']):
        if text_low['text'] == "":
            text_low['text']+='0'
        text_low['text'] +="."


# ##### 기본 컴포넌트 설정

# In[5]:


def NumBtnAddEvent(index):
    global Number_btn
    
    Number_btn[index]['command'] = lambda : input_Num(index)
    
def OperBtnAddEvent(index,target):
    global operator_btn
    
    operator_btn[index]['command'] = lambda : input_oper(target)
    


# In[6]:


Number_btn = list()

for i in range(0,10):
    temp = Button(window,borderwidth=0, text=str(i))#, width=100, height=50) #
    Number_btn.append(temp)
    
for i in range(0,10):
    NumBtnAddEvent(i)

text_high = Label(window,anchor='e',
                  width=24,
                  font="D2Coding 25")
text_low = Label(window,anchor='e',
                 width=18,
                 font="D2Coding 25",
                 borderwidth = 3,
                relief="sunken")


operator_btn = list()
oper_list=['+','-','×','÷','=','ce','c','±', '%','º','◁']

for i in oper_list:
    operator_btn.append(Button(window,borderwidth=0,text=str(i)))#, width=100, height=50))
    
for i in range(0,len(oper_list)):
    OperBtnAddEvent(i,oper_list[i])


# In[7]:


Num_img = list()
for i in range(0,len(Number_btn)):
    Num_img.append(PhotoImage(file = 'image/%s.png'%i))
    Number_btn[i]['image'] = Num_img[i]

oper_img = list()
for i in range(0,len(oper_list)):
    oper_img.append(PhotoImage(file = 'image/%s.png'%oper_list[i]))
    operator_btn[i]['image'] = oper_img[i]


# ##### 기본 컴포넌트 배치

# In[8]:


text_high.grid(row=0,column=0, columnspan=4)
text_low.grid(row=1,column=0, columnspan=3)

for i in range(1,10):
    Number_btn[i].grid(row=(5-((i-1)//3)),column=((i-1)%3))
Number_btn[0].grid(row=6,column=1)
    
oper_location = [[3,5],[3,4],[3,3],[3,2],[3,6],[1,2],[2,2],[0,6],[0,2],[2,6],[3,1] ]

for i in range(0,len(oper_location)):
    operator_btn[i].grid(row=oper_location[i][1],column=oper_location[i][0])


# In[9]:


text_high['text']=""
text_low['text']=""

window.mainloop()

