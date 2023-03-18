#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pygame as pyg
from random import random as rand
import datetime
import time
import os


# In[2]:



WIDTH = 800
HEIGHT = 450

GRAVITY = 0.98/5

BACKGROUND_WIDTH = 800
BOTTOM_WIDTH = 200

MAX_GAUGE = 1000
GAUGE_INC = 5

BACK_SPEED = 1

FPS = 60
UP_DOWN = 30

FORE_SPEED = 5


MOB = []
MOB_X = []
MOB_Y = []
MOB_LENGTH = 8

SECTER = []
SECTER_HEIGHT = 75
SECTER_LENGTH = 5

ITEM_RATE = 0.2
EMPTY_RATE = 0.3

MOB_TYPE=[70,140,210]


HP = 100
SCORE= 0

ITEM_GROUP =[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

GAMEMODE = 0


# In[3]:




class Button:
    def __init__(self, img_in, x, y, width, height, img_act, x_act, y_act, action = None):
        mouse = pyg.mouse.get_pos()
        click = pyg.mouse.get_pressed()
        if x + width > mouse[0] > x and y + height > mouse[1] > y:
            screen.blit(img_act,(x_act, y_act))
            if click[0] and action != None:
                time.sleep(1)
                action()
        else:
            screen.blit(img_in,(x,y))


# In[4]:


def setMob():
    global BOTTOM_WIDTH, WIDTH, ITEM_RATE, ITEM_GROUP, EMPTY_RATE, HEIGHT, MOB
    
    ret = [0, 0, 0, 0, 0]
    mobtype = int(rand()*3)
    empty_sec = int(rand() * 4)
    
    ret[empty_sec] = 0
    ret[empty_sec+1] = 0
    mobcount= 0
    
    if mobtype == 0:
        for i in range(0,5):
            if empty_sec == i or empty_sec+1 == i:
                continue
            
            temp = rand()
            
            if temp < ITEM_RATE:
                #item
                item = int(rand() * 16)
                ret[i] = ITEM_GROUP[item]
                
            elif temp < EMPTY_RATE+ITEM_RATE :
                # empty
                ret[i] = 0
            else :
                if(mobcount == 3):
                    continue
                mobcount+=1
                #mob
                ret[i] = 50
            
    elif mobtype == 1:
        for i in range(0,5):
            if empty_sec == i or empty_sec+1 == i  or ret[i] == 80:
                continue 
                
            temp = rand() 
            
            if temp < ITEM_RATE:
                #item
                item = int(rand() * 16)
                ret[i] = ITEM_GROUP[item]
                
            elif temp < EMPTY_RATE+ITEM_RATE :
                # empty
                ret[i] = 0
            else :
                if(mobcount == 1):
                    continue
                    
                if i == 4:
                    mobcount+=1
                    ret[i] = 50
                else:
                #mob
                    mobcount+=1
                    ret[i] = 60
                    ret[i+1] = 80        

    elif mobtype == 2: 
        for i in range(0,5):            
            if empty_sec == i or empty_sec+1 == i or ret[i] == 80:
                continue
            temp = rand()
            
            if temp < ITEM_RATE:
                #item
                item = int(rand() * 16)
                ret[i] = ITEM_GROUP[item]
                
            elif temp < EMPTY_RATE+ITEM_RATE :
                # empty
                ret[i] = 0
            else :
                if mobcount == 1:
                    continue
                    
                if i == 4:
                    ret[i] = 50
                elif i == 3:
                    mobcount+=1
                    ret[i] = 60
                    ret[i+1] = 80   
                else :    
                                #mob
                    mobcount+=1
                    ret[i] = 70
                    ret[i+1] = 80    
                    ret[i+2] = 80   
                
    return ret


# In[5]:


def init():
    
    global FORE_SPEED, MOB, MOB_X, MOB_Y, MOB_LENGTH, SECTER, SECTER_HEIGHT,SECTER_LENGTH, ITEM_RATE, EMPTY_RATE, HP, SCORE, GAMEMODE,SECTER,background,background_x,  bottom,bottom_x
    
    FORE_SPEED = 5
    MOB = []
    MOB_X = []
    MOB_Y = []
    MOB_LENGTH = 8

    SECTER = []
    SECTER_HEIGHT = 75
    SECTER_LENGTH = 5

    ITEM_RATE = 0.2
    EMPTY_RATE = 0.3



    HP = 100
    SCORE= 0


    GAMEMODE = 0
    
    for i in range(0,5):
        SECTER.append(SECTER_HEIGHT*i + (HEIGHT * 0.1))

    for i in range(0,MOB_LENGTH):
        MOB.append(setMob())
        MOB_X.append(i * BOTTOM_WIDTH + WIDTH)   
    
    background = list()
    background_x = list()

    background.append(pyg.image.load(os.path.join(os.path.abspath('image'),'background_01.jpg')))
    background.append(background[0].copy())

    background_x.append(0)
    background_x.append(BACKGROUND_WIDTH)

    bottom = list()
    bottom_x = list()

    bottom.append(pyg.image.load(os.path.join(os.path.abspath('image'),'bottom_01.png')))
    bottom_x.append(0)

    for i in range(0,8):
        bottom.append(bottom[0].copy())
        bottom_x.append(BOTTOM_WIDTH * (i+1))
    #print(BOTTOM_WIDTH * (i+1))
    
    


# In[6]:



for i in range(0,5):
    SECTER.append(SECTER_HEIGHT*i + (HEIGHT * 0.1))

for i in range(0,MOB_LENGTH):
    MOB.append(setMob())
    MOB_X.append(i * BOTTOM_WIDTH + WIDTH)   
    


# In[7]:


pyg.init();

size = [WIDTH,HEIGHT]

screen = pyg.display.set_mode(size)

pyg.display.set_caption("AstLoner")

pyg.key.set_repeat(1, 1)

txtFont = pyg.font.SysFont( "Console", 30, bold=False, italic=False)


pyg.mixer.init()


# In[8]:



intro = pyg.image.load(os.path.join(os.path.abspath('image'),'Intro_Final_600.png'))
st = pyg.image.load(os.path.join(os.path.abspath('image'),"start_226.png"))
sc = pyg.image.load(os.path.join(os.path.abspath('image'),"score_204.png"))
stOn = pyg.image.load(os.path.join(os.path.abspath('image'),"startOn_226.png"))
scOn = pyg.image.load(os.path.join(os.path.abspath('image'),"scoreOn_204.png"))
overImg = pyg.image.load(os.path.join(os.path.abspath('image'),"GameOverLast.png"))
overText = pyg.image.load(os.path.join(os.path.abspath('image'),"GameOverChar_430.png"))
restart = pyg.image.load(os.path.join(os.path.abspath('image'),"restart_410.png"))
restartOn = pyg.image.load(os.path.join(os.path.abspath('image'),"restartOn_410.png"))


# In[9]:


done = False

clock = pyg.time.Clock()


# In[10]:


def StartGame():
    global GAMEMODE
    GAMEMODE = 1

def GoToIntro():
    global GAMEMODE
    GAMEMODE = 0


# In[11]:


def intro_Scr():

    global screen, done
    
    title = screen.blit(intro, (0,0))
    startButton = Button(st,570,380,220,33,stOn,570,380,StartGame) #game start)
    scoreButton = Button(sc,590,415,204,33,scOn,590,415,over) #score)
    
    for event in pyg.event.get():
        if event.type == pyg.QUIT:
            done=True
            
def over():
    global screen, overImg, overText, restart,restartOn
    
    gameOver = screen.blit(overImg, (0,0))
    overTimg = screen.blit(overText, (185,80))
    
    restartbtn = Button(restart,195,300,410,60,restartOn, 195, 300, GoToIntro ) #game start
    
    for event in pyg.event.get():
        if event.type == pyg.QUIT:
            done=True


# In[12]:


class character:
    def __init__(self):
        self.x = WIDTH/10
        self.y = HEIGHT*0.9
        self.ydown = UP_DOWN
        self.gauge = MAX_GAUGE
        self.width = 56
        self.height = 64
        
    def Up(self):
        global UP_DOWN, GRAVITY, HEIGHT,MAX_GAUGE,GAUGE_INC,WIDTH,SPEED,FORE_SPEED
        if self.gauge < 1:
            return        
        self.gauge -= 1 
        if self.gauge <= 0:
            self.gauge = 0
            return       
        self.y -= UP_DOWN * GRAVITY *0.125 + FORE_SPEED/5
        if self.y < HEIGHT*0.1 :
            self.y = HEIGHT*0.1
    
    def run(self):
        global UP_DOWN, GRAVITY, HEIGHT,MAX_GAUGE,GAUGE_INC,WIDTH,SPEED,FORE_SPEED
        self.y += UP_DOWN * GRAVITY *0.5 + FORE_SPEED/5
        if (self.y > HEIGHT*0.9) :
            self.y = HEIGHT*0.9     
            c.gauge += GAUGE_INC
            if c.gauge >MAX_GAUGE:
                c.gauge = MAX_GAUGE
        
    def display(self, scr):       
        global UP_DOWN, GRAVITY, HEIGHT,MAX_GAUGE,GAUGE_INC,WIDTH,SPEED, HP
        color = (255,255,255)
        if self.gauge > MAX_GAUGE *0.5:
            color = (0,255,0)
        elif self.gauge > MAX_GAUGE *0.3:
            color = ( 255,255, 0)
        else:
            color = (255,0,0)
            # 400 : x = mg : g         400 *g /mg 
        pyg.draw.rect(scr, color , [0,0,WIDTH*self.gauge / MAX_GAUGE,HEIGHT*0.05],0)  # Gauge
        
        
        color = (255,255,255)
        if HP > 50:
            color = (0,255,0)
        elif HP > 30:
            color = ( 255,255, 0)
        else:
            color = (255,0,0)        
        
        pyg.draw.rect(scr, color , [self.x-20,self.y-30 + (30-(HP*0.3)) ,20, HP*0.4 ],0)  # HP
        
        
        
      #  pyg.draw.rect(scr, (255,255,255) , [self.x,self.y-30,20,40],0) # Charcter
        charimg = pyg.image.load(os.path.join(os.path.abspath('image'),'LastFinal.png'))
        scr.blit(charimg, (self.x,self.y-self.height))
        


# In[13]:


background = list()
background_x = list()

background.append(pyg.image.load(os.path.join(os.path.abspath('image'),'background_01.jpg')))
background.append(background[0].copy())

background_x.append(0)
background_x.append(BACKGROUND_WIDTH)

bottom = list()
bottom_x = list()

bottom.append(pyg.image.load(os.path.join(os.path.abspath('image'),'bottom_01.png')))
bottom_x.append(0)

for i in range(0,8):
    bottom.append(bottom[0].copy())
    bottom_x.append(BOTTOM_WIDTH * (i+1))
    #print(BOTTOM_WIDTH * (i+1))
    
    


# In[14]:



pyg.mixer.music.load(os.path.join(os.path.abspath('sound'),'BackgroundMusic.wav'))
pyg.mixer.music.play(-1) 



deadSound = pyg.mixer.Sound(os.path.join(os.path.abspath('sound'),'Dead.wav'))
gameOverSound = pyg.mixer.Sound(os.path.join(os.path.abspath('sound'),'GameOver.wav'))
itemSound = pyg.mixer.Sound(os.path.join(os.path.abspath('sound'),'Item.wav'))
shockSound = pyg.mixer.Sound(os.path.join(os.path.abspath('sound'),'Shock.wav'))


# In[15]:


print(len(MOB))


# In[16]:


def heat(h):
    global c, MOB, BOTTOM_WIDTH, HP
    if not(h):
        for i in range(0,MOB_LENGTH) :
            for j in range(0, SECTER_LENGTH) :
                if MOB[i][j] == 50 and ( MOB_X[i] <= c.x+c.width-50 and c.x <= MOB_X[i] + int(BOTTOM_WIDTH/2) 
                      and SECTER[j] <= c.y+c.height  and 
                        c.y < SECTER[j] +  70* (int(MOB[i][j]/10) - 4) ):
                        HP-=10
                        MOB[i][j] = 0
                        return True
                elif  MOB[i][j]== 60 and ( MOB_X[i] <= c.x+c.width-50 and c.x <= MOB_X[i] + int(BOTTOM_WIDTH/2) 
                      and SECTER[j] <= c.y+c.height and 
                          c.y < SECTER[j] +  70* (int(MOB[i][j]/10) - 4) ):
                        HP-=20
                        MOB[i][j] = 0
                        return True
                elif MOB[i][j] == 70 and ( MOB_X[i] <= c.x+c.width-50 and c.x <= MOB_X[i] + int(BOTTOM_WIDTH/2) 
                      and SECTER[j] <= c.y+c.height  and 
                          c.y < SECTER[j] +  70* (int(MOB[i][j]/10) - 4) ):
                        HP-=40    
                        MOB[i][j] = 0
                        return True

    return False


# In[17]:


def print_background(scr):
    global background1,background2,background1_x,background2_x, MOB, MOB_X, MOB_y, SCORE
    screen.fill((0,0,0))
    
   # print(datetime.datetime.now())
    
    for i in range(0,len(background_x)):    
        background_x[i] -= BACK_SPEED
        if background_x[i] <= -BACKGROUND_WIDTH:
            background_x[i] += (BACKGROUND_WIDTH*2)
    
    for i in range(0,len(bottom_x)):    
        bottom_x[i] -= FORE_SPEED
        if bottom_x[i] <= WIDTH*-1 :
            bottom_x[i] += (WIDTH *2)
            SCORE += FPS * FORE_SPEED
            
    for i in range(0,MOB_LENGTH):
        MOB_X[i] -= FORE_SPEED
       # print(MOB_X[i])
        if not(MOB_X[i] >  BOTTOM_WIDTH * -2):
            MOB.append(setMob())
            MOB.remove(MOB[0])
            MOB_X[0] += ( BOTTOM_WIDTH * MOB_LENGTH )
            MOB_X.append(MOB_X[0])
            MOB_X.remove(MOB_X[0])
            
            break
            
                
    for i in range(0,len(background)):  
        scr.blit(background[i],(background_x[i], 0) )
        
    for i in range(0,len(bottom_x)):  
        scr.blit( bottom[i], (bottom_x[i], HEIGHT*0.9) )
        
    
    for i in range(0,MOB_LENGTH):
        for j in range(0,SECTER_LENGTH):
            if not( MOB[i][j] == 80 or MOB[i][j] == 0 or MOB[i][j] == -1):
                color = (255,255,255)
                high = 50
                img = pyg.image.load(os.path.join(os.path.abspath('image'),'Box.png'))
                if MOB[i][j] == 50 :
                    color = (0,0,255)
                    high= MOB_TYPE[0]
                    img = pyg.image.load(os.path.join(os.path.abspath('image'),'small.png'))
                elif  MOB[i][j]== 60 :
                    color = (0,255,0)
                    high = MOB_TYPE[1]
                    img = pyg.image.load(os.path.join(os.path.abspath('image'),'mid.png'))
                elif MOB[i][j] == 70 :
                    color = (255,0,0)
                    high = MOB_TYPE[2]
                    img = pyg.image.load(os.path.join(os.path.abspath('image'),'Big.png'))
                #print(MOB_X[j])
               # print(SECTER[j])
                scr.blit(img,[int(MOB_X[i]+BOTTOM_WIDTH/4),int(SECTER[j])])
                #pyg.draw.rect(scr,color,(int(MOB_X[i]+BOTTOM_WIDTH/4),int(SECTER[j]),int(BOTTOM_WIDTH/2),high))

            """print(MOB[j], end="\t")
        print()
    print()"""
            
    printScore = txtFont.render("Score : "+str(SCORE),True, (0,0,0) )
    scr.blit(printScore,[0,HEIGHT*0.05])
    
   # pyg.draw.rect(scr, (125,125,125) , [0,HEIGHT*0.9,WIDTH,HEIGHT*0.1],0)


# In[18]:


c = character()

count = 0

isHeat = False
heatTick = 0


# In[19]:


def MAIN_GAME():
    global c,count,screen, FORE_SPEED, done, isHeat,heatTick, GAMEMODE, HP
    
    check = True
    for event in pyg.event.get():# User did something
        if event.type == pyg.QUIT:# If user clicked close
            done=True # Flag that we are done so we exit this loop
        elif event.type == pyg.KEYDOWN:
            if event.key == pyg.K_UP or event.key == pyg.K_SPACE:
                c.Up()
                check = False
    else :
        c.gauge += GAUGE_INC
        if c.gauge > MAX_GAUGE:
            c.gauge = MAX_GAUGE
        c.run()
        

    print_background(screen)
    c.display(screen)
    if heat(isHeat) :
        shockSound.play()
        isHeat = True
        heatTick = 0
        
    if HP <= 0:
        GAMEMODE = 2
    
    if isHeat :
        heatTick += 1
        if heatTick == 120:
            heatTick = 0
            isHeat = False
        
   # print(c.x ,end="\t")
    # print(c.y)
    
    count += 1
    if count == 300 :
        count = 0
        FORE_SPEED += 1
    
    


# In[20]:


while not done :
    
   # pyg.mixer.music.load('./sound/BackgroundMusic.wav')
    clock.tick(FPS)
    if GAMEMODE == 0:
        init()
        intro_Scr()
        pass
    elif GAMEMODE ==1:
        MAIN_GAME()
    elif GAMEMODE == 2:
        over()
        gameOverSound.play()
    
    pyg.display.update()  


# In[21]:



pyg.mixer.quit()
pyg.quit() 


# In[ ]:




