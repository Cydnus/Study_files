
import pygame

pygame.init()

size = [600, 400]
screen = pygame.display.set_mode(size)
done = False

clock = pygame.time.Clock()

while not done:
    clock.tick(60)
    
    pygame.display.update()
    
#def initGame():
    
    global deadSound, gameOverSound, itemSound, shockSound

    pygame.mixer.init()
    pygame.mixer.music.load('BackgroundMusic.wav')
    pygame.mixer.music.play(-1) 
    
   
    deadSound = pygame.mixer.Sound('Dead.wav')
    gameOverSound = pygame.mixer.Sound('GameOver.wav')
    itemSound = pygame.mixer.Sound('Item.wav')
    shockSound = pygame.mixer.Sound('Shock.wav')

    while pygame.mixer.music.get_busy():
    
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done=True
                
pygame.mixer.quit()
pygame.quit()