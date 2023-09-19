import pygame, sys
from pygame.locals import QUIT, KEYDOWN, KEYUP, K_LEFT, K_RIGHT, K_SPACE

bullet = pygame.image.load('54.png')
bullet = pygame.transform.scale(bullet, (20,30))
bulletWidth, bulletHeight = bullet.get_size()
bullets = []

WINDOWSCALE = (300, 400)
BACKGROUNDCOLOR = (255, 255, 255)

myCharLeft = False
myCharRight = False
bulletForward = False

pygame.init()
DISPLAYSURF = pygame.display.set_mode(WINDOWSCALE)
pygame.display.set_caption('shooting Game')
FPSLOCK = pygame.time.Clock()

myChar = pygame.image.load('fighters.png')
myChar = pygame.transform.scale(myChar, (50, 25))
myCharScale = myChar.get_size()
myCharWidth = myCharScale[0]
myCharHeight = myCharScale[1]
myCharX = WINDOWSCALE[0] / 2 - myCharWidth / 2
myCharY = WINDOWSCALE[1] - myCharHeight

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
             pygame.quit()
             sys.exit()
          
        if event.type == KEYDOWN:
          if event.key == K_LEFT:
             myCharLeft = True
          elif event.key == K_RIGHT:
             myCharRight = True
          elif event.key == K_SPACE:
             bulletForward = True
        elif event.type == KEYUP:
          if event.key == K_LEFT:
             myCharLeft = False
          elif event.key == K_RIGHT:
             myCharRight = False
          elif event.key == K_SPACE:
             bulletForward = False
    if bulletForward:
      bulletX = myCharX + myCharWidth/2 - bulletWidth/2
      bulletY = myCharY - bulletHeight
      bullets.append([bulletX, bulletY])

    DISPLAYSURF.fill(BACKGROUNDCOLOR)
    DISPLAYSURF.blit(myChar, (myCharX, myCharY))

    if len(bullets) > 0:
      for i, mXY in enumerate(bullets):
        mXY[1] -= 10
        bullets[i][1] = mXY[1]
        if mXY[1] <= 0:
          try:
            bullets.remove(mXY)
          except:
            pass

    if len(bullets) > 0:
      for mx, my in bullets:
        DISPLAYSURF.blit(bullet, (mx,my))
  
    if myCharLeft:
      myCharX -= 5
    if myCharRight:
      myCharX += 5

    if myCharX <= 0:
      myCharX = 0
    elif myCharX >= WINDOWSCALE[0] - myCharWidth:
      myCharX = WINDOWSCALE[0] - myCharWidth
   
    pygame.display.update()

    FPSLOCK.tick(60)
