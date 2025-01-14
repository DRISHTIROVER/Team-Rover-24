#!/usr/bin/env python3
import rospy
import time
from geometry_msgs.msg import Twist
import pygame
import json, os
msg = Twist()
LEFT, RIGHT, UP, DOWN = False, False, False, False
msg.angular.z = True
pygame.init()
joysticks = []
for i in range(pygame.joystick.get_count()):
    joysticks.append(pygame.joystick.Joystick(i))
for joystick in joysticks:
    joystick.init()
#cwd = os.getcwd()     this fuction returns the current working
path = "/home/dhruv/mip_junior_300/src/mip_junior_300/src"
#cwd = os.getcwd()     this fuction returns the current working directory in which this file is being RAN.
#print(cwd)
with open(os.path.join(path, "ps3_keys.json"), 'r+') as file:
    button_keys = json.load(file)
analog_keys = {0:0, 1:0, 2:0, 3:0, 4:-1, 5: -1 }
rospy.init_node('custom_talker', anonymous=True)
pub = rospy.Publisher('/manipulator', Twist,queue_size = 10)

while not rospy.is_shutdown():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            pass
         # HANDLES BUTTON PRESSES
        if event.type == pygame.JOYBUTTONDOWN:
            if event.button == 15:
                msg.linear.y = 1
            if event.button == 14:
                msg.linear.x = 2
            if event.button == 16:
                msg.linear.y = -1
            if event.button == 13:
                msg.linear.x = -2
            if event.button == 4:
                msg.linear.z = 3
            if event.button == 5:
                msg.linear.z = -3
            if event.button == 8:
                msg.angular.z = not msg.angular.z
            if event.button == 3:
                msg.linear.z = 4
        # HANDLES BUTTON RELEASES
        if event.type == pygame.JOYBUTTONUP:

            if event.button == 13:
                msg.linear.x = 0
            if event.button == 14:
                msg.linear.x = 0
            if event.button == 15:
                msg.linear.y = 0
            if event.button == 16:
                msg.linear.y = 0
            if event.button == 4:
                msg.linear.z = 0
            if event.button == 5:
                msg.linear.z = 0

        if event.type == pygame.JOYAXISMOTION:
            analog_keys[event.axis] = event.value
           
            msg.angular.x =  float("{:.2f}".format(250*analog_keys[1]))
            msg.angular.y =  float("{:.2f}".format(250*analog_keys[4]))
            
            pub.publish(msg)
    time.sleep(0.01)
    
