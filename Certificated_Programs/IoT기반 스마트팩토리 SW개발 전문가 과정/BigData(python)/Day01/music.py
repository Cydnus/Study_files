
import pygame

def playsound(soundfile):
    pygame.init()
    pygame.mixer.init()
    sound = pygame.mixer.Sound(soundfile)
    clock = pygame.time.Clock()
    sound.play()
    while pygame.mixer.get_busy():
        print("Playtin... - func => playsound")
        clock.tick(100)
        
def playmusic(soundfile):
    pygame.init()
    pygame.mixer.init()
    clock = pygame.time.Clock()
    pygame.mixer.music.load(soundfile)
    pygame.mixer.music.play(-1) 
    while pygame.mixer.music.get_busy():
        print("Playtin... - func => playsound")
        clock.tick(1000)
    
def stopmusic():
    pygame.mixer.music.stop()
    
def getmixerargs():
    pygame.mixer.init()
    freq, size, chan = pygame.mixer.get_init()
    return freq, size, chan
   
def initMixer(): 
    BUFFER = 3072
    FREQ, SIZE, CHAN = getmixerargs()
    pygame.mixer.init(FREQ, SIZE, CHAN, BUFFER)
   
    
   
try:
    initMixer()
    filename = 'BackgroundMusic.wav'
    playmusic(filename)
    print("OK")
except KeyboardInterrupt:
    stopmusic()
    print("\nPlay Stopped by user")
except Exception:
    print("unknown error")
    
print("Done")
