#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pygame
import time


# In[2]:


pygame.init()

display_width = 600
display_height = 400
gameDisplay = pygame.display.set_mode((display_width, display_height))

done = False

clock = pygame.time.Clock()

intro = pygame.image.load("./image/Intro_Final_600.png")
st = pygame.image.load("./image/start_226.png")
sc = pygame.image.load("./image/score_204.png")
stOn = pygame.image.load("./image/startOn_226.png")
scOn = pygame.image.load("./image/scoreOn_204.png")
overImg = pygame.image.load("./image/GameOverLast.png")
overText = pygame.image.load("./image/GameOverChar_430.png")
restart = pygame.image.load("./image/restart_410.png")
restartOn = pygame.image.load("./image/restartOn_410.png")


# In[3]:


class Button:
    def __init__(self, img_in, x, y, width, height, img_act, x_act, y_act, action = None):
        mouse = pygame.mouse.get_pos()
        click = pygame.mouse.get_pressed()
        if x + width > mouse[0] > x and y + height > mouse[1] > y:
            gameDisplay.blit(img_act,(x_act, y_act))
            if click[0] and action != None:
                time.sleep(1)
                action()
        else:
            gameDisplay.blit(img_in,(x,y))


# In[4]:


def over():
    global gameDisplay, done
    
    gameOver = gameDisplay.blit(overImg, (0,0))
    overTimg = gameDisplay.blit(overText, (85,30))
    
    restartbtn = Button(restart,95,250,410,60,restartOn, 95, 250, None ) #game start
                     
    pygame.time.delay(3000)


# In[5]:


def quitgame():    
    pygame.quit() 



# In[6]:
def GameModeSet():
    global GAMEMODE
    GAMEMODE = q
    

def main():

    global gameDisplay, done
    
    title = gameDisplay.blit(intro, (0,0))
    startButton = Button(st,370,330,220,33,stOn,370,330,GameModeSet) #game start)
    scoreButton = Button(sc,390,365,204,33,scOn,390,365,over) #score)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done=True


# In[ ]:


while not done:
    
    clock.tick(60)
    
    main()

    pygame.display.update()
    """
    screen.blit(i,(0, 0) )
    screen.blit(st,(370, 330) )
    screen.blit(sc,(390, 365) )

    pygame.display.update()  
    for event in pygame.event.get():# User did something
        if event.type == pygame.QUIT:# If user clicked close
            done=True # Flag that we are done so we exit this loop

    """


# In[ ]:




