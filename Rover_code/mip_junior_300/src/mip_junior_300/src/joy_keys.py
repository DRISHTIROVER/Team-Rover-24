import pygame
import json, os

LEFT, RIGHT, UP, DOWN = False, False, False, False
###########################################################################################
# x ----- 0
# o ----- 1
# △ ----- 2
# □ ----- 3
# L1 ---- 4
# R1 ---- 5
# L2 ---- 6
# R2 ---- 7
# select --- 8
# start ---- 9
# up arrow --- 13
# down arrow - 14
#left arrow -- 15
#right arrow - 16
#Initialize controller
pygame.init()
joysticks = []
running = 1
for i in range(pygame.joystick.get_count()):
    joysticks.append(pygame.joystick.Joystick(i))
for joystick in joysticks:
    joystick.init()
path = "/home/dhruv/mip_junior_300/src/mip_junior_300/src"
#cwd = os.getcwd()     this fuction returns the current working directory in which this file is being RAN.
#print(cwd)
with open(os.path.join(path, "ps3_keys.json"), 'r+') as file:
    button_keys = json.load(file)
analog_keys = {0:0, 1:0, 2:0, 3:0, 4:-1, 5: -1 }

# START OF GAME LOOP
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            pass

        # HANDLES BUTTON PRESSES
        if event.type == pygame.JOYBUTTONDOWN:
            if event.button == button_keys['left_arrow']:
                LEFT = True
            if event.button == button_keys['right_arrow']:
                RIGHT = True
            if event.button == button_keys['down_arrow']:
                DOWN = True
            if event.button == button_keys['up_arrow']:
                UP = True
        # HANDLES BUTTON RELEASES
        if event.type == pygame.JOYBUTTONUP:
            print(event.button)
            if event.button == button_keys['left_arrow']:
                LEFT = False
            if event.button == button_keys['right_arrow']:
                RIGHT = False
            if event.button == button_keys['down_arrow']:
                DOWN = False
            if event.button == button_keys['up_arrow']:
                UP = False

        #HANDLES ANALOG INPUTS
        if event.type == pygame.JOYAXISMOTION:
            analog_keys[event.axis] = event.value
            print("left analog leftright axis")
            print(analog_keys[0])
            print("left analog updown axis")
            print(analog_keys[1])
            print("L2 left front bottom PS3 key")
            print(analog_keys[2])
            print("right analog leftright axis")
            print(analog_keys[3])
            print("right analog updown axis")
            print(analog_keys[4])
            print("R2 right front bottom PS3 key")
            print(analog_keys[5])
