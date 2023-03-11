#!/usr/bin/env python
# coding: utf-8

# 필요한 모듈 불러오기

# In[315]:


import tkinter as tk
from tkinter import messagebox, filedialog, simpledialog
from PIL import Image, ImageTk
import os
import cv2
import numpy as np


# In[316]:


openimg = None


# In[317]:


def Display_Image():
    global  window ,openimg,canvas
    
    img = ImageTk.PhotoImage(openimg)    
    print(openimg.size)
    window.geometry('%sx%s'%(openimg.size[0],openimg.size[1]))
    canvas.delete('all')
    canvas.width = openimg.size[0]
    canvas.height = openimg.size[1]
    canvas.create_image(0, 0,anchor='nw' ,image=img )
    canvas.image =img
    canvas.pack(expand=True, fill='both')
    


# In[318]:


def PILToNpArray(img):
    return np.asarray(img)

def NpArrayToPIL(img):
    temp = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    return Image.fromarray(cv2.cvtColor(temp,cv2.COLOR_BGR2RGB))
    


# 메뉴 -> 파일 -> 열기  
# 이미지 불러오기

# In[319]:


def open_file():
    global openimg
    filename = filedialog.askopenfilename(initialdir="./", title="Select file",
                                          filetypes=(("Image File", "*.png"),
                                          ("all files", "*.*")))
    
    openimg = Image.open(os.path.abspath(filename)).convert('RGB')
    Display_Image()
    


# 메뉴 -> 파일 -> 종료

# In[320]:


def quit_window():
    global windoww
    window.quit()


# In[321]:


def save_file():
    global  window,openimg
    
    if openimg == None:
        return
    
    filename = filedialog.asksaveasfilename(initialdir="./", title="Select file",
                                          filetypes=(("Image File", "*.png"),
                                          ("all files", "*.*")))
    openimg.save(filename+'.png')
    


# In[322]:


def Enlargement():
    global openimg
    if openimg == None :
        return
    
    scale = simpledialog.askinteger('확대','확대할 배율을 입력하세요(2~4)',minvalue = 2,maxvalue=10)
    width = openimg.size[0]
    height = openimg.size[1]
    img2 = cv2.resize(PILToNpArray(openimg),(int(scale*width), int(scale * height)),interpolation=cv2.INTER_CUBIC)
    openimg = None
    openimg = NpArrayToPIL(img2)
    Display_Image()


# In[323]:


def Reduction():
    global openimg
    
    if openimg == None:
        return

    scale = simpledialog.askfloat('축소', '축소할 배율을 입력하세요(0.1~1)', minvalue=0.1, maxvalue=1)
    width = openimg.size[0]
    height = openimg.size[1]
    img2 = cv2.resize(PILToNpArray(openimg),(int(scale*width), int(scale * height)),interpolation=cv2.INTER_CUBIC)
    openimg = None
    openimg = NpArrayToPIL(img2)

    Display_Image()


# In[324]:


def Reverse_up_down():
    global openimg
    if openimg == None:
        return
    img = PILToNpArray(openimg)
    img2 = cv2.flip(img,0)
    openimg=NpArrayToPIL(img2)   
    
    Display_Image()


# In[325]:


def Reverse_left_right():
    global openimg
    if openimg == None:
        return
    img = PILToNpArray(openimg)
    img2 = cv2.flip(img,1)
    openimg=NpArrayToPIL(img2)   
    Display_Image()


# In[326]:


def Rotation():
    global openimg  
    angle = simpledialog.askinteger('회전', '회전할 각도를 입력하세요(1~359)', minvalue=1, maxvalue=359)
    width = openimg.size[0]
    height = openimg.size[1]
    img = PILToNpArray(openimg)
    matrix = cv2.getRotationMatrix2D((width/2,height/2),angle,1)
    img2 = cv2.warpAffine(img,matrix,(width,height))
    openimg=NpArrayToPIL(img2)   
    Display_Image()


# In[327]:


def Brightly():
    global openimg
    
    if openimg == None:
        return
    img = PILToNpArray(openimg)
    
    img2 = cv2.add(img,10)
    
    openimg=NpArrayToPIL(img2)   
    
    Display_Image()


# In[328]:


def Darkly():
    global openimg
    
    if openimg == None:
        return
    
    img = PILToNpArray(openimg)
    
    img2 = cv2.subtract(img,10)
    
    openimg=NpArrayToPIL(img2)   
    
    Display_Image()


# In[329]:


def Blurring():
    global openimg
    if openimg == None:
        return
    
    
    img = PILToNpArray(openimg)
    
    img2 = cv2.subtract(img,-1,np.ones((3,3),np.float32)/9)
    
    openimg=NpArrayToPIL(img2)   
    
    Display_Image()


# In[330]:


def Embossing ():
    global openimg
    if openimg == None:
        return
    
    img = PILToNpArray(openimg)
    
    img2 = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
    
    mask = np.array([[1, 1, 1], [1, -8, 1], [1, 1, 1]])
    
    img3 = cv2.filter2D(img2,-1,mask)
    
    
    openimg=NpArrayToPIL(img3)      
    
    Display_Image()


# In[331]:


def GrayScale():
    global openimg
    if openimg == None:
        return
    
    img = PILToNpArray(openimg)
    
    img2 = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
    
    openimg=NpArrayToPIL(img2)   
    Display_Image()


# Tk설정

# In[332]:


window = tk.Tk()

window.title('My PhotoShop Made By Sangho Cho')

canvas = tk.Canvas(window)


# 메뉴바 설정

# In[333]:



menubar = tk.Menu(window)
filemenu = tk.Menu(menubar,tearoff=0)
imgprocess1menu = tk.Menu(menubar,tearoff=0)
imgprocess2menu = tk.Menu(menubar,tearoff=0)

filemenu.add_command(label="파일 열기", command=open_file)
filemenu.add_command(label="파일 저장", command=save_file)
filemenu.add_command(label="프로그램 종료", command=quit_window)

imgprocess1menu.add_command(label="확대",command=Enlargement)
imgprocess1menu.add_command(label="축소",command=Reduction)
imgprocess1menu.add_command(label="상하 반전",command=Reverse_up_down)
imgprocess1menu.add_command(label="좌우 반전",command=Reverse_left_right)
imgprocess1menu.add_command(label="회전",command=Rotation)

imgprocess2menu.add_command(label="밝게",command=Brightly)
imgprocess2menu.add_command(label="어둡게",command=Darkly)
imgprocess2menu.add_command(label="블러링",command=Blurring)
imgprocess2menu.add_command(label="엠보싱",command=Embossing )
imgprocess2menu.add_command(label="흑백이미지",command=GrayScale)


menubar.add_cascade(label="파일",menu=filemenu)
menubar.add_cascade(label="영상처리1",menu=imgprocess1menu)
menubar.add_cascade(label="영상처리2",menu=imgprocess2menu)

window.config(menu=menubar)


# 메인 반복

# In[334]:


window.mainloop()


# In[ ]:




