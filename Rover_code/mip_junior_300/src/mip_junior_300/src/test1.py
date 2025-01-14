#!/usr/bin/env python3
import pprint
import pygame
import time
import socket
import serial
from geometry_msgs.msg import Twist
import rospy
data = "#"
X,Y=0.0,0.0
rospy.init_node('custom_talker', anonymous=True)
pub = rospy.Publisher('/manipulator', Twist,queue_size = 10)


class PS4Controller(object):
    """Class representing the PS4 controller. Pretty straightforward functionality."""

    controller = None
    axis_data = None
    button_data = None
    hat_data = None
    global X
    global Y
    X=0.0
    Y=0.0
    def init(self):
        """Initialize the joystick components"""

        pygame.init()
        pygame.joystick.init()
        self.controller = pygame.joystick.Joystick(0)
        self.controller.init()

    def listen(self):
        if not self.axis_data:
            self.axis_data = {}

        if not self.button_data:
            self.button_data = {}
            for i in range(self.controller.get_numbuttons()):
                self.button_data[i] = 0
        if not self.hat_data:
            self.hat_data = {}
            for i in range(self.controller.get_numhats()):
                self.hat_data[i] = (0, 0)

        while not rospy.is_shutdown()	:
            msg = Twist()
            time.sleep(0.05)
            for event in pygame.event.get():
                if event.type == pygame.JOYAXISMOTION:
                    self.axis_data[event.axis] = round(event.value, 2)
                    if 0 in self.axis_data:
                           pprint.pprint(self.axis_data[0])
                           X=self.axis_data[0]
                           msg.linear.x=X*200
                    if 4 in self.axis_data:
                 	    pprint.pprint(self.axis_data[4])
                 	    Y=self.axis_data[4]
                 	    msg.linear.y=Y*200
                    rospy.loginfo(msg)
                    pub.publish(msg)
                #     if 5 in self.axis_data:
                #         gripper_joint = self.axis_data[5]
                #         gripper_joint = 3000 + 100 * \
                #             (gripper_joint < 0)+abs(gripper_joint)*99
                #         gripper_joint = "#" + str(gripper_joint)
                #         sock.sendall(gripper_joint.encode('utf-8'))
                #         if(self.axis_data[5] != 0):
                #             sock.sendall(gripper_joint.encode('utf-8'))
                    # print(self.button_data[1])
                    # print(self.button_data[2])
                    # print(self.button_data[3])
                    # print(self.button_data[4])
                   # print(self.button_data[5])
                #pprint.pprint(self.axis_data[])
                #pprint.pprint(self.hat_data)
                # print("3="+str(step3),"2="+str(step2),step1)
                # print("drishti_joint="+str(drishti_joint)+"Svnit_joint="+str(Svnit_joint)+"gripper_joint="+str(gripper_joint))
ps4 = PS4Controller()
ps4.init()
ps4.listen()
